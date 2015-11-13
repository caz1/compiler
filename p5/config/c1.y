%{
#include <stdio.h>
#include <math.h>
#include "common.h"
#include <unistd.h>
#include "util.h"
#include <mcheck.h>

extern int yylineno;
extern int yycolumn;
extern ASTTree ast;	
extern ErrFactory errfactory;
extern Table symtab;
extern List list;
extern bool haveError;
%}

%union {
	char *name;
	int  ival;
	ASTNode node;
	List list;
	ConstDef constdef;
	VarDef vardef; 
}
%locations
%debug
//%glr-parser
%parse-param {char *filename}
%parse-param {DumpDot *dot}

%token NUMBER ID
%token PLUS MINUS MULT DIV MOD EQ ISEQ GT LT LE NE GE UMINUS
%token EOL 
%token LPAR RPAR LBRACE RBRACE LBRACKET RBRACKET 
%token INT SEMICOLON COMMA CONST WHILE IF ELSE VOID
%token A F// declare precedence of the grammar rule



%left A
%left nonelse
%left ELSE
%right LPAR 
%left RPAR
%left  ISEQ GT LT LE NE GE
%nonassoc NUMBER ID
%left EQ 
%left  MINUS PLUS
%left  MULT DIV
%left  MOD 
%left F
%left UMINUS

%type  <ival> PLUS MINUS MULT DIV MOD EQ NUMBER ISEQ GT LT LE NE GE
%type  <name> ID
%type  <node> CompUnit ConstDecl VarDecl Exp LVal MultiBlockItem Decl BlockItem Cond IFCOND WHILECOND Block WHILEStmt IFStmt Stmt FuncDef
%type  <list> MultiConstDef MultiExp MultiVar 
%type  <constdef> ConstDef
%type  <vardef> Var
%%

golbal 
	: CompUnit
	  {
		if (!haveError)
		    ast->root = $1;
	  }

