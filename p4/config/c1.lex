%{
//#include"token.h"
#include <common.h>
#include "c1.tab.h"
extern int num;
extern char *ident;
static void comment();
int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
    yycolumn += yyleng;
%}

%option yylineno

delim	[ \t]
ws	{delim}+
digit	[0-9]
letter	[a-zA-Z]
ID	([_]|{letter})({letter}|{digit})*
number	{digit}+

%%
"/*"    { comment(); }
"//".* 	{}
{ws}	{/*skip it*/}
while	{return(WHILE);}
const	{return(CONST);}
if  	{return(IF);}
else	{return(ELSE);}
int	    {return(INT);}
void	{return(VOID);}
{number}	{num=atoi(yytext); return(NUMBER);}
{ID}	{ident=yytext; return(ID);}

"\n"    {printf("\n");}
'!'	{return(ODD);}

"<"	    {return(LT);}
"=="	{return(ISEQ);}
"<="	{return(LE);}
">"	    {return(GT);}
">="	{return(GE);}
"!="	{return(NE);}
"="	    {return(EQ);}
"("	    {return(LPAR);}
")"	    {return(RPAR);}
"{"	    {return(LBRACE);}
"}"	    {return(RBRACE);}
"["	    {return(LBRACKET);}
"]"	    {return(RBRACKET);}
","	    {return(COMMA);}
";"	    {return(SEMICOLON);}
"+"	    {return(PLUS);}
"-"	    {return(MINUS);}
"*"	    {return(MULT);}
"/"	    {return(DIV);}
"%"	    {return(MOD);}
<<EOF>>	{yyterminate();}

.	{printf("Illegal character");}

%%

int yywrap(){
    return 1;
}

static void comment(void)
{
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
}

