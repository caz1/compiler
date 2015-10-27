%{
#include <stdio.h>
#include <math.h>
//#define debug(a) printf("%s", a)
#include <common.h>
//Table symtab;
ASTTree ast;	
int num;
char *ident;
ErrFactory errfactory;
extern int left_paren;
extern char line[100];
%}

%union {
	char *name;
	int  ival;
	Loc location;
}
%locations
%debug

%token NUMBER ID
%token PLUS MINUS MULT DIV MOD EQ ISEQ GT LT LE NE GE ODD
%token EOL 
%token LPAR RPAR LBRACE RBRACE LBRACKET RBRACKET 
%token INT SEMICOLON COMMA CONST WHILE IF ELSE VOID



%left  MINUS PLUS
%left  MULT DIV
%left  MOD

%type  <ival> PLUS MINUS MULT DIV MOD EQ NUMBER
%type  <name> ID
%type  <location> CompUnit Decl ConstDecl MultiConstDef ConstDef MultiExp Exp VarDecl MultiVar Var 
%type  <location> FuncDef Block MultiBlockItem BlockItem Stmt IFStmt Matched UnMatched LVal Cond


%%

CompUnit
	: CompUnit Decl FuncDef
	  {
		debug("CompUnit ::= CompUnit Decl FuncDef\n");
	  }

	| Decl FuncDef
	  {
		debug("CompUnit ::= Decl FuncDef\n");
	  }
	| FuncDef
	  {
		debug("CompUnit ::= FuncDef\n");
	  } 
Decl
	: ConstDecl
	  {
		debug("Decl ::= ConstDecl\n");
	  }

	| VarDecl
	  {
		debug("Decl ::= VarDecl\n");
	  }

ConstDecl
	: CONST INT MultiConstDef SEMICOLON
	  {
		debug("ConstDecl ::= const int MultiConstDef ;\n");
	  }
	| CONST MultiConstDef SEMICOLON
	  {
		newWarning(errfactory, MissingVarType, 
			@1.last_line, @1.last_column, line);
	  }
	

MultiConstDef
	: MultiConstDef COMMA ConstDef
	  {
		debug("MultiConstDecl ::= MultiConstDecl , ConstDef\n");

	  }

	| ConstDef
	  {
		debug("MultiConstDecl ::= ConstDef\n");
	  }


ConstDef 
	: ID EQ Exp
	  {
		debug("ConstDef ::= ID EQ Exp\n");
	  }
	| ID LBRACKET Exp RBRACKET EQ LBRACE MultiExp RBRACE 
	  {
		debug("ConstDef ::= ID[Exp] EQ {MultiExp}\n");
	  }
	| ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE 
	  {
		debug("ConstDef ::= ID[] EQ {MultiExp}\n");
	  }



MultiExp
	: MultiExp COMMA Exp
	  {
		debug("MultiExp ::= MultiExp , Exp\n");
	  }
	| Exp
	  {
		debug("MultiExp ::= Exp\n");
	  }

VarDecl	
	: INT MultiVar SEMICOLON
	  {
		debug("VarDecl ::= int MultiVar ;\n");
	  }



MultiVar
	: MultiVar COMMA Var
	  {
		debug("MultiVar ::= MultiVar , Var\n");
	  }
	| Var
	  {
		debug("MultiVar ::= Var\n");
	  }

Var
	: ID
	  {
		debug("Var ::= ID\n");
	  }
	| ID LBRACKET Exp RBRACKET
	  {
		debug("Var ::= ID[Exp]\n");
	  }
	| ID LBRACKET RBRACKET
	  {
		debug("Var ::= ID[]\n");
	  }
	| ID EQ Exp
	  {
		debug("Stmt ::= LVal EQ Exp\n");
	  }
	| ID LBRACKET Exp RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Stmt ::= LVal[exp] EQ { MultiExp }\n");
	  }
	| ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Stmt ::= LVal[] EQ { MultiExp }\n");
	  }


FuncDef
	: VOID ID LPAR RPAR Block
	  {
		debug("FuncDef ::= void ID() Block\n");
	  }
	| VOID ID LPAR Block
	  {
		newError(errfactory, MissingRParen,
			@2.last_line, @2.last_column, line);
	  }
	| VOID error Block
	  {
		
	  }

Block
	: LBRACE MultiBlockItem RBRACE
	  {
		debug("Block ::= { MultiBlockItem }\n");
	  }


MultiBlockItem
	: MultiBlockItem BlockItem
	  {
		debug("BlockItem ::= MultiBlockItem BlockItem\n");
	  }
	| BlockItem
	  {
		debug("Block ::= BlockItem\n");
	  }	

BlockItem
	: Decl 
	  {
		debug("BlockItem ::= Decl \n");
	  }
	| Stmt
	  {
		debug("BlockItem ::= Stmt\n");
	  }


