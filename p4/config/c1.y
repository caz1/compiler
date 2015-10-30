%{
#include <stdio.h>
#include <math.h>
#include <common.h>
#include <unistd.h>
//ASTTree ast;	
int num;
char *ident;
ErrFactory errfactory;
extern int yylineno;
extern int yycolumn;
%}

%union {
	char *name;
	int  ival;
}
%locations
%debug
//%glr-parser
%parse-param {char *filename}

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

%type  <ival> PLUS MINUS MULT DIV MOD EQ NUMBER
%type  <name> ID


%%

CompUnit
	: CompUnit Decl
	  {
		debug("CompUnit ::= CompUnit Decl\n");
	  }
	| CompUnit FuncDef
	  {
		debug("CompUnit ::= CompUnit FuncDef\n");
	  }
	| Decl
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
		debug("ConstDecl ::= const MultiConstDef ;\n");
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
	| LVal EQ LBRACE MultiExp RBRACE 
	  {
		debug("ConstDef ::= LVal EQ {MultiExp}\n");
	  }
	|ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE 
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
		debug("Var ::= ID EQ Exp\n");
	  }
	| ID LBRACKET Exp RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Var ::= ID[exp] EQ { MultiExp }\n");
	  }
	| ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Var ::= ID[] EQ { MultiExp }\n");
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
	| LBRACE RBRACE
	  {
		debug("Block ::= {}\n");
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
	: WHILE LPAR Cond RPAR
	  {
		debug("WHILECOND ::= while(Cond)\n");	
	  }
	| WHILE LPAR Cond 
	  {
		debug ("WHILECOND ::= while(cond\n");
		newError(errfactory, MissingRParen, 
			@3.last_line, @3.last_column, 
			filename);
	  }
	| WHILE Cond RPAR
	  {
		debug ("WHILECOND ::= while Cond)\n");
		newError(errfactory, MissingLParen, 
			@1.last_line, @1.last_column,
			filename);
	  }

IFStmt
	: 
	 IFCOND Stmt ELSE Stmt
	  {
		debug("IFStmt ::= IFCOND Stmt ELSE Stmt\n");
	  }
	| IFCOND Stmt %prec nonelse
	  {
		debug("IFStmt ::= IFCOND Cond Stmt\n");	
	  }
	

IFCOND
	: IF LPAR Cond RPAR
	  {
		debug("IFCOND ::= IF (Cond)\n");
	  }
	| IF LPAR Cond
	  {
		debug("IFCOND ::= IF (Cond\n");
		newError(errfactory, MissingRParen, 
			@3.last_line, @3.last_column, 
			filename);	
	  }
	| IF Cond RPAR
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
	:  Exp LT Exp %prec UMINUS
	  {
		debug("Cond ::= exp < exp\n");
	  }
	| Exp ISEQ Exp %prec UMINUS
	  {
		debug("Cond ::= exp == exp\n");
	  }
	| Exp LE Exp %prec UMINUS
	  {
		debug("Cond ::= exp <= exp\n");
	  }
	| Exp GT Exp %prec UMINUS
	  {
		debug("Cond ::= exp > exp\n");
	  }
	| Exp GE Exp %prec UMINUS
	  {
		debug("Cond ::= exp >= exp\n");
	  }	
	| Exp NE Exp %prec UMINUS
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
	   }
	| Exp Exp %prec A 
	  {
		debug("exp ::= exp exp\n");
		newError(errfactory, MissingOp,
			@2.first_line, @2.first_column -1, 
			filename);	
	  }
	 | PLUS Exp %prec PLUS
 	  {
	  	debug("exp ::= PLUS exp\n");
	  }

	| MINUS Exp %prec MINUS
 	  {
	  	debug("exp ::= MINUS exp\n");
	  }
	| NUMBER 
	  {
		debug("exp ::= NUMBER\n");
	  }	
	| LVal
	  {
		debug("exp ::= LVal\n");
	  }
	| LPAR Exp RPAR %prec UMINUS
	  {
		debug("exp ::= ( exp )\n");
	  }
	| LPAR Exp %prec LPAR
	  {
		debug("exp ::= ( exp \n");
		newError(errfactory, MissingRParen, 
			@2.last_line, @2.last_column + 1, 
			filename);					
	  }
	| Exp RPAR %prec UMINUS
	  {
		debug("exp ::= exp )\n");
		newError(errfactory, MissingLParen, 
			@1.first_line, @1.first_column,
			 filename);
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
	while (i < argc)
	{	
		yyin = fopen(argv[i], "r");
		printf("Parsing file \"\033[1;31;40m%s\033[0m\"\n", argv[i]);
		temp = yyparse(argv[i]);
		
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
	dumpErrors(errfactory);
	dumpWarnings(errfactory);	

	return(0);
}
