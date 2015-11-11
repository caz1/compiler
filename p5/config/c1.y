%{
#include <stdio.h>
#include <math.h>
#include "common.h"
#include <unistd.h>
#include "util.h"
ASTTree ast;	
ErrFactory errfactory;
Table symtab;
List list;
bool haveError;
extern int yylineno;
extern int yycolumn;
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
		ast->root = $1;
	  }

CompUnit
	: CompUnit Decl
	  {
		debug("CompUnit ::= CompUnit Decl\n");
		addLast($1->unit->decl, $2);
		$$ = $1;

	  }
	| CompUnit FuncDef
	  {
		debug("CompUnit ::= CompUnit FuncDef\n");
		addLast($1->unit->func, $2);
		$$ = $1;

	  }
	| Decl
	  {
		debug("CompUnit ::= Decl FuncDef\n");
		$$ = newCompUnit();
		addLast($$->unit->decl, $1);
		addFirst(list, $$);

	  }
	| FuncDef
	  {
		debug("CompUnit ::= FuncDef\n");
		$$ = newCompUnit();
		addLast($$->unit->func, $1);
		addFirst(list, $$);

	  } 
Decl
	: ConstDecl
	  {
		debug("Decl ::= ConstDecl\n");
		$$ = $1;

	  }

	| VarDecl
	  {
		debug("Decl ::= VarDecl\n");
		$$ = $1;

	  }

ConstDecl
	: CONST INT MultiConstDef SEMICOLON
	  {
		debug("ConstDecl ::= const int MultiConstDef ;\n");
		$$ = newConstDecl($3);
		addFirst(list, $$);

	  }
	| CONST MultiConstDef SEMICOLON
	  {
		debug("ConstDecl ::= const MultiConstDef ;\n");
		$$ = newConstDecl($2);
        addFirst(list, $$);
		newWarning(errfactory, MissingVarType, 
			@2.first_line, @2.first_column, 
			filename);

	  }
	

MultiConstDef
	: MultiConstDef COMMA ConstDef
	  {
		debug("MultiConstDecl ::= MultiConstDecl , ConstDef\n");
		addLast($1, $3);
		$$ = $1;		
	  }

	| ConstDef
	  {
		debug("MultiConstDecl ::= ConstDef\n");
		$$ = newList();
		addLast($$, $1);
        addFirst(list, $$);

	  }


ConstDef 
	: ID EQ Exp
	  {
		debug("ConstDef ::= ID EQ Exp\n");
		List new = newList();
		addLast(new, $3);
		$$ = newConstDef(newName(symtab, $1, $3), new);
        addFirst(list, $$);		

	  }
	| ID LBRACKET Exp RBRACKET EQ LBRACE MultiExp RBRACE 
	  {
		debug("ConstDef ::= ID[exp] EQ {MultiExp}\n");
		addFirst($7, $3);
		$$ = newConstDef(newArray(symtab, $1, 1, $7), $7);
        addFirst(list, $$);

  	  }
	|ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE 
	  {
		debug("ConstDef ::= ID[] EQ {MultiExp}\n");
		$$ = newConstDef(newArray(symtab, $1, 0, $6), $6);
        addFirst(list, $$);

	  }

MultiExp
	: MultiExp COMMA Exp
	  {
		debug("MultiExp ::= MultiExp , Exp\n");
		addLast($1, $3);
		$$ = $1;

	  }
	| Exp
	  {
		debug("MultiExp ::= Exp\n");
		$$ = newList();
		addLast($$, $1);

	  }

VarDecl	
	: INT MultiVar SEMICOLON
	  {
		debug("VarDecl ::= int MultiVar ;\n");
		$$ = newVarDecl($2);
        addFirst(list, $$);

	  }

MultiVar
	: MultiVar COMMA Var
	  {
		debug("MultiVar ::= MultiVar , Var\n");
		addLast($1, $3);
		$$ = $1;

	  }
	| Var
	  {
		debug("MultiVar ::= Var\n");
		$$ = newList();
		addLast($$, $1);
        addFirst(list, $$);

	  }


