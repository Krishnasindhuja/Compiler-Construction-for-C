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
#line 7 "gram.y" /* yacc.c:339  */


#include "defs.h"
#include "types.h"
#include "symtab.h"
#include "bucket.h"
#include "tree.h"
#include "message.h"

    int yylex();
    int yyerror(char *s);
    BOOLEAN found_ref_param = FALSE;


#line 81 "gram.tab.c" /* yacc.c:339  */

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
    IDENTIFIER = 258,
    STRING_LITERAL = 259,
    SIZEOF = 260,
    INT_CONSTANT = 261,
    DOUBLE_CONSTANT = 262,
    PTR_OP = 263,
    INC_OP = 264,
    DEC_OP = 265,
    LEFT_OP = 266,
    RIGHT_OP = 267,
    LE_OP = 268,
    GE_OP = 269,
    EQ_OP = 270,
    NE_OP = 271,
    AND_OP = 272,
    OR_OP = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    ADD_ASSIGN = 277,
    SUB_ASSIGN = 278,
    LEFT_ASSIGN = 279,
    RIGHT_ASSIGN = 280,
    AND_ASSIGN = 281,
    XOR_ASSIGN = 282,
    OR_ASSIGN = 283,
    TYPE_NAME = 284,
    TYPEDEF = 285,
    EXTERN = 286,
    STATIC = 287,
    AUTO = 288,
    REGISTER = 289,
    CHAR = 290,
    SHORT = 291,
    INT = 292,
    LONG = 293,
    SIGNED = 294,
    UNSIGNED = 295,
    FLOAT = 296,
    DOUBLE = 297,
    CONST = 298,
    VOLATILE = 299,
    VOID = 300,
    STRUCT = 301,
    UNION = 302,
    ENUM = 303,
    ELIPSIS = 304,
    CASE = 305,
    DEFAULT = 306,
    IF = 307,
    ELSE = 308,
    SWITCH = 309,
    WHILE = 310,
    DO = 311,
    FOR = 312,
    GOTO = 313,
    CONTINUE = 314,
    BREAK = 315,
    RETURN = 316,
    BAD = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "gram.y" /* yacc.c:355  */

    int	y_int;
    double	y_double;
    char *	y_string;
    ST_ID y_stid;
    TYPE y_type;
    BUCKET_PTR y_bucket;
    TYPE_SPECIFIER y_tpspec;
    MyDeclList y_mydecl_list;
    EXPR y_expr;
    PARAM_LIST y_plist;
    BINOP_TYPE y_binoptr;
    UNOP_TYPE  y_unoptr;
    EXPR_LIST y_expr_list;
    STMT y_stmt;
	

#line 199 "gram.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 214 "gram.tab.c" /* yacc.c:358  */

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  214
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  348

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,     2,     2,    76,    69,     2,
      63,    64,    70,    71,    68,    72,    67,    75,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    84,
      77,    83,    78,    81,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,    80,    86,    73,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    82,    83,    84,    85,    89,    90,    91,
      92,    93,    94,    95,    99,   100,   104,   105,   109,   110,
     111,   112,   113,   114,   118,   119,   120,   121,   122,   123,
     127,   128,   132,   133,   134,   135,   139,   140,   144,   148,
     149,   150,   154,   155,   156,   157,   158,   162,   163,   164,
     168,   169,   173,   174,   178,   179,   183,   184,   188,   189,
     193,   194,   198,   199,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   217,   218,   222,   226,   227,
     235,   236,   240,   241,   242,   243,   254,   255,   259,   260,
     260,   264,   267,   271,   271,   271,   271,   271,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     290,   291,   292,   296,   297,   301,   302,   306,   310,   311,
     314,   316,   319,   320,   324,   325,   326,   330,   331,   332,
     336,   337,   341,   342,   346,   346,   350,   351,   359,   360,
     361,   362,   365,   368,   374,   375,   379,   380,   384,   385,
     392,   396,   397,   401,   402,   406,   407,   408,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   424,   425,   428,
     430,   434,   435,   443,   444,   444,   445,   446,   447,   448,
     452,   453,   454,   458,   459,   460,   461,   461,   473,   474,
     478,   479,   483,   493,   496,   496,   502,   506,   515,   515,
     516,   517,   562,   563,   564,   571,   588,   589,   593,   594,
     598,   598,   599,   599,   607
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL", "SIZEOF",
  "INT_CONSTANT", "DOUBLE_CONSTANT", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "BAD", "'('", "')'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'",
  "'{'", "'}'", "$accept", "primary_expr", "postfix_expr",
  "argument_expr_list_opt", "argument_expr_list", "unary_expr",
  "unary_operator", "cast_expr", "multiplicative_expr", "additive_expr",
  "shift_expr", "relational_expr", "equality_expr", "and_expr",
  "exclusive_or_expr", "inclusive_or_expr", "logical_and_expr",
  "logical_or_expr", "conditional_expr", "assignment_expr",
  "assignment_operator", "expr", "constant_expr", "expr_opt",
  "declaration", "declaration_specifiers", "init_declarator_list", "@1",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "specifier_qualifier_list_opt",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "type_qualifier", "declarator",
  "direct_declarator", "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "comma_opt",
  "initializer_list", "statement", "$@2", "labeled_statement",
  "compound_statement", "$@3", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "@4", "if_action",
  "iteration_statement", "@5", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "@6", "@7", "identifier", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    40,    41,    91,    93,    46,    44,    38,
      42,    43,    45,   126,    33,    47,    37,    60,    62,    94,
     124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -121

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-121)))

