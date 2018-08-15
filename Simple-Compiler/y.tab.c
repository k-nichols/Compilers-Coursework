/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "lab9.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "AST.h"
#include "symtable.h"

#define max(x,y) ((x) > (y) ? (x) : (y))

int mydebug;
int lineNum;
static int level = 0;
static int offset = 0;
static int globalOffset = 0;
static int maxOffset = 0;

void yyerror (char *s)  /* Called by yyparse on error */
{
  printf ("YACC Parse Error: %s on line number %d\n", s, lineNum);
}


/* Line 371 of yacc.c  */
#line 92 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     INT = 259,
     VOID = 260,
     IF = 261,
     ELSE = 262,
     WHILE = 263,
     RETURN = 264,
     READ = 265,
     WRITE = 266,
     LE = 267,
     GE = 268,
     EQ = 269,
     NE = 270,
     STRING = 271,
     ID = 272,
     UMINUS = 273
   };
#endif
/* Tokens.  */
#define NUM 258
#define INT 259
#define VOID 260
#define IF 261
#define ELSE 262
#define WHILE 263
#define RETURN 264
#define READ 265
#define WRITE 266
#define LE 267
#define GE 268
#define EQ 269
#define NE 270
#define STRING 271
#define ID 272
#define UMINUS 273



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 27 "lab9.y"

	int value;
	char *string;
	ASTnode *node;
	enum OPERATORS operator;


