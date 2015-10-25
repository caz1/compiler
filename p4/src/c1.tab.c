/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "config/c1.y" /* yacc.c:339  */

#include <stdio.h>
#include <math.h>
//#define debug(a) printf("%s", a)
#include <common.h>
//Table symtab;
ASTTree ast;	
int num;
char *ident;
ErrFactory errfactory;

#line 78 "src/c1.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c1.tab.h".  */
#ifndef YY_YY_SRC_C1_TAB_H_INCLUDED
# define YY_YY_SRC_C1_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
#define ODD 272
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 13 "config/c1.y" /* yacc.c:355  */

	char *name;
	int  ival;
	Loc location;

#line 188 "src/c1.tab.c" /* yacc.c:355  */
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
int yyparse (void);

#endif /* !YY_YY_SRC_C1_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "src/c1.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    42,    42,    47,    51,    56,    61,    67,    71,    80,
      86,    93,    97,   101,   109,   113,   119,   127,   131,   137,
     141,   145,   149,   153,   157,   164,   168,   173,   180,   187,
     191,   197,   201,   208,   212,   216,   221,   226,   230,   234,
     238,   244,   248,   254,   258,   263,   270,   274,   279,   287,
     291,   297,   303,   309,   315,   321,   327,   333,   342,   348,
     354,   360,   366,   372,   378,   384,   390,   395,   400,   405
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
  "BlockItem", "Stmt", "IFStmt", "Matched", "UnMatched", "LVal", "Cond",
  "Exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,    64,     3,    74,     2,     0,  -104,  -104,  -104,    -4,
      86,  -104,    -1,    89,   100,  -104,   121,  -104,     0,  -104,
     179,    57,  -104,    64,   179,   118,   117,  -104,    89,   126,
      98,  -104,  -104,    84,   179,   179,   179,  -104,   226,   128,
     125,  -104,   226,   138,   145,  -104,  -104,    98,    62,  -104,
    -104,   179,   234,   234,   231,   179,   179,   179,   179,   179,
    -104,   139,   156,   146,   161,  -104,   116,  -104,   149,   158,
    -104,  -104,    22,  -104,  -104,  -104,  -104,  -104,   162,   150,
    -104,   234,   234,    14,    14,   153,   179,   155,   179,   165,
      33,   163,   175,   179,   175,   167,   194,  -104,  -104,   179,
    -104,    43,   226,   179,    55,   179,   164,  -104,  -104,   168,
     226,    85,   210,    99,   179,   179,   179,   179,   179,   179,
      49,  -104,   179,    58,  -104,    82,  -104,    99,    99,   160,
     166,   226,   226,   226,   226,   226,   226,  -104,   226,  -104,
    -104,  -104,   173,    99,    99,    99,  -104,  -104,  -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     5,     6,     4,    19,
       0,    18,     0,     0,     0,    10,     0,     1,     0,     3,
       0,     0,    16,     0,     0,     0,     0,     8,     0,     0,
       0,     2,    69,    49,     0,     0,     0,    68,    22,    21,
       0,    17,    11,     0,     0,     7,     9,     0,     0,    27,
      26,     0,    64,    63,    66,     0,     0,     0,     0,     0,
      67,     0,    20,     0,     0,    25,    49,    40,     0,     0,
      31,    37,     0,    30,    32,    38,    42,    41,     0,     0,
      65,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,     0,
      50,     0,    15,     0,     0,     0,     0,    35,    36,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     0,    13,     0,    34,     0,     0,    48,
      47,    53,    55,    52,    54,    57,    56,    33,    14,    23,
      12,    39,    46,     0,     0,     0,    45,    44,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,    13,  -104,   180,   183,   -85,  -104,  -104,   172,
      28,   -18,  -104,   124,  -103,  -104,  -104,  -104,   -27,    16,
     -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,    70,     6,    14,    15,   101,     7,    10,    11,
       8,    71,    72,    73,    74,    75,    76,    77,    37,    95,
     102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    40,    17,   104,    42,    44,    20,    12,   129,    24,
     130,    49,    50,     5,    52,    53,    54,    18,   123,    21,
     125,    78,    25,    59,   141,   142,    66,     1,    13,    65,
       2,    79,     3,    19,    60,    81,    82,    83,    84,    85,
     146,   147,   148,    48,    97,    78,    31,     1,    67,    96,
       2,    68,    69,   106,    55,    56,    57,    58,    59,   107,
      32,    33,    34,    35,     1,   121,    66,     2,     9,    60,
     122,     3,    96,   110,   112,   137,    36,   124,    16,   120,
     139,    39,   122,    48,    78,   122,    78,     1,    67,    66,
       2,    68,    69,    12,   131,   132,   133,   134,   135,   136,
      78,    78,   138,    66,   140,   128,    48,    51,   109,   122,
     111,    67,    22,    23,    68,    69,    78,    78,    78,    48,
      48,    32,    33,    34,    35,    67,    27,    28,    68,    69,
      55,    56,    57,    58,    59,    90,    91,    36,    61,    51,
      29,    30,    43,    45,    28,    60,    47,    48,    63,    62,
      55,    56,    57,    58,    59,    55,    56,    57,    58,    59,
      86,    32,    33,    34,    35,    60,    87,    88,    92,    64,
      60,    89,    99,    60,   100,    93,   103,    94,    32,    33,
      34,    35,    32,    33,    34,    35,   105,   113,   127,   108,
     126,   143,    93,    26,    36,    41,    98,   144,    36,    55,
      56,    57,    58,    59,   145,   114,   115,   116,   117,   118,
     119,    46,     0,     0,    60,    55,    56,    57,    58,    59,
       0,   114,   115,   116,   117,   118,   119,     0,     0,     0,
      80,    55,    56,    57,    58,    59,    55,    56,    57,    58,
      59,    57,    58,    59,     0,     0,    60,     0,     0,     0,
       0,    80,     0,     0,    60
};