#define YYTABLE_NINF -213

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     818,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,     3,   218,  -121,   912,  -121,    96,  1073,  1073,  -121,
       8,  -121,  1073,  -121,    -9,   218,   726,  -121,  -121,  -121,
      17,   -68,   -41,   912,  -121,  -121,   912,  -121,   -39,  -121,
      64,  -121,  -121,   912,   -30,  -121,    13,   980,   296,  -121,
    -121,  -121,   -43,  -121,    23,    17,  -121,  -121,  -121,  -121,
    -121,   524,    13,   659,  -121,   213,   912,   343,  -121,  -121,
     228,   -20,    53,  -121,  -121,   647,  -121,  -121,   668,   668,
     575,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,    62,
    -121,   680,  -121,   -13,    -3,   160,    -4,   207,    44,    47,
      51,   117,    -5,  -121,    82,  -121,    17,  -121,   680,   -37,
     218,   524,   414,  -121,  -121,  -121,  -121,  -121,  -121,   680,
     -31,  -121,    75,   880,   680,    85,    88,    91,   115,   489,
     120,    17,   123,   126,   680,  -121,  -121,   144,   131,  -121,
      96,  -121,    13,  -121,   860,   415,  -121,  -121,  -121,  -121,
     143,   772,   561,  -121,   228,  -121,    95,  -121,  1052,   575,
    -121,   680,  -121,  -121,    36,    38,   164,    17,  -121,  -121,
     680,   680,    17,  -121,   680,   680,   680,   680,   680,   680,
     680,   680,   680,   680,   680,   680,   680,   680,   680,   680,
     680,   680,   680,  -121,  -121,  -121,  -121,  -121,   154,  -121,
     171,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,   680,  -121,   213,  -121,   680,  -121,   175,   489,
     680,   680,   680,   206,   680,   158,  -121,  -121,   178,   680,
    -121,  -121,  -121,  -121,   489,  -121,  -121,   489,  -121,   201,
     204,  -121,   200,  -121,  1016,   596,  -121,  -121,   205,  -121,
     938,    38,  -121,   680,  -121,   208,   203,  -121,   113,  -121,
    -121,  -121,  -121,   -13,   -13,    -3,    -3,   160,   160,   160,
     160,    -4,    -4,   207,    44,    47,    51,   117,   -16,   524,
     184,  -121,  -121,  -121,   489,  -121,    54,    69,    72,   210,
     190,  -121,  -121,  -121,   452,  -121,  -121,  -121,  -121,  -121,
     215,  -121,   214,  -121,  -121,  -121,   680,  -121,   680,  -121,
    -121,  -121,  -121,   489,  -121,   680,   680,  -121,  -121,  -121,
    -121,  -121,   489,  -121,   489,    78,   212,   231,  -121,   223,
     680,  -121,  -121,   221,   489,   489,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   214,   109,    93,    94,    95,    96,    97,    99,   100,
     101,   102,   105,   106,   103,   104,   134,   135,    98,   113,
     114,     0,     0,   145,   120,   209,     0,    82,    84,   107,
       0,   108,    86,   210,   136,     0,     0,   206,   208,   138,
       0,   129,     0,   120,   121,   144,   120,    80,     0,    88,
      91,    83,    85,     0,   112,    87,     0,     0,     0,   137,
       1,   207,     0,   130,   132,     0,   139,   118,   119,    89,
      81,     0,     0,     0,   115,     0,     0,    78,   211,   143,
     151,     0,   146,   148,     5,     0,     3,     4,     0,     0,
       0,   140,    24,    25,    26,    27,    28,    29,     7,    18,
      30,     0,    32,    36,    39,    42,    47,    50,    52,    54,
      56,    58,    60,    77,     0,     2,     0,   127,     0,     0,
       0,     0,    30,    62,   167,    92,   213,   110,   116,     0,
       0,   122,   124,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,    78,   183,    75,    79,     0,   188,
       0,   190,     0,   173,   186,    78,   176,   177,   178,   179,
       2,     0,     0,   150,   155,   152,   156,   142,     0,     0,
      22,     0,    19,    20,     0,   153,     0,     0,    12,    13,
      14,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   131,   133,   128,    90,    91,   171,
     169,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    64,     0,   125,     0,   117,     0,   111,     0,    78,
       0,     0,     0,     0,    78,     0,   203,   204,     0,     0,
     192,   175,   185,   189,    78,   184,   191,    78,   163,     0,
       0,   159,     0,   157,     0,     0,   147,   149,     0,     6,
       0,   155,   154,     0,    11,     0,    15,    16,     0,    10,
      33,    34,    35,    37,    38,    40,    41,    45,    46,    43,
      44,    48,    49,    51,    53,    55,    57,    59,     0,   170,
       0,    63,   123,   126,    78,   182,     0,     0,     0,     0,
       0,   202,   205,    76,    78,   180,   164,   158,   160,   165,
       0,   161,     0,    23,    31,     9,     0,     8,     0,   172,
     168,   181,   197,    78,   198,     0,    78,   187,   166,   162,
      17,    61,    78,   196,    78,     0,     0,   193,   199,     0,
      78,   194,   200,     0,    78,    78,   195,   201
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,  -121,     1,  -121,   -89,    30,    45,
      58,    63,    89,    92,    90,   108,   109,  -121,   -51,   -70,
    -121,   -87,  -102,  -120,   -73,    14,  -121,  -121,   189,  -121,
     187,  -121,  -121,   235,   -54,    15,   -28,  -121,    93,  -121,
     247,   197,   202,    12,  -121,   -52,   -49,  -121,   146,   147,
     -47,  -121,  -119,  -121,  -121,   -91,  -121,  -121,   -67,  -121,
    -121,    71,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
     282,  -121,  -121,  -121,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    98,    99,   265,   266,   122,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   123,   146,
     222,   147,   114,   148,    25,    80,    48,   120,    49,    27,
      28,    29,    30,    73,    74,    75,    45,   130,   131,    31,
      62,    63,    32,    33,    34,    35,   249,    82,    83,   176,
     250,   166,   125,   290,   210,   151,   152,   153,    78,   244,
     154,   155,   156,   157,   344,   332,   158,   334,   159,    36,
      37,    38,    56,    72,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   124,   209,   174,   149,   126,     1,   113,    81,   191,
     192,     1,   183,   201,    26,    67,   205,    65,    68,   128,
       1,    41,    39,    66,   238,   116,    39,   223,   164,    69,
      54,   116,   228,   165,    42,    39,    39,   224,    50,    44,
      64,    51,    52,   117,   167,    70,    55,    59,   233,   206,
      26,   124,   239,   225,    57,    76,    58,   184,    44,   100,
     252,    44,   185,   186,   246,    64,   318,   113,   187,   188,
     177,   178,   179,   193,   194,    39,   202,   160,   113,   128,
      39,   243,   174,   113,   174,   241,   170,   132,    40,   172,
     173,   150,   163,    53,   268,   270,   271,   272,    77,     1,
     259,   260,   100,   162,   239,   175,   118,    23,    24,   164,
     267,   113,   164,   197,   300,   288,    64,   253,   322,   100,
      39,   168,   239,   261,   293,   180,   198,   181,   262,   182,
     100,   199,   208,   323,   200,   100,   324,   239,   295,   160,
     239,   235,   339,   296,   297,   298,   239,    71,   203,  -212,
      39,   230,   291,   312,   231,   160,   305,   226,   254,    22,
     255,    39,   208,   100,    39,    23,    24,   229,   150,   303,
     319,   189,   190,    42,   314,   113,    59,   264,   232,   317,
      47,   239,   269,   234,   175,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   321,   113,   310,   336,   236,   261,   261,
     237,    43,   239,   246,   253,   240,     1,   273,   274,   124,
     343,     1,   195,   196,    39,   247,    46,   100,   263,   160,
      43,     1,   333,    43,   275,   276,   132,    71,   335,   289,
      43,   337,   301,   338,   160,    46,   330,   160,    46,   277,
     278,   279,   280,   346,   347,    46,   100,   294,   281,   282,
      43,   299,   302,    43,   100,   306,   308,   331,   307,   313,
     320,   316,   315,   325,   326,    46,    22,    43,    46,   328,
     329,    22,    23,    24,   341,   345,   283,    23,    24,   285,
     284,   161,    46,   162,   160,   129,   340,    23,    24,     1,
      84,    85,    86,    87,   160,    88,    89,   342,   286,   207,
     287,   133,   119,   204,   257,   304,   258,   292,    61,   100,
      43,     0,     0,   160,     0,     0,     0,     0,     0,     0,
       0,     0,   160,     0,   160,    46,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   160,     1,    84,    85,    86,
      87,     0,    88,    89,     0,     0,    43,     0,     0,    90,
       0,     0,    91,     0,     0,    92,    93,    94,    95,    96,
      97,    46,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,   134,   135,   136,     0,   137,   138,   139,
     140,   141,   142,   143,   144,     0,    90,     0,     0,     0,
       0,     0,    92,    93,    94,    95,    96,    97,     1,    84,
      85,    86,    87,     0,    88,    89,     0,     0,  -174,   145,
       0,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,    84,    85,    86,    87,
       0,    88,    89,     0,     0,   134,   135,   136,     0,   137,
     138,   139,   140,   141,   142,   143,   144,     0,    90,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
       0,     0,     1,    84,    85,    86,    87,   221,    88,    89,
    -174,   245,   134,   135,   136,     0,   137,   138,   139,   140,
     141,   142,   143,   144,     0,    90,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,     1,    84,    85,
      86,    87,     0,    88,    89,     0,     0,  -174,   327,   134,
     135,   136,     0,   137,   138,   139,   140,   141,   142,   143,
     144,     0,    90,     0,     0,     0,     0,     0,    92,    93,
      94,    95,    96,    97,     1,    84,    85,    86,    87,     0,
      88,    89,     0,     0,  -174,     0,     0,     0,     1,    84,
      85,    86,    87,     0,    88,    89,     0,    90,     0,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,     1,
      84,    85,    86,    87,     2,    88,    89,     0,     0,   121,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    90,     0,     0,   251,     0,     0,
      92,    93,    94,    95,    96,    97,     0,     0,    90,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
       1,    84,    85,    86,    87,     0,    88,    89,     0,    90,
       0,     0,   311,     0,     0,    92,    93,    94,    95,    96,
      97,     1,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     1,    84,    85,    86,    87,     2,    88,
      89,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
     169,     0,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,     0,     0,     0,     0,    60,     0,     0,     1,
       0,   171,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,    90,     0,   127,     0,     0,     0,    92,
      93,    94,    95,    96,    97,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,    23,    24,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,   248,   162,     0,     0,
       0,    23,    24,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,    23,    24,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     2,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,   242,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,   227,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   248,   162,     0,     0,     0,    23,    24,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   256,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    71,   121,    90,    77,    72,     3,    58,    57,    13,
      14,     3,   101,    18,     0,    43,   118,    85,    46,    73,
       3,    21,    22,    64,   144,    68,    26,   129,    80,    68,
      30,    68,   134,    80,    22,    35,    36,    68,    26,    24,
      40,    27,    28,    86,    64,    84,    32,    35,   139,    86,
      36,   121,    68,    84,    63,    85,    65,    70,    43,    58,
     162,    46,    75,    76,   155,    65,    82,   118,    71,    72,
       8,     9,    10,    77,    78,    75,    81,    77,   129,   133,
      80,   154,   169,   134,   171,   152,    85,    75,    85,    88,
      89,    77,    80,    85,   181,   184,   185,   186,    85,     3,
      64,    63,   101,    65,    68,    90,    83,    69,    70,   161,
     180,   162,   164,    69,   234,   202,   116,   164,    64,   118,
     120,    68,    68,   175,   226,    63,    79,    65,   175,    67,
     129,    80,   120,    64,    17,   134,    64,    68,   229,   139,
      68,   141,    64,   230,   231,   232,    68,    83,    66,    85,
     150,    63,   222,   255,    63,   155,   247,    82,    63,    63,
      65,   161,   150,   162,   164,    69,    70,    82,   154,   239,
     289,    11,    12,   161,   263,   226,   164,   177,    63,    66,
      84,    68,   182,    63,   169,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   294,   255,   254,   326,    84,   260,   261,
      84,    24,    68,   304,   261,    84,     3,   187,   188,   289,
     340,     3,    15,    16,   224,    82,    24,   226,    64,   229,
      43,     3,   323,    46,   189,   190,   224,    83,   325,    68,
      53,   332,    84,   334,   244,    43,   316,   247,    46,   191,
     192,   193,   194,   344,   345,    53,   255,    82,   195,   196,
      73,    55,    84,    76,   263,    64,    66,   318,    64,    64,
      86,    68,    64,    63,    84,    73,    63,    90,    76,    64,
      66,    63,    69,    70,    53,    64,   197,    69,    70,   199,
     198,    63,    90,    65,   294,    82,    84,    69,    70,     3,
       4,     5,     6,     7,   304,     9,    10,    84,   200,   120,
     201,    76,    65,   116,   168,   244,   169,   224,    36,   318,
     133,    -1,    -1,   323,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   332,    -1,   334,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   344,   345,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,   169,    -1,    -1,    63,
      -1,    -1,    66,    -1,    -1,    69,    70,    71,    72,    73,
      74,   169,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    -1,    85,    86,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      -1,    -1,     3,     4,     5,     6,     7,    83,     9,    10,
      85,    86,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    85,    86,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    -1,    85,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,     3,
       4,     5,     6,     7,    29,     9,    10,    -1,    -1,    85,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    63,    -1,    -1,    66,    -1,    -1,
      69,    70,    71,    72,    73,    74,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    63,
      -1,    -1,    66,    -1,    -1,    69,    70,    71,    72,    73,
      74,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    29,     9,
      10,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,     0,    -1,    -1,     3,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    63,    -1,    86,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,
      -1,    69,    70,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    29,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    86,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    86,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    -1,    -1,    -1,    69,    70,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    63,    69,    70,   111,   112,   116,   117,   118,
     119,   126,   129,   130,   131,   132,   156,   157,   158,   161,
      85,   161,   130,   117,   122,   123,   129,    84,   113,   115,
     130,   112,   112,    85,   161,   112,   159,    63,    65,   130,
       0,   157,   127,   128,   161,    85,    64,   123,   123,    68,
      84,    83,   160,   120,   121,   122,    85,    85,   145,    64,
     112,   133,   134,   135,     4,     5,     6,     7,     9,    10,
      63,    66,    69,    70,    71,    72,    73,    74,    88,    89,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   109,   161,    68,    86,    83,   127,
     114,    85,    92,   105,   106,   139,   145,    86,   121,    82,
     124,   125,   130,   120,    50,    51,    52,    54,    55,    56,
      57,    58,    59,    60,    61,    86,   106,   108,   110,   111,
     112,   142,   143,   144,   147,   148,   149,   150,   153,   155,
     161,    63,    65,   130,   132,   137,   138,    64,    68,    63,
      92,    63,    92,    92,   108,   122,   136,     8,     9,    10,
      63,    65,    67,    94,    70,    75,    76,    71,    72,    11,
      12,    13,    14,    77,    78,    15,    16,    69,    79,    80,
      17,    18,    81,    66,   128,   109,    86,   115,   130,   139,
     141,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    83,   107,   109,    68,    84,    82,    86,   109,    82,
      63,    63,    63,   142,    63,   161,    84,    84,   110,    68,
      84,   145,    86,   111,   146,    86,   142,    82,    64,   133,
     137,    66,   109,   137,    63,    65,    49,   135,   136,    64,
      63,   132,   137,    64,   161,    90,    91,   106,   108,   161,
      94,    94,    94,    95,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    99,   100,   101,   102,   103,   108,    68,
     140,   106,   125,   109,    82,   142,   108,   108,   108,    55,
     110,    84,    84,   106,   148,   142,    64,    64,    66,    64,
     133,    66,   109,    64,    94,    64,    68,    66,    82,   139,
      86,   142,    64,    64,    64,    63,    84,    86,    64,    66,
     106,   105,   152,   142,   154,   108,   110,   142,   142,    64,
      84,    53,    84,   110,   151,    64,   142,   142
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   110,   110,
     111,   111,   112,   112,   112,   112,   112,   112,   113,   114,
     113,   115,   115,   116,   116,   116,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     118,   118,   118,   119,   119,   120,   120,   121,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   126,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     131,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   135,   136,   136,   137,   137,   137,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   139,   139,   140,
     140,   141,   141,   142,   143,   142,   142,   142,   142,   142,
     144,   144,   144,   145,   145,   145,   146,   145,   147,   147,
     148,   148,   149,   150,   151,   150,   150,   152,   154,   153,
     153,   153,   155,   155,   155,   155,   156,   156,   157,   157,
     159,   158,   160,   158,   161
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     4,
       3,     3,     2,     2,     0,     1,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     0,     1,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     0,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     2,     1,     1,     1,     2,     3,     2,     2,
       0,     1,     1,     3,     1,     2,     3,     4,     5,     2,
       1,     3,     1,     3,     1,     1,     1,     2,     1,     3,
       3,     4,     4,     3,     2,     1,     1,     3,     1,     3,
       2,     1,     2,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     2,     3,     3,     4,     1,     4,     0,
       1,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     0,     5,     1,     2,
       1,     2,     2,     6,     0,     9,     5,     0,     0,     6,
       7,     9,     3,     2,     2,     3,     1,     2,     1,     1,
       0,     3,     0,     4,     1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 81 "gram.y" /* yacc.c:1646  */
    { debug("creating var expr for: %s", st_get_id_str((yyvsp[0].y_stid))); (yyval.y_expr) = create_var_expr((yyvsp[0].y_stid));  debug("created var expr for: %s", st_get_id_str((yyvsp[0].y_stid)));  }
