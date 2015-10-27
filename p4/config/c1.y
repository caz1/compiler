%{
#include <stdio.h>
#include <math.h>
#include <common.h>
#include <unistd.h>
//ASTTree ast;	
int num;
char *ident;
ErrFactory errfactory;
extern long int pos;
extern int yylineno;
%}

%union {
	char *name;
	int  ival;
}
%locations
%debug
%glr-parser 
%parse-param {char *filename}
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
			@2.first_line, @2.first_column, 
			filename);
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
		debug("FuncDef  ::= void ID( Block\n");
		newError(errfactory, MissingRParen,
			@3.last_line, @3.last_column, 
			filename);
	  }
	| VOID ID RPAR Block
	  {
		debug("FuncDef  ::= void ID) Block\n");
		newError(errfactory, MissingLParen,
			@2.last_line, @2.last_column, 
			filename);
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
		debug ("Stmt ::= ID(\n");
		newError(errfactory, MissingRParen, 
			@3.first_line, @3.first_column,
			filename);	
	  }  
	| ID RPAR SEMICOLON
	  {
		debug ("Stmt ::= ID)\n");
		newError(errfactory, MissingLParen, 
			@2.first_line, @2.first_column,
			filename);	
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
	: WHILECOND Stmt 
	  {
		debug("Stmt ::= WHILECOND Stmt\n");
	  }

WHILECOND
	: WHILE LPAR Cond RPAR %dprec 3
	  {
		debug("WHILECOND ::= while(Cond)\n");	
	  }
	| WHILE LPAR Cond %dprec 2
	  {
		debug ("WHILECOND ::= while(cond\n");
		newError(errfactory, MissingRParen, 
			@3.last_line, @3.last_column, 
			filename);
	  }
	| WHILE Cond RPAR %dprec 2
	  {
		debug ("WHILECOND ::= while Cond)\n");
		newError(errfactory, MissingLParen, 
			@1.last_line, @1.last_column,
			filename);
	  }

IFStmt
	: UnMatched %dprec 2
	  {
		debug("IFStmt ::= UnMatched\n");
	  }
	| Matched %dprec 3
	  {
		debug("IFStmt ::= Matched\n");
	  }

Matched
	: IFCOND Stmt ELSE Stmt %dprec 2
	  {
		debug("Matched ::= IFCOND Stmt ELSE Stmt\n");
	  }


UnMatched
	: IFCOND Stmt %dprec 2
	  {
		debug("UnMatched ::= IFCOND Cond Stmt\n");	
	  }
	

IFCOND
	: IF LPAR Cond RPAR %dprec 2
	  {
		debug("IFCOND ::= IF (Cond)\n");
	  }
	| IF LPAR Cond %dprec 1
	  {
		debug("IFCOND ::= IF (Cond\n");
		newError(errfactory, MissingRParen, 
			@3.last_line, @3.last_column, 
			filename);	
	  }
	| IF Cond RPAR %dprec 1
	  {
		debug("IFCOND ::= IF Cond)\n");
		newError(errfactory, MissingLParen, 
			@2.first_line, @2.first_column, 
			filename);	
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
	: ODD Exp %dprec 2
	  {
		debug("Cond ::= ! exp \n"); 	
	  } 
	| Exp LT Exp %dprec 2
	  {
		debug("Cond ::= exp < exp\n");
	  }
	| Exp ISEQ Exp %dprec 2
	  {
		debug("Cond ::= exp == exp\n");
	  }
	| Exp LE Exp %dprec 2
	  {
		debug("Cond ::= exp <= exp\n");
	  }
	| Exp GT Exp %dprec 2
	  {
		debug("Cond ::= exp > exp\n");
	  }
	| Exp GE Exp %dprec 2
	  {
		debug("Cond ::= exp >= exp\n");
	  }	
	| Exp NE Exp %dprec 2
	  {
		debug("Cond ::= exp != exp\n");
	  }



Exp
	: Exp PLUS Exp %dprec 4
	  {
		debug("exp ::= exp PLUS exp\n");
	  }
	| Exp MINUS Exp %dprec 4
	  {
		debug("exp ::= exp MINUS exp\n");
	  }
	| Exp MULT Exp %dprec 4
	  {
		debug("exp ::= exp MULT exp\n");
	  }
	| Exp DIV Exp %dprec 4
	  {
		debug("exp ::= exp DIV exp\n");
	  }
	| Exp MOD Exp %dprec 4
	  {
		debug("exp ::= exp MOD exp\n");
	   }
	| MINUS Exp %prec MINUS %dprec 4
	  {
	  	debug("exp ::= MINUS exp\n");
	  }
	| PLUS Exp %prec PLUS %dprec 4
	  {
		debug("exp ::= PLUS exp\n");
	  }
	| LPAR Exp RPAR %dprec 11
	  {
		debug("exp ::= ( exp )\n");
	  }
	| LVal 
	  {
		debug("exp ::= LVal\n");
	  }

	| NUMBER
	  {
		debug("exp ::= NUMBER\n");
	  }
	| LPAR Exp %dprec 10
	  {
		debug("exp ::= ( exp \n");
		newError(errfactory, MissingRParen, 
			@2.last_line, @2.last_column + 1, 
			filename);
						
	  }
	| Exp RPAR %dprec 8
	  {
		debug("exp ::= exp )\n");
		newError(errfactory, MissingLParen, 
			@1.first_line, @1.first_column,
			 filename);
	  }
	| Exp Exp %dprec 1
	  {
		debug("exp ::= exp exp\n");
		newError(errfactory, MissingOp,
			@2.first_line, @2.first_column, 
			filename);	
	  }


%%

void yyerror(char *message)
{
	printf("%s\n",message);
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
	errfactory = newErrFactory();
	printf("Parsing ...\n");
	if (argc > 1)

		while (i < argc)
		{	
			yyin = fopen(argv[i], "r");
			yyparse(argv[i]);
			yylineno = 1;
			fclose(yyin);
			i++;
		}
	dumpErrors(errfactory);
	dumpWarnings(errfactory);	

	return(0);
}