static const yytype_int16 yycheck[] =
{
      20,    21,     0,    88,    24,    25,    10,     4,   111,    10,
     113,    29,    30,     0,    34,    35,    36,     4,   103,    23,
     105,    48,    23,     9,   127,   128,     4,    25,    25,    47,
      28,    51,    32,     5,    20,    55,    56,    57,    58,    59,
     143,   144,   145,    21,    22,    72,    18,    25,    26,    69,
      28,    29,    30,    20,     5,     6,     7,     8,     9,    26,
       3,     4,     5,     6,    25,    22,     4,    28,     4,    20,
      27,    32,    92,    93,    94,    26,    19,    22,     4,    99,
      22,    24,    27,    21,   111,    27,   113,    25,    26,     4,
      28,    29,    30,     4,   114,   115,   116,   117,   118,   119,
     127,   128,   122,     4,    22,    20,    21,    23,    92,    27,
      94,    26,    26,    27,    29,    30,   143,   144,   145,    21,
      21,     3,     4,     5,     6,    26,    26,    27,    29,    30,
       5,     6,     7,     8,     9,    19,    20,    19,    10,    23,
      19,    20,    24,    26,    27,    20,    20,    21,    10,    24,
       5,     6,     7,     8,     9,     5,     6,     7,     8,     9,
      21,     3,     4,     5,     6,    20,    10,    21,    19,    24,
      20,    10,    10,    20,    24,    17,    21,    19,     3,     4,
       5,     6,     3,     4,     5,     6,    21,    20,    20,    26,
      26,    31,    17,    13,    19,    23,    72,    31,    19,     5,
       6,     7,     8,     9,    31,    11,    12,    13,    14,    15,
      16,    28,    -1,    -1,    20,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      20,     5,     6,     7,     8,     9,     5,     6,     7,     8,
       9,     7,     8,     9,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    28,    32,    34,    35,    36,    40,    43,     4,
      41,    42,     4,    25,    37,    38,     4,     0,    35,    43,
      10,    23,    26,    27,    10,    23,    37,    26,    27,    19,
      20,    43,     3,     4,     5,     6,    19,    51,    53,    24,
      53,    42,    53,    24,    53,    26,    38,    20,    21,    44,
      44,    23,    53,    53,    53,     5,     6,     7,     8,     9,
      20,    10,    24,    10,    24,    44,     4,    26,    29,    30,
      35,    44,    45,    46,    47,    48,    49,    50,    51,    53,
      20,    53,    53,    53,    53,    53,    21,    10,    21,    10,
      19,    20,    19,    17,    19,    52,    53,    22,    46,    10,
      24,    39,    53,    21,    39,    21,    20,    26,    26,    52,
      53,    52,    53,    20,    11,    12,    13,    14,    15,    16,
      53,    22,    27,    39,    22,    39,    26,    20,    20,    47,
      47,    53,    53,    53,    53,    53,    53,    26,    53,    22,
      22,    47,    47,    31,    31,    31,    47,    47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    38,    38,    39,    39,    40,    41,    41,    42,
      42,    42,    42,    42,    42,    43,    43,    43,    44,    45,
      45,    46,    46,    47,    47,    47,    47,    47,    47,    47,
      47,    48,    48,    49,    49,    49,    50,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     1,     4,     3,     3,
       1,     3,     8,     7,     3,     1,     3,     3,     1,     1,
       4,     3,     3,     8,     7,     5,     4,     4,     3,     2,
       1,     1,     1,     4,     4,     3,     3,     1,     1,     5,
       1,     1,     1,     7,     6,     6,     5,     4,     4,     1,
       4,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     2,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


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


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
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
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
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
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 43 "config/c1.y" /* yacc.c:1646  */
    {
		debug("CompUnit ::= CompUnit Decl FuncDef\n");
	  }
#line 1505 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 48 "config/c1.y" /* yacc.c:1646  */
    {
		debug("CompUnit ::= Decl FuncDef\n");
	  }
#line 1513 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 52 "config/c1.y" /* yacc.c:1646  */
    {
		debug("CompUnit ::= FuncDef\n");
	  }
#line 1521 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Decl ::= ConstDecl\n");
	  }
