#include <util.h>
#include <common.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "c1.tab.h"

//some function to generate dot file

DumpDot *newDumpDot(FILE *fp, int count)
{
    DumpDot *dot = (DumpDot*)malloc(sizeof(DumpDot));

    if (!fp) return NULL;
    dot->fp = fp;
    dot->count = count;
    fprintf(fp, "digraph {\n");
    fprintf(fp, "    node [shape = record];\n");	
    return dot;
}

void drawLine(DumpDot *dot, int nSrc, int pSrc, int nDst)
{
    if (!dot) return;
    fprintf(dot->fp, "    %d", nSrc);
    if (pSrc>=0)
        fprintf(dot->fp, ":%d", pSrc);
    fprintf(dot->fp, " -> %d;\n", nDst);
}
 
int newNode(DumpDot *dot, int num, ...)
{
    va_list list;
    va_start(list, num);
    fprintf(dot->fp, "    %d [label = \"", dot->count);
    int first = 1, i;
    for (i=0; i<num; i++) {
        char* st = va_arg(list, char*);
	    //printf("%s\n", st);
        if (!first)
            fprintf(dot->fp, "|");
        first = 0;
        if (st[0]=='<')
            fprintf(dot->fp, "<%d> \\<", i);
        else
            fprintf(dot->fp, "<%d> %s", i, st);
    }
    va_end(list);
    fprintf(dot->fp, "\"];\n");
    return dot->count++;
}

int newNode_1(DumpDot *dot, List list)
{
    fprintf(dot->fp, "    %d [label = \"", dot->count);
    int first = 1, i;
    for (i=0; i<list->size; i++) {
        char *st = (char *)removeFirst(list);
        if (!first)
            fprintf(dot->fp, "|");
        first = false;
        fprintf(dot->fp, "<%d> %s", i, st);
    }
    fprintf(dot->fp, "\"];\n");
    return dot->count++;
}


// dump ast to dot

int dumpNum(DumpDot *dot, ASTNode node)
{
    if (node->kind != KValue) return 0;
    //printf("%d\n", node->val);
    char str[10];
    sprintf(str, "%d", node->val);
    return newNode(dot, 1, str);	
}


int dumpVar(DumpDot *dot, ASTNode node)
{
    if (node->kind != KName) return -1;
    if (node->sym->kind != INt) return -1;
    return newNode(dot, 1, node->sym->sym->name);
}

int dumpStmt(DumpDot *dot, ASTNode node)
{
    if (node->kind != KStmt) return 0;
    Stmt stmt = node->stmt;
    switch(stmt->type)
    {
        case 0: return dumpAsgnExp(dot, stmt->asgnExp);
        case 1: return dumpFuncall(dot, stmt->funcall);
        case 3: return dumpIF(dot, stmt->ifstmt);
        case 4: return dumpWhile(dot, stmt->whilestmt);
        case 2: return dumpBlock(dot, stmt->block);
        case 5: return newNode(dot, 1, "empty");
        default: return 0;
    }
}



int dumpWhile(DumpDot *dot, ASTNode node)
{
    if (node->kind != KWhileStmt) return 0;
    int i = newNode(dot, 3, "while", "cond", "block");
    int j = dumpCond(dot, node->whilestmt->cond);
    int k = dumpStmt(dot, node->whilestmt->stmt);
    drawLine(dot, i, 1, j);
    drawLine(dot, i, 2, k);
    return i;
}

int dumpIF(DumpDot *dot, ASTNode node)
{
    if (node->kind != KIFStmt) return 0;
    int i, j, k, m;
    if (node->ifstmt->havelse)
    {
        i = newNode(dot, 5, "if", "cond", "stmt", "else", "stmt");
        j = dumpCond(dot, node->ifstmt->cond);
        k = dumpStmt(dot, node->ifstmt->stmt[0]);
        m = dumpStmt(dot, node->ifstmt->stmt[1]);
        drawLine(dot, i, 1, j);
        drawLine(dot, i, 2, k);
        drawLine(dot, i, 4, m);
        
    }
    else
    {
        i = newNode(dot, 3, "if", "cond", "stmt");
        j = dumpCond(dot, node->ifstmt->cond);
        k = dumpStmt(dot, node->ifstmt->stmt[0]);
        drawLine(dot, i, 1, j);
        drawLine(dot, i, 2, k);
    }
    return i;
}


