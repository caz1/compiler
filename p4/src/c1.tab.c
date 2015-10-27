/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Skeleton implementation for Bison GLR parsers in C

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user declarations.  */
#line 1 "config/c1.y" /* glr.c:207  */

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

#line 67 "src/c1.tab.c" /* glr.c:207  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "c1.tab.h"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;

/* Copy the second part of user declarations.  */

#line 100 "src/c1.tab.c" /* glr.c:230  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify clang.  */
# define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#ifndef YYASSERT
# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    41,    41,    45,    49,    54,    59,    65,    69,    78,
      83,    90,    94,    98,   106,   110,   116,   122,   126,   132,
     136,   140,   144,   148,   152,   159,   163,   170,   179,   186,
     190,   196,   200,   207,   211,   215,   222,   229,   233,   237,
     241,   247,   253,   257,   264,   273,   277,   283,   290,   297,
     301,   308,   317,   321,   327,   331,   335,   339,   343,   347,
     351,   359,   363,   367,   371,   375,   379,   383,   387,   391,
     396,   400,   408,   415
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "PLUS", "MINUS", "MULT",
  "DIV", "MOD", "EQ", "ISEQ", "GT", "LT", "LE", "NE", "GE", "ODD", "EOL",
  "LPAR", "RPAR", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "INT",
  "SEMICOLON", "COMMA", "CONST", "WHILE", "IF", "ELSE", "VOID", "$accept",
  "CompUnit", "Decl", "ConstDecl", "MultiConstDef", "ConstDef", "MultiExp",
  "VarDecl", "MultiVar", "Var", "FuncDef", "Block", "MultiBlockItem",
  "BlockItem", "Stmt", "WHILEStmt", "WHILECOND", "IFStmt", "Matched",
  "UnMatched", "IFCOND", "LVal", "Cond", "Exp", YY_NULLPTR
};
#endif

