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
extern int left_paren;
extern char line[100];

#line 80 "src/c1.tab.c" /* yacc.c:339  */

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
#line 15 "config/c1.y" /* yacc.c:355  */

	char *name;
	int  ival;
	Loc location;

#line 190 "src/c1.tab.c" /* yacc.c:355  */
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

#line 219 "src/c1.tab.c" /* yacc.c:358  */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

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
       0,    44,    44,    49,    53,    58,    63,    69,    73,    81,
      87,    94,    98,   102,   110,   114,   120,   128,   132,   138,
     142,   146,   150,   154,   158,   165,   169,   174,   180,   187,
     191,   197,   201,   208,   212,   216,   234,   238,   242,   246,
     252,   256,   275,   279,   283,   302,   308,   315,   319,   325,
     331,   337,   343,   349,   355,   361,   371,   376,   381,   387,
     393,   399,   405,   411,   417,   422,   426,   443
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
  "BlockItem", "Stmt", "WHILEStmt", "IFStmt", "Matched", "UnMatched",
  "LVal", "Cond", "Exp", YY_NULLPTR
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

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -48

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      50,     8,     4,   193,    11,   -22,   -82,   -82,   -82,    -9,
      17,   -82,    54,    14,    66,   -82,    45,    57,   -82,   -22,
     -82,   151,    82,   -82,     8,   151,   104,    85,   -82,    14,
      31,   -82,   147,   -82,    60,   -82,    90,   151,   151,   160,
     -82,   194,   115,    41,   -82,   194,   135,   129,   -82,   -82,
       5,   -82,     6,    22,   -82,   -82,    69,   -82,   -82,   -82,
     -82,   -82,   -82,   141,    45,   -82,   -82,   151,    95,    95,
      60,   166,   151,   151,   151,   151,   151,   138,   159,   155,
     167,   152,   175,     1,   143,     1,   143,   -82,   -82,   151,
     -82,   134,   -82,    95,    95,   187,   187,   -82,   151,   183,
     151,   184,   -82,   154,   -82,   151,   186,   176,   -82,   188,
     124,   -82,    15,   194,   151,    99,   151,   -82,   194,     1,
     151,   151,   151,   151,   151,   151,     1,   -82,   -82,   151,
     100,   -82,   171,   -82,   194,   194,   194,   194,   194,   194,
     178,   194,   -82,   -82,     1,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     5,     6,     4,    19,
       0,    18,     0,     0,     0,    10,     0,     0,     1,     0,
       3,     0,     0,    16,     0,     0,     0,     0,     8,     0,
       0,    27,     0,     2,     0,    65,    47,     0,     0,     0,
      64,    22,    21,     0,    17,    11,     0,     0,     7,     9,
       0,    39,     0,     0,    31,    36,     0,    30,    32,    38,
      37,    43,    42,     0,     0,    26,    67,     0,    62,    61,
      66,     0,     0,     0,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,     0,
      25,     0,    63,    56,    57,    58,    59,    60,     0,     0,
       0,     0,    35,     0,    41,     0,     0,     0,    44,     0,
       0,    48,     0,    15,     0,     0,     0,    34,    49,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    24,     0,
       0,    13,     0,    40,    51,    53,    50,    52,    55,    54,
      46,    14,    23,    12,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,     9,   -82,   197,   182,   -42,   -82,   -82,   189,
      35,   -13,   -82,   156,   -81,   -82,   -82,   -82,   -82,   -30,
     121,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,    54,     6,    14,    15,   112,     7,    10,    11,
       8,    55,    56,    57,    58,    59,    60,    61,    62,    40,
     106,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    21,   104,    31,   108,    50,    81,    83,    12,     5,
       3,    18,     9,    19,    22,   -47,    41,    43,    12,    65,
      45,    47,    30,    85,    82,    84,    63,    51,    67,    13,
      52,    53,    68,    69,    71,    50,     1,   128,   133,     2,
      20,    86,   129,    23,    24,   140,    72,    73,    74,    75,
      76,    90,    30,    63,    33,    63,     1,    51,   115,     2,
      52,    53,    91,   145,    25,    78,    30,    93,    94,    95,
      96,    97,   130,    50,   132,     1,    32,    26,     2,   107,
      66,   107,     3,    34,   110,    35,    36,    37,    38,    63,
      30,    87,    28,    29,     1,    51,    63,     2,    52,    53,
     118,    39,    74,    75,    76,    34,    42,    35,    36,    37,
      38,    48,    29,    67,    63,   134,   135,   136,   137,   138,
     139,   131,   142,    39,   141,    77,   129,   129,    46,    72,
      73,    74,    75,    76,    72,    73,    74,    75,    76,    72,
      73,    74,    75,    76,    34,    79,    35,    36,    37,    38,
     127,    89,    34,    80,    35,    36,    37,    38,   111,    98,
     105,    70,    39,    35,    36,    37,    38,    64,    30,    99,
      39,    72,    73,    74,    75,    76,   100,   101,   102,    39,
     117,    72,    73,    74,    75,    76,    92,   120,   121,   122,
     123,   124,   125,   143,    16,   103,    76,    17,   129,    72,
      73,    74,    75,    76,   114,   116,   119,   109,   126,   144,
      27,    49,    88,    44
};