int dumpAsgnExp(DumpDot *dot, ASTNode node)
{
    if (node->kind == KAssignExp)
    {
        int i = newNode(dot, 3, "Exp", "=", "Exp");
        int j = dumpLVal(dot, node->asgnexp->left);
        int k = dumpExp(dot, node->asgnexp->right);
        drawLine(dot, i, 0, j);
        drawLine(dot, i, 2, k);
        return i;    
    }
    return 0;
}

int dumpLVal(DumpDot *dot, ASTNode node)
{
    if (node->kind != KLVal) return 0;
    if (node->lval->type == 0 || node->lval->type == 2)
    {
        return dumpName(dot, node->lval->name);
    }
    else 
    {
        int i = newNode(dot, 4, node->lval->name->asym->name, "[", "Exp", "]");
        int k = dumpExp(dot, node->lval->exp);
        drawLine(dot, i, 2, k);
        return i;
    }   
}

int dumpBlock(DumpDot *dot, ASTNode node)
{
    if (node->kind != KBlock) return 0;
    List decl = node->block->decl;
    List stmts = node->block->stmts;
    Lnode temp;
    int i, j, k;
    i = newNode(dot, 2, "decl", "stmt");
    if (decl)
    {
        for (temp = decl->first; temp; temp = temp->next)
        {
            j = dumpDecl(dot, temp->item);
            drawLine(dot, i, 0, j);
        }    
    }
    if (stmts)
    {
        for (temp = stmts->first; temp; temp = temp->next)
        {
            j = dumpStmt(dot, temp->item);
            drawLine(dot, i, 1, j);
        }
    }
    return i;
}

int dumpName(DumpDot *dot, Entry name)
{
    if (!name) return 0;
    if (name->kind == INt) return newNode(dot, 1, name->sym->name);
    else if (name->kind == ARRAY) return newNode(dot, 1, name->asym->name);
    else return newNode(dot, 1, name->fsym->name);
}


int dumpExp(DumpDot *dot, ASTNode node)
{
    if (node->kind == KInfixExp)
    {
        char op[1];
        switch(node->exp->op)
        {
            case PLUS: op[0] = '+'; break;
            case MINUS: op[0] = '-'; break;
            case MULT: op[0] = '*'; break;
            case DIV: op[0] = '/'; break;
            case MOD: op[0] = '%'; break;
        }
             
        int i = newNode(dot, 3, "Exp", op, "Exp"); 
        int j = dumpExp(dot, node->exp->kids[0]);
        int k = dumpExp(dot, node->exp->kids[1]);
        drawLine(dot, i, 0, j);
	    drawLine(dot, i, 2, k);
	    return i;
    }
    else if (node->kind == KPrefixExp)
    {
        char op[1];
        op[0] = (node->exp->op == PLUS) ? '+' : '-';
        int i = newNode(dot, 2, op, "Exp");
        int j = dumpExp(dot, node->exp->kids[0]);
        drawLine(dot, i, 1, j);
        return i;
    }
    else if (node->kind == KParenExp)
    {
        int i = newNode(dot, 3, "(", "Exp", ")");
        int j = dumpExp(dot, node->exp->kids[0]);
        drawLine(dot, i, 1, j);
        return i;
    }//TODO
    else if (node->kind == KValue)
        return dumpNum(dot, node);
    else if (node->kind == KName)
    {
        if (node->sym->kind == INt) 
            return dumpVar(dot, node);
        else if (node->sym->kind == ARRAY)
            return dumpArray(dot, node);
        else return 0;
    }
    else if (node->kind == KLVal)
    {
        return dumpLVal(dot, node);
    }
    //return 0;
    
}

int dumpArray(DumpDot *dot, ASTNode node)
{
    if (node->kind != KName) return -1;
    if (node->sym->kind != ARRAY) return -1;
    int i, j;
    if (node->sym->asym->sizeInitial)
    {
        i = newNode(dot, 4, node->sym->asym->name, "[", "exp", "]");
        j = dumpExp(dot, node->sym->asym->exp);// TODO
        drawLine(dot, i, 2, j);
    }
    else
    {
        i = newNode(dot, 2, node->sym->asym->name, "[]");
    } 
    return i;
}
    
int dumpFunc(DumpDot *dot, ASTNode func)
{
    if (func->kind != KFuncDef) return -1;
    ASTNode name = func->func->name;
    ASTNode block = func->func->block;
    int i = newNode(dot, 3, name->sym->fsym->name, "()", "block");
    int j = dumpBlock(dot, block);
    drawLine(dot, i, 2, j);
    return i;
}