#define YYPACT_NINF -76
#define YYTABLE_NINF -69

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const short int yypact[] =
{
      -3,    23,    16,    48,    17,    43,   -76,   -76,   -76,     9,
      80,   -76,    11,    75,   100,   -76,   135,   -76,    43,   -76,
     469,   243,   -76,    23,   469,   247,   175,   -76,    75,   207,
      68,   -76,   -76,    64,   469,   469,   469,   -76,   305,    85,
       4,   -76,   305,    87,   214,   -76,   -76,    68,   178,   -76,
     -76,   469,   419,   426,   312,   469,   469,   469,   469,   469,
     -76,   330,    98,   122,   113,   127,   -76,   177,   -76,   444,
     461,   -76,   -76,    36,   -76,   -76,   -76,    52,   -76,   -76,
     -76,    52,   150,   236,   109,   137,   165,    90,   433,   437,
     469,   126,   469,   141,    28,    82,   469,   465,   145,   269,
     465,   155,   -76,   -76,   -76,   152,   469,   -76,    33,   305,
     469,    47,   469,   162,   -76,   -76,   337,   170,   287,   -76,
     469,   469,   469,   469,   469,   469,   173,   -76,    52,   206,
     -76,   469,    61,   -76,    69,   -76,   -76,   355,   362,   380,
     387,   405,   412,   -76,   -76,   -76,   305,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     0,     5,     6,     4,    19,
       0,    18,     0,     0,     0,    10,     0,     1,     0,     3,
       0,     0,    16,     0,     0,     0,     0,     8,     0,     0,
       0,     2,    70,    52,     0,     0,     0,    69,    22,    21,
       0,    17,    11,     0,     0,     7,     9,     0,     0,    26,
      27,     0,    67,    66,    71,     0,     0,     0,     0,     0,
      72,    73,     0,    20,     0,     0,    25,    52,    40,     0,
       0,    31,    37,     0,    30,    32,    39,     0,    38,    46,
      45,     0,     0,     0,    68,    61,    62,    63,    64,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    41,    48,     0,    53,     0,    15,
       0,     0,     0,     0,    35,    36,    54,    43,     0,    44,
       0,     0,     0,     0,     0,     0,    50,    51,     0,     0,
      24,     0,     0,    13,     0,    34,    42,    56,    58,    55,
      57,    60,    59,    49,    47,    33,    14,    23,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
     -76,   -76,    59,   -76,   185,   188,   -66,   -76,   -76,   182,
      66,    38,   -76,   151,   -75,   -76,   -76,   -76,   -76,   -76,
     -76,   -30,   -67,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const signed char yydefgoto[] =
{
      -1,     4,    71,     6,    14,    15,   108,     7,    10,    11,
       8,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    37,    98,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const short int yytable[] =
{
      38,    40,   104,   101,    42,    44,   105,    32,    33,    55,
      56,    57,    58,    59,    52,    53,    54,    17,    82,    20,
      12,    24,     1,    36,    60,     2,   111,     9,    63,     3,
     117,    83,    21,   126,    25,    85,    86,    87,    88,    89,
      67,    13,     1,    82,   132,     2,   134,    82,   113,    99,
      99,    82,    16,   144,   114,   130,    67,    48,   102,     5,
     131,     1,    68,    18,     2,    69,    70,    49,    50,   133,
     109,    19,   109,    48,   131,     3,   116,   118,    68,    12,
     118,    69,    70,   147,    31,    66,   129,    51,   131,    48,
     109,   148,   109,    32,    33,    62,   131,    64,    82,    59,
     137,   138,   139,   140,   141,   142,    22,    23,   115,    36,
      60,   146,   -68,   -68,   -68,   -68,   -68,   -68,   -68,    90,
     -68,   -68,   -68,   -68,   -68,   -68,    27,    28,   -68,   -68,
     -68,   -68,    91,   -68,    92,   -68,   -68,    93,   -68,   -68,
      32,    33,   -61,   -61,    57,    58,    59,   110,   -61,   -61,
     -61,   -61,   -61,   -61,    29,    30,    36,    60,   -61,   -61,
     106,   -61,   112,   -61,   -61,   119,   -61,   -61,    32,    33,
     -62,   -62,    57,    58,    59,   127,   -62,   -62,   -62,   -62,
     -62,   -62,    67,   128,    36,    60,   -62,   -62,   135,   -62,
     136,   -62,   -62,   143,   -62,   -62,    94,    95,    26,    48,
      51,    45,    28,     1,    68,    41,     2,    69,    70,    32,
      33,    55,    56,    57,    58,    59,    46,    32,    33,    55,
      56,    57,    58,    59,   103,    36,    60,    47,    48,     0,
       0,     0,   145,    36,    60,     0,     0,     0,    65,    32,
      33,    55,    56,    57,    58,    59,    32,    33,    34,    35,
      32,    33,    34,    35,     0,    36,    60,     0,     0,     0,
     107,     0,    36,     0,     0,     0,    36,    39,     0,     0,
       0,    43,    32,    33,    55,    56,    57,    58,    59,     0,
     120,   121,   122,   123,   124,   125,     0,     0,    36,    60,
      32,    33,    55,    56,    57,    58,    59,     0,   120,   121,
     122,   123,   124,   125,     0,     0,    36,    84,    32,    33,
      55,    56,    57,    58,    59,    32,    33,    55,    56,    57,
      58,    59,     0,     0,    36,    60,     0,     0,     0,     0,
       0,    36,    84,    32,    33,    55,    56,    57,    58,    59,
      32,    33,    55,    56,    57,    58,    59,     0,     0,    36,
      60,     0,     0,     0,     0,     0,    36,    60,    32,    33,
      55,    56,    57,    58,    59,    32,    33,    55,    56,    57,
      58,    59,     0,     0,    36,    60,     0,     0,     0,     0,
       0,    36,    60,    32,    33,    55,    56,    57,    58,    59,
      32,    33,    55,    56,    57,    58,    59,     0,     0,    36,
      60,     0,     0,     0,     0,     0,    36,    60,    32,    33,
      55,    56,    57,    58,    59,    32,    33,    55,    56,    57,
      58,    59,    32,    33,    36,    60,    57,    58,    59,    32,
      33,    36,    60,    57,    58,    59,    32,    33,    36,    60,
      32,    33,    59,     0,     0,    36,    60,    32,    33,    34,
      35,     0,    36,    60,     0,     0,    36,    60,     0,     0,
       0,    96,     0,    97,    32,    33,    34,    35,    32,    33,
      34,    35,    32,    33,    34,    35,     0,     0,    96,     0,
     100,     0,    96,     0,    36,     0,     0,     0,    36
};

static const short int yycheck[] =
{
      20,    21,    77,    70,    24,    25,    81,     3,     4,     5,
       6,     7,     8,     9,    34,    35,    36,     0,    48,    10,
       4,    10,    25,    19,    20,    28,    92,     4,    24,    32,
      97,    51,    23,   100,    23,    55,    56,    57,    58,    59,
       4,    25,    25,    73,   110,    28,   112,    77,    20,    69,
      70,    81,     4,   128,    26,    22,     4,    21,    22,     0,
      27,    25,    26,     4,    28,    29,    30,    29,    30,    22,
      90,     5,    92,    21,    27,    32,    96,    97,    26,     4,
     100,    29,    30,    22,    18,    47,   106,    23,    27,    21,
     110,    22,   112,     3,     4,    10,    27,    10,   128,     9,
     120,   121,   122,   123,   124,   125,    26,    27,    26,    19,
      20,   131,     3,     4,     5,     6,     7,     8,     9,    21,
      11,    12,    13,    14,    15,    16,    26,    27,    19,    20,
      21,    22,    10,    24,    21,    26,    27,    10,    29,    30,
       3,     4,     5,     6,     7,     8,     9,    21,    11,    12,
      13,    14,    15,    16,    19,    20,    19,    20,    21,    22,
      10,    24,    21,    26,    27,    20,    29,    30,     3,     4,
       5,     6,     7,     8,     9,    20,    11,    12,    13,    14,
      15,    16,     4,    31,    19,    20,    21,    22,    26,    24,
      20,    26,    27,    20,    29,    30,    19,    20,    13,    21,
      23,    26,    27,    25,    26,    23,    28,    29,    30,     3,
       4,     5,     6,     7,     8,     9,    28,     3,     4,     5,
       6,     7,     8,     9,    73,    19,    20,    20,    21,    -1,
      -1,    -1,    26,    19,    20,    -1,    -1,    -1,    24,     3,
       4,     5,     6,     7,     8,     9,     3,     4,     5,     6,
       3,     4,     5,     6,    -1,    19,    20,    -1,    -1,    -1,
      24,    -1,    19,    -1,    -1,    -1,    19,    24,    -1,    -1,
      -1,    24,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,     3,     4,
       5,     6,     7,     8,     9,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    19,    20,     3,     4,     5,     6,     7,     8,     9,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    19,    20,     3,     4,
       5,     6,     7,     8,     9,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    19,    20,     3,     4,     5,     6,     7,     8,     9,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    19,    20,     3,     4,
       5,     6,     7,     8,     9,     3,     4,     5,     6,     7,
       8,     9,     3,     4,    19,    20,     7,     8,     9,     3,
       4,    19,    20,     7,     8,     9,     3,     4,    19,    20,
       3,     4,     9,    -1,    -1,    19,    20,     3,     4,     5,
       6,    -1,    19,    20,    -1,    -1,    19,    20,    -1,    -1,
      -1,    17,    -1,    19,     3,     4,     5,     6,     3,     4,
       5,     6,     3,     4,     5,     6,    -1,    -1,    17,    -1,
      19,    -1,    17,    -1,    19,    -1,    -1,    -1,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    25,    28,    32,    34,    35,    36,    40,    43,     4,
      41,    42,     4,    25,    37,    38,     4,     0,    35,    43,
      10,    23,    26,    27,    10,    23,    37,    26,    27,    19,
      20,    43,     3,     4,     5,     6,    19,    54,    56,    24,
      56,    42,    56,    24,    56,    26,    38,    20,    21,    44,
      44,    23,    56,    56,    56,     5,     6,     7,     8,     9,
      20,    56,    10,    24,    10,    24,    44,     4,    26,    29,
      30,    35,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    56,    20,    56,    56,    56,    56,    56,
      21,    10,    21,    10,    19,    20,    17,    19,    55,    56,
      19,    55,    22,    46,    47,    47,    10,    24,    39,    56,
      21,    39,    21,    20,    26,    26,    56,    55,    56,    20,
      11,    12,    13,    14,    15,    16,    55,    20,    31,    56,
      22,    27,    39,    22,    39,    26,    20,    56,    56,    56,
      56,    56,    56,    20,    47,    26,    56,    22,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    33,    34,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    38,    38,    39,    39,    40,    41,    41,    42,
      42,    42,    42,    42,    42,    43,    43,    43,    44,    45,
      45,    46,    46,    47,    47,    47,    47,    47,    47,    47,
      47,    48,    49,    49,    49,    50,    50,    51,    52,    53,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     3,     2,     1,     1,     1,     4,     3,     3,
       1,     3,     8,     7,     3,     1,     3,     3,     1,     1,
       4,     3,     3,     8,     7,     5,     4,     4,     3,     2,
       1,     1,     1,     4,     4,     3,     3,     1,     1,     1,
       1,     2,     4,     3,     3,     1,     1,     4,     2,     4,
       3,     3,     1,     4,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     1,
       1,     2,     2,     2
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     2,     2,     2,     3,     2,     2,     2,
       1,     1,     0,     0,     2,     2,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     4,     4,     4,    11,     0,
       0,    10,     8,     1
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned short int yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
     187,     0,    53,    55,    57,    59,    61,    63,    65,     0,
      67,    69,    71,    73,    75,    77,     0,     0,    79,    81,
      83,    85,     0,    87,     0,    89,    91,     0,    93,    95,
      97,   100,   103,   105,     0,     0,     0,     0,   107,   109,
     111,   113,   115,   117,     0,     0,   119,   122,   125,   127,
       0,   129,     0,   131,   133,     0,   135,   137,   139,   142,
     145,   147,     0,     0,     0,     0,   149,   151,   153,   155,
     157,   159,     0,   205,   161,   164,   167,   169,     0,   171,
       0,   173,   175,     0,   177,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     211,   213,   215,   217,   219,   221,   223,     0,   225,   227,
     229,   231,   233,   235,     0,     0,   237,   239,     0,     0,
       0,     0,     0,     0,     0,    17,    19,    21,    23,    25,
      27,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    33,    35,    37,    39,    41,    43,    45,    47,
       0,   207,     0,     0,     0,     0,     0,     0,     0,    49,
      51,     0,     0,     0,     0,     0,     0,   209,     0,   241,
       0,     0,     0,     0,     0,     0,   245,     0,     0,     0,
       0,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,     0,   247,     0,   249,     0,     0,     0,     0,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
     251,     0,     0,     0,     0,     0,     0,   255,     0,   257,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     1,     3,     0,   259,     0,     0,     0,     9,
      11,     0,   263,     0,     0,     0,   189,   191,     5,     7,
     197,   199,     0,     0,     0,    13,    15,     0,     0,     0,
       0,     0,   193,   195,     0,     0,   201,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,    67,     0,    67,     0,    67,     0,    67,     0,    66,
       0,    66,     0,    66,     0,    66,     0,    71,     0,    71,
       0,    71,     0,    71,     0,    71,     0,    71,     0,    71,
       0,    71,     0,    71,     0,    73,     0,    73,     0,    73,
       0,    73,     0,    73,     0,    73,     0,    73,     0,    73,
       0,    73,     0,    72,     0,    72,     0,    72,     0,    72,
       0,    72,     0,    72,     0,    72,     0,    72,     0,    72,
       0,    72,     0,    72,     0,    72,     0,    72,     0,    72,
       0,    72,     0,    72,     0,    72,     0,    72,     0,    72,
       0,    72,     0,    72,     0,    72,     0,    61,    67,     0,
      61,    67,     0,    67,     0,    67,     0,    67,     0,    67,
       0,    67,     0,    67,     0,    67,     0,    67,     0,    61,
      67,     0,    61,    67,     0,    67,     0,    67,     0,    67,
       0,    67,     0,    67,     0,    67,     0,    67,     0,    62,
      66,     0,    62,    66,     0,    66,     0,    66,     0,    66,
       0,    66,     0,    66,     0,    66,     0,    66,     0,    66,
       0,    62,    66,     0,    62,    66,     0,    66,     0,    66,
       0,    66,     0,    66,     0,    66,     0,    66,     0,    66,
       0,    63,     0,    63,     0,    63,     0,    63,     0,    64,
       0,    64,     0,    64,     0,    64,     0,    65,     0,    65,
       0,    65,     0,    65,     0,    48,     0,    54,     0,    54,
       0,    71,     0,    71,     0,    71,     0,    71,     0,    71,
       0,    71,     0,    71,     0,    71,     0,    71,     0,    71,
       0,    71,     0,    71,     0,    71,     0,    71,     0,    71,
       0,    56,     0,    56,     0,    58,     0,    58,     0,    55,
       0,    55,     0,    57,     0,    57,     0,    60,     0,    60,
       0,    59,     0,    59,     0
};

/* Error token number */
#define YYTERROR 1


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)


YYSTYPE yylval;
YYLTYPE yylloc;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YYDPRINTF(Args)                        \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
  } while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, char *filename)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (filename);
  if (!yyvaluep)
    return;
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, char *filename)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, filename);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YYFPRINTF (stderr, "%s ", Title);                               \
        yy_symbol_print (stderr, Type, Value, Location, filename);        \
        YYFPRINTF (stderr, "\n");                                       \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, size_t yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (struct yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static _Noreturn void
yyFail (yyGLRStack* yystackp, char *filename, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (filename, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static _Noreturn void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, char *filename)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = (yystackp->yysplitPoint == YY_NULLPTR);
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYUSE (filename);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (filename, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;

  switch (yyn)
    {
        case 2:
#line 42 "config/c1.y" /* glr.c:783  */
    {
		debug("CompUnit ::= CompUnit Decl FuncDef\n");
	  }
#line 1136 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 3:
#line 46 "config/c1.y" /* glr.c:783  */
    {
		debug("CompUnit ::= Decl FuncDef\n");
	  }
#line 1144 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 4:
#line 50 "config/c1.y" /* glr.c:783  */
    {
		debug("CompUnit ::= FuncDef\n");
	  }
#line 1152 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 5:
#line 55 "config/c1.y" /* glr.c:783  */
    {
		debug("Decl ::= ConstDecl\n");
	  }
#line 1160 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 6:
#line 60 "config/c1.y" /* glr.c:783  */
    {
		debug("Decl ::= VarDecl\n");
	  }
#line 1168 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 7:
#line 66 "config/c1.y" /* glr.c:783  */
    {
		debug("ConstDecl ::= const int MultiConstDef ;\n");
	  }
#line 1176 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 8:
#line 70 "config/c1.y" /* glr.c:783  */
    {
		newWarning(errfactory, MissingVarType, 
			(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).first_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).first_column, 
			filename);
	  }
#line 1186 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 9:
#line 79 "config/c1.y" /* glr.c:783  */
    {
		debug("MultiConstDecl ::= MultiConstDecl , ConstDef\n");
	  }
#line 1194 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 10:
#line 84 "config/c1.y" /* glr.c:783  */
    {
		debug("MultiConstDecl ::= ConstDef\n");
	  }
#line 1202 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 11:
#line 91 "config/c1.y" /* glr.c:783  */
    {
		debug("ConstDef ::= ID EQ Exp\n");
	  }
#line 1210 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 12:
#line 95 "config/c1.y" /* glr.c:783  */
    {
		debug("ConstDef ::= ID[Exp] EQ {MultiExp}\n");
	  }
#line 1218 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 13:
#line 99 "config/c1.y" /* glr.c:783  */
    {
		debug("ConstDef ::= ID[] EQ {MultiExp}\n");
	  }
#line 1226 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 14:
#line 107 "config/c1.y" /* glr.c:783  */
    {
		debug("MultiExp ::= MultiExp , Exp\n");
	  }
#line 1234 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 15:
#line 111 "config/c1.y" /* glr.c:783  */
    {
		debug("MultiExp ::= Exp\n");
	  }
#line 1242 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 16:
#line 117 "config/c1.y" /* glr.c:783  */
    {
		debug("VarDecl ::= int MultiVar ;\n");
	  }
#line 1250 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 17:
#line 123 "config/c1.y" /* glr.c:783  */
    {
		debug("MultiVar ::= MultiVar , Var\n");
	  }
#line 1258 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 18:
#line 127 "config/c1.y" /* glr.c:783  */
    {
		debug("MultiVar ::= Var\n");
	  }
#line 1266 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 19:
#line 133 "config/c1.y" /* glr.c:783  */
    {
		debug("Var ::= ID\n");
	  }
#line 1274 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 20:
#line 137 "config/c1.y" /* glr.c:783  */
    {
		debug("Var ::= ID[Exp]\n");
	  }
#line 1282 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 21:
#line 141 "config/c1.y" /* glr.c:783  */
    {
		debug("Var ::= ID[]\n");
	  }
#line 1290 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 22:
#line 145 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= LVal EQ Exp\n");
	  }
#line 1298 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 23:
#line 149 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= LVal[exp] EQ { MultiExp }\n");
	  }
#line 1306 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 24:
#line 153 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= LVal[] EQ { MultiExp }\n");
	  }