#line 1728 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = create_int_constant((yyvsp[0].y_int));    }
#line 1734 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 83 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = create_double_constant((yyvsp[0].y_double)); }
#line 1740 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 84 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = create_string_constant((yyvsp[0].y_string));   }
#line 1746 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "gram.y" /* yacc.c:1646  */
    {  (yyval.y_expr) = (yyvsp[-1].y_expr);  }
#line 1752 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = create_arr_access_expr((yyvsp[-3].y_expr), (yyvsp[-1].y_expr)); }
#line 1758 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 91 "gram.y" /* yacc.c:1646  */
    { debug("Creating func call"); (yyval.y_expr) = create_func_call_expr((yyvsp[-3].y_expr), (yyvsp[-1].y_expr_list));  }
#line 1764 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 92 "gram.y" /* yacc.c:1646  */
    {}
#line 1770 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 93 "gram.y" /* yacc.c:1646  */
    {}
#line 1776 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 94 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = create_unary_expr((yyvsp[-1].y_expr), POST_INC);  }
#line 1782 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 95 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = create_unary_expr((yyvsp[-1].y_expr), POST_DEC);  }
#line 1788 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 99 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr_list) = NULL; }
#line 1794 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 104 "gram.y" /* yacc.c:1646  */
    { debug("creating expr list"); (yyval.y_expr_list) = create_expr_list((yyvsp[0].y_expr)); }