#line 1529 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Decl ::= VarDecl\n");
	  }
#line 1537 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 68 "config/c1.y" /* yacc.c:1646  */
    {
		debug("ConstDecl ::= const int MultiConstDef ;\n");
	  }
#line 1545 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 72 "config/c1.y" /* yacc.c:1646  */
    {
	
	    newError(errfactory, MissingVarType, 
		(yylsp[-2]).last_line, (yylsp[-2]).last_column);
	  }
#line 1555 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 81 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiConstDecl ::= MultiConstDecl , ConstDef\n");
		//$$ = Loc((Loc)@$);
	  }
#line 1564 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 87 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiConstDecl ::= ConstDef\n");
	  }
#line 1572 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 94 "config/c1.y" /* yacc.c:1646  */
    {
		debug("ConstDef ::= ID EQ Exp\n");
	  }
#line 1580 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 98 "config/c1.y" /* yacc.c:1646  */
    {
		debug("ConstDef ::= ID[Exp] EQ {MultiExp}\n");
	  }
#line 1588 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 102 "config/c1.y" /* yacc.c:1646  */
    {
		debug("ConstDef ::= ID[] EQ {MultiExp}\n");
	  }
#line 1596 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 110 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiExp ::= MultiExp , Exp\n");
	  }
#line 1604 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 114 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiExp ::= Exp\n");
	  }
#line 1612 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 120 "config/c1.y" /* yacc.c:1646  */
    {
		debug("VarDecl ::= int Var ;\n");
	  }
#line 1620 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 128 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiVar ::= MultiVar , Var\n");
	  }
#line 1628 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiVar ::= Var\n");
	  }
#line 1636 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 138 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Var ::= ID\n");
	  }
#line 1644 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 142 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Var ::= ID[Exp]\n");
	  }
#line 1652 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Var ::= ID[]\n");
	  }
#line 1660 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= LVal EQ Exp\n");
	  }
#line 1668 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 154 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= LVal[exp] EQ { MultiExp }\n");
	  }
#line 1676 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 158 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= LVal[] EQ { MultiExp }\n");
	  }
#line 1684 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 165 "config/c1.y" /* yacc.c:1646  */
    {
		debug("FuncDef ::= void ID() Block\n");
	  }
#line 1692 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 169 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingLParen,
			(yylsp[-2]).last_line, (yylsp[-2]).last_column);
	  }
#line 1701 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 174 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingRParen,
			(yylsp[-2]).last_line, (yylsp[-2]).last_column);
	  }
#line 1710 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 181 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Block ::= { MultiBlockItem }\n");
	  }
#line 1718 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 188 "config/c1.y" /* yacc.c:1646  */
    {
		debug("BlockItem ::= MultiBlockItem BlockItem\n");
	  }
#line 1726 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 192 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Block ::= BlockItem\n");
	  }
#line 1734 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 198 "config/c1.y" /* yacc.c:1646  */
    {
		debug("BlockItem ::= Decl \n");
	  }
#line 1742 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 202 "config/c1.y" /* yacc.c:1646  */
    {
		debug("BlockItem ::= Stmt\n");
	  }
#line 1750 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 209 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= LVal EQ Exp ;\n");
	  }
#line 1758 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 213 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= ID() ;\n");
	  }
#line 1766 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 217 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingRParen,
			(yylsp[-1]).last_line, (yylsp[-1]).last_column);
	  }
