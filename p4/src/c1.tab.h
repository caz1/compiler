/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2013 Free Software Foundation, Inc.

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
    ODD = 272,
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
    VOID = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 14 "config/c1.y" /* glr.c:2555  */

	char *name;
	int  ival;

#line 92 "src/c1.tab.h" /* glr.c:2555  */
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
int yyparse (char *filename);

#endif /* !YY_YY_SRC_C1_TAB_H_INCLUDED  */