static const yytype_uint8 yycheck[] =
{
      30,    10,    83,    16,    85,     4,     1,     1,     4,     0,
      32,     0,     4,     4,    23,    10,    21,    22,     4,    32,
      25,    26,    21,     1,    19,    19,    56,    26,    23,    25,
      29,    30,    37,    38,    39,     4,    25,    22,   119,    28,
       5,    19,    27,    26,    27,   126,     5,     6,     7,     8,
       9,    64,    21,    83,    19,    85,    25,    26,   100,    28,
      29,    30,    67,   144,    10,    24,    21,    72,    73,    74,
      75,    76,   114,     4,   116,    25,    19,    23,    28,    84,
      20,    86,    32,     1,    89,     3,     4,     5,     6,   119,
      21,    22,    26,    27,    25,    26,   126,    28,    29,    30,
     105,    19,     7,     8,     9,     1,    24,     3,     4,     5,
       6,    26,    27,    23,   144,   120,   121,   122,   123,   124,
     125,    22,    22,    19,   129,    10,    27,    27,    24,     5,
       6,     7,     8,     9,     5,     6,     7,     8,     9,     5,
       6,     7,     8,     9,     1,    10,     3,     4,     5,     6,
      26,    10,     1,    24,     3,     4,     5,     6,    24,    21,
      17,     1,    19,     3,     4,     5,     6,    20,    21,    10,
      19,     5,     6,     7,     8,     9,    21,    10,    26,    19,
      26,     5,     6,     7,     8,     9,    20,    11,    12,    13,
      14,    15,    16,    22,     1,    20,     9,     4,    27,     5,
       6,     7,     8,     9,    21,    21,    20,    86,    20,    31,
      13,    29,    56,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    28,    32,    34,    35,    36,    40,    43,     4,
      41,    42,     4,    25,    37,    38,     1,     4,     0,    35,
      43,    10,    23,    26,    27,    10,    23,    37,    26,    27,
      21,    44,    19,    43,     1,     3,     4,     5,     6,    19,
      52,    54,    24,    54,    42,    54,    24,    54,    26,    38,
       4,    26,    29,    30,    35,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    20,    44,    20,    23,    54,    54,
       1,    54,     5,     6,     7,     8,     9,    10,    24,    10,
      24,     1,    19,     1,    19,     1,    19,    22,    46,    10,
      44,    54,    20,    54,    54,    54,    54,    54,    21,    10,
      21,    10,    26,    20,    47,    17,    53,    54,    47,    53,
      54,    24,    39,    54,    21,    39,    21,    26,    54,    20,
      11,    12,    13,    14,    15,    16,    20,    26,    22,    27,
      39,    22,    39,    47,    54,    54,    54,    54,    54,    54,
      47,    54,    22,    22,    31,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    38,    38,    39,    39,    40,    41,    41,    42,
      42,    42,    42,    42,    42,    43,    43,    43,    44,    45,
      45,    46,    46,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    49,    49,    49,    50,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     1,     4,     3,     3,
       1,     3,     8,     7,     3,     1,     3,     3,     1,     1,
       4,     3,     3,     8,     7,     5,     4,     3,     3,     2,
       1,     1,     1,     4,     4,     3,     1,     1,     1,     1,
       5,     3,     1,     1,     3,     7,     5,     1,     4,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     1,     1,     2,     2
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
#line 45 "config/c1.y" /* yacc.c:1646  */
    {
		debug("CompUnit ::= CompUnit Decl FuncDef\n");
	  }
#line 1499 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 50 "config/c1.y" /* yacc.c:1646  */
    {
		debug("CompUnit ::= Decl FuncDef\n");
	  }
#line 1507 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 54 "config/c1.y" /* yacc.c:1646  */
    {
		debug("CompUnit ::= FuncDef\n");
	  }
#line 1515 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Decl ::= ConstDecl\n");
	  }
