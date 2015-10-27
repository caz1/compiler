%{
//#include"token.h"
#include <common.h>
#include "c1.tab.h"
extern int num;
extern char *ident;

int yycolumn = 1;
int left_paren = 0;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
    yycolumn += yyleng;
char line[100];
%}

%option yylineno

delim	[ \t]
ws	{delim}+
digit	[0-9]
letter	[a-zA-Z]
ID	([_]|{letter})({letter}|{digit})*
number	{digit}+

%%

"//".* 	{}
{ws}	{strcat(line, yytext);}
while	{strcat(line, "while"); return(WHILE);}
const	{strcat(line, "const"); return(CONST);}
if  	{strcat(line, "if"); return(IF);}
else	{strcat(line, "else"); return(ELSE);}
int	{strcat(line, "int"); return(INT);}
void	{strcat(line, "void"); return(VOID);}
{number}	{strcat(line, yytext); num=atoi(yytext); return(NUMBER);}
{ID}	{strcat(line, yytext); ident=yytext; return(ID);}

"\n"    {printf("%s\n", line); yycolumn = 1; memset(line, 0, 100);}
'!'	{strcat(line, '!'); return(ODD);}

"<"	{strcat(line, '<'); return(LT);}
"=="	{strcat(line, "=="); return(ISEQ);}
"<="	{strcat(line, "<="); return(LE);}
">"	{strcat(line, ">"); return(GT);}
">="	{strcat(line, ">="); return(GE);}
"!="	{strcat(line, "!="); return(NE);}
"="	    {strcat(line, "="); return(EQ);}
"("	    {strcat(line, "("); left_paren++; return(LPAR);}
")"	    {strcat(line, ")"); left_paren--; return(RPAR);}
"{"	    {strcat(line, "{"); return(LBRACE);}
"}"	    {strcat(line, "}"); return(RBRACE);}
"["	    {strcat(line, "["); return(LBRACKET);}
"]"	    {strcat(line, "]"); return(RBRACKET);}
","	    {strcat(line, ","); return(COMMA);}
";"	    {strcat(line, ";"); return(SEMICOLON);}
"+"	    {strcat(line, "+"); return(PLUS);}
"-"	    {strcat(line, "-"); return(MINUS);}
"*"	    {strcat(line, "*"); return(MULT);}
"/"	    {strcat(line, "/"); return(DIV);}
"%"	    {strcat(line, "%"); return(MOD);}
<<EOF>>	{yyterminate();}

.	{printf("Illegal character");}

%%

int yywrap(){
    return 1;
}