/* Line 387 of yacc.c  */
#line 179 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 207 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    24,    19,     2,
      29,    30,    22,    20,    31,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
      35,    34,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,    18,    33,     2,     2,     2,     2,
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
      15,    16,    17,    25
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    25,
      27,    29,    30,    31,    40,    42,    44,    46,    50,    53,
      58,    59,    65,    66,    69,    70,    73,    75,    77,    79,
      81,    83,    85,    87,    89,    91,    94,    98,   104,   112,
     118,   121,   125,   129,   133,   137,   139,   141,   146,   148,
     152,   154,   156,   158,   160,   162,   164,   166,   170,   172,
     174,   176,   180,   182,   184,   188,   190,   192,   194,   199,
     200,   202,   204
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    40,    -1,    40,    39,    -1,
      41,    -1,    43,    -1,    42,    17,    26,    -1,    42,    17,
      27,     3,    28,    26,    -1,     4,    -1,     5,    -1,    -1,
      -1,    42,    17,    29,    44,    46,    45,    30,    49,    -1,
       5,    -1,    47,    -1,    48,    -1,    48,    31,    47,    -1,
      42,    17,    -1,    42,    17,    27,    28,    -1,    -1,    32,
      50,    51,    52,    33,    -1,    -1,    41,    51,    -1,    -1,
      53,    52,    -1,    49,    -1,    54,    -1,    55,    -1,    56,
      -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,    26,
      -1,    61,    26,    -1,    62,    34,    54,    -1,     6,    29,
      61,    30,    53,    -1,     6,    29,    61,    30,    53,     7,
      53,    -1,     8,    29,    61,    30,    53,    -1,     9,    26,
      -1,     9,    61,    26,    -1,    10,    62,    26,    -1,    11,
      61,    26,    -1,    11,    16,    26,    -1,    63,    -1,    17,
      -1,    17,    27,    61,    28,    -1,    65,    -1,    63,    64,
      65,    -1,    12,    -1,    35,    -1,    36,    -1,    13,    -1,
      14,    -1,    15,    -1,    67,    -1,    65,    66,    67,    -1,
      20,    -1,    21,    -1,    69,    -1,    67,    68,    69,    -1,
      22,    -1,    23,    -1,    29,    61,    30,    -1,     3,    -1,
      62,    -1,    70,    -1,    17,    29,    71,    30,    -1,    -1,
      72,    -1,    61,    -1,    61,    31,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    51,    52,    58,    59,    62,    81,   103,
     104,   107,   122,   107,   144,   145,   148,   149,   155,   167,
     181,   181,   195,   196,   202,   203,   209,   210,   211,   212,
     213,   214,   215,   216,   219,   220,   230,   243,   249,   257,
     264,   265,   271,   277,   281,   288,   291,   316,   344,   345,
     364,   365,   366,   367,   368,   369,   372,   373,   392,   393,
     396,   397,   416,   417,   420,   421,   426,   427,   430,   465,
     466,   469,   478
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "INT", "VOID", "IF", "ELSE",
  "WHILE", "RETURN", "READ", "WRITE", "LE", "GE", "EQ", "NE", "STRING",
  "ID", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "';'",
  "'['", "']'", "'('", "')'", "','", "'{'", "'}'", "'='", "'<'", "'>'",
  "$accept", "program", "decls", "dec", "vardec", "typespec", "functdec",
  "$@1", "$@2", "params", "paramls", "param", "cmpdstmt", "$@3", "lcdecs",
  "stmtls", "stmt", "exprstmt", "asgnstmt", "selecstmt", "itrstmt",
  "rtrnstmt", "readstmt", "writestmt", "expr", "var", "simplexpr", "relop",
  "addexpr", "addop", "term", "multop", "factor", "functcall", "args",
  "argls", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   124,    38,
      43,    45,    42,    47,    37,   273,    59,    91,    93,    40,
      41,    44,   123,   125,    61,    60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    44,    45,    43,    46,    46,    47,    47,    48,    48,
      50,    49,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    56,    56,    57,
      58,    58,    59,    60,    60,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    71,
      71,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     1,
       1,     0,     0,     8,     1,     1,     1,     3,     2,     4,
       0,     5,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     5,     7,     5,
       2,     3,     3,     3,     3,     1,     1,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     4,     0,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     0,     2,     3,     5,     0,     6,     1,
       4,     0,     7,     0,    11,     0,     0,     0,    10,     0,
      12,    15,    16,     8,    18,     0,     0,     0,     0,    17,
      19,    20,    13,    22,    22,     0,    24,    23,     0,    65,
       0,     0,     0,     0,     0,    46,    34,     0,    26,     0,
      24,    27,    28,    29,    30,    31,    32,    33,     0,    66,
      45,    48,    56,    60,    67,     0,     0,    40,     0,    66,
      46,     0,     0,     0,     0,    69,     0,    21,    25,    35,
       0,    50,    53,    54,    55,    51,    52,     0,    58,    59,
       0,    62,    63,     0,     0,     0,    41,    42,    44,    43,
       0,    71,     0,    70,    64,    36,    49,    57,    61,     0,
       0,    47,     0,    68,    37,    39,    72,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    16,    25,    20,
      21,    22,    48,    33,    36,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    69,    60,    87,    61,    90,
      62,    93,    63,    64,   102,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int8 yypact[] =
{
      17,   -67,   -67,     5,   -67,    17,   -67,    -7,   -67,   -67,
     -67,   -18,   -67,    25,   -67,     4,    55,    14,    26,    30,
     -67,   -67,    19,   -67,    50,    42,    17,    51,    46,   -67,
     -67,   -67,   -67,    17,    17,    63,     9,   -67,    35,   -67,
      53,    54,    10,    67,    13,   -25,   -67,    28,   -67,    52,
       9,   -67,   -67,   -67,   -67,   -67,   -67,   -67,    60,    56,
      40,    43,    45,   -67,   -67,    28,    28,   -67,    61,   -67,
      62,    65,    66,    68,    28,    28,    58,   -67,   -67,   -67,
      20,   -67,   -67,   -67,   -67,   -67,   -67,    28,   -67,   -67,
      28,   -67,   -67,    28,    69,    70,   -67,   -67,   -67,   -67,
      73,    64,    72,   -67,   -67,   -67,    43,    45,   -67,     9,
       9,   -67,    28,   -67,    86,   -67,   -67,     9,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,    91,   -67,    36,    32,   -67,   -67,   -67,   -67,
      71,   -67,    75,   -67,    74,    48,   -66,    24,   -67,   -67,
     -67,   -67,   -67,   -67,   -41,   -36,   -67,   -67,    18,   -67,
      16,   -67,    21,   -67,   -67,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int8 yytable[] =
{
      59,    68,    74,    73,    75,     9,    76,    71,    12,    13,
      11,    14,    39,    39,    59,    40,    39,    41,    42,    43,
      44,     1,     2,    39,    94,    95,    45,    45,    15,    72,
      45,    39,    17,   100,   101,    46,    67,    45,    47,    47,
      23,    31,    47,   114,   115,    45,    46,    24,    19,    47,
      26,   118,    81,    82,    83,    84,   -14,    47,    19,     1,
      18,    12,    13,    88,    89,    35,    35,    91,    92,    34,
      34,   101,    28,    59,    59,    85,    86,    27,    31,    30,
      38,    59,    65,    66,    70,    77,    79,    96,   104,    74,
      80,    97,    98,   117,    99,   112,    10,    29,    78,   109,
     110,   111,   113,    32,   105,   106,   107,   116,    37,     0,
       0,     0,     0,     0,   108
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      36,    42,    27,    44,    29,     0,    47,    43,    26,    27,
      17,    29,     3,     3,    50,     6,     3,     8,     9,    10,
      11,     4,     5,     3,    65,    66,    17,    17,     3,    16,
      17,     3,    28,    74,    75,    26,    26,    17,    29,    29,
      26,    32,    29,   109,   110,    17,    26,    17,    16,    29,
      31,   117,    12,    13,    14,    15,    30,    29,    26,     4,
       5,    26,    27,    20,    21,    33,    34,    22,    23,    33,
      34,   112,    30,   109,   110,    35,    36,    27,    32,    28,
      17,   117,    29,    29,    17,    33,    26,    26,    30,    27,
      34,    26,    26,     7,    26,    31,     5,    26,    50,    30,
      30,    28,    30,    28,    80,    87,    90,   112,    34,    -1,
      -1,    -1,    -1,    -1,    93
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    38,    39,    40,    41,    42,    43,     0,
      39,    17,    26,    27,    29,     3,    44,    28,     5,    42,
      46,    47,    48,    26,    17,    45,    31,    27,    30,    47,
      28,    32,    49,    50,    41,    42,    51,    51,    17,     3,
       6,     8,     9,    10,    11,    17,    26,    29,    49,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    65,    67,    69,    70,    29,    29,    26,    61,    62,
      17,    62,    16,    61,    27,    29,    61,    33,    52,    26,
      34,    12,    13,    14,    15,    35,    36,    64,    20,    21,
      66,    22,    23,    68,    61,    61,    26,    26,    26,    26,
      61,    61,    71,    72,    30,    54,    65,    67,    69,    30,
      30,    28,    31,    30,    53,    53,    72,     7,    53
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 48 "lab9.y"
    { rootNode=(yyvsp[(1) - (1)].node); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 51 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 52 "lab9.y"
    {
                (yyvsp[(1) - (2)].node)->next=(yyvsp[(2) - (2)].node);
                (yyval.node)=(yyvsp[(1) - (2)].node);
            }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 58 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 59 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 62 "lab9.y"
    {
                /* Search for the specified ID at the current level only */
                /* If the variable does not already exist, insert into the symbol table */
                if(Search((yyvsp[(2) - (3)].string), level, 0) == NULL) {
                    (yyval.node)=ASTCreateNode(VARDEC);
                    (yyval.node)->operator=(yyvsp[(1) - (3)].operator); /* int or void */
                    (yyval.node)->isType=(yyvsp[(1) - (3)].operator);    /* set type for comparison */
                    (yyval.node)->name=(yyvsp[(2) - (3)].string);     /* identifier ID */
                    /* Insert into symbol table */
                    (yyval.node)->symbol=Insert((yyvsp[(2) - (3)].string), (yyvsp[(1) - (3)].operator), 0, level, 1, offset, NULL);
                    offset++;     /* offset memory address for next insertion */
                }
                /* Else, throw an error for the ID and the associated error */
                else {
                    yyerror((yyvsp[(2) - (3)].string));
                    yyerror("symbol already in use");
                    exit(1);
                }
            }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 81 "lab9.y"
    {
                /* Search for the specified ID at the current level only */
                /* If the variable does not already exist, insert into the symbol table */
                if(Search((yyvsp[(2) - (6)].string), level, 0) == NULL) {
                    (yyval.node)=ASTCreateNode(VARDEC);
                    (yyval.node)->operator=(yyvsp[(1) - (6)].operator); /* int or void */
                    (yyval.node)->isType=(yyvsp[(1) - (6)].operator);    /* set type for comparison */
                    (yyval.node)->name=(yyvsp[(2) - (6)].string);     /* identifier ID */
                    (yyval.node)->value=(yyvsp[(4) - (6)].value);    /* array dimension NUM */
                    /* Insert into symbol table */
                    (yyval.node)->symbol = Insert((yyvsp[(2) - (6)].string), (yyvsp[(1) - (6)].operator), 2, level, (yyvsp[(4) - (6)].value), offset, NULL);
                    offset += (yyvsp[(4) - (6)].value);    /* offset memory address for next insertion */
                }
                /* Else, throw an error for the ID and the associated error */
                else {
                    yyerror((yyvsp[(2) - (6)].string));
                    yyerror("symbol already in use");
                    exit(1);
                }
            }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 103 "lab9.y"
    { (yyval.operator)=INTTYPE; }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 104 "lab9.y"
    { (yyval.operator)=VOIDTYPE; }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 107 "lab9.y"
    {
                if(Search((yyvsp[(2) - (3)].string), level, 0) == NULL) {
                    Insert((yyvsp[(2) - (3)].string), (yyvsp[(1) - (3)].operator), 1, level, 0, 0, NULL);
                    /* Save current offset as the global offset */
                    globalOffset = offset;
                    /* Set current offset as 0 within the function */
                    offset = 2;
                    maxOffset = offset;
                }
                else {
                    yyerror((yyvsp[(2) - (3)].string));
                    yyerror("function already in use");
                    exit(1);
                }
            }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 122 "lab9.y"
    {
                /* Get function symbol table entry, set fparms to params */
                (Search((yyvsp[(2) - (5)].string), 0, 0))->fparms = (yyvsp[(5) - (5)].node);
            }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 126 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(FUNCTDEC);
                (yyval.node)->operator=(yyvsp[(1) - (8)].operator);/* int or void */
                (yyval.node)->isType=(yyvsp[(1) - (8)].operator);   /* set type for comparison */
                (yyval.node)->name=(yyvsp[(2) - (8)].string);	/* identifier ID */
                (yyval.node)->value=maxOffset; /* set offset */
                (yyval.node)->stmt0=(yyvsp[(5) - (8)].node);	/* function parameters */
                (yyval.node)->stmt1=(yyvsp[(8) - (8)].node);	/* compound stmtements */
                /* Get symbol table entry */
                (yyval.node)->symbol = Search((yyvsp[(2) - (8)].string), 0, 0);
                (yyval.node)->symbol->mySize = maxOffset;
                
                offset -= Delete(1);
                offset = globalOffset;  /* return global offset */
                level = 0;              /* reset level */
            }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 144 "lab9.y"
    { (yyval.node)=NULL; }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 145 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 148 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 149 "lab9.y"
    {
                (yyvsp[(1) - (3)].node)->next=(yyvsp[(3) - (3)].node);
                (yyval.node)=(yyvsp[(1) - (3)].node);
            }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 155 "lab9.y"
    { 
                /* check if appears in the symbol table at one higher level */
                if(Search((yyvsp[(2) - (2)].string), level+1, 0) == NULL) {
                    (yyval.node)=ASTCreateNode(PARAM);
                    (yyval.node)->operator=(yyvsp[(1) - (2)].operator);/* int or void */
                    (yyval.node)->isType=(yyvsp[(1) - (2)].operator);   /* set type for comparison */
                    (yyval.node)->name=(yyvsp[(2) - (2)].string);	/* identifier ID */
                    (yyval.node)->symbol = Insert((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].operator), 0, level+1, 1, offset, NULL);
                    if(mydebug) Display();
                    offset++;    /* offset memory address for next insertion */
                }
            }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 167 "lab9.y"
    {
                /* check if appears in the symbol table at one higher level */
                if(Search((yyvsp[(2) - (4)].string), level+1, 0) == NULL) {
                    (yyval.node)=ASTCreateNode(PARAM);
                    (yyval.node)->operator=(yyvsp[(1) - (4)].operator);/* int or void */
                    (yyval.node)->isType=(yyvsp[(1) - (4)].operator);   /* set type for comparison */
                    (yyval.node)->name=(yyvsp[(2) - (4)].string);	/* identifier ID */
                    (yyval.node)->value=-1;	/* no value */
                    (yyval.node)->symbol = Insert((yyvsp[(2) - (4)].string), (yyvsp[(1) - (4)].operator), 2, level+1, 1, offset, NULL);
                    offset++;    /* offset memory address for next insertion */
                }
            }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 181 "lab9.y"
    { level++; }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 182 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(CMPDSTMT);
                (yyval.node)->stmt0=(yyvsp[(3) - (5)].node);	/* local declarations */
                (yyval.node)->stmt1=(yyvsp[(4) - (5)].node);	/* statement list */
                
                if(mydebug) Display();
                /* Remove all symbols within the level */
                maxOffset = max(offset, maxOffset);
                offset -= Delete(level); /*  */
                level--;    /* back out a level */
            }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 195 "lab9.y"
    { (yyval.node)=NULL; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 196 "lab9.y"
    {
                (yyvsp[(1) - (2)].node)->next=(yyvsp[(2) - (2)].node);
                (yyval.node)=(yyvsp[(1) - (2)].node);
            }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 202 "lab9.y"
    { (yyval.node)=NULL; }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 203 "lab9.y"
    {
                (yyvsp[(1) - (2)].node)->next=(yyvsp[(2) - (2)].node);
                (yyval.node)=(yyvsp[(1) - (2)].node);
            }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 209 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 210 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 211 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 212 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 213 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 214 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 215 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 216 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 219 "lab9.y"
    { (yyval.node)=NULL; }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 220 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(EXPRSTMT);
                (yyval.node)->stmt0=(yyvsp[(1) - (2)].node);	/* expression */
                (yyval.node)->isType=(yyvsp[(1) - (2)].node)->isType;
                (yyval.node)->name=CreateTemp();
                (yyval.node)->symbol=Insert((yyval.node)->name, INTTYPE, 0, level, 1, offset, NULL);
                offset ++;
            }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 230 "lab9.y"
    {
                if(((yyvsp[(1) - (3)].node)->isType != VOIDTYPE) && ((yyvsp[(1) - (3)].node)->isType == (yyvsp[(3) - (3)].node)->isType)) {
                    (yyval.node)=ASTCreateNode(ASGNSTMT);
                    (yyval.node)->stmt0=(yyvsp[(1) - (3)].node);	/* variable */
                    (yyval.node)->stmt1=(yyvsp[(3) - (3)].node);	/* expression statement */
                }
                else {
                    yyerror("type mismatch, assignment cannot be made");
                    exit(1);
                }
            }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 243 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(SELECSTMT);
                (yyval.node)->stmt0=(yyvsp[(3) - (5)].node);	/* expression */
                (yyval.node)->stmt1=(yyvsp[(5) - (5)].node);	/* if statement */
                (yyval.node)->stmt2=NULL;	/* no else statement */
            }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 249 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(SELECSTMT);
                (yyval.node)->stmt0=(yyvsp[(3) - (7)].node);	/* expression */
                (yyval.node)->stmt1=(yyvsp[(5) - (7)].node);	/* if statement */
                (yyval.node)->stmt2=(yyvsp[(7) - (7)].node);	/* else statement */
            }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 257 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(ITRSTMT);
                (yyval.node)->stmt0=(yyvsp[(3) - (5)].node);	/* expression */
                (yyval.node)->stmt1=(yyvsp[(5) - (5)].node);	/* statement */
            }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 264 "lab9.y"
    { (yyval.node)=ASTCreateNode(RTRNSTMT); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 265 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(RTRNSTMT);
                (yyval.node)->stmt0=(yyvsp[(2) - (3)].node);	/* expression */
            }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 271 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(READSTMT);
                (yyval.node)->stmt0=(yyvsp[(2) - (3)].node);	/* variable */
            }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 277 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(WRITESTMT);
                (yyval.node)->stmt0=(yyvsp[(2) - (3)].node);	/* expression */
            }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 281 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(WRITESTMT);
                (yyval.node)->name=(yyvsp[(2) - (3)].string);	/* expression */
                (yyval.node)->label=CreateLabel();
            }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 288 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 291 "lab9.y"
    {
            struct SymbTab *p;
            /* check if appears in the symbol table at current level or lower */
            if((p = Search((yyvsp[(1) - (1)].string), level, 1)) != NULL) {
                (yyval.node)=ASTCreateNode(IDENTIFIER);
                (yyval.node)->name=(yyvsp[(1) - (1)].string);	/* identifier ID */
                
                /* check if the found variable is an array */
                if(p->IsAFunc != 2) {
                    (yyval.node)->symbol=p;
                    (yyval.node)->isType=p->Type;
                }
                else {
                    yyerror((yyvsp[(1) - (1)].string));
                    yyerror("variable is an array");
                    exit(1);
                }
            }
            /* if not found, throw error (variable is undeclared) */
            else {
                yyerror((yyvsp[(1) - (1)].string));
                yyerror("variable is undeclared");
                exit(1);
            }
            }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 316 "lab9.y"
    {
            struct SymbTab *p;
            /* check if appears in the symbol table at current level or lower */
            if((p = Search((yyvsp[(1) - (4)].string), level, 1)) != NULL) {
                (yyval.node)=ASTCreateNode(IDENTIFIER);
                (yyval.node)->name=(yyvsp[(1) - (4)].string);	/* identifier ID */
                (yyval.node)->stmt0=(yyvsp[(3) - (4)].node);	/* expression */
                
                /* check if the found variable is an array */
                if(p->IsAFunc == 2) {
                    (yyval.node)->symbol=p;
                    (yyval.node)->isType=p->Type;
                }
                else {
                    yyerror((yyvsp[(1) - (4)].string));
                    yyerror("type mismatch, variable is not an array");
                    exit(1);
                }
            }
            /* if not found, throw error (variable is undeclared) */
            else {
                yyerror((yyvsp[(1) - (4)].string));
                yyerror("variable is undeclared");
                exit(1);
            }
        }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 344 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 345 "lab9.y"
    {
                if((yyvsp[(1) - (3)].node)->isType == (yyvsp[(3) - (3)].node)->isType) {
                    (yyval.node)=ASTCreateNode(EXPRESSION);
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name, INTTYPE, 0, level, 1, offset, NULL);
                    offset ++;
                    
                    (yyval.node)->stmt0=(yyvsp[(1) - (3)].node);	/* simple expression */
                    (yyval.node)->operator=(yyvsp[(2) - (3)].operator);/* relational operator */
                    (yyval.node)->isType=INTTYPE;
                    (yyval.node)->stmt1=(yyvsp[(3) - (3)].node);	/* additive expression */
                }
                else {
                    yyerror("type mismatch, cannot perform relational operation");
                    exit(1);
                }
            }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 364 "lab9.y"
    { (yyval.operator)=LESSEQ; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 365 "lab9.y"
    { (yyval.operator)=LESSTH; }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 366 "lab9.y"
    { (yyval.operator)=GREATERTH; }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 367 "lab9.y"
    { (yyval.operator)=GREATEREQ; }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 368 "lab9.y"
    { (yyval.operator)=EQUAL; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 369 "lab9.y"
    { (yyval.operator)=NOTEQUAL; }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 372 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 373 "lab9.y"
    {
                if((yyvsp[(1) - (3)].node)->isType == (yyvsp[(3) - (3)].node)->isType) {
                    (yyval.node)=ASTCreateNode(EXPRESSION);
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name, INTTYPE, 0, level, 1, offset, NULL);
                    offset++;
                    
                    (yyval.node)->stmt0=(yyvsp[(1) - (3)].node);	/* additive expression */
                    (yyval.node)->operator=(yyvsp[(2) - (3)].operator);/* '+' or '-' operator */
                    (yyval.node)->isType=INTTYPE;
                    (yyval.node)->stmt1=(yyvsp[(3) - (3)].node);	/* term */
                }
                else {
                    yyerror("type mismatch, cannot perform additive operation");
                    exit(1);
                }
            }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 392 "lab9.y"
    { (yyval.operator)=PLUS; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 393 "lab9.y"
    { (yyval.operator)=MINUS; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 396 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 397 "lab9.y"
    {
                if((yyvsp[(1) - (3)].node)->isType == (yyvsp[(3) - (3)].node)->isType) {
                    (yyval.node)=ASTCreateNode(EXPRESSION);
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name, INTTYPE, 0, level, 1, offset, NULL);
                    offset++;
                    
                    (yyval.node)->stmt0=(yyvsp[(1) - (3)].node);	/* term */
                    (yyval.node)->operator=(yyvsp[(2) - (3)].operator);/* '*' or '/' operator */
                    (yyval.node)->isType=INTTYPE;
                    (yyval.node)->stmt1=(yyvsp[(3) - (3)].node);	/* factor */
                }
                else {
                    yyerror("type mismatch, cannot perform multiplication operation");
                    exit(1);
                }
            }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 416 "lab9.y"
    { (yyval.operator)=MULT; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 417 "lab9.y"
    { (yyval.operator)=DIV; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 420 "lab9.y"
    { (yyval.node)=(yyvsp[(2) - (3)].node); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 421 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(NUMBER);
                (yyval.node)->value=(yyvsp[(1) - (1)].value);	/* expression */
                (yyval.node)->isType=INTTYPE;
            }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 426 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 427 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 430 "lab9.y"
    {
            struct SymbTab *p;
            p=Search((yyvsp[(1) - (4)].string), 0, 0);
            /* If function exists */
            if(p != NULL) {
                /* If call is to a function */
                if(p->IsAFunc == 1) {
                    /* If arguments match required function parameters */
                    if(compareFormal(p->fparms, (yyvsp[(3) - (4)].node))) {
                        (yyval.node)=ASTCreateNode(FUNCTIONCALL);
                        (yyval.node)->name=(yyvsp[(1) - (4)].string);	/* indentifier ID */
                        (yyval.node)->stmt0=(yyvsp[(3) - (4)].node);	/* arguments */
                        (yyval.node)->isType=p->Type;
                        (yyval.node)->symbol=p;
                    }
                    else {
                        yyerror((yyvsp[(1) - (4)].string));
                        yyerror("arguments are not compatible with the function being called");
                        exit(1);
                    }
                }
                else {
                    yyerror((yyvsp[(1) - (4)].string));
                    yyerror("call must be made to a function");
                    exit(1);
                }
            }
            else {
                yyerror((yyvsp[(1) - (4)].string));
                yyerror("function does not exist");
                exit(1);
            }
		}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 465 "lab9.y"
    { (yyval.node)=NULL; }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 466 "lab9.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 469 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(ARGUMENT);
                (yyval.node)->name=CreateTemp();
                (yyval.node)->symbol=Insert((yyval.node)->name, INTTYPE, 0, level, 1, offset, NULL);
                offset++;
                (yyval.node)->next=NULL;
                (yyval.node)->stmt0=(yyvsp[(1) - (1)].node);	/* expression */
                (yyval.node)->isType=(yyvsp[(1) - (1)].node)->isType;
            }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 478 "lab9.y"
    {
                (yyval.node)=ASTCreateNode(ARGUMENT);
                (yyval.node)->name=CreateTemp();
                (yyval.node)->symbol=Insert((yyval.node)->name, INTTYPE, 0, level, 1, offset, NULL);
                offset++;
                (yyval.node)->next=(yyvsp[(3) - (3)].node);    /* argument list */
                (yyval.node)->stmt0=(yyvsp[(1) - (3)].node);	/* expression */
                (yyval.node)->isType=(yyvsp[(1) - (3)].node)->isType;
            }
    break;


/* Line 1792 of yacc.c  */
#line 2236 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 489 "lab9.y"
	/* end of rules, start of program */

main(int argv, char *argc[]) { 
	int i = 1;
	char *nasmFile;
	mydebug = 0;
	
	/* ... -d = debug, ... -o <filename> = output NASM file */
	while(i < argv) {
        if (strcmp(argc[i], "-d") == 0)
            mydebug = 1;
        else if (strcmp(argc[i], "-o") == 0) {
             nasmFile = argc[i + 1];
             i++;
        }
        i++;
    }

	yyparse();
	if(mydebug) fprintf(stderr,"The input has been syntactically checked\n\n");
	emitAST(rootNode, nasmFile);  /* this is where we can do things with the AST like print it or process it */
	if(mydebug) Display();
}
