/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_C1_TAB_H_INCLUDED
# define YY_YY_SRC_C1_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    ID = 259,
    PLUS = 260,
    MINUS = 261,
    MULT = 262,
    DIV = 263,
    MOD = 264,
    EQ = 265,
    ISEQ = 266,
    GT = 267,
    LT = 268,
    LE = 269,
    NE = 270,
    GE = 271,
    UMINUS = 272,
    EOL = 273,
    LPAR = 274,
    RPAR = 275,
    LBRACE = 276,
    RBRACE = 277,
    LBRACKET = 278,
    RBRACKET = 279,
    INT = 280,
    SEMICOLON = 281,
    COMMA = 282,
    CONST = 283,
    WHILE = 284,
    IF = 285,
    ELSE = 286,
    VOID = 287,
    A = 288,
    F = 289,
    nonelse = 290
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define PLUS 260
#define MINUS 261
#define MULT 262
#define DIV 263
#define MOD 264
#define EQ 265
#define ISEQ 266
#define GT 267
#define LT 268
#define LE 269
#define NE 270
#define GE 271
#define UMINUS 272
#define EOL 273
#define LPAR 274
#define RPAR 275
#define LBRACE 276
#define RBRACE 277
#define LBRACKET 278
#define RBRACKET 279
#define INT 280
#define SEMICOLON 281
#define COMMA 282
#define CONST 283
#define WHILE 284
#define IF 285
#define ELSE 286
#define VOID 287
#define A 288
#define F 289
#define nonelse 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 14 "config/c1.y" /* yacc.c:1909  */

	char *name;
	int  ival;
	ASTNode node;
	List list;
	ConstDef constdef;
	VarDef vardef; 

#line 133 "src/c1.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (char *filename, DumpDot *dot);

#endif /* !YY_YY_SRC_C1_TAB_H_INCLUDED  */