Stmt
	: LVal EQ Exp SEMICOLON 
	  {
		debug("Stmt ::= LVal EQ Exp ;\n");
	  }
	| ID LPAR RPAR SEMICOLON
	  {
		debug("Stmt ::= ID() ;\n");
	  }
	| ID error SEMICOLON
	  {
		debug ("ID()\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			@2.last_line, @2.last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			@2.first_line, @2.first_column, line);
			left_paren++;		
		}
		yyerrok;  
	}
	  
	| Block 
	  {
		debug("Stmt ::= Block\n");
	  }
	| IFStmt
	  {
		debug("Stmt ::= IFStmt\n");
	  }
	| WHILEStmt
	  {
		debug("Stmt ::= WHILEStmt\n");
	  }
	| SEMICOLON
	  {
		debug("Stmt ::= ;\n");
	  }

WHILEStmt
	: WHILE LPAR Cond RPAR Stmt
	  {
		debug("Stmt ::= while(Cond) Stmt ;\n");
	  }
	| WHILE error Stmt
	  {
		debug ("while\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			@1.last_line, @1.last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			@1.last_line, @1.last_column, line);
			left_paren++;		
		}
		yyerrok;
	  }

IFStmt
	: UnMatched
	  {
		debug("IFStmt ::= UnMatched\n");
	  }
	| Matched
	  {
		debug("IFStmt ::= Matched\n");
	  }
	| IF error Stmt
	  {
		debug("error\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			@2.last_line, @2.last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			@2.last_line, @2.last_column, line);
			left_paren++;		
		}
		yyerrok;
	  }

Matched
	: IF LPAR Cond RPAR Stmt ELSE Stmt
	  {
		debug("Matched ::= IF Cond Stmt ELSE Stmt\n");
	  }

UnMatched
	: IF LPAR Cond RPAR Stmt
	  {
		debug("UnMatched ::= IF Cond Stmt\n");	
	  }


LVal
	: ID
	  {
	  	debug("LVal ::= ID\n");
	  }
	| ID LBRACKET Exp RBRACKET
	  {
	  	debug("LVal ::= ID[Exp]\n");
	  }

Cond
	: ODD Exp
	  {
		debug("Cond ::= ! exp\n");
		//$$ = newCondExp($1, $2, NULL);
		//setLoc($$, (Loc)&(@$));	  	
	  } 
	| Exp LT Exp
	  {
		debug("Cond ::= exp < exp\n");
	  }
	| Exp ISEQ Exp
	  {
		debug("Cond ::= exp == exp\n");
	  }
	| Exp LE Exp
	  {
		debug("Cond ::= exp <= exp\n");
	  }
	| Exp GT Exp
	  {
		debug("Cond ::= exp > exp\n");
	  }
	| Exp GE Exp
	  {
		debug("Cond ::= exp >= exp\n");
	  }	
	| Exp NE Exp
	  {
		debug("Cond ::= exp != exp\n");
	  }



Exp
	: Exp PLUS Exp
	  {
		debug("exp ::= exp PLUS exp\n");
	  }
	| Exp MINUS Exp
	  {
		debug("exp ::= exp MINUS exp\n");
	  }
	| Exp MULT Exp 
	  {
		debug("exp ::= exp MULT exp\n");
	  }
	| Exp DIV Exp 
	  {
		debug("exp ::= exp DIV exp\n");
	  }
	| Exp MOD Exp
	  {
		debug("exp ::= exp MOD exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	    //setLoc($$, (Loc)&(@$));
	  }
	| MINUS Exp %prec MINUS
	  {
	  	debug("exp ::= MINUS exp\n");
	    //$$ = newPrefixExp($1, $2); 
	   // setLoc($$, (Loc)&(@$));
	  }
	| PLUS Exp %prec PLUS
	  {
		debug("exp ::= PLUS exp\n");
	    //$$ = newPrefixExp($1, $2); 
	    //setLoc($$, (Loc)&(@$));
	  }
	| LPAR Exp RPAR
	  {
		debug("exp ::= LPAR exp RPAR\n");
	    //$$ = newParenExp($2);
	   // setLoc($$, (Loc)&(@$));
	  }
	| LVal
	  {
		debug("Exp ::= LVal\n");
	  }

	| NUMBER
	  {
		debug("Exp ::= NUMBER\n");
	  }
	| LPAR error 
	  {
		debug("(err\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			@2.last_line, @2.last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			@2.last_line, @2.last_column, line);
			left_paren++;		
		}
		yyerrok;
	  }
	| error RPAR
	  {
		debug("err)\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			@1.last_line, @1.last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			@1.first_line, @1.first_column, line);
			left_paren++;		
		}
		yyerrok;
	  }
%%

void yyerror(char *message)
{
	printf("%s\n",message);
}




int main(int argc, char *argv[])
{

	//symtab = newTable();
	//ast = newAST();
	printf("Parsing ...\n");
	errfactory = newErrFactory();
	yyparse();
	dumpErrors(errfactory);
	dumpWarnings(errfactory);	
	//destroyTable(&symtab);
	//printf("\n\nFinished destroying symbolic table.\n");
	return(0);
}