int dumpVarDef(DumpDot *dot, VarDef def)
{
    int i, j ,k;
    Lnode temp;
    if (def->name->sym->kind == INt) 
    {
        if (def->name->sym->sym->isInitial)
        {        
            j = dumpVar(dot, def->name);
            i = newNode(dot, 3, "name", "=", "exp");
            k = dumpExp(dot, def->name->sym->sym->exp);
            drawLine(dot, i, 2, k);
            drawLine(dot, i, 0, j);
        }
        else i = newNode(dot, 1, def->name->sym->sym->name);//TODO
    }
    else if (def->name->sym->kind == ARRAY){
        j = dumpArray(dot, def->name);
        if (def->name->sym->asym->isInitial)
        {
            i = newNode(dot, 3, "name", "=", "exp");
            for (temp = def->name->sym->asym->exp->first; temp; temp = temp->next)
            {
                k = dumpExp(dot, temp->item);
                drawLine(dot, i, 2, k);
            }
            drawLine(dot, i, 0, j);
        }
        else i = newNode(dot, 1, "name");
    }
    else return 0;
    return i;
}

int dumpConstDef(DumpDot *dot, ConstDef def)
{
    int i, j, k;
    Lnode temp;
    if (def->name->sym->kind == INt) j = dumpVar(dot, def->name);
    else if (def->name->sym->kind == ARRAY) j = dumpArray(dot, def->name);
    else return 0;
    i = newNode(dot, 3, "name", "=", "exp");
    if (def->name->sym->kind == INt)
    {
        k = dumpExp(dot, def->exp->first->item);
        drawLine(dot, i, 2, k);
    }
    else if (def->name->sym->kind == ARRAY)
    {
     
       for (temp = listnode(def->exp, 1); temp; temp = temp->next)
       {
            k = dumpExp(dot, temp->item);
            drawLine(dot, i, 2, k);
       }
    }
    drawLine(dot, i, 0, j);
    
    return i;
}


int dumpVarDecl(DumpDot *dot, ASTNode node)
{
    if (node->kind != KVarDecl) return 0;
    int i, j, k;
    List def = node->vardecl->def;
    i = newNode(dot, 2, "int", "def");
    for (k = 0; k < def->size; k++)
    {
        j = dumpVarDef(dot, listnode(def, k)->item);
        drawLine(dot, i, 1, j);
    }
    return i;
}


int dumpConstDecl(DumpDot *dot, ASTNode node)
{
    if (node->kind != KConstDecl) return -1;
    int i, j, k;  
    List def = node->constdecl->def;
    i = newNode(dot, 3, "const", "int", "def");
    for (k = 0; k < def->size; k++)
    {
        j = dumpConstDef(dot, listnode(def, k)->item); 
        drawLine(dot, i, 2, j);
    }
    return i;
}

int dumpDecl(DumpDot *dot, ASTNode node)
{
    if (node->kind == KConstDecl)
        return dumpConstDecl(dot, node);
    else if (node->kind == KVarDecl)
        return dumpVarDecl(dot, node);
    else return 0;
}

int dumpUnit(DumpDot *dot, ASTNode node)
{
	if (node->kind != KCompUnit) return -1;
	int j;
    List decl = node->unit->decl;    
    List func = node->unit->func;
    Lnode temp;
    
    int i = newNode(dot, 2, "decl", "func");
    for (temp = decl->first; temp; temp= temp->next)
    {
        j = dumpDecl(dot, temp->item);
        drawLine(dot, i, 0, j);
    }
    for (temp = func->first; temp; temp = temp->next)
    {
        j = dumpFunc(dot, temp->item);
        drawLine(dot, i, 1, j);
    } 
    return i;
}

int dumpFuncall(DumpDot *dot, ASTNode node)
{
    if (node->kind != KFuncall) return 0;
    int i = newNode(dot, 2, "name", "()");
    int j = newNode(dot, 1, node->name);
    drawLine(dot, i, 0, j);
    return i;
}

int dumpCond(DumpDot *dot, ASTNode node)
{
    if (node->kind != KCondExp) return 0;
    char *op;
    switch(node->exp->op)
    {
        case ISEQ: op = "==\0"; break;
        case GT: op = "\\>\0"; break;
        case LT: op = "\\<\0"; break;
        case LE: op = "\\<=\0"; break;
        case GE: op = "\\>=\0"; break;
        case NE: op = "!=\0"; break;
        default: op = "\0";
    }
    int i = newNode(dot, 3, "exp", op, "exp");
    int j = dumpExp(dot, node->exp->kids[0]);
    int k = dumpExp(dot, node->exp->kids[1]);
    drawLine(dot, i, 0, j);
    drawLine(dot, i, 2, k);
    return i;
}




