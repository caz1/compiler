%{
#include <cstdio>
#include <cmath>
#include <unistd.h>
#include <string>
#include <vector>
#include "node.hh"
#include "err.hh"
#include "c1.tab.hh"


using namespace std;
void yyerror(char *, char *);
extern int yylex ();
extern int yylineno;
extern int yycolumn;
extern Node *root;	
extern ErrFactory errfactory;
extern vector<Node*> List;
extern bool haveError;
%}

%union {
	std::string *name;
	int  ival;
	Node *node;
	std::vector<ConstDefNode*> *ConstDefArray;
	std::vector<ExpNode*> *ExpArray;
	std::vector<VarDefNode*> *VarArray;
}
%locations
%debug
//%glr-parser
%parse-param {char *filename}

%token NUMBER ID
%token PLUS MINUS MULT DIV MOD EQ ISEQ GT LT LE NE GE UMINUS
%token EOL EXTERN NOT AND OR BREAK CONTINUE
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

%type  <ival> PLUS MINUS MULT DIV MOD EQ NUMBER ISEQ GT LT LE NE GE NOT AND OR
%type  <name> ID
%type  <node> CompUnit ConstDecl VarDecl Exp LVal MultiBlockItem Decl BlockItem Cond IFCOND WHILECOND Block WHILEStmt IFStmt Stmt FuncDef ConstDef Var ExternFunc ExternDecl
%type  <ConstDefArray> MultiConstDef
%type  <ExpArray> MultiExp
%type  <VarArray> MultiVar 

%%

golbal 
	: CompUnit
	  {
		if (!haveError)
             root = $1; // todo
	  }