#line 1314 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 25:
#line 160 "config/c1.y" /* glr.c:783  */
    {
		debug("FuncDef ::= void ID() Block\n");
	  }
#line 1322 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 26:
#line 164 "config/c1.y" /* glr.c:783  */
    {
		debug("FuncDef  ::= void ID( Block\n");
		newError(errfactory, MissingRParen,
			(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).last_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).last_column, 
			filename);
	  }
#line 1333 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 27:
#line 171 "config/c1.y" /* glr.c:783  */
    {
		debug("FuncDef  ::= void ID) Block\n");
		newError(errfactory, MissingLParen,
			(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yyloc).last_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yyloc).last_column, 
			filename);
	  }
#line 1344 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 28:
#line 180 "config/c1.y" /* glr.c:783  */
    {
		debug("Block ::= { MultiBlockItem }\n");
	  }
#line 1352 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 29:
#line 187 "config/c1.y" /* glr.c:783  */
    {
		debug("BlockItem ::= MultiBlockItem BlockItem\n");
	  }
#line 1360 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 30:
#line 191 "config/c1.y" /* glr.c:783  */
    {
		debug("Block ::= BlockItem\n");
	  }
#line 1368 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 31:
#line 197 "config/c1.y" /* glr.c:783  */
    {
		debug("BlockItem ::= Decl \n");
	  }