Var
	: ID
	  {
		debug("Var ::= ID\n");
		$$ = newVarDef(newName(symtab, $1, NULL), newList());
        addFirst(list, $$);

	  }
	| ID LBRACKET Exp RBRACKET
	  {
		debug("Var ::= ID[Exp]\n");
		List tmp = newList();
		addLast(tmp, $3);
		$$ = newVarDef(newArray(symtab, $1, 1, tmp), NULL);
        addFirst(list, $$);

	  }
	| ID EQ Exp//
	  {
		debug("Var ::= ID EQ Exp\n");
		List tmp = newList();
		addLast(tmp, $3);
		$$ = newVarDef(newName(symtab, $1, $3), tmp);
        addFirst(list, $$);

	  }
	| ID LBRACKET Exp RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Var ::= ID[exp] EQ { MultiExp }\n");
		addFirst($7, $3); 
		$$ = newVarDef(newArray(symtab, $1, 1, $7), $7);
        addFirst(list, $$);

	  }
	| ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Var ::= ID[] EQ { MultiExp }\n");
		$$ = newVarDef(newArray(symtab, $1, 0, $6), $6); // 
        addFirst(list, $$);

	  }


FuncDef
	: VOID ID LPAR RPAR Block
	  {
		debug("FuncDef ::= void ID() Block\n");
		$$ = newFuncDef(newFunc(symtab, $2), $5);
        addFirst(list, $$);

	  }
	| VOID ID LPAR Block
	  {
		debug("FuncDef  ::= void ID( Block\n");
		newError(errfactory, MissingRParen,
			@3.last_line, @3.last_column, 
			filename);
			
	    destroyList(list, destroyAST);
	    haveError = true;
	  }
	| VOID ID RPAR Block
	  {
		debug("FuncDef  ::= void ID) Block\n");
		newError(errfactory, MissingLParen,
			@2.last_line, @2.last_column, 
			filename);
	    destroyList(list, destroyAST);
	    haveError = true;
	  }

Block
	: LBRACE MultiBlockItem RBRACE
	  {
		debug("Block ::= { MultiBlockItem }\n");
		$$ = $2;
	  }
	| LBRACE RBRACE
	  {
		debug("Block ::= {}\n");
		$$ = newBlock();
        addFirst(list, $$);
	  }

MultiBlockItem
	: MultiBlockItem BlockItem
	  {
		debug("MultiBlockItem ::= MultiBlockItem BlockItem\n");
		if ($2->kind == KVarDecl || $2->kind == KConstDecl) addLast($1->block->decl, $1);
		else addLast($1->block->stmts, $2);
		$$ = $1;
	  }
	| BlockItem
	  {
		debug("MultiBlockItem ::= BlockItem\n");
		$$ = newBlock();
		if ($1->kind == KVarDecl || $1->kind == KConstDecl) addLast($$->block->decl, $1);
		else addLast($$->block->stmts, $1);
        addFirst(list, $$);
	  }	

BlockItem
	: Decl 
	  {
		debug("BlockItem ::= Decl \n");
		$$ = $1;
	  }
	| Stmt
	  {
		debug("BlockItem ::= Stmt\n");
		$$ = $1;
	  }


Stmt
	: LVal EQ Exp SEMICOLON 
	  {
		debug("Stmt ::= LVal EQ Exp ;\n");
		$$ = newStmt(newAssignment($1, $3), 0);
        addFirst(list, $$);
	  }
	| ID LPAR RPAR SEMICOLON//
	  {
		debug("Stmt ::= ID() ;\n");
		$$ = newStmt(newFuncall($1), 1);
        addFirst(list, $$);
	  }
	| ID LPAR SEMICOLON
	  {
		debug ("Stmt ::= ID(\n");
		newError(errfactory, MissingRParen, 
			@3.first_line, @3.first_column,
			filename);	
	    destroyList(list, destroyAST);
	    haveError = true;
	  }  
	| ID RPAR SEMICOLON
	  {
		debug ("Stmt ::= ID)\n");
		newError(errfactory, MissingLParen, 
			@2.first_line, @2.first_column,
			filename);	
	    destroyList(list, destroyAST);
	    haveError = true;
	  }  
	| Block 
	  {
		debug("Stmt ::= Block\n");
		$$ = newStmt($1, 2);		
        addFirst(list, $$);
	  }
	| IFStmt
	  {
		debug("Stmt ::= IFStmt\n");
		$$ = newStmt($1, 3);
        addFirst(list, $$);
	  }
	| WHILEStmt
	  {
		debug("Stmt ::= WHILEStmt\n");
		$$ = newStmt($1, 4);
        addFirst(list, $$);
	  }
	| SEMICOLON
	  {
		debug("Stmt ::= ;\n");
		$$ = newStmt(NULL, 5);
        addFirst(list, $$);
	  }