CompUnit
	: CompUnit Decl
	  {
		debug("CompUnit ::= CompUnit Decl\n");
		if (!haveError)
		{
		    dynamic_cast<CompUnitNode*>($1)->append(dynamic_cast<DeclNode*>($2));
		    $$ = $1;
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| CompUnit FuncDef
	  {
		debug("CompUnit ::= CompUnit FuncDef\n");
		if (!haveError)
		{
		    dynamic_cast<CompUnitNode*>($1)->append(dynamic_cast<ExternFuncNode*>($2));
		    $$ = $1;
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| CompUnit ExternFunc
	  {
	    debug("CompUnit ::= CompUnit ExternFunc\n");
	    if (!haveError)
	    {
            dynamic_cast<CompUnitNode*>($1)->append(dynamic_cast<ExternFuncNode*>($2)); 
		    $$ = $1;
	        $$->setLoc((Loc)&(@$));		
	    }
	  }
	| Decl
	  {
		debug("CompUnit ::= Decl\n");
		if (!haveError)
		{
		    $$ = new CompUnitNode();
            dynamic_cast<CompUnitNode*>($$)->append(dynamic_cast<DeclNode*>($1));
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| FuncDef
	  {
		debug("CompUnit ::= FuncDef\n");
		if (!haveError)
		{
		    $$ = new CompUnitNode();
            dynamic_cast<CompUnitNode*>($$)->append(dynamic_cast<ExternFuncNode*>($1));
	        $$->setLoc((Loc)&(@$));		    
        }
	  } 
	| ExternFunc
	  {
	    debug("CompUnit ::= ExternFunc\n");
	    if (!haveError)
	    {
	        $$ = new CompUnitNode();
	        dynamic_cast<CompUnitNode*>($$)->append(dynamic_cast<ExternFuncNode*>($1));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	 
	  
ExternFunc
    : EXTERN VOID ID LPAR RPAR SEMICOLON
    {
        debug("ExternFunc ::= extern void ID();\n");
        if (!haveError)
        {
            $$ = new ExternFuncNode($3);
            $$->setLoc((Loc)&(@$));
        }
    }
    
Decl
	: ConstDecl
	  {
		debug("Decl ::= ConstDecl\n");
		if (!haveError)
		{
	    	$$ = $1;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }

	| VarDecl
	  {
		debug("Decl ::= VarDecl\n");
		if (!haveError)
		{
			$$ = $1;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| ExternDecl
	  {
	    debug("Decl ::= ExternDecl\n");
	    if (!haveError)
	    {
	        $$ = $1;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }

ExternDecl
    : EXTERN INT MultiVar SEMICOLON
      {
        debug("ConstDecl ::= extern int MultiVar ;\n");
        if (!haveError)
        {
            $$ = new ExternDeclNode(*$3);
	        $$->setLoc((Loc)&(@$));		    
        }
      }  

ConstDecl
	: CONST INT MultiConstDef SEMICOLON
	  {
		debug("ConstDecl ::= const int MultiConstDef ;\n");
		if (!haveError)
		{
		    $$ = new ConstDeclNode(*$3);
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| CONST MultiConstDef SEMICOLON
	  {
		debug("ConstDecl ::= const MultiConstDef ;\n");
		if (!haveError)
		{
		    $$ = new ConstDeclNode(*$2);
	        $$->setLoc((Loc)&(@$));		    
		    errfactory.append(new errmsg(MissingVarType, 
			    @2.first_line, @2.first_column, 
		    	filename, true));
        }
	  }
	

MultiConstDef
	: MultiConstDef COMMA ConstDef
	  {
		debug("MultiConstDecl ::= MultiConstDecl , ConstDef\n");
		if (!haveError)
		{
		    $1->push_back(dynamic_cast<ConstDefNode*>($3));
		    $$ = $1;		
	    }
	  }

	| ConstDef
	  {
		debug("MultiConstDecl ::= ConstDef\n");
		if (!haveError)
        {
            $$ = new vector<ConstDefNode*>();
            $$->push_back(dynamic_cast<ConstDefNode*>($1));
        }
	  }


ConstDef 
	: ID EQ Exp
	  {
		debug("ConstDef ::= ID EQ Exp\n");
		if (!haveError)
		{
	    	$$ = new ConstINTNode(dynamic_cast<ExpNode*>($3), new VarNode($1, 0, NULL));
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| ID LBRACKET Exp RBRACKET EQ LBRACE MultiExp RBRACE 
	  {
		debug("ConstDef ::= ID[exp] EQ {MultiExp}\n");
		if (!haveError)
		{		
		    $$ = new ConstARRAYNode(*$7, new VarNode($1, 1, dynamic_cast<ExpNode*>($3)));
	        $$->setLoc((Loc)&(@$));		    
        }
  	  }
	|ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE 
	  {
		debug("ConstDef ::= ID[] EQ {MultiExp}\n");
		if (!haveError)
        {
		    $$ = new ConstARRAYNode(*$6, new VarNode($1, 1, NULL));
	        $$->setLoc((Loc)&(@$));		    
        }
	  }

MultiExp
	: MultiExp COMMA Exp
	  {
		debug("MultiExp ::= MultiExp , Exp\n");
		if (!haveError)
		{
		    $1->push_back(dynamic_cast<ExpNode*>($3));
		    $$ = $1;
        }
	  }
	| Exp
	  {
		debug("MultiExp ::= Exp\n");
		if (!haveError)
		{
		    $$ = new vector<ExpNode*>();
		    $$->push_back(dynamic_cast<ExpNode*>($1));
        }
	  }

VarDecl	
	: INT MultiVar SEMICOLON
	  {
		debug("VarDecl ::= int MultiVar ;\n");
		if (!haveError)
		{
    		$$ = new VarDeclNode(*$2);
            List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
        }
	  }

MultiVar
	: MultiVar COMMA Var
	  {
		debug("MultiVar ::= MultiVar , Var\n");
		if (!haveError)
		{
    		$1->push_back(dynamic_cast<VarDefNode*>($3));
    		$$ = $1;
       }
	  }
	| Var
	  {
		debug("MultiVar ::= Var\n");
		if (!haveError)		
		{
		    $$ = new vector<VarDefNode*>();
		    $$->push_back(dynamic_cast<VarDefNode*>($1));
        }
	  }


Var
	: ID
	  {
		debug("Var ::= ID\n");
		if (!haveError)
		{
		    $$ = new VarINTNode(new VarNode($1, 0, NULL), false, NULL);
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| ID LBRACKET Exp RBRACKET
	  {
		debug("Var ::= ID[Exp]\n");
		if (!haveError)
		{
		    $$ = new VarARRAYNode(new VarNode($1, 1, dynamic_cast<ExpNode*>($3)), false, vector<ExpNode*>());
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| ID EQ Exp//
	  {
		debug("Var ::= ID EQ Exp\n");
		if (!haveError)
		{
		    $$ = new VarINTNode(new VarNode($1, 0, NULL), true, dynamic_cast<ExpNode*>($3));
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| ID LBRACKET Exp RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Var ::= ID[exp] EQ { MultiExp }\n");
		if (!haveError)
		{
		    $$ = new VarARRAYNode(new VarNode($1, 1, dynamic_cast<ExpNode*>($3)), true, *$7);
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| ID LBRACKET RBRACKET EQ LBRACE MultiExp RBRACE
	  {
		debug("Var ::= ID[] EQ { MultiExp }\n");
		if (!haveError)
		{
		    $$ = new VarARRAYNode(new VarNode($1, 1, NULL), true, *$6);  
	        $$->setLoc((Loc)&(@$));		    
        }
	  }


FuncDef
	: VOID ID LPAR RPAR Block
	  {
		debug("FuncDef ::= void ID() Block\n");
		if (!haveError)
		{
		    $$ = new FuncDefNode($2, dynamic_cast<BlockNode*>($5));
            List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
        }
	  }
	| VOID ID LPAR Block
	  {
		debug("FuncDef  ::= void ID( Block\n");
		errfactory.append(new errmsg(MissingRParen,
			@3.last_line, @3.last_column, 
			filename, false));
			
        delete root;
	    haveError = true;
	  }
	| VOID ID RPAR Block
	  {
		debug("FuncDef  ::= void ID) Block\n");
		errfactory.append(new errmsg(MissingLParen,
			@2.last_line, @2.last_column, 
			filename, false));
        delete root;
	    haveError = true;
	  }


Block
	: LBRACE MultiBlockItem RBRACE
	  {
		debug("Block ::= { MultiBlockItem }\n");
		if (!haveError)
		{
		    $$ = $2;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| LBRACE RBRACE
	  {
		debug("Block ::= {}\n");
		if (!haveError)
		{
		    $$ = new BlockNode();
            List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }

MultiBlockItem
	: MultiBlockItem BlockItem
	  {
		debug("MultiBlockItem ::= MultiBlockItem BlockItem\n");
		if (!haveError)
		{
		    if ($2->type == CONSTDECL || $2->type == VARDECL || $2->type == EXTERNDECL)
		        dynamic_cast<BlockNode*>($1)->append(dynamic_cast<DeclNode*>($2));
		    else dynamic_cast<BlockNode*>($1)->append(dynamic_cast<StmtNode*>($2));
		    $$ = $1;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| BlockItem
	  {
		debug("MultiBlockItem ::= BlockItem\n");
		if (!haveError)
		{
		    $$ = new BlockNode();
		    if ($1->type == CONSTDECL || $1->type == VARDECL || $1->type == EXTERNDECL)
		        dynamic_cast<BlockNode*>($$)->append(dynamic_cast<DeclNode*>($1));
		    else dynamic_cast<BlockNode*>($$)->append(dynamic_cast<StmtNode*>($1));
            List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }	

BlockItem
	: Decl 
	  {
		debug("BlockItem ::= Decl \n");
		if (!haveError)
		{
    		$$ = $1;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Stmt
	  {
		debug("BlockItem ::= Stmt\n");
		if (!haveError)
		{
    		$$ = $1;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }


Stmt
	: LVal EQ Exp SEMICOLON 
	  {
		debug("Stmt ::= LVal EQ Exp ;\n");
		if (!haveError)
		{
		    $$ = new AsgnNode(dynamic_cast<VarNode*>($1), dynamic_cast<ExpNode*>($3));
            List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| ID LPAR RPAR SEMICOLON//
	  {
		debug("Stmt ::= ID() ;\n");
		if (!haveError)
		{
		    $$ = new FuncCallNode($1);
            List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| ID LPAR SEMICOLON
	  {
		debug ("Stmt ::= ID(\n");
		errfactory.append(new errmsg(MissingRParen, 
			@3.first_line, @3.first_column,
			filename, false));	
        delete root;
	    haveError = true;
	  }  
	| ID RPAR SEMICOLON
	  {
		debug ("Stmt ::= ID)\n");
		errfactory.append(new errmsg(MissingLParen, 
			@2.first_line, @2.first_column,
			filename, false));	
        delete root;
	    haveError = true;
	  }  
	| Block 
	  {
		debug("Stmt ::= Block\n");
		if (!haveError)
        {    
 	        $$ = $1;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| IFStmt
	  {
		debug("Stmt ::= IFStmt\n");
		if (!haveError)
		{
		    $$ = $1;
		    List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| WHILEStmt
	  {
		debug("Stmt ::= WHILEStmt\n");
		if (!haveError)
		{
		    $$ = $1;
		    List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| SEMICOLON
	  {
		debug("Stmt ::= ;\n");
		if (!haveError)
		{
		    $$ = new EmptyNode();
            List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| BREAK SEMICOLON
	  {
	    debug("Stmt ::= break;\n");
	    if (!haveError)
	    {
	        $$ = new BreakNode();
	        List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    	        
	    }  
	  }
	| CONTINUE SEMICOLON
	  {
	    debug("Stmt ::= continue;\n");
	    if (!haveError)
	    {
	        $$ = new ContinueNode();
	        List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }

WHILEStmt
	: WHILECOND Stmt 
	  {
		debug("Stmt ::= WHILECOND Stmt\n");
		if (!haveError)
		{		
		    $$ = new WhileStmtNode(dynamic_cast<CondNode*>($1), dynamic_cast<StmtNode*>($2));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }

WHILECOND
	: WHILE LPAR Cond RPAR
	  {
		debug("WHILECOND ::= while(Cond)\n");
		if (!haveError)
		{		
			$$ = $3;	
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| WHILE LPAR Cond 
	  {
		debug ("WHILECOND ::= while(cond\n");
		errfactory.append(new errmsg(MissingRParen, 
			@3.last_line, @3.last_column, 
			filename, false));
        delete root;
	    haveError = true;
	  }
	| WHILE Cond RPAR
	  {
		debug ("WHILECOND ::= while Cond)\n");
		errfactory.append(new errmsg(MissingLParen, 
			@1.last_line, @1.last_column,
			filename, false));
        delete root;
	    haveError = true;
	  }

IFStmt
	: 
	 IFCOND Stmt ELSE Stmt
	  {
		debug("IFStmt ::= IFCOND Stmt ELSE Stmt\n");
		if (!haveError)
		{
		    $$ = new IfStmtNode(dynamic_cast<CondNode*>($1), dynamic_cast<StmtNode*>($2), dynamic_cast<StmtNode*>($4));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| IFCOND Stmt %prec nonelse
	  {
		debug("IFStmt ::= IFCOND Stmt\n");	
		if (!haveError)
		{		
		    $$ = new IfStmtNode(dynamic_cast<CondNode*>($1), dynamic_cast<StmtNode*>($2), NULL);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	

IFCOND
	: IF LPAR Cond RPAR
	  {
		debug("IFCOND ::= IF (Cond)\n");
		if (!haveError)
		{		
    		$$ = $3;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| IF LPAR Cond
	  {
		debug("IFCOND ::= IF (Cond\n");
		errfactory.append(new errmsg(MissingRParen, 
			@3.last_line, @3.last_column, 
			filename, false));	
        delete root;
	    haveError = true;
	  }
	| IF Cond RPAR
	  {
		debug("IFCOND ::= IF Cond)\n");
		errfactory.append(new errmsg(MissingLParen, 
			@2.first_line, @2.first_column, 
			filename, false));	
        delete root;
	    haveError = true;
	  }

LVal
	: ID
	  {
	  	debug("LVal ::= ID\n");
		if (!haveError)
		{
		    $$ = new VarNode($1, 0, NULL);
            List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| ID LBRACKET Exp RBRACKET
	  {
	  	debug("LVal ::= ID[Exp]\n");
		if (!haveError)
		{
		    $$ = new VarNode($1, 1, dynamic_cast<ExpNode*>($3));
            List.push_back($$);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	  
Cond
	:  Exp LT Exp %prec UMINUS
	  {
		debug("Cond ::= exp < exp\n");
		if (!haveError)
        {		
		    $$ = new CondNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Exp ISEQ Exp %prec UMINUS
	  {
		debug("Cond ::= exp == exp\n");
		if (!haveError)
		{
		    $$ = new CondNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Exp LE Exp %prec UMINUS
	  {
		debug("Cond ::= exp <= exp\n");
		if (!haveError)
        {		
		    $$ = new CondNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Exp GT Exp %prec UMINUS
	  {
		debug("Cond ::= exp > exp\n");
		if (!haveError)
        {
		    $$ = new CondNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Exp GE Exp %prec UMINUS
	  {
		debug("Cond ::= exp >= exp\n");
		if (!haveError)
		{	
		    $$ = new CondNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }	
	| Exp NE Exp %prec UMINUS
	  {
		debug("Cond ::= exp != exp\n");
		if (!haveError)
		{		
		    $$ = new CondNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
  	| Cond AND Cond %prec UMINUS
	  {
		debug("Cond ::= cond && cond\n");
		if (!haveError)
		{		
		    $$ = new CondNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Cond OR Cond %prec UMINUS
	  {
		debug("Cond ::= cond || cond\n");
		if (!haveError)
		{		
		    $$ = new CondNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3));
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| NOT Cond %prec UMINUS
	  {
		debug("Cond ::= !cond\n");
		if (!haveError)
		{		
		    $$ = new CondNode($1, dynamic_cast<ExpNode*>($2), NULL);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
Exp
	: Exp PLUS Exp  
	  {
		debug("exp ::= exp PLUS exp\n");
		if (!haveError)
		{
		    $$ = new BinaryExpNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3)); 
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Exp MINUS Exp 
	  {
		debug("exp ::= exp MINUS exp\n");
		if (!haveError)
		{
		    $$ = new BinaryExpNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3)); 
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Exp MULT Exp  
	  {
		debug("exp ::= exp MULT exp\n");
		if (!haveError)
		{
		    $$ = new BinaryExpNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3)); 
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Exp DIV Exp 
	  {
		debug("exp ::= exp DIV exp\n");
		if (!haveError)		
        {   
		    $$ = new BinaryExpNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3)); 
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| Exp MOD Exp  
	  {
		debug("exp ::= exp MOD exp\n");
		if (!haveError)
		{		
		    $$ = new BinaryExpNode($2, dynamic_cast<ExpNode*>($1), dynamic_cast<ExpNode*>($3)); 
	        $$->setLoc((Loc)&(@$));		    
	    }
	   }
	| Exp Exp %prec A 
	  {
		debug("exp ::= exp exp\n");
		errfactory.append(new errmsg(MissingOp,
			@2.first_line, @2.first_column -1, 
			filename, false));	
        delete root;
	    haveError = true;
	  }
	 | PLUS Exp %prec PLUS
 	  {
	  	debug("exp ::= PLUS exp\n");
		if (!haveError)
		{	  	
	   	    $$ = new UnaryExpNode($1, dynamic_cast<ExpNode*>($2)); 	
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }

	| MINUS Exp %prec MINUS
 	  {
	  	debug("exp ::= MINUS exp\n");
		if (!haveError)
		{	  	
	   	    $$ = new UnaryExpNode($1, dynamic_cast<ExpNode*>($2)); 	
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| NUMBER 
	  {
		debug("exp ::= NUMBER\n");
		if (!haveError)
		{
		    $$ = new NumNode($1);
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }	
	| LVal
	  {
		debug("exp ::= LVal\n");
		if (!haveError)
		{
		    $$ = $1;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| LPAR Exp RPAR %prec UMINUS
	  {
		debug("exp ::= ( exp )\n");
		if (!haveError)
		{
    	    $$ = $2;
	        $$->setLoc((Loc)&(@$));		    
	    }
	  }
	| LPAR Exp %prec LPAR
	  {
		debug("exp ::= ( exp \n");
		errfactory.append(new errmsg(MissingRParen, 
			@2.last_line, @2.last_column + 1, 
			filename, false));		
        delete root;
	    haveError = true;
	  }
	| Exp RPAR %prec UMINUS
	  {
		debug("exp ::= exp )\n");
		errfactory.append(new errmsg(MissingLParen, 
			@1.first_line, @1.first_column,
			 filename, false));
        delete root;
	    haveError = true;
	  }
	
%%

void yyerror(char *filename, char *message)
{
	printf("\033[1;31;40m%s\033[0m in %s\n",message, filename);
}