#line 1376 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 32:
#line 201 "config/c1.y" /* glr.c:783  */
    {
		debug("BlockItem ::= Stmt\n");
	  }
#line 1384 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 33:
#line 208 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= LVal EQ Exp ;\n");
	  }
#line 1392 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 34:
#line 212 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= ID() ;\n");
	  }
#line 1400 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 35:
#line 216 "config/c1.y" /* glr.c:783  */
    {
		debug ("Stmt ::= ID(\n");
		newError(errfactory, MissingRParen, 
			(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).first_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).first_column,
			filename);	
	  }
#line 1411 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 36:
#line 223 "config/c1.y" /* glr.c:783  */
    {
		debug ("Stmt ::= ID)\n");
		newError(errfactory, MissingLParen, 
			(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).first_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).first_column,
			filename);	
	  }
#line 1422 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 37:
#line 230 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= Block\n");
	  }
#line 1430 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 38:
#line 234 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= IFStmt\n");
	  }
#line 1438 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 39:
#line 238 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= WHILEStmt\n");
	  }
#line 1446 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 40:
#line 242 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= ;\n");
	  }
#line 1454 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 41:
#line 248 "config/c1.y" /* glr.c:783  */
    {
		debug("Stmt ::= WHILECOND Stmt\n");
	  }