WHILEStmt
	: WHILECOND Stmt 
	  {
		debug("Stmt ::= WHILECOND Stmt\n");
		$$ = newWhileStmt($1, $2);
        addFirst(list, $$);
	  }

WHILECOND
	: WHILE LPAR Cond RPAR
	  {
		debug("WHILECOND ::= while(Cond)\n");
		$$ = $3;	
	  }
	| WHILE LPAR Cond 
	  {
		debug ("WHILECOND ::= while(cond\n");
		newError(errfactory, MissingRParen, 
			@3.last_line, @3.last_column, 
			filename);
	    destroyList(list, destroyAST);
	    haveError = true;
	  }
	| WHILE Cond RPAR
	  {
		debug ("WHILECOND ::= while Cond)\n");
		newError(errfactory, MissingLParen, 
			@1.last_line, @1.last_column,
			filename);
	    destroyList(list, destroyAST);
	    haveError = true;
	  }

IFStmt
	: 
	 IFCOND Stmt ELSE Stmt
	  {
		debug("IFStmt ::= IFCOND Stmt ELSE Stmt\n");
		$$ = newIfStmt($1, $2, 1, $4);
        addFirst(list, $$);
	  }
	| IFCOND Stmt %prec nonelse
	  {
		debug("IFStmt ::= IFCOND Cond Stmt\n");	
		$$ = newIfStmt($1, $2, 0, NULL);
        addFirst(list, $$);
	  }
	

IFCOND
	: IF LPAR Cond RPAR
	  {
		debug("IFCOND ::= IF (Cond)\n");
		$$ = $3;
	  }
	| IF LPAR Cond
	  {
		debug("IFCOND ::= IF (Cond\n");
		newError(errfactory, MissingRParen, 
			@3.last_line, @3.last_column, 
			filename);	
	    destroyList(list, destroyAST);
	    haveError = true;
	  }
	| IF Cond RPAR
	  {
		debug("IFCOND ::= IF Cond)\n");
		newError(errfactory, MissingLParen, 
			@2.first_line, @2.first_column, 
			filename);	
	    destroyList(list, destroyAST);
	    haveError = true;
	  }

LVal
	: ID
	  {
	  	debug("LVal ::= ID\n");
		if (lookupvar(symtab, $1))
			$$ = newLVal($1, 0, NULL);
		else if (lookupfunc(symtab, $1))
			$$ = newLVal($1, 2, NULL);
		else 
			newError(errfactory, UndefinedVar,
				@1.first_line, @1.first_column,
				filename);
        addFirst(list, $$);
	  }
	| ID LBRACKET Exp RBRACKET
	  {
	  	debug("LVal ::= ID[Exp]\n");
		if (lookuparray(symtab, $1))
			$$ = newLVal($1, 1, $3);
		else 
			newError(errfactory, UndefinedVar, 
			@1.first_line, @1.first_column, 
			filename);
        addFirst(list, $$);
	  }
Cond
	:  Exp LT Exp %prec UMINUS
	  {
		debug("Cond ::= exp < exp\n");
		$$ = newCondExp($2, $1, $3);
        addFirst(list, $$);
	  }
	| Exp ISEQ Exp %prec UMINUS
	  {
		debug("Cond ::= exp == exp\n");
		$$ = newCondExp($2, $1, $3);
        addFirst(list, $$);
	  }
	| Exp LE Exp %prec UMINUS
	  {
		debug("Cond ::= exp <= exp\n");
		$$ = newCondExp($2, $1, $3);
        addFirst(list, $$);
	  }
	| Exp GT Exp %prec UMINUS
	  {
		debug("Cond ::= exp > exp\n");
		$$ = newCondExp($2, $1, $3);
        addFirst(list, $$);	 
	  }
	| Exp GE Exp %prec UMINUS
	  {
		debug("Cond ::= exp >= exp\n");
		$$ = newCondExp($2, $1, $3);
        addFirst(list, $$);
	  }	
	| Exp NE Exp %prec UMINUS
	  {
		debug("Cond ::= exp != exp\n");
		$$ = newCondExp($2, $1, $3);
        addFirst(list, $$);
	  }