#line 1800 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 105 "gram.y" /* yacc.c:1646  */
    { debug("appending to expr list"); (yyval.y_expr_list) = append_to_expr_list((yyvsp[-2].y_expr_list), (yyvsp[0].y_expr)); }
#line 1806 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 110 "gram.y" /* yacc.c:1646  */
    {    (yyval.y_expr) = create_unary_expr((yyvsp[0].y_expr), PRE_INC);   }
#line 1812 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 111 "gram.y" /* yacc.c:1646  */
    {    (yyval.y_expr) = create_unary_expr((yyvsp[0].y_expr), PRE_DEC); }
#line 1818 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 112 "gram.y" /* yacc.c:1646  */
    {    (yyval.y_expr) = create_unary_expr((yyvsp[0].y_expr), (yyvsp[-1].y_unoptr));  }
#line 1824 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 113 "gram.y" /* yacc.c:1646  */
    {}
#line 1830 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 114 "gram.y" /* yacc.c:1646  */
    {}
#line 1836 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 118 "gram.y" /* yacc.c:1646  */
    {   (yyval.y_unoptr) = ADDR_OF; }
#line 1842 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 119 "gram.y" /* yacc.c:1646  */
    {   (yyval.y_unoptr) = STAR; }
#line 1848 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 120 "gram.y" /* yacc.c:1646  */
    {   (yyval.y_unoptr) = PLUS; }
