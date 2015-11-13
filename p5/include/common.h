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
Table 	    newTable();
Entry	    newINTEntry(Table tab, const char *name, int isInitial, struct astnode *exp);
Entry	    newArrayEntry(Table tab, const char *name, int sizeInitial, List exp);
Entry	    newFuncEntry(Table tab, const char *name);
Entry	    lookup(Table tab, const char *name, int type);
Symbol 	    getSym(Table ptab, const char *name);
arraySymbol getaSym(Table tab, const char *name);
funcSymbol  getfSym(Table tab, const char *name);
int	        *getVal(Table ptab, const char *name, int *size);
Symbol	    lookupvar(Table tab, const char *name);
arraySymbol lookuparray(Table tab, const char *name);
funcSymbol  lookupfunc(Table tab, const char *name);
Symbol 	    setVal(Table ptab, const char *name, int val);
void 	    destroyTable();

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
        Loc loc;
} *ConstDef;      

typedef struct {
        struct astnode *name;
        Loc loc;
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
		KBlock,			// block
		KCondExp		// condition expression 
	} kind;	// kind of the AST node
	union {		// information of various kinds of AST node 
		int  val;		// KValue: numerial value
		Entry sym;		// KName: symbols 
        ConstDecl constdecl; // KConstDecl
        VarDecl vardecl;     // KVarDecl
		char *name;          // KFuncall  
		CompUnit unit;       // KCompUnit
        WHILEStmt whilestmt; // KWhileStmt
        IFStmt ifstmt;       // KIFStmt
		LVal lval;           // KLVal
		Stmt stmt;           // KStmt
        FuncDef func;        // KFuncDef        
		Exp   exp;		// KPrefixExp,
					    // KInfixExp,
					    // Kcond
					    // KParenExp
		asgnExp asgnexp;	// KAssignExp
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

ASTNode newInfixExp(int op, ASTNode left, ASTNode right);
ASTNode newAssignment(ASTNode left, ASTNode right);
ASTNode newIfStmt(ASTNode cond, ASTNode block, int havelse, ASTNode Else);
ASTNode newFuncall(const char *name);
ASTNode newStmt(ASTNode exp, int type);
ASTNode newWhileStmt(ASTNode cond, ASTNode block);
ASTNode newFuncDef(ASTNode name, ASTNode block);
VarDef  newVarDef(ASTNode name);
ASTNode newVarDecl(List var);
ASTNode newLVal(char *name, int type, ASTNode exp);
ConstDef newConstDef(ASTNode name);
ASTNode newConstDecl(List def);
ASTNode newCompUnit();
void	destroyExp(Exp *pexp);
ASTNode newBlock();
void	destroyBlock(ASTNode *node);
ASTTree newAST();
void	destroyAST(ASTNode *pnode);
void    destroyNum(ASTNode *node);
void    destroyName(ASTNode *node);
void    destroyArray(ASTNode *node);
void    destroyFunc(ASTNode *node);
void    destroyPrefixExp(ASTNode *node);

void    destroyInfixExp(ASTNode *node);
void    destroyCond(ASTNode *node);
void    destroyCompUnit(ASTNode *node);
void    destroyConstDecl(ASTNode *decl);
void    destroyConstDef(ConstDef *def);
void    destroyVarDecl(ASTNode *node);
void    destroyLVal(ASTNode *node);
void    destroyVarDef(VarDef *node);
void    destroyFuncDef(ASTNode *node);
void    destroyWhileStmt(ASTNode *node);
void    destroyStmt(ASTNode *node);
void    destroyIFStmt(ASTNode *node);
void    destroyFuncall(ASTNode *node);


int     dumpNum(DumpDot *dot, ASTNode node);
int     dumpVar(DumpDot *dot, ASTNode node);
int     dumpStmt(DumpDot *dot, ASTNode node);
int     dumpWhile(DumpDot *dot, ASTNode node);
int     dumpIF(DumpDot *dot, ASTNode node);
int     dumpAsgnExp(DumpDot *dot, ASTNode node);
int     dumpLVal(DumpDot *dot, ASTNode node);
int     dumpBlock(DumpDot *dot, ASTNode node);
int     dumpName(DumpDot *dot, Entry name);
int     dumpExp(DumpDot *dot, ASTNode node);
int     dumpArray(DumpDot *dot, ASTNode node);
int     dumpFunc(DumpDot *dot, ASTNode node);
int     dumpVarDef(DumpDot *dot, VarDef def);
int     dumpConstDef(DumpDot *dot, ConstDef def);
int     dumpConstDecl(DumpDot *dot, ASTNode node);
int     dumpVarDecl(DumpDot *dot, ASTNode node);
int     dumpDecl(DumpDot *dot, ASTNode node);
int     dumpUnit(DumpDot *dot, ASTNode node);
int     dumpCond(DumpDot *dot, ASTNode node);
int     dumpFuncall(DumpDot *dot, ASTNode node);



void    dumpAST(DumpDot *dot, ASTTree ast);
Loc	setLoc(ASTNode node, Loc loc);

#endif // !def(_COMMON_H_)
