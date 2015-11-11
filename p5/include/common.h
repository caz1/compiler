/* 
 * Common definitions and declarations for compilers 
 * Author: Yu Zhang (yuzhang@ustc.edu.cn)
 */
#ifndef _COMMON_H_
#define _COMMON_H_
#include "util.h"
#include <stdbool.h>
// operator kinds
// You could add more kinds of error messages into op.h 
enum {
#define opxx(a, b) OP_##a,
#include "op.h"
	OPLAST
};

//extern char **opname;

// symbolic table
typedef struct symbol {
	char	*name;	// name of the symbol
	bool	isInitial;	// whether it is initialized	
	int	val;	// value of the symbol
	struct astnode *exp;
} *Symbol;

typedef struct {
	char *name;
	bool isInitial, sizeInitial;
	List exp; // first is size
} *arraySymbol;

typedef struct {
	char *name;
} *funcSymbol;


typedef struct entry {
	union {
		Symbol sym;
		arraySymbol asym;
		funcSymbol fsym;
	};
	enum {
		INt = 0,
		ARRAY,
		FUNC,
	} kind;
	struct entry *next;
} *Entry;

typedef struct table {
	// a hashtable to store symbols
	struct entry *buckets[256];
} *Table;
#define HASHSIZE 256

// Function declarations corresponding to symbolic table
Table 	newTable();
Entry	newINTEntry(Table tab, const char *name, int isInitial, struct astnode *exp);
Entry	newArrayEntry(Table tab, const char *name, int sizeInitial, List exp);
Entry	newFuncEntry(Table tab, const char *name);
Entry	lookup(Table tab, const char *name, int type);
Symbol 	getSym(Table ptab, const char *name);
arraySymbol getaSym(Table tab, const char *name);
funcSymbol getfSym(Table tab, const char *name);
int	*getVal(Table ptab, const char *name, int *size);
Symbol	lookupvar(Table tab, const char *name);
arraySymbol lookuparray(Table tab, const char *name);
funcSymbol lookupfunc(Table tab, const char *name);
Symbol 	setVal(Table ptab, const char *name, int val);
void 	destroyTable();

// Error/warning message
// You could add more kinds of error messages into errcfg.h 
enum {
#define errxx(a, b) a,
#include "errcfg.h"
	LASTERR
};

// An error/warning message
typedef struct errmsg {
	bool	isWarn;
	int 	type;
	char 	*msg;
	int	line;
	int	column;
	char	filename[50];
} *Errmsg;

// Error factory
typedef struct errfactory { 
	List	errors;
	List	warnings;
} *ErrFactory;

// Function declarations on error message management
Errmsg	newError	(ErrFactory errfactory, int type, int line, int col, char *filename);
Errmsg	newWarning	(ErrFactory errfactory, int type, int line, int col, char *filename);
void	dumpErrmsg	(Errmsg error);
ErrFactory newErrFactory();
void	dumpErrors	(ErrFactory errfactory);
void	dumpWarnings	(ErrFactory errfactory);
void	destroyErrFactory(ErrFactory *errfact);

// abstract syntax tree
// Structure for tracking locations, same as YYLTYPE in y.tab.h
typedef struct location {
	int first_line;
	int first_column;
	int last_line;
	int last_column;
} *Loc;

typedef struct {
	int 	op;
	//int type;
	int 	val;
	struct astnode	*kids[2];// kids of the AST node
} *Exp;

typedef struct {
	int op;
	int val;
	struct astnode *kids[2];
} *Cond;

typedef struct {
	struct astnode *exp;
} *ExpStmt;

typedef struct {
	List  decl;
        List stmts;
} *Block;

typedef struct {
        int type;
        union {
                struct astnode *asgnExp;
                struct astnode *funcall;
                struct astnode *ifstmt;
        	struct astnode *whilestmt;
	        Block block;
		struct astnode *empty;
        };
} *Stmt; 

	
typedef struct {
       struct astnode *block;
       struct astnode *name;
} *FuncDef;