#line 1854 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 121 "gram.y" /* yacc.c:1646  */
    {   (yyval.y_unoptr) = MINUS; }
#line 1860 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 122 "gram.y" /* yacc.c:1646  */
    {   (yyval.y_unoptr) = NEGATE; }
#line 1866 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 123 "gram.y" /* yacc.c:1646  */
    {   (yyval.y_unoptr) = NOT; }
#line 1872 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 128 "gram.y" /* yacc.c:1646  */
    {}
#line 1878 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 133 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), MUL);   }
#line 1884 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 134 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), DIV);   }
#line 1890 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 135 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), MOD);   }
#line 1896 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 140 "gram.y" /* yacc.c:1646  */
    {
	                                                validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr));
	                                                (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), ADD);
	                                            }
#line 1905 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 144 "gram.y" /* yacc.c:1646  */
    {  validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), SUB);   }
#line 1911 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 155 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), LT);   }
#line 1917 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 156 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), GT);   }
#line 1923 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 157 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), LTE);   }
#line 1929 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 158 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), GTE);   }
#line 1935 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 163 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), EQUAL_TO);   }
#line 1941 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 164 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), NOT_EQUAL_TO); }
#line 1947 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 184 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), LGCL_AND);   }
#line 1953 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 189 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), LGCL_OR);   }
#line 1959 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 193 "gram.y" /* yacc.c:1646  */
    {   (yyval.y_expr) = (yyvsp[0].y_expr);   }
