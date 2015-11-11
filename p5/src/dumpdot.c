#include <util.h>
#include <common.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

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
    if (node->kind != KValue) return;
    printf("%d\n", node->val);
    char *str;
    sprintf(str, "%d", node->val);
    return newNode(dot, 1, str);	
}


int dumpVar(DumpDot *dot, ASTNode node)
{
    if (node->kind != KName) return -1;
    if (node->sym->kind != INt) return -1;
    return newNode(dot, 1, node->sym->sym->name);
}


int dumpAsgnExp(DumpDot *dot, ASTNode node)
{
    if (ndoe->kind == KAssignExp)
    {
        int i = newNode(dot, 3, "Exp", "=", "Exp");
        int j = dumpExp()
    
    }
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
        op[0] = (node->exp->op == PLUS) ? '+' : '-'';
        int i = newNode(dot, 2, op, "Exp");
        int j = dumpExp(dot, node->exp->kids[0]);
        drawLine(dot, i, 1, j);
        return i;
    }
    else if (node->kind == KParenExp)
    {
        int i = newNode(dot, 3, "(", "Exp", ")");
        int j = dumpExp(node) //TODO
        drawLine(dot, i, 1, j);
        return i;
    }
}

int dumpArray(DumpDot *dot, ASTNode node)
{
    if (node->kind != KName) return -1;
    if (node->sym->kind != ARRAY) return -1;
    int i = newNode(dot, 4, node->sym->asym->name, "[", "exp", "]");
    int j = dumpExp(dot, )// TODO
    drawLine(dot, i, 2, j);
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

   

int dumpConstDef(DumpDot *dot, ConstDef def)
{
    if (def->name->sym->kind == INt) dumpVar(dot, def->name);
    int i = newNode(dot, 4, "const", "name", "=", "exp");
    int j = new
}

int dumpConstDecl(DumpDot *dot, ASTNode node)
{
    if (node->kind != KConstDecl) return -1;
    int i;  
    List def = node->constdecl->def;
    for (i = 0; i < node->constdecl->def->size; i++)
        dumpConstDef(dot, listnode(def, i)->item); 
    return i;
}



int dumpUnit(DumpDot *dot, ASTNode node)
{
	if (node->kind != KCompUnit) return -1;
    ASTNode decl = node->decl;    
    if (nod)
    return newNode(dot, node->unit->decl) + newNode(dot, node->unit->func);
}







