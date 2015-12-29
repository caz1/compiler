%{

#include "node.hh"
#include <string>
#include "c1.tab.hh"

extern void yyerror (const char *msg);
using namespace std;

int yycolumn = 1;
static void comment();
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
{ws}	{}
while	{return(WHILE);}
const	{ return(CONST);}
if  	{return(IF);}
else	{return(ELSE);}
int	    { return(INT);}
void	{ return(VOID);}
extern { return(EXTERN); }
break 	{ return(BREAK); }
continue { return(CONTINUE); }
{number}	{yylval.ival=atoi(yytext); return(NUMBER);}
{ID}	{yylval.name = new string(yytext); return(ID);}

"\n"    {yycolumn = 1;}
"!"	{yylval.ival=NOT; return(NOT);}
"||"	{yylval.ival=OR; return(OR);}
"&&"	{yylval.ival=AND; return(AND);}
"<"	    {yylval.ival=LT; return(LT);}
"=="	{yylval.ival=ISEQ; return(ISEQ);}
"<="	{yylval.ival=LE; return(LE);}
">"	    {yylval.ival=GT; return(GT);}
">="	{yylval.ival=GE; return(GE);}
"!="	{yylval.ival=NE; return(NE);}
"="	    {return(EQ);}
"("	    {return(LPAR);}
")"	    {return(RPAR);}
"{"	    {return(LBRACE);}
"}"	    {return(RBRACE);}
"["	    {return(LBRACKET);}
"]"	    {return(RBRACKET);}
","	    {return(COMMA);}
";"	    {return(SEMICOLON);}
"+"	    {yylval.ival=PLUS; return(PLUS);}
"-"	    {yylval.ival=MINUS; return(MINUS);}
"*"	    {yylval.ival=MULT;return(MULT);}
"/"	    {yylval.ival=DIV;return(DIV);}
"%"	    {yylval.ival=MOD;return(MOD);}
<<EOF>>	{yyterminate();}

.	{printf("Illegal character");}

%%

static void comment(void)
{
    int c;

    while ((c = yyinput()) != 0)
    {
        yycolumn++;
        if (c == '*')
        {
            while ((c = yyinput()) == '*')
                yycolumn++;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
        else if (c == '\n')
            yycolumn = 1;
       
    }
    //yyerror("unterminated comment");
}

int yywrap(){
    return 1;
}