#line 1462 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 42:
#line 254 "config/c1.y" /* glr.c:783  */
    {
		debug("WHILECOND ::= while(Cond)\n");	
	  }
#line 1470 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 43:
#line 258 "config/c1.y" /* glr.c:783  */
    {
		debug ("WHILECOND ::= while(cond\n");
		newError(errfactory, MissingRParen, 
			(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).last_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).last_column, 
			filename);
	  }
#line 1481 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 44:
#line 265 "config/c1.y" /* glr.c:783  */
    {
		debug ("WHILECOND ::= while Cond)\n");
		newError(errfactory, MissingLParen, 
			(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yyloc).last_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yyloc).last_column,
			filename);
	  }
#line 1492 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 45:
#line 274 "config/c1.y" /* glr.c:783  */
    {
		debug("IFStmt ::= UnMatched\n");
	  }
#line 1500 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 46:
#line 278 "config/c1.y" /* glr.c:783  */
    {
		debug("IFStmt ::= Matched\n");
	  }
#line 1508 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 47:
#line 284 "config/c1.y" /* glr.c:783  */
    {
		debug("Matched ::= IFCOND Stmt ELSE Stmt\n");
	  }
#line 1516 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 48:
#line 291 "config/c1.y" /* glr.c:783  */
    {
		debug("UnMatched ::= IFCOND Cond Stmt\n");	
	  }