#line 1965 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 194 "gram.y" /* yacc.c:1646  */
    {              }
#line 1971 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 199 "gram.y" /* yacc.c:1646  */
    { validate_binary_operands((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); (yyval.y_expr) = create_binary_expr((yyvsp[-2].y_expr), (yyvsp[0].y_expr), (yyvsp[-1].y_binoptr)); }
#line 1977 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 203 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binoptr) = ASSIGN; }
#line 1983 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 204 "gram.y" /* yacc.c:1646  */
    {}
#line 1989 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 205 "gram.y" /* yacc.c:1646  */
    {}
#line 1995 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 206 "gram.y" /* yacc.c:1646  */
    {}
#line 2001 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 207 "gram.y" /* yacc.c:1646  */
    {}
#line 2007 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 208 "gram.y" /* yacc.c:1646  */
    {}
#line 2013 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 209 "gram.y" /* yacc.c:1646  */
    {}
#line 2019 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 210 "gram.y" /* yacc.c:1646  */
    {}
#line 2025 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 211 "gram.y" /* yacc.c:1646  */
    {}
#line 2031 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 212 "gram.y" /* yacc.c:1646  */
    {}
#line 2037 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 213 "gram.y" /* yacc.c:1646  */
    {}
#line 2043 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 218 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr);}
#line 2049 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 226 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = NULL; }
#line 2055 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 235 "gram.y" /* yacc.c:1646  */
    { error("No declarator in declaration"); }
#line 2061 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 236 "gram.y" /* yacc.c:1646  */
    {}
#line 2067 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 240 "gram.y" /* yacc.c:1646  */
    {}
#line 2073 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 241 "gram.y" /* yacc.c:1646  */
    {}
#line 2079 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 242 "gram.y" /* yacc.c:1646  */
    { (yyval.y_bucket) = update_bucket(NULL, (yyvsp[0].y_tpspec), NULL); }
#line 2085 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 243 "gram.y" /* yacc.c:1646  */
    { (yyval.y_bucket) = update_bucket((yyvsp[0].y_bucket), (yyvsp[-1].y_tpspec), NULL); 
														 if((yyvsp[-1].y_tpspec) == SHORT_SPEC &&
														    (((yyvsp[0].y_bucket) == SHORT_SPEC) || ((yyvsp[0].y_bucket) == FLOAT_SPEC) || ((yyvsp[0].y_bucket) == LONG_SPEC)
														    || ((yyvsp[0].y_bucket) == CHAR_SPEC)))
															error("illegal size specifier");
														 if((yyvsp[-1].y_tpspec) == LONG_SPEC && (((yyvsp[0].y_bucket) == SHORT_SPEC) ||
														    ((yyvsp[0].y_bucket) == FLOAT_SPEC) || ((yyvsp[0].y_bucket) == LONG_SPEC) || ((yyvsp[0].y_bucket) == CHAR_SPEC)))
															error("illegal size specifier");
														 if((yyvsp[-1].y_tpspec) == SIGNED_SPEC && (((yyvsp[0].y_bucket) == DOUBLE_SPEC) || ((yyvsp[0].y_bucket) == CHAR_SPEC)))
															error("illegal sign specifier");
														}
#line 2101 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 254 "gram.y" /* yacc.c:1646  */
    {}
#line 2107 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 255 "gram.y" /* yacc.c:1646  */
    {}
#line 2113 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 259 "gram.y" /* yacc.c:1646  */
    {}
#line 2119 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 260 "gram.y" /* yacc.c:1646  */
    { (yyval.y_bucket) = (yyvsp[-2].y_bucket); }
#line 2125 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 260 "gram.y" /* yacc.c:1646  */
    {(yyvsp[-1].y_bucket); /*to get rid of warning*/}
#line 2131 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 264 "gram.y" /* yacc.c:1646  */
    {
                  install_into_symtab(build_base((yyvsp[-1].y_bucket)), (yyvsp[0].y_mydecl_list));
                 }
#line 2139 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 267 "gram.y" /* yacc.c:1646  */
    {}
#line 2145 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 275 "gram.y" /* yacc.c:1646  */
    { (yyval.y_tpspec) = VOID_SPEC; }
#line 2151 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 276 "gram.y" /* yacc.c:1646  */
    { (yyval.y_tpspec) = CHAR_SPEC; }
#line 2157 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 277 "gram.y" /* yacc.c:1646  */
    { (yyval.y_tpspec) = SHORT_SPEC; }
#line 2163 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 278 "gram.y" /* yacc.c:1646  */
    { (yyval.y_tpspec) = INT_SPEC; }
#line 2169 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 279 "gram.y" /* yacc.c:1646  */
    { (yyval.y_tpspec) = LONG_SPEC; }
#line 2175 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 280 "gram.y" /* yacc.c:1646  */
    { (yyval.y_tpspec) = FLOAT_SPEC; }
#line 2181 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 281 "gram.y" /* yacc.c:1646  */
    { (yyval.y_tpspec) = DOUBLE_SPEC; }
#line 2187 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 282 "gram.y" /* yacc.c:1646  */
    { (yyval.y_tpspec) = SIGNED_SPEC; }
#line 2193 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 283 "gram.y" /* yacc.c:1646  */
    { (yyval.y_tpspec) = UNSIGNED_SPEC; }
#line 2199 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 284 "gram.y" /* yacc.c:1646  */
    {}
#line 2205 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 285 "gram.y" /* yacc.c:1646  */
    {}
#line 2211 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 286 "gram.y" /* yacc.c:1646  */
    {}
#line 2217 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 350 "gram.y" /* yacc.c:1646  */
    { (yyval.y_mydecl_list) = (yyvsp[0].y_mydecl_list); }
#line 2223 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 351 "gram.y" /* yacc.c:1646  */
    {
	                                (yyval.y_mydecl_list) = create_ptr_decl_list((yyvsp[0].y_mydecl_list));
	                                // to make sure that an incorrect non-param decl does not effect the param decls
	                                //found_ref_param = FALSE;
	                              }
#line 2233 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 359 "gram.y" /* yacc.c:1646  */
    { (yyval.y_mydecl_list) = create_id_decl_list((yyvsp[0].y_stid)); }
#line 2239 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 360 "gram.y" /* yacc.c:1646  */
    { (yyval.y_mydecl_list) = (yyvsp[-1].y_mydecl_list); }
#line 2245 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 362 "gram.y" /* yacc.c:1646  */
    {
                                                    (yyval.y_mydecl_list) = create_array_decl_list((yyvsp[-3].y_mydecl_list), (yyvsp[-1].y_expr));
                                                   }
#line 2253 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 365 "gram.y" /* yacc.c:1646  */
    {
                                                    (yyval.y_mydecl_list) = create_func_decl_list((yyvsp[-3].y_mydecl_list), (yyvsp[-1].y_plist));
                                                  }
#line 2261 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 368 "gram.y" /* yacc.c:1646  */
    {
                                                    (yyval.y_mydecl_list) = create_func_decl_list((yyvsp[-2].y_mydecl_list), NULL);
                                                  }
#line 2269 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 375 "gram.y" /* yacc.c:1646  */
    { found_ref_param = TRUE;}
#line 2275 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 385 "gram.y" /* yacc.c:1646  */
    {
	                                                    (yyval.y_plist) = add_to_param_list((yyvsp[-2].y_plist), (yyvsp[0].y_plist));
	                                                    found_ref_param = FALSE;
	                                                  }
#line 2284 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 392 "gram.y" /* yacc.c:1646  */
    {
                                                            (yyval.y_plist) = create_param_list(build_base((yyvsp[-1].y_bucket)), (yyvsp[0].y_mydecl_list), found_ref_param);
                                                            found_ref_param = FALSE;
	                                                   }
#line 2293 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 396 "gram.y" /* yacc.c:1646  */
    {error(" no id in parameter list");}
#line 2299 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 397 "gram.y" /* yacc.c:1646  */
    {}
#line 2305 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 444 "gram.y" /* yacc.c:1646  */
    { /* p3 */st_enter_block(); }
#line 2311 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 444 "gram.y" /* yacc.c:1646  */
    { st_exit_block(); s_pop();/* p3 */}
#line 2317 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 458 "gram.y" /* yacc.c:1646  */
    {}
#line 2323 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 459 "gram.y" /* yacc.c:1646  */
    {}
#line 2329 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 460 "gram.y" /* yacc.c:1646  */
    {}
#line 2335 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 461 "gram.y" /* yacc.c:1646  */
    {
	                            /* p3 */ //install_local_decls(); and alloc space in current activation_record
	                            //by some offset from frame pointer
	                            //1. for each decl call b_alloc_local_var(8);
	                            //2. install into symtab with that offset
	                            //allocate_local_vars($2);

	                       }
#line 2348 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 469 "gram.y" /* yacc.c:1646  */
    {}
#line 2354 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 483 "gram.y" /* yacc.c:1646  */
    { if((yyvsp[-1].y_expr) != NULL) {
	                        //eval expr
	                        encode_expr_eval((yyvsp[-1].y_expr));
	                        if(ty_query((yyvsp[-1].y_expr)->type) != TYVOID)
	                            b_pop();
	                      }
	                    }
#line 2366 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 493 "gram.y" /* yacc.c:1646  */
    { b_label((yyvsp[-1].y_string));  }
#line 2372 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 496 "gram.y" /* yacc.c:1646  */
    { debug("in if stmt");
                                              char *end = new_symbol();
                                              b_jump(end);
                                              (yyval.y_string) = end;
                                              b_label((yyvsp[-2].y_string));
                                             }
#line 2383 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 501 "gram.y" /* yacc.c:1646  */
    {  b_label((yyvsp[-3].y_string));  }
#line 2389 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 506 "gram.y" /* yacc.c:1646  */
    {
	                  TYPETAG type = ty_query((yyvsp[(-1) - (0)].y_expr)->type);
                      encode_expr_eval((yyvsp[(-1) - (0)].y_expr));
                      char * label = new_symbol();
                      b_cond_jump(type, B_ZERO, label);
                      (yyval.y_string) = label;
                  }
#line 2401 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 515 "gram.y" /* yacc.c:1646  */
    { (yyval.y_stmt) = start_while((yyvsp[-1].y_expr)); }
#line 2407 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 515 "gram.y" /* yacc.c:1646  */
    { b_jump((yyvsp[-3].y_stmt)->start); b_label((yyvsp[-3].y_stmt)->end);}
#line 2413 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 517 "gram.y" /* yacc.c:1646  */
    {	/*
	                                                                char *new_label_exit = new_symbol();
																	b_label(new_label_exit);
																	char * new_label_loop = new_symbol();
																	b_label(new_label_loop);
																				
																	if( $3 != NULL){
																		TYPETAG type = ty_query($3->type);
																		while( type != NULL){
																			encode_expr_eval($3);
																			b_pop();
																		}
																		encode_expr_eval($5);
																		if( $5 != NULL){
																			b_cond_jump($5->type, B_ZERO, *new_label_exit);
																			$$ = $9;
																			encode_expr_eval($7);
																			TYPETAG non_void_type = ty_query($7->type);
																			while(non_void_type != NULL)
																				b_pop();
																			b_jump(new_label_loop);
																		}
																		else
																			$$ = $9;
																	}																		
																	else{
																		encode_expr_eval($5);
																		if( $5 != NULL){
																			b_cond_jump($5->type, B_ZERO, *new_label_exit);
																			$$ = $9;
																			encode_expr_eval($7);
																			TYPETAG non_void_type = ty_query($7->type);
																			while(non_void_type != NULL)
																				b_pop();
																			b_jump(new_label_loop);
																		}
																		else
																			$$ = $9;
																	}
																		*/
																}
#line 2459 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 564 "gram.y" /* yacc.c:1646  */
    {
                                    STMT stmt = s_pop();
                                    if (stmt == NULL)
                                        error("break statement outside loop or switch");
                                    else
                                        b_jump(stmt->end);
	                            }
#line 2471 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 571 "gram.y" /* yacc.c:1646  */
    {	/*encode_expr_eval($2);
									if( $2 != NULL){
										TYPETAG typetag = ty_query($2->type);
										b_convert(typetag, TYSIGNEDINT);
										while(typetag != NULL)
										$$ = b_encode_return(typetag);
									}
									else
										$$ = b_encode_return(TYVOID); */
								}
#line 2486 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 598 "gram.y" /* yacc.c:1646  */
    {  (yyval.y_string) = func_prologue(ty_build_basic(TYSIGNEDINT), (yyvsp[0].y_mydecl_list)); }
#line 2492 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 598 "gram.y" /* yacc.c:1646  */
    { func_epilogue((yyvsp[-1].y_string)); }
#line 2498 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 599 "gram.y" /* yacc.c:1646  */
    {  (yyval.y_string) = func_prologue(build_base((yyvsp[-1].y_bucket)), (yyvsp[0].y_mydecl_list)); }
#line 2504 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 599 "gram.y" /* yacc.c:1646  */
    { func_epilogue((yyvsp[-1].y_string)); }
#line 2510 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 607 "gram.y" /* yacc.c:1646  */
    { (yyval.y_stid) = st_enter_id((yyvsp[0].y_string)); }
#line 2516 "gram.tab.c" /* yacc.c:1646  */
    break;


#line 2520 "gram.tab.c" /* yacc.c:1646  */
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 609 "gram.y" /* yacc.c:1906  */


extern int column;

int yyerror(char *s)
{
	error("%s (column %d)",s,column);
        return 0;  /* never reached */
}
