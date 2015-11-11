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
newName(Table ptab, char *name, int type, void *content)
{
	ASTNode new;
	NEW0(new);
	new->kind = KName;
	if (type == 0)
		if (content == NULL)
			new->sym = newINTEntry(ptab, name, 0, 0);
		else new->sym = newINTEntry(ptab, name, 1, calculateExp((ASTNode)content)); 
	else if (type == 1)
		if (((List)content)->size == 1)
			new->sym = newArrayEntry(ptab, name, 0, NULL, 0); // TODO how to compute the val
		else new->sym = newArrayEntry(ptab, name, 1, NULL, (((List)content)->size) - 1);
	else if (type == 2)
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
	Cond newexp;
	NEW0(newexp);
	newexp->op = op;
	newexp->kids[0] = left;
	newexp->kids[1] = right;
}

ASTNode
newAssignment(int op, ASTNode left, ASTNode right)
{
	ASTNode new;
	NEW0(new);
	new->kind = KAssignExp;
	Exp newexp;
	NEW0(newexp);
	newexp->op = op;
	newexp->kids[0] = left;
	newexp->kids[1] = right;
	new->exp = newexp;
	return new;
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
newExpStmt(ASTNode exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KExpStmt;
	ExpStmt newstmt;
	NEW0(newstmt);
	new->estmt = newstmt;
	newstmt->exp = exp;
	return new;
}

void
destroyExpStmt(ExpStmt *pnode)
{
	if (*pnode == NULL) return;
	ExpStmt node = *pnode;
	destroyAST(&node->exp);
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
destroyBlock(Block *pnode)
{
	if (*pnode == NULL) return;
	Block node = *pnode;
	destroyList(&node->stmts, destroyAST);
	free(node);
	*pnode = NULL;
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
		break;
	case KPrefixExp:
	case KParenExp:
	case KInfixExp:
	case KAssignExp:
		destroyExp(&node->exp);
		break;
	case KExpStmt:
		destroyExpStmt(&node->estmt);
		break;
	case KBlock:
		destroyBlock(&node->block);
		break;
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

ConstDef
newConstDef(ASTNode name, List exp)
{
	ConstDef new;
	NEW0(new);
	new->name = name;
	new->exp = exp;
	return new;
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



VarDef 
newVarDef(ASTNode name, List Exp)
{
	VarDef new;
	NEW0(new);
	new->name = name;
	new->exp = Exp; // first elem in exp is size if it is array
	return new;
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

void
dumpAST(ASTNode node)
{
	if (node == NULL) return;
	int kind = node->kind;
	
	switch (kind) {
	case KValue:
		printf("%g", node->val);
		break;
	case KName:
		printf("%s", node->sym->sym->name);
		break;
	case KPrefixExp:
		printf("%s", opname[node->exp->op]);
		dumpAST(node->exp->kids[0]);
		break;
	case KParenExp:
		printf("(");
		dumpAST(node->exp->kids[0]);
		printf(")");
		break;
	case KInfixExp:
		dumpAST(node->exp->kids[0]);
		printf("%s", opname[node->exp->op]);
		dumpAST(node->exp->kids[1]);
		break;
	case KAssignExp:
		dumpAST(node->exp->kids[0]);
		printf("%s", opname[node->exp->op]);
		dumpAST(node->exp->kids[1]);
		break;
	case KExpStmt:
		dumpAST(node->estmt->exp);
		printf(";");
		break;
	case KBlock:
	{
		List stmts = node->block->stmts;
		ListItr itr = getGListItr(stmts, 0);
		while ( hasNext(itr) )  {
			dumpAST((ASTNode)nextItem(itr));
			printf("\n");
		}
		break;
	}
	default:
		printf("Unhandled ASTNode kind!\n");
	}
}