#line 1524 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 49:
#line 298 "config/c1.y" /* glr.c:783  */
    {
		debug("IFCOND ::= IF (Cond)\n");
	  }
#line 1532 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 50:
#line 302 "config/c1.y" /* glr.c:783  */
    {
		debug("IFCOND ::= IF (Cond\n");
		newError(errfactory, MissingRParen, 
			(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).last_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).last_column, 
			filename);	
	  }
#line 1543 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 51:
#line 309 "config/c1.y" /* glr.c:783  */
    {
		debug("IFCOND ::= IF Cond)\n");
		newError(errfactory, MissingLParen, 
			(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).first_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).first_column, 
			filename);	
	  }
#line 1554 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 52:
#line 318 "config/c1.y" /* glr.c:783  */
    {
	  	debug("LVal ::= ID\n");
	  }
#line 1562 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 53:
#line 322 "config/c1.y" /* glr.c:783  */
    {
	  	debug("LVal ::= ID[Exp]\n");
	  }
#line 1570 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 54:
#line 328 "config/c1.y" /* glr.c:783  */
    {
		debug("Cond ::= ! exp \n"); 	
	  }
#line 1578 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 55:
#line 332 "config/c1.y" /* glr.c:783  */
    {
		debug("Cond ::= exp < exp\n");
	  }
#line 1586 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 56:
#line 336 "config/c1.y" /* glr.c:783  */
    {
		debug("Cond ::= exp == exp\n");
	  }
#line 1594 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 57:
#line 340 "config/c1.y" /* glr.c:783  */
    {
		debug("Cond ::= exp <= exp\n");
	  }
