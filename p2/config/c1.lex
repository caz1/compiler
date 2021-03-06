%{
#include"token.h"
%}

delim	[ \t]
ws	{delim}+
digit	[0-9]
letter	[a-zA-Z]
ID	([_]|{letter})({letter}|{digit})*
number	{digit}+

%%



{ws}	{/*skip it*/}
while	{return(WHILE);}
const	{return(CONST);}
if  	{return(IF);}
else	{return(ELSE);}
int	    {return(INT);}

{number}	{num=atoi(yytext); return(NUMBER);}
{ID}	{identifier=yytext; return(ID);}

"\n"    {printf("\n");}

"\""    {return(QUOTE);}
"\\"    {return(SLASH);}
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