#line 1775 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 222 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingLParen,
			(yylsp[-2]).last_line, (yylsp[-2]).last_column);
	  }
#line 1784 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 227 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= Block\n");
	  }
#line 1792 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 231 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= IFStmt\n");
	  }
#line 1800 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 235 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= while(Cond) Stmt ;\n");
	  }
#line 1808 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 239 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= ;\n");
	  }
#line 1816 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 245 "config/c1.y" /* yacc.c:1646  */
    {
		debug("IFStmt ::= UnMatched\n");
	  }
#line 1824 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 249 "config/c1.y" /* yacc.c:1646  */
    {
		debug("IFStmt ::= Matched\n");
	  }
#line 1832 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 255 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Matched ::= IF Cond Stmt ELSE Stmt\n");
	  }
#line 1840 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 259 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingLParen,
			(yylsp[-5]).last_line, (yylsp[-5]).last_column);
	  }
#line 1849 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 264 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingLParen,
			(yylsp[-3]).last_line, (yylsp[-3]).last_column);
	  }
#line 1858 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 271 "config/c1.y" /* yacc.c:1646  */
    {
		debug("UnMatched ::= IF Cond Stmt\n");	
	  }
#line 1866 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 275 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingLParen,
			(yylsp[-3]).last_line, (yylsp[-3]).last_column);
	  }
#line 1875 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 280 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingLParen,
			(yylsp[-1]).last_line, (yylsp[-1]).last_column);
	  }
#line 1884 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 288 "config/c1.y" /* yacc.c:1646  */
    {
	  	debug("LVal ::= ID\n");
	  }
#line 1892 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 292 "config/c1.y" /* yacc.c:1646  */
    {
	  	debug("LVal ::= ID[Exp]\n");
	  }
#line 1900 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 298 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= ! exp\n");
		//$$ = newCondExp($1, $2, NULL);
		//setLoc($$, (Loc)&(@$));	  	
	  }
#line 1910 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 304 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp < exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1920 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 310 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp == exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1930 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 316 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp <= exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1940 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 322 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp > exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1950 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 328 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp >= exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1960 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 334 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp != exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1970 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 343 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp PLUS exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	   // setLoc($$, (Loc)&(@$));
	  }
#line 1980 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 349 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp MINUS exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	   //setLoc($$, (Loc)&(@$));
	  }
#line 1990 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 355 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp MULT exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	   // setLoc($$, (Loc)&(@$));
	  }
#line 2000 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 361 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp DIV exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	  //  setLoc($$, (Loc)&(@$));
	  }
#line 2010 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 367 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp MOD exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	    //setLoc($$, (Loc)&(@$));
	  }
#line 2020 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 373 "config/c1.y" /* yacc.c:1646  */
    {
	  	debug("exp ::= MINUS exp\n");
	    //$$ = newPrefixExp($1, $2); 
	   // setLoc($$, (Loc)&(@$));
	  }
#line 2030 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 379 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= PLUS exp\n");
	    //$$ = newPrefixExp($1, $2); 
	    //setLoc($$, (Loc)&(@$));
	  }
#line 2040 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 385 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= LPAR exp RPAR\n");
	    //$$ = newParenExp($2);
	   // setLoc($$, (Loc)&(@$));
	  }
#line 2050 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 391 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingRParen, 
			(yylsp[-1]).last_line, (yylsp[-1]).last_column);
	  }
#line 2059 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 396 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingLParen, 
			(yylsp[-1]).last_line, (yylsp[-1]).last_column);
	  }
#line 2068 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 401 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Exp ::= LVal\n");
	  }
#line 2076 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 406 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Exp ::= NUMBER\n");
	  }
#line 2084 "src/c1.tab.c" /* yacc.c:1646  */
    break;


#line 2088 "src/c1.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 411 "config/c1.y" /* yacc.c:1906  */


yyerror(char *message)
{
	printf("%s\n",message);
}




int main(int argc, char *argv[])
{

	//symtab = newTable();
	//ast = newAST();
	printf("Parsing ...\n");
	errfactory = newErrFactory();
	yyparse();
	dumpErrors(errfactory);
	//printf("\n\nDump the program from the generated AST:\n");
	//dumpAST(ast->root);
	//destroyAST(&ast->root);
	//printf("\n\nFinished destroying AST.\n");
	//destroyTable(&symtab);
	//printf("\n\nFinished destroying symbolic table.\n");
	return(0);
}