#line 1602 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 58:
#line 344 "config/c1.y" /* glr.c:783  */
    {
		debug("Cond ::= exp > exp\n");
	  }
#line 1610 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 59:
#line 348 "config/c1.y" /* glr.c:783  */
    {
		debug("Cond ::= exp >= exp\n");
	  }
#line 1618 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 60:
#line 352 "config/c1.y" /* glr.c:783  */
    {
		debug("Cond ::= exp != exp\n");
	  }
#line 1626 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 61:
#line 360 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= exp PLUS exp\n");
	  }
#line 1634 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 62:
#line 364 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= exp MINUS exp\n");
	  }
#line 1642 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 63:
#line 368 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= exp MULT exp\n");
	  }
#line 1650 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 64:
#line 372 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= exp DIV exp\n");
	  }
#line 1658 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 65:
#line 376 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= exp MOD exp\n");
	   }
#line 1666 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 66:
#line 380 "config/c1.y" /* glr.c:783  */
    {
	  	debug("exp ::= MINUS exp\n");
	  }
#line 1674 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 67:
#line 384 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= PLUS exp\n");
	  }
#line 1682 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 68:
#line 388 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= ( exp )\n");
	  }
#line 1690 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 69:
#line 392 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= LVal\n");
	  }
#line 1698 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 70:
#line 397 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= NUMBER\n");
	  }
#line 1706 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 71:
#line 401 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= ( exp \n");
		newError(errfactory, MissingRParen, 
			(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).last_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).last_column + 1, 
			filename);
						
	  }
#line 1718 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 72:
#line 409 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= exp )\n");
		newError(errfactory, MissingLParen, 
			(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).first_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc).first_column,
			 filename);
	  }
#line 1729 "src/c1.tab.c" /* glr.c:783  */
    break;

  case 73:
#line 416 "config/c1.y" /* glr.c:783  */
    {
		debug("exp ::= exp exp\n");
		newError(errfactory, MissingOp,
			(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).first_line, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc).first_column, 
			filename);	
	  }
#line 1740 "src/c1.tab.c" /* glr.c:783  */
    break;