#line 1523 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 64 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Decl ::= VarDecl\n");
	  }
#line 1531 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 70 "config/c1.y" /* yacc.c:1646  */
    {
		debug("ConstDecl ::= const int MultiConstDef ;\n");
	  }
#line 1539 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 74 "config/c1.y" /* yacc.c:1646  */
    {
		newWarning(errfactory, MissingVarType, 
			(yylsp[-2]).last_line, (yylsp[-2]).last_column, line);
	  }
#line 1548 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiConstDecl ::= MultiConstDecl , ConstDef\n");

	  }
#line 1557 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiConstDecl ::= ConstDef\n");
	  }
#line 1565 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 95 "config/c1.y" /* yacc.c:1646  */
    {
		debug("ConstDef ::= ID EQ Exp\n");
	  }
#line 1573 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 99 "config/c1.y" /* yacc.c:1646  */
    {
		debug("ConstDef ::= ID[Exp] EQ {MultiExp}\n");
	  }
#line 1581 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 103 "config/c1.y" /* yacc.c:1646  */
    {
		debug("ConstDef ::= ID[] EQ {MultiExp}\n");
	  }
#line 1589 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 111 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiExp ::= MultiExp , Exp\n");
	  }
#line 1597 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 115 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiExp ::= Exp\n");
	  }
#line 1605 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 121 "config/c1.y" /* yacc.c:1646  */
    {
		debug("VarDecl ::= int MultiVar ;\n");
	  }
#line 1613 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 129 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiVar ::= MultiVar , Var\n");
	  }
#line 1621 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 133 "config/c1.y" /* yacc.c:1646  */
    {
		debug("MultiVar ::= Var\n");
	  }
#line 1629 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 139 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Var ::= ID\n");
	  }
#line 1637 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 143 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Var ::= ID[Exp]\n");
	  }
#line 1645 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 147 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Var ::= ID[]\n");
	  }
#line 1653 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 151 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= LVal EQ Exp\n");
	  }
#line 1661 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 155 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= LVal[exp] EQ { MultiExp }\n");
	  }
#line 1669 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 159 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= LVal[] EQ { MultiExp }\n");
	  }
#line 1677 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 166 "config/c1.y" /* yacc.c:1646  */
    {
		debug("FuncDef ::= void ID() Block\n");
	  }
#line 1685 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 170 "config/c1.y" /* yacc.c:1646  */
    {
		newError(errfactory, MissingRParen,
			(yylsp[-2]).last_line, (yylsp[-2]).last_column, line);
	  }
#line 1694 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 175 "config/c1.y" /* yacc.c:1646  */
    {
	
	  }
#line 1702 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 181 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Block ::= { MultiBlockItem }\n");
	  }
#line 1710 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 188 "config/c1.y" /* yacc.c:1646  */
    {
		debug("BlockItem ::= MultiBlockItem BlockItem\n");
	  }
#line 1718 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 192 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Block ::= BlockItem\n");
	  }
#line 1726 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 198 "config/c1.y" /* yacc.c:1646  */
    {
		debug("BlockItem ::= Decl \n");
	  }
#line 1734 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 202 "config/c1.y" /* yacc.c:1646  */
    {
		debug("BlockItem ::= Stmt\n");
	  }
#line 1742 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 209 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= LVal EQ Exp ;\n");
	  }
#line 1750 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 213 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= ID() ;\n");
	  }
#line 1758 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 217 "config/c1.y" /* yacc.c:1646  */
    {
		debug ("ID()\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			(yylsp[-1]).last_line, (yylsp[-1]).last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			(yylsp[-1]).first_line, (yylsp[-1]).first_column, line);
			left_paren++;		
		}
		yyerrok;  
	}
#line 1779 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 235 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= Block\n");
	  }
#line 1787 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 239 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= IFStmt\n");
	  }
#line 1795 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 243 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= WHILEStmt\n");
	  }
#line 1803 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 247 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= ;\n");
	  }
#line 1811 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 253 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Stmt ::= while(Cond) Stmt ;\n");
	  }
#line 1819 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 257 "config/c1.y" /* yacc.c:1646  */
    {
		debug ("while\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			(yylsp[-2]).last_line, (yylsp[-2]).last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			(yylsp[-2]).last_line, (yylsp[-2]).last_column, line);
			left_paren++;		
		}
		yyerrok;
	  }