typedef struct {
        struct astnode *cond;
        struct astnode *stmt[2];
        int havelse;
} *IFStmt;

typedef struct {
        struct astnode *cond;
        struct astnode *stmt;
} *WHILEStmt;

typedef struct {
	struct astnode *name; // information stored in name such as type and size
        List exp; // if it is an array, the fist element in exp is the length
} *ConstDef;      

typedef struct {
        struct astnode *name;
        List exp; // if it is an array, the first element in exp is the length
} *VarDef;

typedef struct {
        List def;
} *ConstDecl;

typedef struct {
        List def;
} *VarDecl;

typedef struct {
        struct astnode *left, *right;
} *asgnExp;        

typedef struct {
	Entry name;
	int type;	
	struct astnode *exp;
} *LVal;

typedef struct {
	List decl;
	List func;
} *CompUnit;

         
typedef struct astnode{
	enum {
		KValue = 0x200,		// numerial value:
		KName,			// name, such as variable name
		KConstDecl,
                KVarDecl,
		KFuncall,
		KCompUnit,
                KWhileStmt,
                KLVal,
                KIFStmt,
		KStmt,
                KFuncDef, 
		KPrefixExp,		// prefix expression
		KInfixExp,		// infix expression
		KAssignExp,		// assignment expression
		KParenExp,		// parentheses expression
		KExpStmt,		// expression statement
		KBlock,			// block
		KCondExp		// condition expression 
	} kind;	// kind of the AST node
	union {		// information of various kinds of AST node 
		int  val;		// KValue: numerial value
		Entry sym;		// KName/KLVal: symbols 
        ConstDecl constdecl;
        VarDecl vardecl;
		char *name;
		CompUnit unit;
        WHILEStmt whilestmt;
        IFStmt ifstmt;
		LVal lval;
		Stmt stmt;
        FuncDef func;                
		Exp   exp;		// KPrefixExp,
					// KInfixExp,
		asgnExp asgnexp;	// KAssignExp,
					// KParenExp
		ExpStmt  estmt;		// KExpStmt
		Block  block;		// KBlock
	};
	Loc 	loc;			// locations
} *ASTNode;

typedef struct ASTtree {
	ASTNode root;
} *ASTTree;

// functions for creating various kinds of ASTnodes
ASTNode newNumber(int value);
ASTNode newName(Table ptab, const char *name, ASTNode exp);
ASTNode newArray(Table ptab, const char *name, int sizeInitial, List exp);
ASTNode newFunc(Table ptab, const char *name);
ASTNode newPrefixExp(int op, ASTNode exp);
ASTNode newParenExp(ASTNode exp);
ASTNode newInfixExp(int op, ASTNode left, ASTNode right);
ASTNode newAssignment(int op, ASTNode left, ASTNode right);
ASTNode newIfStmt(ASTNode cond, ASTNode block, int havelse, ASTNode Else);
ASTNode newFuncall(const char *name);
ASTNode newStmt(ASTNode exp, int type);
ASTNode newWhileStmt(ASTNode cond, ASTNode block);
ASTNode newFuncDef(ASTNode name, ASTNode block);
VarDef newVarDef(ASTNode name, List Exp);
ASTNode newVarDecl(List var);
ASTNode newLVal(char *name, int type, ASTNode exp);
ConstDef newConstDef(ASTNode name, List exp);
ASTNode newConstDecl(List def);
ASTNode newCompUnit();
void	destroyExp(Exp *pexp);
ASTNode newExpStmt(ASTNode exp);
void	destroyExpStmt(ExpStmt *pexpstmt);
ASTNode newBlock();
void	destroyBlock(Block *pblock);
ASTTree newAST();
void	destroyAST(ASTNode *pnode);





void 	dumpAST(ASTNode node);
Loc	setLoc(ASTNode node, Loc loc);

#endif // !def(_COMMON_H_)