#line 1744 "src/c1.tab.c" /* glr.c:783  */
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, char *filename)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (filename);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, char *filename)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval, &yys->yyloc, filename);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YYFPRINTF (stderr, "%s unresolved", yymsg);
          else
            YYFPRINTF (stderr, "%s incomplete", yymsg);
          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, filename);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) \
  0

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
                int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default (yypact[yystate])
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YYASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yynewSize;
  size_t yyn;
  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            {
              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
            }
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            {
              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
                          (unsigned long int) yyi, (unsigned long int) yyj));
            }
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
            size_t yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
                 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YYASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print Args;               \
} while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
                 yyRuleNum yyrule, char *filename)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
             (unsigned long int) yyk, yyrule - 1,
             (unsigned long int) yyrline[yyrule]);
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval
                       , &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , filename);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YYFPRINTF (stderr, " (unresolved)");
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, char *filename)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((1, yyrhs, yyk, yyrule, filename));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp, yylocp, filename);
    }
  else
    {
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((0, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule, filename));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, filename);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
             yybool yyforceEval, char *filename)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval, &yyloc, filename);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        {
          YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
                     (unsigned long int) yyk, yyrule - 1));
        }
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval, &yyloc);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
                  "Reduced stack %lu by rule #%d; action deferred.  "
                  "Now in state %d.\n",
                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
                                (unsigned long int) yyk,
                                (unsigned long int) yyi));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = YY_NULLPTR;

      if (yystackp->yytops.yycapacity
          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
                                  (yystackp->yytops.yycapacity
                                   * sizeof yynewStates[0]));
      if (yynewStates == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                             (yystackp->yytops.yycapacity
                              * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp, char *filename);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, char *filename)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, filename));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, filename));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, char *filename)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, filename);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, filename);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, filename);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
               (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]));
          else
            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]),
                       (unsigned long int) (yystates[yyi-1]->yyposn + 1),
                       (unsigned long int) yystates[yyi]->yyposn);
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, char *filename)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (filename, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState* yys1, int yyn1,
                    yyGLRStack *yystackp, char *filename)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, filename);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YYASSERT (yyoption != YY_NULLPTR);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (yynrhs > 0)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, filename);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          {
            int yychar_current = yychar;
            YYSTYPE yylval_current = yylval;
            YYLTYPE yylloc_current = yylloc;
            yychar = yyoption->yyrawchar;
            yylval = yyoption->yyval;
            yylloc = yyoption->yyloc;
            YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
            yychar = yychar_current;
            yylval = yylval_current;
            yylloc = yylloc_current;
          }
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, char *filename)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, filename);
              return yyreportAmbiguity (yybest, yyp, filename);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, filename);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other, &yydummy, filename);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval, yylocp, filename);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, filename);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, char *filename)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , filename));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                   size_t yyposn, char *filename)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
                  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], filename);
          if (yyflag == yyerr)
            {
              YYDPRINTF ((stderr,
                          "Stack %lu dies "
                          "(predicate failure or explicit user error).\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken;
          int yyaction;
          const short int* yyconflicts;

          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
          if (yychar == YYEMPTY)
            {
              YYDPRINTF ((stderr, "Reading a token: "));
              yychar = yylex ();
            }

          if (yychar <= YYEOF)
            {
              yychar = yytoken = YYEOF;
              YYDPRINTF ((stderr, "Now at end of input.\n"));
            }
          else
            {
              yytoken = YYTRANSLATE (yychar);
              YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
            }

          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              size_t yynewStack = yysplitStack (yystackp, yyk);
              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
                          (unsigned long int) yynewStack,
                          (unsigned long int) yyk));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], filename);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, filename));
              else if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr, "Stack %lu dies.\n",
                              (unsigned long int) yynewStack));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], filename);
              if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr,
                              "Stack %lu dies "
                              "(predicate failure or explicit user error).\n",
                              (unsigned long int) yyk));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp, char *filename)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (filename, YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  size_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
  size_t yysize = yysize0;
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected").  */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;
          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytokenName (yyx);
                {
                  size_t yysz = yysize + yytnamerr (YY_NULLPTR, yytokenName (yyx));
                  yysize_overflow |= yysz < yysize;
                  yysize = yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    size_t yysz = yysize + strlen (yyformat);
    yysize_overflow |= yysz < yysize;
    yysize = yysz;
  }

  if (!yysize_overflow)
    yymsg = (char *) YYMALLOC (yysize);

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              yyp++;
              yyformat++;
            }
        }
      yyerror (filename, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (filename, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, char *filename)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        if (yychar == YYEOF)
          yyFail (yystackp, filename, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, filename);
          }
        YYDPRINTF ((stderr, "Reading a token: "));
        yychar = yylex ();
        if (yychar <= YYEOF)
          {
            yychar = yytoken = YYEOF;
            YYDPRINTF ((stderr, "Now at end of input.\n"));
          }
        else
          {
            yytoken = YYTRANSLATE (yychar);
            YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
          }
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, filename, YY_NULLPTR);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yytable[yyj],
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, filename);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, filename, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (char *filename)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyRuleNum yyrule;
          int yyaction;
          const short int* yyconflicts;

          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
               yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, filename);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, filename));
            }
          else
            {
              yySymbol yytoken;
              if (yychar == YYEMPTY)
                {
                  YYDPRINTF ((stderr, "Reading a token: "));
                  yychar = yylex ();
                }

              if (yychar <= YYEOF)
                {
                  yychar = yytoken = YYEOF;
                  YYDPRINTF ((stderr, "Now at end of input.\n"));
                }
              else
                {
                  yytoken = YYTRANSLATE (yychar);
                  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
                }

              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
               yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, filename);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, filename));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          size_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, filename));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, filename, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, filename));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
           yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, filename);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              int yyaction;
              const short int* yyconflicts;
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
                          (unsigned long int) yys,
                          yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, filename));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, filename);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (filename, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, filename);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          size_t yysize = yystack.yytops.yysize;
          size_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                 yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                  if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, filename);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)                                                         \
    ((YYX) == YY_NULLPTR ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
        {
          YYASSERT (yyp->yystate.yyisState);
          YYASSERT (yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
                     (unsigned long int) yyp->yystate.yyposn,
                     (long int) YYINDEX (yyp->yystate.yypred));
          if (! yyp->yystate.yyresolved)
            YYFPRINTF (stderr, ", firstVal: %ld",
                       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
        }
      else
        {
          YYASSERT (!yyp->yystate.yyisState);
          YYASSERT (!yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                     yyp->yyoption.yyrule - 1,
                     (long int) YYINDEX (yyp->yyoption.yystate),
                     (long int) YYINDEX (yyp->yyoption.yynext));
        }
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc



#line 424 "config/c1.y" /* glr.c:2551  */


void yyerror(char *message)
{
	printf("%s\n",message);
}

void usage()
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
	
	/* // this is prepare for p5
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
