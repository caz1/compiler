%{
#define NUL	0
#define NUMBER	1
#define ID	2
#define PLUS	3
#define MINUS	4
#define MULT	5
#define DIV	6	
#define MOD	7
#define EQ	8
#define NE	9
#define LT	10	
#define LE	11
#define GT	12	
#define GE	13
#define MAIN	14
#define RELOP	15
#define BINOP	16
#define COMMA	17
#define SEMICOLON	18
#define LBRACKET	19
#define RBRACKET	20
#define LPAR	21
#define RPAR	22
#define LBRACE	23
#define RBRACE	24
#define WHILE	25
#define IF	26	
#define CONST	27
#define INT	28
#define ELSE	29

%}
%option main noyywrap




delim	[ \n\t]
ws	{delim}+
digit	[0-9]
letter	[a-zA-Z]
ID	([_]|{letter})+({letter}|{digit})*
number	{digit}+

%%



{ws}	{}
while	{return(WHILE);}
const	{return(CONST);}
if	{return(IF);}
else	{return(ELSE);}
int	{return(INT);}

{number}	{ECHO; return;}
{ID}	{ECHO; return;}

"<"	{ return(RELOP);}
"=="	{}
"<="	{return(RELOP);}
">"	{return(RELOP);}
">="	{return(RELOP);}
"!="	{return(RELOP);}
"="	{return(RELOP);}
"("	{return(LPAR);}
")"	{return(RPAR);}
"{"	{return(LBRACE);}
"}"	{return(RBRACE);}
"["	{return(LBRACKET);}
"]"	{return(RBRACKET);}
","	{return(COMMA);}
";"	{return(SEMICOLON);}
"+"	{return(BINOP);}
"-"	{return(BINOP);}
"*"	{return(BINOP);}
"/"	{return(BINOP);}
"%"	{return(BINOP);}
<<EOF>>	{yyterminate();}

.	{printf("Illegal character");}


%%


