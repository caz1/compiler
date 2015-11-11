/*
 * TODO Functions of Abstract Syntax Tree
 * Author: Yu Zhang (yuzhang@ustc.edu.cn)
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "util.h"
#include "c1.tab.h"

extern Table symtab;


char *opname[]={
#undef opxx
#define opxx(a, b) b,
#include "op.h"
	"Undefined Op"
};

void 
destroyDecl(ASTNode *node)
{
    ASTNode temp = *node;
    if (temp->kind == KConstDecl)
        destroyConstDecl(node);
    else 
        destroyVarDecl(node);
}

ASTNode
newNumber(int value)
{
	ASTNode new;
	NEW0(new);
	new->kind = KValue;
	new->val = value;
	return new;
}

ASTNode
newName(Table ptab, const char *name, ASTNode exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KName;
	if (exp == NULL)
	    new->sym = newINTEntry(ptab, name, 0, NULL);
	else new->sym = newINTEntry(ptab, name, 1, exp); 
	return new;
}


ASTNode 
newArray(Table ptab, const char *name, int sizeInitial, List exp)
{
    ASTNode new;
    NEW0(new);
    new->kind = KName; 
    new->sym = newArrayEntry(ptab, name, sizeInitial, exp);
    return new;
}

ASTNode 
newFunc(Table ptab, const char *name)
{
    ASTNode new;
    NEW0(new);
    new->kind = KName;
    new->sym = newFuncEntry(ptab, name);
    return new;
}

ASTNode
newPrefixExp(int op, ASTNode exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KPrefixExp;
	Exp newexp;
	NEW0(newexp);
	newexp->op = op;
	newexp->kids[0] = exp;
	new->exp = newexp;
	return new;
}


ASTNode
newParenExp(ASTNode exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KParenExp;
	Exp newexp;
	NEW0(newexp);
	newexp->op = -1;
	newexp->kids[0] = exp;
	new->exp = newexp;
	return new;
}


ASTNode
newInfixExp(int op, ASTNode left, ASTNode right)
{
	ASTNode new;
	NEW0(new);
	new->kind = KInfixExp;
	Exp newexp;
	NEW0(newexp);
	newexp->op = op;
	newexp->kids[0] = left;
	newexp->kids[1] = right;
	new->exp = newexp;
	return new;
}


ASTNode 
newCondExp(int op, ASTNode left, ASTNode right)
{
	ASTNode new;
	NEW0(new);
	new->kind = KCondExp;
	Exp newexp;
	NEW0(newexp);
	newexp->op = op;
	newexp->kids[0] = left;
	newexp->kids[1] = right;
	new->exp = newexp;
	return new;
}


ASTNode
newAssignment(ASTNode left, ASTNode right)
{
	ASTNode new;
	NEW0(new);
	new->kind = KAssignExp;
	asgnExp newexp;
	NEW0(newexp);
	newexp->left = left;
	newexp->right = right;
	new->asgnexp = newexp;
	return new;
}

void
destroyAsgnExp(ASTNode *node)
{
    ASTNode temp = *node;
    destroyAST(&temp->asgnexp->left);
    destroyAST(&temp->asgnexp->right);
    free(temp->asgnexp);
    (*node)->asgnexp = NULL;   
}

void
destroyExp(Exp *pnode)
{
	if (*pnode == NULL) return;
	Exp node = *pnode;
	destroyAST(&node->kids[0]);
	destroyAST(&node->kids[1]);
	free(node);
	*pnode = NULL;
}

ASTNode
newBlock()
{
	ASTNode new;
	NEW0(new);
	new->kind = KBlock;
	Block newb;
	NEW0(newb);
	new->block = newb;
	newb->decl = newList();
	newb->stmts = newList();
	return new;
}

void
destroyBlock(ASTNode *node)
{
	if (*node == NULL) return;
	ASTNode temp = *node;
	destroyList(&temp->block->decl, destroyDecl);
    destroyList(&temp->block->stmts, destroyStmt);
    free(temp->block);
	(*node)->block = NULL;
}

ASTTree
newAST()
{
	ASTTree new;
	NEW0(new);
	return new;
}

void
destroyAST(ASTNode *pnode)
{
	if (*pnode == NULL) return;
	ASTNode node = *pnode;
	int kind = node->kind;
	
	switch (kind) {
	case KValue:
	case KName:
	case KFuncall:
		break;
    case KConstDecl: destroyConstDecl(&node->constdecl); break;
    case KVarDecl: destroyVarDecl(&node->vardecl); break;
	case KPrefixExp: 
	case KParenExp: 
	case KInfixExp: 
	case KCondExp: destroyExp(&node->exp); break;
	case KFuncDef: destroyFuncDef(&node); break;
	case KStmt: destroyStmt(&node); break;
	case KAssignExp: destroyAsgnExp(&node); break;
	case KIFStmt: destroyIFStmt(&node); break;
	case KBlock: destroyBlock(&node); break;
    case KCompUnit: destroyCompUnit(&node); break;
    case KWhileStmt: destroyWhileStmt(&node); break;
    case KLVal: destroyLVal(&node); break;
	default:
		printf("Unhandled ASTNode kind!\n");
	}
	free(node);
	*pnode = NULL;
}


ASTNode 
newCompUnit()
{
	ASTNode new;
	NEW0(new);
	new->kind = KCompUnit;
	CompUnit newb;
	NEW0(newb);
	newb->decl = newList();
	newb->func = newList();
	new->unit = newb;
	return new;
}

void destroyCompUnit(ASTNode *node)
{
    ASTNode temp = *node;
    destroyList(&temp->unit->decl, destroyDecl);
    destroyList(&temp->unit->func, destroyFuncDef);
    free(temp->unit);
    (*node)->unit = NULL;
}
	
ASTNode 
newConstDecl(List def)
{
	ASTNode new;
	NEW0(new);
	ConstDecl decl;
	NEW0(decl);
	new->constdecl = decl;
	new->kind = KConstDecl;
	new->constdecl->def = def;
	return new;
}

void destroyConstDecl(ASTNode *decl)
{
    ASTNode temp = *decl;
    destroyList(&temp->constdecl->def, destroyConstDef);
    free(temp->constdecl);
    (*decl)->constdecl = NULL;
}

ConstDef
newConstDef(ASTNode name, List exp)
{
	ConstDef new;
	NEW0(new);
	new->name = name;
	new->exp = exp;
	return new;
}

void destroyConstDef(ConstDef *def)
{
    ConstDef temp = *def;
    destroyAST(&temp->name);
    destroyList(&temp->exp, destroyExp);
    free(temp);
    *def = NULL;
}

ASTNode 
newLVal(char *name, int type, ASTNode exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KLVal;
	LVal newb;
	NEW0(newb);
	new->lval = newb;
	new->lval->type = type;	
	Entry pent = lookup(symtab, name, type);
	if (pent) new->lval->name = pent;
	else new->lval->name = NULL;
	if (type == 1) new->lval->exp = exp;
	return new;
}

void destroyLVal(ASTNode *node)
{
    ASTNode temp = *node;
    destroyAST(&temp->lval->exp);
    free(temp->lval);
    (*node)->lval = NULL;
}
ASTNode 
newVarDecl(List var)
{
	ASTNode new;
	NEW0(new);
	new->kind = KVarDecl;
	VarDecl newb;
	NEW0(newb);
	new->vardecl = newb;
	new->vardecl->def = var;
	return new;
}

void destroyVarDecl(ASTNode *node)
{
    ASTNode temp = *node;
    destroyList(&temp->vardecl->def, destroyVarDef); 
    free(temp->vardecl);
    (*node)->vardecl = NULL;
}

VarDef 
newVarDef(ASTNode name, List Exp)
{
	VarDef new;
	NEW0(new);
	new->name = name;
	new->exp = Exp; // first elem in exp is size if it is array
	return new;
}
void destroyVarDef(VarDef *node)
{
    VarDef temp = *node;
    destroyAST(&temp->name);
    destroyList(&temp->exp, destroyExp);
    free(temp);
    *node = NULL;
}


ASTNode 
newFuncDef(ASTNode name, ASTNode block)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFuncDef;
	FuncDef newb;
	NEW0(newb);
	new->func = newb;
	new->func->name = name;
	new->func->block = block;
	return new;
}

void destroyFuncDef(ASTNode *node)
{
    ASTNode temp = *node;
    destroyAST(&temp->func->block);
    destroyAST(&temp->func->name);
    free(temp->func);
    (*node)->func = NULL;
}

ASTNode 
newWhileStmt(ASTNode cond, ASTNode block)
{
	ASTNode new;
	NEW0(new);
	new->kind = KWhileStmt;
	WHILEStmt newb;
	NEW0(newb);
	newb->cond = cond;
	newb->stmt = block;
	new->whilestmt = newb;
	return new;
}

void destroyWhileStmt(ASTNode *node)
{
    ASTNode temp = *node;
    destroyAST(&temp->whilestmt->cond);
    destroyAST(&temp->whilestmt->stmt);
    free(temp->whilestmt);
    (*node)->whilestmt = NULL;
}

ASTNode
newStmt(ASTNode exp, int type)
{
	ASTNode new;
	NEW0(new);
	new->kind = KStmt;
	Stmt newb;
	NEW0(newb);
	newb->type = type;
	switch(type)
	{
		case 0: newb->asgnExp = exp; break;
		case 1: newb->funcall = exp; break;
		case 2: newb->block = exp; break;
		case 3: newb->ifstmt= exp; break;
		case 4: newb->whilestmt = exp; break;
		case 5: newb->empty = NULL; break;
	}
	new->stmt = newb;
	return new;
}

void destroyStmt(ASTNode *node)
{
    ASTNode temp = *node;
    Stmt newb = temp->stmt;
    switch(temp->stmt->type)
	{
		case 0: destroyAsgnExp(&newb->asgnExp); break;
		case 1: break;
		case 2: destroyBlock(&newb->block); break;
		case 3: destroyIFStmt(&newb->ifstmt); break;
		case 4: destroyWhileStmt(&newb->whilestmt); break;
	}
	free(newb);
    temp->stmt = NULL;
}

ASTNode 
newIfStmt(ASTNode cond, ASTNode block, int havelse, ASTNode Else)
{
	ASTNode new;
	NEW0(new);	
	new->kind = KIFStmt;
	IFStmt newb;
	NEW0(newb);
	newb->cond = cond;
	newb->havelse = havelse;	
	newb->stmt[0] = block;
	newb->stmt[1] = Else;
	new->ifstmt = newb;
	return new;
}

void destroyIFStmt(ASTNode *node)
{
    ASTNode temp = *node;
    destroyAST(&temp->ifstmt->cond);
    destroyAST(&temp->ifstmt->stmt[0]);    
    destroyAST(&temp->ifstmt->stmt[1]);
    free(temp->ifstmt);
    (*node)->ifstmt = NULL;        
}

ASTNode
newFuncall(const char *name)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFuncall;
	new->name = name;
	return new;
}

int calculateExp(ASTNode Exp)
{
	int kind = Exp->kind;
	if (kind != KInfixExp && kind != KPrefixExp && kind != KValue && kind != KName && kind != KLVal)
		exit(-1);
	if (kind == KLVal)
		if ( Exp->lval->name->sym->isInitial)
			return Exp->lval->name->sym->val;
		else exit(-1);
	else if (kind == KPrefixExp)
		if (Exp->exp->op == PLUS)
			return calculateExp(Exp->exp->kids[0]);
		else return -calculateExp(Exp->exp->kids[0]);
	else if (kind == KValue) return Exp->val;
	else if (kind == KName && Exp->sym->sym->isInitial == 1) return Exp->sym->sym->val;
	else if (kind == KInfixExp)
	{
		switch(Exp->exp->op)
		{
			case PLUS: return calculateExp(Exp->exp->kids[0]) + calculateExp(Exp->exp->kids[1]);
			case MINUS: return calculateExp(Exp->exp->kids[0]) - calculateExp(Exp->exp->kids[1]);
			case MULT: return calculateExp(Exp->exp->kids[0]) * calculateExp(Exp->exp->kids[1]);
			case DIV: return calculateExp(Exp->exp->kids[0]) / calculateExp(Exp->exp->kids[1]);
			case MOD: return calculateExp(Exp->exp->kids[0]) % calculateExp(Exp->exp->kids[1]);
		}
	}
	else exit(-1);	
}


Loc
setLoc(ASTNode node, Loc loc)//fline, int fcol, int lline, int lcol)
{
	if (node->loc == NULL )
		NEW0(node->loc);
	node->loc->first_line = loc->first_line;
	node->loc->first_column = loc->first_column;
	node->loc->last_line = loc->last_line;
	node->loc->last_column = loc->last_column;
	return node->loc;
}

void dumpAST(DumpDot *dot, ASTTree ast)
{
    dumpUnit(dot, ast->root);
}