#line 1840 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 276 "config/c1.y" /* yacc.c:1646  */
    {
		debug("IFStmt ::= UnMatched\n");
	  }
#line 1848 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 280 "config/c1.y" /* yacc.c:1646  */
    {
		debug("IFStmt ::= Matched\n");
	  }
#line 1856 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 284 "config/c1.y" /* yacc.c:1646  */
    {
		debug("error\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			(yylsp[-1]).last_line, (yylsp[-1]).last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			(yylsp[-1]).last_line, (yylsp[-1]).last_column, line);
			left_paren++;		
		}
		yyerrok;
	  }
#line 1877 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 303 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Matched ::= IF Cond Stmt ELSE Stmt\n");
	  }
#line 1885 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 309 "config/c1.y" /* yacc.c:1646  */
    {
		debug("UnMatched ::= IF Cond Stmt\n");	
	  }
#line 1893 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 316 "config/c1.y" /* yacc.c:1646  */
    {
	  	debug("LVal ::= ID\n");
	  }
#line 1901 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 320 "config/c1.y" /* yacc.c:1646  */
    {
	  	debug("LVal ::= ID[Exp]\n");
	  }
#line 1909 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 326 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= ! exp\n");
		//$$ = newCondExp($1, $2, NULL);
		//setLoc($$, (Loc)&(@$));	  	
	  }
#line 1919 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 332 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp < exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1929 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 338 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp == exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1939 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 344 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp <= exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1949 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 350 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp > exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1959 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 356 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp >= exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1969 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 362 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Cond ::= exp != exp\n");
		//newCondExp($2, $1, $3);
		//setLoc($$, (Loc)&(@$));
	  }
#line 1979 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 372 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp PLUS exp\n");
	   // setLoc($$, (Loc)&(@$));
	  }
#line 1988 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 377 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp MINUS exp\n");
	   //setLoc($$, (Loc)&(@$));
	  }
#line 1997 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 382 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp MULT exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	   // setLoc($$, (Loc)&(@$));
	  }
#line 2007 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 388 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp DIV exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	  //  setLoc($$, (Loc)&(@$));
	  }
#line 2017 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 394 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= exp MOD exp\n");
	    //$$ = newInfixExp($2, $1, $3); 
	    //setLoc($$, (Loc)&(@$));
	  }
#line 2027 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 400 "config/c1.y" /* yacc.c:1646  */
    {
	  	debug("exp ::= MINUS exp\n");
	    //$$ = newPrefixExp($1, $2); 
	   // setLoc($$, (Loc)&(@$));
	  }
#line 2037 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 406 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= PLUS exp\n");
	    //$$ = newPrefixExp($1, $2); 
	    //setLoc($$, (Loc)&(@$));
	  }
#line 2047 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 412 "config/c1.y" /* yacc.c:1646  */
    {
		debug("exp ::= LPAR exp RPAR\n");
	    //$$ = newParenExp($2);
	   // setLoc($$, (Loc)&(@$));
	  }
#line 2057 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 418 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Exp ::= LVal\n");
	  }
#line 2065 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 423 "config/c1.y" /* yacc.c:1646  */
    {
		debug("Exp ::= NUMBER\n");
	  }
#line 2073 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 427 "config/c1.y" /* yacc.c:1646  */
    {
		debug("(err\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			(yylsp[0]).last_line, (yylsp[0]).last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			(yylsp[0]).last_line, (yylsp[0]).last_column, line);
			left_paren++;		
		}
		yyerrok;
	  }
#line 2094 "src/c1.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 444 "config/c1.y" /* yacc.c:1646  */
    {
		debug("err)\n");
		if (left_paren > 0)
		{
			newError(errfactory, MissingRParen, 
			(yylsp[-1]).last_line, (yylsp[-1]).last_column, line);
			left_paren--;
		}		
		else if (left_paren < 0)
		{	
			newError(errfactory, MissingLParen,
			(yylsp[-1]).first_line, (yylsp[-1]).first_column, line);
			left_paren++;		
		}
		yyerrok;
	  }
#line 2115 "src/c1.tab.c" /* yacc.c:1646  */
    break;


#line 2119 "src/c1.tab.c" /* yacc.c:1646  */
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
#line 460 "config/c1.y" /* yacc.c:1906  */


void yyerror(char *message)
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
	dumpWarnings(errfactory);	
	//destroyTable(&symtab);
	//printf("\n\nFinished destroying symbolic table.\n");
	return(0);
}