Exp
	: Exp PLUS Exp  
	  {
		debug("exp ::= exp PLUS exp\n");
		$$ = newInfixExp($2, $1, $3); 
        addFirst(list, $$);
	  }
	| Exp MINUS Exp 
	  {
		debug("exp ::= exp MINUS exp\n");
		$$ = newInfixExp($2, $1, $3); 
        addFirst(list, $$);
	  }
	| Exp MULT Exp  
	  {
		debug("exp ::= exp MULT exp\n");
		$$ = newInfixExp($2, $1, $3); 
        addFirst(list, $$);
	  }
	| Exp DIV Exp 
	  {
		debug("exp ::= exp DIV exp\n");
		$$ = newInfixExp($2, $1, $3); 
        addFirst(list, $$);
	  }
	| Exp MOD Exp  
	  {
		debug("exp ::= exp MOD exp\n");
		$$ = newInfixExp($2, $1, $3); 
        addFirst(list, $$);
	   }
	| Exp Exp %prec A 
	  {
		debug("exp ::= exp exp\n");
		newError(errfactory, MissingOp,
			@2.first_line, @2.first_column -1, 
			filename);	
	    destroyList(list, destroyAST);
	    haveError = true;
	  }
	 | PLUS Exp %prec PLUS
 	  {
	  	debug("exp ::= PLUS exp\n");
	   	$$ = newPrefixExp($1, $2); 	
        addFirst(list, $$);
	  }

	| MINUS Exp %prec MINUS
 	  {
	  	debug("exp ::= MINUS exp\n");
	  	$$ = newPrefixExp($1, $2); 
        addFirst(list, $$);
	  }
	| NUMBER 
	  {
		debug("exp ::= NUMBER\n");
		$$ = newNumber($1);
        addFirst(list, $$);
	  }	
	| LVal
	  {
		debug("exp ::= LVal\n");
		$$ = $1;
        addFirst(list, $$);
	  }
	| LPAR Exp RPAR %prec UMINUS
	  {
		debug("exp ::= ( exp )\n");
    	$$ = newParenExp($2);
        addFirst(list, $$);
	  }
	| LPAR Exp %prec LPAR
	  {
		debug("exp ::= ( exp \n");
		newError(errfactory, MissingRParen, 
			@2.last_line, @2.last_column + 1, 
			filename);		
	    destroyList(list, destroyAST);			
	    haveError = true;
	  }
	| Exp RPAR %prec UMINUS
	  {
		debug("exp ::= exp )\n");
		newError(errfactory, MissingLParen, 
			@1.first_line, @1.first_column,
			 filename);
	    destroyList(list, destroyAST);
	    haveError = true;
	  }
	
%%

void yyerror(char *filename, char *message)
{
	printf("\033[1;31;40m%s\033[0m in %s\n",message, filename);
}

void usage() // this prepare for p5
{
	printf("Usage: ./c1 <filelist> [-hv]\n\
		\t-h: Optional help flag that prints usage info\n\
		<filelist>: Name of files need to be analysed.\n\
		\t-v: Optional verbose flag that display the analyse info.\n");		
}	


int main(int argc, char *argv[])
{
	extern FILE *yyin;
	int i = 1;
	int temp;
	haveError = false;
    list = newList();
	symtab = newTable();
	NEW0(ast);
	/* // this prepare for p5
	extern char *optarg;	
	while (-1 != (opt = getopt(argc, argv, ":hv")))
	{
		switch(opt)
		{
			case 'h': usage(); break;
			case 'v': break;
			default: filename = optarg; break;
		}
	}
	*/	
	FILE *fp = fopen("new.dot", "w");
	DumpDot *dot = newDumpDot(fp, 1);

	errfactory = newErrFactory();
	printf("Parsing ...\n");
	while (i < argc)
	{	
		yyin = fopen(argv[i], "r");
		printf("Parsing file \"\033[1;31;40m%s\033[0m\"\n", argv[i]);
		temp = yyparse(argv[i], dot);
		
		if(temp == 1)
		{
			yylineno = 0;
			printf("parsing failed\n");		
		}		
		else if (temp == 2)
		{
			printf("using up memory\n");
			fclose(yyin);	
			exit(-1);	
		}
		else 
		{
			yylineno = 1;
			printf("parsing file \"\033[1;31;40m%s\033[0m\" succcessful\n", argv[i]);				
		}
		yycolumn = 1;
		fclose(yyin);
		i++;
	}
	if (errfactory->errors->size == 0)    
	    dumpAST(dot, ast);
	dumpErrors(errfactory);
	dumpWarnings(errfactory);
	fprintf(dot->fp, "}\n");
	fclose(fp);	
	//dumpDot(dot);
	return(0);
}