CompUnit
	: CompUnit Decl
	  {
		debug("CompUnit ::= CompUnit Decl\n");
		if (!haveError)
		{
		    addLast($1->unit->decl, $2);
		    $$ = $1;
	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| CompUnit FuncDef
	  {
		debug("CompUnit ::= CompUnit FuncDef\n");
		if (!haveError)
		{
		    addLast($1->unit->func, $2);
		    $$ = $1;
	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| Decl
	  {
		debug("CompUnit ::= Decl\n");
		if (!haveError)
		{
		    $$ = newCompUnit();
		    addLast($$->unit->decl, $1);
		    addFirst(list, $$);
	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| FuncDef
	  {
		debug("CompUnit ::= FuncDef\n");
		if (!haveError)
		{
		    $$ = newCompUnit();
		    addLast($$->unit->func, $1);
		    addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
       }
	  } 
Decl
	: ConstDecl
	  {
		debug("Decl ::= ConstDecl\n");
		if (!haveError)
		{
	    	$$ = $1;
        	setLoc($$, (Loc)&(@$));	    
	    }
	  }

	| VarDecl
	  {
		debug("Decl ::= VarDecl\n");
		if (!haveError)
		{
			$$ = $1;
	        setLoc($$, (Loc)&(@$));	
	    }
	  }

ConstDecl
	: CONST INT MultiConstDef SEMICOLON
	  {
		debug("ConstDecl ::= const int MultiConstDef ;\n");
		if (!haveError)
		{
		    $$ = newConstDecl($3);
	    	addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| CONST MultiConstDef SEMICOLON
	  {
		debug("ConstDecl ::= const MultiConstDef ;\n");
		if (!haveError)
		{
		    $$ = newConstDecl($2);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
		    newWarning(errfactory, MissingVarType, 
			    @2.first_line, @2.first_column, 
		    	filename);
        }
	  }
	

MultiConstDef
	: MultiConstDef COMMA ConstDef
	  {
		debug("MultiConstDecl ::= MultiConstDecl , ConstDef\n");
		if (!haveError)
		{
		    addLast($1, $3);
		    $$ = $1;		
	    }
	  }

	| ConstDef
	  {
		debug("MultiConstDecl ::= ConstDef\n");
		if (!haveError)
        {
		    $$ = newList();
		    addLast($$, $1);
        }
	  }


ConstDef 
	: ID EQ Exp
	  {
		debug("ConstDef ::= ID EQ Exp\n");
		if (!haveError)
		{
	    	$$ = newConstDef(newName(symtab, $1, $3));
  	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| ID LBRACKET Exp RBRACKET EQ LBRACE MultiExp RBRACE 
	  {
		debug("ConstDef ::= ID[exp] EQ {MultiExp}\n");
		if (!haveError)
		{		
		    addFirst($7, $3);
		    $$ = newConstDef(newArray(symtab, $1, 1, $7));
  	        setLoc($$, (Loc)&(@$));		    
        }
  	  }
	|ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE 
	  {
		debug("ConstDef ::= ID[] EQ {MultiExp}\n");
		if (!haveError)
        {
		    $$ = newConstDef(newArray(symtab, $1, 0, $6));
 	        setLoc($$, (Loc)&(@$));		    
        }
	  }

MultiExp
	: MultiExp COMMA Exp
	  {
		debug("MultiExp ::= MultiExp , Exp\n");
		if (!haveError)
		{
		    addLast($1, $3);
		    $$ = $1;
        }
	  }
	| Exp
	  {
		debug("MultiExp ::= Exp\n");
		if (!haveError)
		{
		    $$ = newList();
		    addLast($$, $1);
        }
	  }

VarDecl	
	: INT MultiVar SEMICOLON
	  {
		debug("VarDecl ::= int MultiVar ;\n");
		if (!haveError)
		{
    		$$ = newVarDecl($2);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
        }
	  }

MultiVar
	: MultiVar COMMA Var
	  {
		debug("MultiVar ::= MultiVar , Var\n");
		if (!haveError)
		{
    		addLast($1, $3);
    		$$ = $1;
       }
	  }
	| Var
	  {
		debug("MultiVar ::= Var\n");
		if (!haveError)		
		{
		    $$ = newList();
		    addLast($$, $1);
        }
	  }


Var
	: ID
	  {
		debug("Var ::= ID\n");
		if (!haveError)
		{
		    $$ = newVarDef(newName(symtab, $1, NULL));
 	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| ID LBRACKET Exp RBRACKET
	  {
		debug("Var ::= ID[Exp]\n");
		if (!haveError)
		{
		    List tmp = newList();
		    addLast(tmp, $3);
		    $$ = newVarDef(newArray(symtab, $1, 1, tmp));
 	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| ID EQ Exp//
	  {
		debug("Var ::= ID EQ Exp\n");
		if (!haveError)
		{
		    $$ = newVarDef(newName(symtab, $1, $3));
 	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| ID LBRACKET Exp RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Var ::= ID[exp] EQ { MultiExp }\n");
		if (!haveError)
		{
		    addFirst($7, $3); 
		    $$ = newVarDef(newArray(symtab, $1, 1, $7));
 	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Var ::= ID[] EQ { MultiExp }\n");
		if (!haveError)
		{
		    $$ = newVarDef(newArray(symtab, $1, 0, $6));  
 	        setLoc($$, (Loc)&(@$));		    
        }
	  }


FuncDef
	: VOID ID LPAR RPAR Block
	  {
		debug("FuncDef ::= void ID() Block\n");
		if (!haveError)
		{
		    $$ = newFuncDef(newFunc(symtab, $2), $5);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
        }
	  }
	| VOID ID LPAR Block
	  {
		debug("FuncDef  ::= void ID( Block\n");
		newError(errfactory, MissingRParen,
			@3.last_line, @3.last_column, 
			filename);
			
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }
	| VOID ID RPAR Block
	  {
		debug("FuncDef  ::= void ID) Block\n");
		newError(errfactory, MissingLParen,
			@2.last_line, @2.last_column, 
			filename);
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }

Block
	: LBRACE MultiBlockItem RBRACE
	  {
		debug("Block ::= { MultiBlockItem }\n");
		if (!haveError)
		{
		    $$ = $2;
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| LBRACE RBRACE
	  {
		debug("Block ::= {}\n");
		if (!haveError)
		{
		    $$ = newBlock();
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }

MultiBlockItem
	: MultiBlockItem BlockItem
	  {
		debug("MultiBlockItem ::= MultiBlockItem BlockItem\n");
		if (!haveError)
		{
		    if ($2->kind == KVarDecl || $2->kind == KConstDecl) addLast($1->block->decl, $2);
		    else addLast($1->block->stmts, $2);
		    $$ = $1;
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| BlockItem
	  {
		debug("MultiBlockItem ::= BlockItem\n");
		if (!haveError)
		{
		    $$ = newBlock();
		    if ($1->kind == KVarDecl || $1->kind == KConstDecl) addLast($$->block->decl, $1);
	    	else addLast($$->block->stmts, $1);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }	

BlockItem
	: Decl 
	  {
		debug("BlockItem ::= Decl \n");
		if (!haveError)
		{
    		$$ = $1;
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| Stmt
	  {
		debug("BlockItem ::= Stmt\n");
		if (!haveError)
		{
    		$$ = $1;
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }


Stmt
	: LVal EQ Exp SEMICOLON 
	  {
		debug("Stmt ::= LVal EQ Exp ;\n");
		if (!haveError)
		{
		    $$ = newStmt(newAssignment($1, $3), 0);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| ID LPAR RPAR SEMICOLON//
	  {
		debug("Stmt ::= ID() ;\n");
		if (!haveError)
		{
		    $$ = newStmt(newFuncall($1), 1);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| ID LPAR SEMICOLON
	  {
		debug ("Stmt ::= ID(\n");
		newError(errfactory, MissingRParen, 
			@3.first_line, @3.first_column,
			filename);	
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }  
	| ID RPAR SEMICOLON
	  {
		debug ("Stmt ::= ID)\n");
		newError(errfactory, MissingLParen, 
			@2.first_line, @2.first_column,
			filename);	
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }  
	| Block 
	  {
		debug("Stmt ::= Block\n");
		if (!haveError)
		{
		    $$ = newStmt($1, 2);		
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| IFStmt
	  {
		debug("Stmt ::= IFStmt\n");
		if (!haveError)
		{
		    $$ = newStmt($1, 3);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| WHILEStmt
	  {
		debug("Stmt ::= WHILEStmt\n");
		if (!haveError)
		{
		    $$ = newStmt($1, 4);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| SEMICOLON
	  {
		debug("Stmt ::= ;\n");
		if (!haveError)
		{
		    $$ = newStmt(NULL, 5);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }

WHILEStmt
	: WHILECOND Stmt 
	  {
		debug("Stmt ::= WHILECOND Stmt\n");
		if (!haveError)
		{		
		    $$ = newWhileStmt($1, $2);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }

WHILECOND
	: WHILE LPAR Cond RPAR
	  {
		debug("WHILECOND ::= while(Cond)\n");
		if (!haveError)
		{		
			$$ = $3;	
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| WHILE LPAR Cond 
	  {
		debug ("WHILECOND ::= while(cond\n");
		newError(errfactory, MissingRParen, 
			@3.last_line, @3.last_column, 
			filename);
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }
	| WHILE Cond RPAR
	  {
		debug ("WHILECOND ::= while Cond)\n");
		newError(errfactory, MissingLParen, 
			@1.last_line, @1.last_column,
			filename);
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }

IFStmt
	: 
	 IFCOND Stmt ELSE Stmt
	  {
		debug("IFStmt ::= IFCOND Stmt ELSE Stmt\n");
		if (!haveError)
		{
		    $$ = newIfStmt($1, $2, 1, $4);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| IFCOND Stmt %prec nonelse
	  {
		debug("IFStmt ::= IFCOND Stmt\n");	
		if (!haveError)
		{		
		    $$ = newIfStmt($1, $2, 0, NULL);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	

IFCOND
	: IF LPAR Cond RPAR
	  {
		debug("IFCOND ::= IF (Cond)\n");
		if (!haveError)
		{		
    		$$ = $3;
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| IF LPAR Cond
	  {
		debug("IFCOND ::= IF (Cond\n");
		newError(errfactory, MissingRParen, 
			@3.last_line, @3.last_column, 
			filename);	
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }
	| IF Cond RPAR
	  {
		debug("IFCOND ::= IF Cond)\n");
		newError(errfactory, MissingLParen, 
			@2.first_line, @2.first_column, 
			filename);	
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }

LVal
	: ID
	  {
	  	debug("LVal ::= ID\n");
		if (!haveError)
		{
		    if (lookupvar(symtab, $1))
		    	$$ = newLVal($1, 0, NULL);
		    else if (lookupfunc(symtab, $1))
			    $$ = newLVal($1, 2, NULL);
	    	else 
	    		newError(errfactory, UndefinedVar,
	    			@1.first_line, @1.first_column,
	    			filename);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| ID LBRACKET Exp RBRACKET
	  {
	  	debug("LVal ::= ID[Exp]\n");
		if (!haveError)
		{
		    if (lookuparray(symtab, $1))
		    	$$ = newLVal($1, 1, $3);
		    else 
			    newError(errfactory, UndefinedVar, 
			    @1.first_line, @1.first_column, 
			    filename);
            addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	  
Cond
	:  Exp LT Exp %prec UMINUS
	  {
		debug("Cond ::= exp < exp\n");
		if (!haveError)
        {		
		    $$ = newCondExp($2, $1, $3);
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| Exp ISEQ Exp %prec UMINUS
	  {
		debug("Cond ::= exp == exp\n");
		if (!haveError)
		{
		    $$ = newCondExp($2, $1, $3);
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| Exp LE Exp %prec UMINUS
	  {
		debug("Cond ::= exp <= exp\n");
		if (!haveError)
        {		
		    $$ = newCondExp($2, $1, $3);
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| Exp GT Exp %prec UMINUS
	  {
		debug("Cond ::= exp > exp\n");
		if (!haveError)
        {
		    $$ = newCondExp($2, $1, $3);
            //addFirst(list, $$);	 
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| Exp GE Exp %prec UMINUS
	  {
		debug("Cond ::= exp >= exp\n");
		if (!haveError)
		{	
		    $$ = newCondExp($2, $1, $3);
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }	
	| Exp NE Exp %prec UMINUS
	  {
		debug("Cond ::= exp != exp\n");
		if (!haveError)
		{		
		    $$ = newCondExp($2, $1, $3);
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }



Exp
	: Exp PLUS Exp  
	  {
		debug("exp ::= exp PLUS exp\n");
		if (!haveError)
		{
		    $$ = newInfixExp($2, $1, $3); 
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| Exp MINUS Exp 
	  {
		debug("exp ::= exp MINUS exp\n");
		if (!haveError)
		{
		    $$ = newInfixExp($2, $1, $3); 
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| Exp MULT Exp  
	  {
		debug("exp ::= exp MULT exp\n");
		if (!haveError)
		{
		    $$ = newInfixExp($2, $1, $3); 
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| Exp DIV Exp 
	  {
		debug("exp ::= exp DIV exp\n");
		if (!haveError)		
        {   
    		$$ = newInfixExp($2, $1, $3); 
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| Exp MOD Exp  
	  {
		debug("exp ::= exp MOD exp\n");
		if (!haveError)
		{		
		    $$ = newInfixExp($2, $1, $3); 
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	   }
	| Exp Exp %prec A 
	  {
		debug("exp ::= exp exp\n");
		newError(errfactory, MissingOp,
			@2.first_line, @2.first_column -1, 
			filename);	
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }
	 | PLUS Exp %prec PLUS
 	  {
	  	debug("exp ::= PLUS exp\n");
		if (!haveError)
		{	  	
	   	    $$ = newPrefixExp($1, $2); 	
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }

	| MINUS Exp %prec MINUS
 	  {
	  	debug("exp ::= MINUS exp\n");
		if (!haveError)
		{	  	
	  	    $$ = newPrefixExp($1, $2); 
            //addFirst(list, $$);
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| NUMBER 
	  {
		debug("exp ::= NUMBER\n");
		if (!haveError)
		{
		    $$ = newNumber($1);
            //addFirst(list, $$);  
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }	
	| LVal
	  {
		debug("exp ::= LVal\n");
		if (!haveError)
		{
		    $$ = $1;
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| LPAR Exp RPAR %prec UMINUS
	  {
		debug("exp ::= ( exp )\n");
		if (!haveError)
		{
    	    $$ = $2;
 	        setLoc($$, (Loc)&(@$));		    
	    }
	  }
	| LPAR Exp %prec LPAR
	  {
		debug("exp ::= ( exp \n");
		newError(errfactory, MissingRParen, 
			@2.last_line, @2.last_column + 1, 
			filename);		
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }
	| Exp RPAR %prec UMINUS
	  {
		debug("exp ::= exp )\n");
		newError(errfactory, MissingLParen, 
			@1.first_line, @1.first_column,
			 filename);
		if (list)
	        destroyList(&list, destroyAST);
	    haveError = true;
	  }
	
%%

void yyerror(char *filename, char *message)
{
	printf("\033[1;31;40m%s\033[0m in %s\n",message, filename);
}



