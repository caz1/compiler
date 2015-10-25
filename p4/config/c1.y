%{
#include <stdio.h>
#include <math.h>
//#define debug(a) printf("%s", a)
#include <common.h>
//Table symtab;
ASTTree ast;	
int num;
char *ident;
char *line;
ErrFactory errfactory;
%}

%union {
	char *name;
	int  ival;
	Loc location;
}
%locations


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
		line = "const ";
		strcat(line, );
		strcat(line, ";");
		newError(errfactory, MissingVarType, 
			@1.last_line, @1.last_column);
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
		debug("VarDecl ::= int Var ;\n");
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
	| VOID ID RPAR Block
	  {
		newError(errfactory, MissingLParen,
			@2.last_line, @2.last_column);
	  }
	| VOID ID LPAR Block
	  {
		newError(errfactory, MissingRParen,
			@2.last_line, @2.last_column);
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
	| ID LPAR SEMICOLON
	  {
		newError(errfactory, MissingRParen,
			@2.last_line, @2.last_column);
	  }
	| ID RPAR SEMICOLON
	  {
		newError(errfactory, MissingLParen,
			@1.last_line, @1.last_column);
	  }
	| Block 
	  {
		debug("Stmt ::= Block\n");
	  }
	| IFStmt
	  {
		debug("Stmt ::= IFStmt\n");
	  }
	| WHILE LPAR Cond RPAR Stmt
	  {
		debug("Stmt ::= while(Cond) Stmt ;\n");
	  }
	| SEMICOLON
	  {
		debug("Stmt ::= ;\n");
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

Matched
	: IF LPAR Cond RPAR Stmt ELSE Stmt
	  {
		debug("Matched ::= IF Cond Stmt ELSE Stmt\n");
	  }
	| IF Cond RPAR Stmt ELSE Stmt
	  {
		newError(errfactory, MissingLParen,
			@1.last_line, @1.last_column);
	  }
	| IF LPAR Cond Stmt ELSE Stmt
	  {
		newError(errfactory, MissingLParen,
			@3.last_line, @3.last_column);
	  }

UnMatched
	: IF LPAR Cond RPAR Stmt
	  {
		debug("UnMatched ::= IF Cond Stmt\n");	
	  }
	| IF Cond RPAR Stmt
	  {
		newError(errfactory, MissingLParen,
			@1.last_line, @1.last_column);
	  }
	| IF LPAR Cond Stmt
	  {
		newError(errfactory, MissingLParen,
			@3.last_line, @3.last_column);
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
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
	| Exp ISEQ Exp
	  {
		debug("Cond ::= exp == exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
	| Exp LE Exp
	  {
		debug("Cond ::= exp <= exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
	| Exp GT Exp
	  {
		debug("Cond ::= exp > exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
	| Exp GE Exp
	  {
		debug("Cond ::= exp >= exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }	
	| Exp NE Exp
	  {
		debug("Cond ::= exp != exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }


Exp
	: Exp PLUS Exp
	  {
		debug("exp ::= exp PLUS exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	   // setLoc($$, (Loc)&(@$));
	  }
	| Exp MINUS Exp
	  {
		debug("exp ::= exp MINUS exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	   //setLoc($$, (Loc)&(@$));
	  }
	| Exp MULT Exp 
	  {
		debug("exp ::= exp MULT exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	   // setLoc($$, (Loc)&(@$));
	  }
	| Exp DIV Exp 
	  {
		debug("exp ::= exp DIV exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	  //  setLoc($$, (Loc)&(@$));
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
	| LPAR Exp
	  {
		newError(errfactory, MissingRParen, 
			@1.last_line, @1.last_column);
	  }
	| Exp RPAR
	  {
		newError(errfactory, MissingLParen, 
			@1.last_line, @1.last_column);
	  }
	| LVal
	  {
		debug("Exp ::= LVal\n");
	  }

	| NUMBER
	  {
		debug("Exp ::= NUMBER\n");
	  }


%%

yyerror(char *message)
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
	//destroyTable(&symtab);
	//printf("\n\nFinished destroying symbolic table.\n");
	return(0);
}



