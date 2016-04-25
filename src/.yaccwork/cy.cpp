/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "c.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pars/cytypes.h"
#include "pars/psbuff.h"

extern unsigned int g_line;
extern void yyerror(const char *s);
extern TranslationUnit* tunit;


#line 80 ".yaccwork/cy.cpp" /* yacc.c:339  */

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
   by #include "cy.hpp".  */
#ifndef YY_YY_YACCWORK_CY_HPP_INCLUDED
# define YY_YY_YACCWORK_CY_HPP_INCLUDED
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
    storage_class_specifier = 258,
    type_specifier_keywords = 259,
    type_qualifier_keywords = 260,
    struct_or_union = 261,
    assignment_operator_keywords = 262,
    ENUM = 263,
    IF = 264,
    ELSE = 265,
    SWITCH = 266,
    DO = 267,
    FOR = 268,
    CASE = 269,
    WHILE = 270,
    GOTO = 271,
    CONTINUE = 272,
    BREAK = 273,
    RETURN = 274,
    DEFAULT = 275,
    SIZEOF = 276,
    DOTS = 277,
    DOT = 278,
    GT = 279,
    LT = 280,
    GE = 281,
    LE = 282,
    PP = 283,
    MM = 284,
    ARROW = 285,
    OR = 286,
    AND = 287,
    EQUAL = 288,
    NOTEQUAL = 289,
    LSHIFT = 290,
    RSHIFT = 291,
    string = 292,
    identifier = 293,
    integer_constant = 294,
    character_constant = 295,
    floating_constant = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "c.y" /* yacc.c:355  */

    char* str;
    SourceLocation*  sloc;
    Statement*       stmt;
    Expression*      expr;
    Declaration*     decl;
    TranslationUnit* tunt;

#line 171 ".yaccwork/cy.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACCWORK_CY_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 188 ".yaccwork/cy.cpp" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1072

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  195
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  349

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,     2,     2,    60,    56,     2,
      49,    50,    42,    57,    46,    58,     2,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    43,
       2,    47,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,    54,    45,    61,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    43,    52,    56,    70,    80,    89,    97,
     106,   117,   128,   132,   140,   147,   152,   159,   164,   171,
     178,   182,   186,   193,   203,   212,   220,   228,   232,   244,
     248,   257,   261,   270,   279,   285,   289,   295,   301,   305,
     314,   318,   325,   336,   345,   353,   361,   365,   374,   378,
     389,   393,   399,   403,   410,   418,   425,   433,   441,   450,
     456,   460,   467,   475,   480,   489,   493,   503,   507,   517,
     523,   529,   535,   539,   548,   554,   561,   571,   575,   584,
     590,   596,   600,   606,   612,   619,   627,   634,   641,   647,
     655,   662,   666,   686,   690,   694,   698,   702,   706,   712,
     718,   724,   732,   739,   745,   752,   759,   767,   774,   780,
     791,   802,   813,   824,   835,   846,   857,   870,   876,   882,
     888,   895,   906,   915,   922,   929,   937,   941,   954,   961,
     966,   979,   983,   993,   997,  1007,  1011,  1021,  1025,  1035,
    1039,  1049,  1053,  1061,  1071,  1075,  1083,  1091,  1099,  1109,
    1115,  1123,  1133,  1139,  1147,  1157,  1164,  1172,  1180,  1190,
    1194,  1205,  1209,  1215,  1221,  1227,  1233,  1245,  1249,  1253,
    1257,  1261,  1265,  1271,  1275,  1285,  1295,  1306,  1315,  1324,
    1331,  1340,  1345,  1350,  1355,  1365,  1369,  1373,  1388,  1393,
    1406,  1411,  1422,  1427,  1439,  1443
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "storage_class_specifier",
  "type_specifier_keywords", "type_qualifier_keywords", "struct_or_union",
  "assignment_operator_keywords", "ENUM", "IF", "ELSE", "SWITCH", "DO",
  "FOR", "CASE", "WHILE", "GOTO", "CONTINUE", "BREAK", "RETURN", "DEFAULT",
  "SIZEOF", "DOTS", "DOT", "GT", "LT", "GE", "LE", "PP", "MM", "ARROW",
  "OR", "AND", "EQUAL", "NOTEQUAL", "LSHIFT", "RSHIFT", "string",
  "identifier", "integer_constant", "character_constant",
  "floating_constant", "'*'", "';'", "'{'", "'}'", "','", "'='", "':'",
  "'('", "')'", "'['", "']'", "'?'", "'|'", "'^'", "'&'", "'+'", "'-'",
  "'/'", "'%'", "'~'", "'!'", "$accept", "translation_unit",
  "external_declaration", "function_definition", "declaration",
  "declaration_list", "declaration_specifier", "type_specifier",
  "type_qualifier", "struct_or_union_specifier", "struct_declaration_list",
  "init_declarator_list", "init_declarator", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "initializer", "initializer_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "statement",
  "labeled_statement", "expression_statement", "select_statement",
  "iteration_statement", "jump_statement", "compound_statement",
  "statement_list", "constant_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "unary_operator", "postfix_expression",
  "primary_expression", "constant", "expression",
  "assignment_expression_list", "assignment_expression",
  "assignment_operator", YY_NULLPTR
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
     295,   296,    42,    59,   123,   125,    44,    61,    58,    40,
      41,    91,    93,    63,   124,    94,    38,    43,    45,    47,
      37,   126,    33
};
# endif

#define YYPACT_NINF -195

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-195)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     198,   361,  -195,  -195,    -2,   138,  -195,    20,   167,   129,
    -195,  -195,  -195,   100,   361,   361,  -195,  -195,  1028,   163,
       5,  -195,   -31,   324,     4,   -19,  -195,  -195,    20,    16,
    -195,  -195,  -195,    39,  -195,   408,  -195,  -195,   282,  -195,
    1028,   100,  -195,    73,   598,   163,   324,   324,   324,    63,
    -195,   230,   -19,    33,     6,  -195,  -195,  -195,  -195,  -195,
     167,   624,  1028,  -195,    41,    57,   530,    82,   936,   123,
     161,    58,   164,   650,   165,   962,   988,   988,  -195,   181,
    -195,  -195,  -195,  -195,  -195,  -195,   368,  -195,  -195,  -195,
    -195,  -195,   342,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
     422,  -195,    52,   214,   207,   196,   215,   113,   448,   366,
     363,   197,  -195,    13,   936,   285,  -195,  -195,    93,  -195,
    -195,  -195,   236,  -195,  -195,   267,   262,   271,  -195,    53,
    -195,  -195,   316,  -195,  -195,   229,  -195,  -195,  -195,  -195,
     936,   180,  -195,   329,   296,   936,  -195,   -19,  -195,   624,
    -195,  -195,  -195,   936,   936,   373,   676,   399,   936,   349,
    -195,  -195,  -195,   202,   530,   368,  -195,   936,  -195,  -195,
     530,    45,   420,    76,  -195,   476,  -195,  -195,   936,   936,
     936,   936,   936,   936,   936,   936,   936,   936,   936,   936,
     936,   936,   936,   936,   936,   936,   936,  -195,  -195,   936,
    -195,   411,  -195,  -195,   438,   702,   936,  -195,   936,   557,
     728,  -195,    79,  -195,   255,  -195,   504,   439,  -195,  -195,
    -195,  -195,  -195,   230,   936,  -195,  -195,  -195,  -195,   400,
     143,   192,   409,   754,   216,   530,   234,  -195,  -195,  -195,
     431,  -195,    23,   284,  -195,   936,  -195,  -195,   214,   347,
     207,   196,   215,   113,   448,   448,   366,   366,   366,   366,
     363,   363,   197,   197,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,   344,  -195,   146,  -195,  -195,   432,   436,  -195,   450,
     255,   182,   780,  -195,  -195,  -195,  -195,  -195,  -195,   572,
     530,   530,   936,   806,   246,   832,  -195,   530,  -195,  -195,
     936,   936,  -195,  -195,  -195,  -195,  -195,  -195,   453,  -195,
     454,  -195,  -195,   501,  -195,   369,   530,   372,   858,   884,
     306,  -195,  -195,  -195,  -195,  -195,   530,   479,  -195,   530,
     530,   377,   530,   382,   910,  -195,  -195,  -195,  -195,   530,
    -195,   530,   530,   398,  -195,  -195,  -195,   530,  -195
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,    20,    23,     0,     0,    52,    60,     0,     0,
       2,     4,     5,     0,    17,    19,    21,    22,     0,    51,
       0,    14,    26,     0,    45,     0,    63,    62,    59,     0,
       1,     3,    11,     0,    29,    31,    16,    18,     0,    12,
       0,     0,     9,     0,     0,    50,     0,    35,    37,     0,
      27,     0,     0,    48,     0,    46,    64,    61,    53,    10,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   181,
     185,   186,   187,   168,   103,   125,     0,   167,   169,   170,
     171,   172,     0,   126,    93,    94,    96,    97,    98,    95,
       0,   192,   129,   131,   133,   135,   137,   139,   141,   144,
     149,   152,   155,   159,     0,   161,   173,   182,     0,   188,
      13,     7,    31,    72,    58,    71,     0,    65,    67,     0,
     181,    55,     0,   128,   159,     0,    34,    36,    25,    28,
       0,     0,    38,    40,     0,     0,    44,     0,    30,     0,
      32,    74,     6,     0,     0,     0,     0,     0,     0,     0,
     118,   119,   121,     0,     0,     0,   165,     0,   162,   163,
       0,    80,     0,     0,   123,     0,   124,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,   195,     0,
     164,     0,   179,   180,     0,     0,     0,   102,     0,     0,
       0,    69,    81,    70,    83,    56,     0,     0,    57,    54,
      24,    42,    33,     0,     0,    43,    49,    47,    77,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   120,   101,
       0,    99,     0,    81,    79,     0,   184,   122,   132,     0,
     134,   136,   138,   140,   142,   143,   145,   146,   147,   148,
     150,   151,   153,   154,   156,   157,   158,   193,   177,   178,
     175,     0,   190,     0,   189,    92,     0,     0,    88,     0,
      82,     0,     0,    66,    68,    73,    39,    41,    75,     0,
       0,     0,     0,     0,     0,     0,   100,     0,   166,   160,
       0,     0,   176,   174,    90,    84,    86,    91,     0,    87,
       0,    76,    78,   104,   106,     0,     0,     0,     0,     0,
       0,   107,   130,   191,    89,    85,     0,     0,   116,     0,
       0,     0,     0,     0,     0,   105,   108,   115,   114,     0,
     112,     0,     0,     0,   113,   111,   110,     0,   109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,  -195,   514,  -195,    24,   340,     1,     9,   172,  -195,
     478,  -195,   467,   -43,   -25,  -195,   305,  -195,   477,   383,
      -1,   -16,     2,  -195,   -40,  -195,   315,  -195,  -144,  -195,
     370,  -108,  -194,   -66,  -195,  -195,  -195,  -195,  -195,    35,
     444,   -27,   -33,  -195,   362,   374,   371,   375,   381,   269,
     312,   266,   276,   -75,   -30,  -195,  -195,  -195,  -195,   -65,
    -195,   -24,  -195
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    39,    40,    41,    14,    15,    16,
      49,    33,    34,    50,    51,   141,   142,    17,    54,    55,
      18,    19,    20,    28,   276,   127,   128,   129,   150,   229,
     172,   277,   214,    93,    94,    95,    96,    97,    98,    99,
     100,   132,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     271,   119,   199
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     155,    13,    21,   126,    45,   228,   139,    29,   163,    27,
      13,   133,    35,    46,   134,    36,    37,   213,   280,    53,
     197,   173,   136,   137,    12,     3,     1,     2,     3,     4,
      57,     5,    47,    12,   177,   133,    22,   151,   134,   200,
     122,   157,    23,     6,   125,   166,   168,   169,    52,   280,
     143,   146,   147,    42,     8,    47,    47,    47,    47,   122,
     198,   171,     7,   244,   120,     7,    58,     2,     3,     4,
      63,     5,   242,   275,   210,   121,     1,     2,     3,     4,
     145,     5,    59,   178,   134,    60,   120,     7,   230,   231,
     153,   234,   139,   236,   242,    47,   210,   152,   239,   217,
     173,   160,   173,   218,   241,   179,   154,   133,   138,   177,
     134,   123,   133,   221,   249,   134,   120,     6,   226,   264,
     265,   266,   208,   124,   211,   151,   246,   212,   209,    30,
     210,   156,     1,     2,     3,     4,   207,     5,     6,   208,
     171,   273,     7,    32,    47,   312,   184,   185,   134,     8,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,     6,   294,   296,
     299,     7,   158,   243,    47,   267,    24,   133,     8,    26,
     134,   272,    25,   279,   274,     1,     2,     3,     4,   208,
       5,   133,   208,   290,   134,    48,    45,   287,   303,   159,
      56,     1,     2,     3,     4,     6,     5,   161,    29,     7,
     125,   212,    43,   164,    44,   134,     8,   125,    48,    48,
      48,    48,   143,   222,   313,   314,   223,   315,   317,   170,
     320,   321,   307,     2,     3,     4,     6,     5,   208,   194,
       7,   308,   291,   125,   243,   238,   180,     8,   208,   133,
     328,   182,   134,   331,   333,   310,   195,   196,    48,   295,
     335,   181,   208,   337,   338,   151,   340,   322,     6,   343,
     134,   183,     7,   344,   220,   345,   346,   323,   140,     8,
     208,   348,   125,    61,   297,     1,     2,     3,     4,   318,
       5,    64,   208,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,   281,     6,   282,    48,   201,     7,
      76,    77,   215,   202,   203,   204,   209,   216,   210,    78,
      79,    80,    81,    82,    83,    84,    38,    85,     2,     3,
       4,    86,     5,   242,   205,   210,   206,    48,    87,    88,
      89,   225,   147,    90,    91,     1,     2,     3,     4,   334,
       5,    64,   208,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     1,     2,     3,     4,   219,     5,
      76,    77,     2,     3,     4,    62,     5,   224,    92,    78,
      79,    80,    81,    82,    83,    84,    38,   174,   232,    75,
     301,    86,   237,   208,   302,   300,    76,    77,    87,    88,
      89,   190,   191,    90,    91,    78,   130,    80,    81,    82,
      83,     1,     2,     3,     4,   208,     5,    86,   208,   327,
     192,   193,   329,   208,    87,    88,    89,   339,   208,    90,
      91,    64,   341,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,   208,   288,   289,   235,   347,   268,
      76,    77,    38,   254,   255,    61,   260,   261,   292,    78,
      79,    80,    81,    82,    83,    84,    38,   176,   262,   263,
     245,    86,   186,   187,   188,   189,   269,   285,    87,    88,
      89,   298,   304,    90,    91,    64,   305,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,   256,   257,
     258,   259,   306,   324,    76,    77,   325,     1,     2,     3,
       4,   326,     5,    78,    79,    80,    81,    82,    83,    84,
      38,   247,   336,    31,   135,    86,   283,   148,   286,   144,
     227,   284,    87,    88,    89,   240,   175,    90,    91,    64,
     248,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,   251,     0,   250,     0,     0,   252,    76,    77,
       1,     2,     3,     4,   253,     5,     0,    78,    79,    80,
      81,    82,    83,    84,    38,     0,     0,     0,     0,    86,
       0,     0,     0,     0,     0,     0,    87,    88,    89,     0,
       0,    90,    91,    75,     0,     6,     0,     0,     0,     7,
      76,    77,     0,     0,     0,     0,   209,   275,   210,    78,
     130,    80,    81,    82,    83,     0,   149,   311,     0,    75,
       0,    86,     0,     0,     0,     0,    76,    77,    87,    88,
      89,     0,     0,    90,    91,    78,   130,    80,    81,    82,
      83,     0,     0,     0,     0,    75,     0,    86,     0,     0,
     131,     0,    76,    77,    87,    88,    89,     0,     0,    90,
      91,    78,   130,    80,    81,    82,    83,     0,   149,     0,
       0,    75,     0,    86,     0,     0,     0,     0,    76,    77,
      87,    88,    89,     0,     0,    90,    91,    78,   130,    80,
      81,    82,    83,   162,     0,     0,     0,    75,     0,    86,
       0,     0,     0,     0,    76,    77,    87,    88,    89,     0,
       0,    90,    91,    78,   130,    80,    81,    82,    83,   233,
       0,     0,     0,    75,     0,    86,     0,     0,     0,     0,
      76,    77,    87,    88,    89,     0,     0,    90,    91,    78,
     130,    80,    81,    82,    83,     0,     0,     0,     0,    75,
       0,    86,   270,     0,     0,     0,    76,    77,    87,    88,
      89,     0,     0,    90,    91,    78,   130,    80,    81,    82,
      83,     0,     0,     0,     0,    75,     0,    86,     0,     0,
     278,     0,    76,    77,    87,    88,    89,     0,     0,    90,
      91,    78,   130,    80,    81,    82,    83,   293,     0,     0,
       0,    75,     0,    86,     0,     0,     0,     0,    76,    77,
      87,    88,    89,     0,     0,    90,    91,    78,   130,    80,
      81,    82,    83,     0,     0,     0,     0,    75,     0,    86,
       0,     0,   309,     0,    76,    77,    87,    88,    89,     0,
       0,    90,    91,    78,   130,    80,    81,    82,    83,     0,
       0,     0,     0,    75,     0,    86,   316,     0,     0,     0,
      76,    77,    87,    88,    89,     0,     0,    90,    91,    78,
     130,    80,    81,    82,    83,   319,     0,     0,     0,    75,
       0,    86,     0,     0,     0,     0,    76,    77,    87,    88,
      89,     0,     0,    90,    91,    78,   130,    80,    81,    82,
      83,     0,     0,     0,     0,    75,     0,    86,   330,     0,
       0,     0,    76,    77,    87,    88,    89,     0,     0,    90,
      91,    78,   130,    80,    81,    82,    83,     0,     0,     0,
       0,    75,     0,    86,   332,     0,     0,     0,    76,    77,
      87,    88,    89,     0,     0,    90,    91,    78,   130,    80,
      81,    82,    83,     0,     0,     0,     0,    75,     0,    86,
     342,     0,     0,     0,    76,    77,    87,    88,    89,     0,
       0,    90,    91,    78,   130,    80,    81,    82,    83,     0,
       0,     0,     0,    75,     0,    86,     0,     0,     0,     0,
      76,    77,    87,    88,    89,     0,     0,    90,    91,    78,
     130,    80,    81,    82,    83,     0,     0,     0,     0,    75,
       0,   165,     0,     0,     0,     0,    76,    77,    87,    88,
      89,     0,     0,    90,    91,    78,   130,    80,    81,    82,
      83,     1,     2,     3,     4,     0,     5,   167,     0,     0,
       0,     0,     0,     0,    87,    88,    89,     0,     0,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38
};

static const yytype_int16 yycheck[] =
{
      66,     0,     1,    43,    20,   149,    49,     8,    73,     7,
       9,    44,    13,    44,    44,    14,    15,   125,   212,    38,
       7,    86,    47,    48,     0,     5,     3,     4,     5,     6,
      28,     8,    23,     9,   100,    68,    38,    61,    68,   114,
      41,    68,    44,    38,    43,    75,    76,    77,    44,   243,
      51,    45,    46,    18,    49,    46,    47,    48,    49,    60,
      47,    86,    42,   171,    40,    42,    50,     4,     5,     6,
      35,     8,    49,    50,    51,    40,     3,     4,     5,     6,
      47,     8,    43,    31,   114,    46,    62,    42,   153,   154,
      49,   156,   135,   158,    49,    86,    51,    62,   164,    46,
     165,    43,   167,    50,   170,    53,    49,   140,    45,   175,
     140,    38,   145,   140,   179,   145,    92,    38,   145,   194,
     195,   196,    46,    50,   125,   149,    50,   125,    49,     0,
      51,    49,     3,     4,     5,     6,    43,     8,    38,    46,
     165,   206,    42,    43,   135,   289,    33,    34,   178,    49,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    38,   233,   235,
     245,    42,    49,   171,   165,   199,    38,   210,    49,     7,
     210,   205,    44,   210,   208,     3,     4,     5,     6,    46,
       8,   224,    46,    50,   224,    23,   212,   224,    52,    38,
      28,     3,     4,     5,     6,    38,     8,    43,   209,    42,
     209,   209,    49,    48,    51,   245,    49,   216,    46,    47,
      48,    49,   223,    43,   290,   291,    46,   292,   293,    48,
     295,   297,    50,     4,     5,     6,    38,     8,    46,    42,
      42,   281,    50,   242,   242,    43,    32,    49,    46,   282,
     316,    55,   282,   318,   319,   282,    59,    60,    86,    43,
     326,    54,    46,   329,   330,   289,   332,   300,    38,   334,
     300,    56,    42,   339,    45,   341,   342,   301,    48,    49,
      46,   347,   281,    47,    50,     3,     4,     5,     6,    43,
       8,     9,    46,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    49,    38,    51,   135,    23,    42,
      28,    29,    50,    28,    29,    30,    49,    46,    51,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     4,     5,
       6,    49,     8,    49,    49,    51,    51,   165,    56,    57,
      58,    45,    46,    61,    62,     3,     4,     5,     6,    43,
       8,     9,    46,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     3,     4,     5,     6,    52,     8,
      28,    29,     4,     5,     6,    35,     8,    48,    38,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    15,    21,
      46,    49,    43,    46,    50,    48,    28,    29,    56,    57,
      58,    35,    36,    61,    62,    37,    38,    39,    40,    41,
      42,     3,     4,     5,     6,    46,     8,    49,    46,    50,
      57,    58,    50,    46,    56,    57,    58,    50,    46,    61,
      62,     9,    50,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    46,    45,    46,    48,    50,    38,
      28,    29,    44,   184,   185,    47,   190,   191,    49,    37,
      38,    39,    40,    41,    42,    43,    44,    45,   192,   193,
      50,    49,    24,    25,    26,    27,    38,    38,    56,    57,
      58,    50,    50,    61,    62,     9,    50,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   186,   187,
     188,   189,    52,    50,    28,    29,    52,     3,     4,     5,
       6,    10,     8,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    43,     9,    46,    49,    22,    60,   223,    52,
     147,   216,    56,    57,    58,   165,    92,    61,    62,     9,
     178,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   181,    -1,   180,    -1,    -1,   182,    28,    29,
       3,     4,     5,     6,   183,     8,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    62,    21,    -1,    38,    -1,    -1,    -1,    42,
      28,    29,    -1,    -1,    -1,    -1,    49,    50,    51,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    -1,    21,
      -1,    49,    -1,    -1,    -1,    -1,    28,    29,    56,    57,
      58,    -1,    -1,    61,    62,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    21,    -1,    49,    -1,    -1,
      52,    -1,    28,    29,    56,    57,    58,    -1,    -1,    61,
      62,    37,    38,    39,    40,    41,    42,    -1,    44,    -1,
      -1,    21,    -1,    49,    -1,    -1,    -1,    -1,    28,    29,
      56,    57,    58,    -1,    -1,    61,    62,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    21,    -1,    49,
      -1,    -1,    -1,    -1,    28,    29,    56,    57,    58,    -1,
      -1,    61,    62,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    21,    -1,    49,    -1,    -1,    -1,    -1,
      28,    29,    56,    57,    58,    -1,    -1,    61,    62,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    21,
      -1,    49,    50,    -1,    -1,    -1,    28,    29,    56,    57,
      58,    -1,    -1,    61,    62,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    21,    -1,    49,    -1,    -1,
      52,    -1,    28,    29,    56,    57,    58,    -1,    -1,    61,
      62,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    21,    -1,    49,    -1,    -1,    -1,    -1,    28,    29,
      56,    57,    58,    -1,    -1,    61,    62,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    21,    -1,    49,
      -1,    -1,    52,    -1,    28,    29,    56,    57,    58,    -1,
      -1,    61,    62,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    21,    -1,    49,    50,    -1,    -1,    -1,
      28,    29,    56,    57,    58,    -1,    -1,    61,    62,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    21,
      -1,    49,    -1,    -1,    -1,    -1,    28,    29,    56,    57,
      58,    -1,    -1,    61,    62,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    21,    -1,    49,    50,    -1,
      -1,    -1,    28,    29,    56,    57,    58,    -1,    -1,    61,
      62,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    21,    -1,    49,    50,    -1,    -1,    -1,    28,    29,
      56,    57,    58,    -1,    -1,    61,    62,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    21,    -1,    49,
      50,    -1,    -1,    -1,    28,    29,    56,    57,    58,    -1,
      -1,    61,    62,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    21,    -1,    49,    -1,    -1,    -1,    -1,
      28,    29,    56,    57,    58,    -1,    -1,    61,    62,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    21,
      -1,    49,    -1,    -1,    -1,    -1,    28,    29,    56,    57,
      58,    -1,    -1,    61,    62,    37,    38,    39,    40,    41,
      42,     3,     4,     5,     6,    -1,     8,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,    38,    42,    49,    64,
      65,    66,    67,    69,    70,    71,    72,    80,    83,    84,
      85,    69,    38,    44,    38,    44,    71,    85,    86,    83,
       0,    65,    43,    74,    75,    83,    69,    69,    44,    67,
      68,    69,   102,    49,    51,    84,    44,    70,    71,    73,
      76,    77,    44,    38,    81,    82,    71,    85,    50,    43,
      46,    47,    68,   102,     9,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    28,    29,    37,    38,
      39,    40,    41,    42,    43,    45,    49,    56,    57,    58,
      61,    62,    68,    96,    97,    98,    99,   100,   101,   102,
     103,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   124,
      67,   102,    83,    38,    50,    69,    87,    88,    89,    90,
      38,    52,   104,   105,   117,    73,    77,    77,    45,    76,
      48,    78,    79,    83,    81,    47,    45,    46,    75,    44,
      91,   124,   102,    49,    49,    96,    49,   104,    49,    38,
      43,    43,    43,   122,    48,    49,   117,    49,   117,   117,
      48,    77,    93,   122,    45,   103,    45,    96,    31,    53,
      32,    54,    55,    56,    33,    34,    24,    25,    26,    27,
      35,    36,    57,    58,    42,    59,    60,     7,    47,   125,
     116,    23,    28,    29,    30,    49,    51,    43,    46,    49,
      51,    83,    85,    94,    95,    50,    46,    46,    50,    52,
      45,   104,    43,    46,    48,    45,   104,    82,    91,    92,
     122,   122,    15,    43,   122,    48,   122,    43,    43,    96,
      93,    96,    49,    85,    94,    50,    50,    45,   107,   122,
     108,   109,   110,   111,   112,   112,   113,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   116,   124,    38,    38,
      50,   123,   124,   122,   124,    50,    87,    94,    52,   104,
      95,    49,    51,    22,    89,    38,    79,   104,    45,    46,
      50,    50,    49,    43,   122,    43,    96,    50,    50,   116,
      48,    46,    50,    52,    50,    50,    52,    50,    87,    52,
     104,    45,    91,    96,    96,   122,    50,   122,    43,    43,
     122,    96,   105,   124,    50,    52,    10,    50,    96,    50,
      50,   122,    50,   122,    43,    96,    43,    96,    96,    50,
      96,    50,    50,   122,    96,    96,    96,    50,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    70,    70,    71,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    77,    77,    77,    77,    78,    78,
      79,    79,    79,    80,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    96,    96,    96,    96,    97,
      97,    97,    98,    98,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   103,   103,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   111,   112,   112,   112,   112,   112,   113,
     113,   113,   114,   114,   114,   115,   115,   115,   115,   116,
     116,   117,   117,   117,   117,   117,   117,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   120,   120,   121,   121,   121,   122,   122,
     123,   123,   124,   124,   125,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     4,     3,     3,     2,
       3,     2,     1,     2,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     5,     4,     2,     1,     2,     1,
       3,     1,     3,     3,     2,     1,     2,     1,     1,     3,
       1,     3,     2,     5,     4,     2,     1,     3,     1,     3,
       2,     1,     1,     3,     4,     3,     4,     4,     3,     2,
       1,     3,     2,     1,     2,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     3,     4,     1,     3,     2,
       1,     1,     2,     1,     3,     4,     3,     3,     2,     4,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     1,     5,     7,     5,     5,     7,     9,
       8,     8,     7,     8,     7,     7,     6,     3,     2,     2,
       3,     2,     4,     3,     3,     2,     1,     2,     1,     1,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       4,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     4,     3,     3,     2,
       2,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1
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
#line 38 "c.y" /* yacc.c:1646  */
    {
                                            tunit->pushDeclaration((yyvsp[0].decl));
                                            (yyval.tunt) = tunit;
                                            dprintf("Translation Unit1", "%s\n", tunit->toString());
                                        }
#line 1681 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 44 "c.y" /* yacc.c:1646  */
    {
                                            TranslationUnit* tunit = (yyvsp[-1].tunt);
                                            tunit->pushDeclaration((yyvsp[0].decl));
                                            (yyval.tunt) = tunit;
                                            dprintf("Translation Unit2", "%s\n", tunit->toString());
                                        }
#line 1692 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 53 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.decl) = (yyvsp[0].decl);
                                        }
#line 1700 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.decl) = (yyvsp[0].decl);
                                        }
#line 1708 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 71 "c.y" /* yacc.c:1646  */
    {
                                            char* funcname;
                                            Declaration* decl = (yyvsp[-1].decl);
                                            funcname = psbuff_realloc((yyvsp[-3].str),  (yyvsp[-2].str));
                                            funcname = psbuff_realloc(funcname, decl->toString());
                                            FunctionDefinition *fdef = new FunctionDefinition(decl->getLine(), funcname, (yyvsp[0].stmt));
                                            (yyval.decl) = fdef;
                                            dprintf("function def1", "%s %s %s\n", (yyvsp[-3].str), (yyvsp[-2].str), decl->toString());
                                        }
#line 1722 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "c.y" /* yacc.c:1646  */
    {
                                            char* funcname;
                                            Declaration* decl = (yyvsp[-1].decl);
                                            funcname = psbuff_realloc((yyvsp[-2].str), decl->toString());
                                            FunctionDefinition* fdef = new FunctionDefinition(decl->getLine(), funcname, (yyvsp[0].stmt));
                                            (yyval.decl) = fdef;
                                            dprintf("function def2", "%s %s\n", (yyvsp[-2].str), decl->toString());
                                        }
#line 1735 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "c.y" /* yacc.c:1646  */
    {
                                            char* funcname;
                                            funcname = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            FunctionDefinition* fdef = new FunctionDefinition((yyvsp[0].stmt)->getLine(), funcname, (yyvsp[0].stmt));
                                            (yyval.decl) = fdef;
                                            dprintf("function def3", "%s %s\n", (yyvsp[-2].str), (yyvsp[-1].str));
                                        }
#line 1747 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 98 "c.y" /* yacc.c:1646  */
    {
                                            // このLineだけdeclaratorを文字列で扱っている都合上断念。。。
                                            FunctionDefinition* fdef = new FunctionDefinition(g_line, (yyvsp[-1].str), (yyvsp[0].stmt));
                                            (yyval.decl) = fdef;
                                            dprintf("function def4", "%s\n", (yyvsp[-1].str));
                                        }
#line 1758 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));

                                            Declaration* decl = new Declaration(g_line, str);
                                            (yyval.decl) = decl;
                                            //dprintf("declaration1", "%s\n", decl->toString());
                                            dprintf("declaration1", "%s, %s, %s\n", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
                                        }
#line 1773 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 118 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));

                                            Declaration* decl = new Declaration(g_line, str);
                                            (yyval.decl) = decl;
                                            dprintf("declaration2", "%s\n", decl->toString());
                                        }
#line 1786 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.decl) = (yyvsp[0].decl);
                                        }
#line 1794 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "c.y" /* yacc.c:1646  */
    {
                                            Declaration* base = (yyvsp[-1].decl);
                                            base->pushSibling((yyvsp[0].decl));
                                            (yyval.decl) = base;
                                        }
#line 1804 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                            dprintf("declaration_spec1", "%s, %s\n", (yyvsp[-1].str),(yyvsp[0].str));
                                        }
#line 1815 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 148 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                            dprintf("declaration_spec2", "%s\n", (yyval.str));
                                        }
#line 1824 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                            dprintf("declaration_spec3", "%s\n", (yyval.str));
                                        }
#line 1835 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 160 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                            dprintf("declaration_spec4", "%s\n", (yyval.str));
                                        }
#line 1844 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 165 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                            dprintf("declaration_spec5", "%s\n", (yyval.str));
                                        }
#line 1855 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 172 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                            dprintf("declaration_spec6", "%s\n", (yyval.str));
                                        }
#line 1864 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 179 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 1872 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 183 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 1880 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 187 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 1888 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 194 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 1896 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-4].str), (yyvsp[-3].str));
                                            str = psbuff_realloc(str,     (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 1909 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 213 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-3].str), (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 1921 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 221 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 1931 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 229 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 1939 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 233 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 1949 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 245 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 1957 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 249 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 1968 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 258 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 1976 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 262 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 1987 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 271 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 1998 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 280 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2008 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 286 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2016 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 290 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2026 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 296 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2034 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 302 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2042 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 306 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2053 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 315 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2061 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 319 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2072 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 326 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2082 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 337 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-4].str), (yyvsp[-3].str));
                                            str = psbuff_realloc(str,     (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2095 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 346 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-3].str), (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2107 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 354 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2117 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 362 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2125 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 366 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2136 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 375 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2144 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 379 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2155 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 390 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                        }
#line 2163 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 394 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2171 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 400 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2179 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 404 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2190 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 411 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-3].str), (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2202 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 419 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2213 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 426 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-3].str), (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2225 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 434 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-3].str), (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2237 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 442 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2248 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 451 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2258 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 457 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2266 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 461 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2277 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 468 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2287 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 476 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                            dprintf("type_qualifier", "%s\n", (yyval.str));
                                        }
#line 2296 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 481 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                            dprintf("type_qualifier", "%s\n", (yyval.str));
                                        }
#line 2307 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 490 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2315 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 494 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                            dprintf("parameter_type_list", "%s\n", (yyval.str));
                                        }
#line 2327 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 504 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2335 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 508 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                            dprintf("parameter_list", "%s\n", (yyval.str));
                                        }
#line 2347 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 518 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2357 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 524 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2367 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 530 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2375 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 536 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2383 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 540 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2394 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 549 "c.y" /* yacc.c:1646  */
    {
                                            /* 初期化子は文字列扱いにする。 */
                                            Expression* expr = (yyvsp[0].expr);
                                            (yyval.str) = (char*)expr->toString();
                                        }
#line 2404 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 555 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2415 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 562 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-3].str), (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2427 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 572 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2435 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 576 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2446 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 585 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2456 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 591 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2464 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 597 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2472 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 601 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2482 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 607 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 2490 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 613 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2501 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 620 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-3].str), (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2513 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 628 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2524 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 635 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2535 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 642 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2545 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 648 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-3].str), (yyvsp[-2].str));
                                            str = psbuff_realloc(str,     (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2557 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 656 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-2].str), (yyvsp[-1].str));
                                            str = psbuff_realloc(str,     (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2568 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 663 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = psbuff_realloc((yyvsp[-2].str), "()");
                                        }
#line 2576 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 667 "c.y" /* yacc.c:1646  */
    {
                                            char* str;
                                            str = psbuff_realloc((yyvsp[-1].str), (yyvsp[0].str));
                                            (yyval.str) = str;
                                        }
#line 2586 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 687 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.stmt) = (yyvsp[0].stmt);
                                        }
#line 2594 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 691 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.stmt) = (yyvsp[0].stmt);
                                        }
#line 2602 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 695 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.stmt) = (yyvsp[0].stmt);
                                        }
#line 2610 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 699 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.stmt) = (yyvsp[0].stmt);
                                        }
#line 2618 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 703 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.stmt) = (yyvsp[0].stmt);
                                        }
#line 2626 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 707 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.stmt) = (yyvsp[0].stmt);
                                        }
#line 2634 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 713 "c.y" /* yacc.c:1646  */
    {
                                            LabeledStatement* lstmt = new LabeledStatement(g_line, (yyvsp[-2].str), (yyvsp[0].stmt));
                                            (yyval.stmt) = lstmt;
                                            dprintf("LabeledStatement", "%s--\n", lstmt->toString()); 
                                        }
#line 2644 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 719 "c.y" /* yacc.c:1646  */
    {
                                            CaseStatement* cstmt = new CaseStatement(g_line, (yyvsp[-2].expr), (yyvsp[0].stmt));
                                            (yyval.stmt) = cstmt;
                                            dprintf("LabeledStatement Case", "%s\n", cstmt->toString());
                                        }
#line 2654 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 725 "c.y" /* yacc.c:1646  */
    {
                                            DefaultStatement* dstmt = new DefaultStatement(g_line, (yyvsp[0].stmt));
                                            (yyval.stmt) = dstmt;
                                            dprintf("LabeledStatement Default", "%s\n", dstmt->toString());
                                        }
#line 2664 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 733 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr = (yyvsp[-1].expr);
                                            ExpressionStatement* stmt = new ExpressionStatement(g_line, expr);
                                            (yyval.stmt) = stmt;
                                            dprintf("Expression Statement", "%s\n", stmt->toString());
                                        }
#line 2675 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 740 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.stmt) = new NullStatement();
                                        }
#line 2683 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 746 "c.y" /* yacc.c:1646  */
    {
                                            IfStatement* ifstmt = new IfStatement((yyvsp[-2].expr)->getLine(), (yyvsp[-2].expr));
                                            ifstmt->setTrue((yyvsp[0].stmt));
                                            (yyval.stmt) = ifstmt;
                                            dprintf("IfStatement", "%s\n", ifstmt->toString());
                                        }
#line 2694 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 753 "c.y" /* yacc.c:1646  */
    {
                                            IfStatement* ifstmt = new IfStatement((yyvsp[-4].expr)->getLine(), (yyvsp[-4].expr));
                                            ifstmt->setTrue((yyvsp[-2].stmt));
                                            ifstmt->setElse((yyvsp[0].stmt)); (yyval.stmt) = ifstmt;
                                            dprintf("IfStatement", "%s\n", ifstmt->toString());
                                        }
#line 2705 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 760 "c.y" /* yacc.c:1646  */
    {
                                            SwtStatement* swt = new SwtStatement((yyvsp[-2].expr)->getLine(), (yyvsp[-2].expr), (yyvsp[0].stmt));
                                            (yyval.stmt) = swt;
                                            dprintf("SwitchStatement", "%s\n", swt->toString());
                                        }
#line 2715 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 768 "c.y" /* yacc.c:1646  */
    {
                                            WhileStatement* wstmt = new WhileStatement((yyvsp[-2].expr)->getLine(), (yyvsp[-2].expr), (yyvsp[0].stmt));
                                            (yyval.stmt) = wstmt;
                                            dprintf("WhileStatement", "%s\n", wstmt->toString());

                                        }
#line 2726 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 775 "c.y" /* yacc.c:1646  */
    {
                                            DoStatement* dstmt = new DoStatement((yyvsp[-2].expr)->getLine(), (yyvsp[-5].stmt), (yyvsp[-2].expr));
                                            (yyval.stmt) = dstmt;
                                            dprintf("DoStatement", "%s\n", dstmt->toString());
                                        }
#line 2736 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 781 "c.y" /* yacc.c:1646  */
    {
                                            ForStatement *fstmt = new ForStatement(
                                                                    (yyvsp[-6].expr)->getLine(), 
                                                                    (yyvsp[-6].expr),
                                                                    (yyvsp[-4].expr),
                                                                    (yyvsp[-2].expr),
                                                                    (yyvsp[0].stmt));
                                            (yyval.stmt) = fstmt;
                                            dprintf("ForStatement1", "%s\n", fstmt->toString());
                                        }
#line 2751 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 792 "c.y" /* yacc.c:1646  */
    {
                                            ForStatement *fstmt = new ForStatement(
                                                                    (yyvsp[-5].expr)->getLine(),
                                                                    (yyvsp[-5].expr),
                                                                    (yyvsp[-3].expr),
                                                                    new NullExpression(),
                                                                    (yyvsp[0].stmt));
                                            (yyval.stmt) = fstmt;
                                            dprintf("ForStatement2", "%s\n", fstmt->toString());
                                        }
#line 2766 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 803 "c.y" /* yacc.c:1646  */
    {
                                            ForStatement *fstmt = new ForStatement(
                                                                    (yyvsp[-5].expr)->getLine(),
                                                                    (yyvsp[-5].expr),
                                                                    new NullExpression(),
                                                                    (yyvsp[-2].expr),
                                                                    (yyvsp[0].stmt));
                                            (yyval.stmt) = fstmt;
                                            dprintf("ForStatement3", "%s\n", fstmt->toString());
                                        }
#line 2781 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 814 "c.y" /* yacc.c:1646  */
    {
                                            ForStatement *fstmt = new ForStatement(
                                                                    (yyvsp[-4].expr)->getLine(),
                                                                    (yyvsp[-4].expr),
                                                                    new NullExpression(),
                                                                    new NullExpression(),
                                                                    (yyvsp[0].stmt));
                                            (yyval.stmt) = fstmt;
                                            dprintf("ForStatement4", "%s\n", fstmt->toString());
                                        }
#line 2796 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 825 "c.y" /* yacc.c:1646  */
    {
                                            ForStatement *fstmt = new ForStatement(
                                                                    (yyvsp[-4].expr)->getLine(),
                                                                    new NullExpression(),
                                                                    (yyvsp[-4].expr),
                                                                    (yyvsp[-2].expr),
                                                                    (yyvsp[0].stmt));
                                            (yyval.stmt) = fstmt;
                                            dprintf("ForStatement5", "%s\n", fstmt->toString());
                                        }
#line 2811 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 836 "c.y" /* yacc.c:1646  */
    {
                                            ForStatement *fstmt = new ForStatement(
                                                                    (yyvsp[-3].expr)->getLine(),
                                                                    new NullExpression(),
                                                                    (yyvsp[-3].expr),
                                                                    new NullExpression(),
                                                                    (yyvsp[0].stmt));
                                            (yyval.stmt) = fstmt;
                                            dprintf("ForStatement6", "%s\n", fstmt->toString());
                                        }
#line 2826 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 847 "c.y" /* yacc.c:1646  */
    {
                                            ForStatement *fstmt = new ForStatement(
                                                                    (yyvsp[-2].expr)->getLine(),
                                                                    new NullExpression(),
                                                                    new NullExpression(),
                                                                    (yyvsp[-2].expr),
                                                                    (yyvsp[0].stmt));
                                            (yyval.stmt) = fstmt;
                                            dprintf("ForStatement7", "%s\n", fstmt->toString());
                                        }
#line 2841 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 858 "c.y" /* yacc.c:1646  */
    {
                                            ForStatement *fstmt = new ForStatement(
                                                                    g_line, 
                                                                    new NullExpression(),
                                                                    new NullExpression(),
                                                                    new NullExpression(),
                                                                    (yyvsp[0].stmt));
                                            (yyval.stmt) = fstmt;
                                            dprintf("ForStatement8", "%s\n", fstmt->toString());
                                        }
#line 2856 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 871 "c.y" /* yacc.c:1646  */
    {
                                            GotoStatement* gtstmt = new GotoStatement(g_line, (yyvsp[-1].str));
                                            (yyval.stmt) = gtstmt;
                                            dprintf("GotoStatement", "%s\n", gtstmt->toString());
                                        }
#line 2866 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 877 "c.y" /* yacc.c:1646  */
    {
                                            ContinueStatement* cstmt = new ContinueStatement(g_line);
                                            (yyval.stmt) = cstmt;
                                            dprintf("Continue Statement", "%s\n", cstmt->toString());
                                        }
#line 2876 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 883 "c.y" /* yacc.c:1646  */
    {
                                            BreakStatement* bstmt = new BreakStatement(g_line);
                                            (yyval.stmt) = bstmt;
                                            dprintf("Break Statement", "%s\n", bstmt->toString());
                                        }
#line 2886 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 889 "c.y" /* yacc.c:1646  */
    {
                                            ReturnStatement* rstmt = new ReturnStatement(g_line);
                                            rstmt->setExpression((yyvsp[-1].expr));
                                            (yyval.stmt) = rstmt;
                                            dprintf("Return Statement", "%s\n", rstmt->toString());
                                        }
#line 2897 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 896 "c.y" /* yacc.c:1646  */
    {
                                            ReturnStatement* rstmt = new ReturnStatement(g_line);
                                            (yyval.stmt) = rstmt;
                                            dprintf("Return Statement", "%s\n", rstmt->toString());
                                        }
#line 2907 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 907 "c.y" /* yacc.c:1646  */
    {
                                            Statement*         stmt  = (yyvsp[-1].stmt);
                                            CompoundStatement* cstmt = new CompoundStatement(stmt->getLine());
                                            cstmt->pushDeclaration((yyvsp[-2].decl));
                                            cstmt->pushStatement(stmt);
                                            (yyval.stmt) = cstmt;
                                            dprintf("Compound Statement1", "\n%s--\n", cstmt->toString());
                                        }
#line 2920 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 916 "c.y" /* yacc.c:1646  */
    {
                                            CompoundStatement* cstmt = new CompoundStatement((yyvsp[-1].decl)->getLine());
                                            cstmt->pushDeclaration((yyvsp[-1].decl));
                                            (yyval.stmt) = cstmt;
                                            dprintf("Compound Statement2", "\n%s--\n", cstmt->toString());
                                        }
#line 2931 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 923 "c.y" /* yacc.c:1646  */
    {
                                            CompoundStatement* cstmt = new CompoundStatement((yyvsp[-1].stmt)->getLine());
                                            cstmt->pushStatement((yyvsp[-1].stmt));
                                            (yyval.stmt) = cstmt;
                                            dprintf("Compound Statement3", "\n%s--\n", cstmt->toString());
                                        }
#line 2942 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 930 "c.y" /* yacc.c:1646  */
    {
                                            CompoundStatement* cstmt = new CompoundStatement(g_line);
                                            (yyval.stmt) = cstmt;
                                            dprintf("Compound Statement4", "\n%s--\n", cstmt->toString());
                                        }
#line 2952 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 938 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.stmt) = (yyvsp[0].stmt);
                                        }
#line 2960 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 942 "c.y" /* yacc.c:1646  */
    {
                                            Statement* base = (yyvsp[-1].stmt);
                                            Statement* stmt = (yyvsp[0].stmt);
                                            base->pushSibling(stmt);
                                            (yyval.stmt) = base;
                                        }
#line 2971 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 955 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                            dprintf("Constant Expression",  "%s\n", (yyvsp[0].expr)->toString());
                                        }
#line 2980 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 962 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                            Expression* expr = (yyvsp[0].expr);
                                        }
#line 2989 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 967 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr1 = new Expression(g_line, (yyvsp[-3].str));
                                            Expression* expr2 = new Expression(g_line, (yyvsp[-1].str));
                                            Expression* base = (yyvsp[-4].expr);
                                            base->pushSibling(expr1);
                                            base->pushSibling((yyvsp[-2].expr));
                                            base->pushSibling(expr2);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3004 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 980 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3012 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 984 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3024 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 994 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3032 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 998 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3044 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1008 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3052 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1012 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3064 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1022 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3072 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1026 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3084 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1036 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3092 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1040 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3104 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1050 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3112 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1054 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3124 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1062 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3136 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1072 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3144 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1076 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3156 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1084 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3168 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1092 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3180 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1100 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3192 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1110 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                            Expression* expr = (yyvsp[0].expr);
                                            dprintf("Shift Expression", "%s\n", expr->toString());
                                        }
#line 3202 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1116 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3214 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1124 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3226 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1134 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                            Expression* expr = (yyvsp[0].expr);
                                            dprintf("Additive Expression", "%s\n", expr->toString());
                                        }
#line 3236 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1140 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3248 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1148 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3260 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1158 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);

                                            Expression* expr = (yyvsp[0].expr);
                                            dprintf("Multiplicativ Expression", "%s\n", expr->toString());
                                        }
#line 3271 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1165 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3283 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1173 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3295 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1181 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression *base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                        }
#line 3307 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1191 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3315 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1195 "c.y" /* yacc.c:1646  */
    {
                                            size_t len = strlen((yyvsp[-2].str));
                                            char*  str = (char*)malloc(len + 3);

                                            sprintf(str, "(%s)", (yyvsp[-2].str));
                                            Expression *expr = new Expression(g_line, str);
                                            (yyval.expr) = expr;
                                        }
#line 3328 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1206 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3336 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1210 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr = new Expression(g_line, (yyvsp[-1].str));
                                            expr->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = expr;
                                        }
#line 3346 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1216 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr = new Expression(g_line, (yyvsp[-1].str));
                                            expr->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = expr;
                                        }
#line 3356 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1222 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr = new Expression(g_line, (yyvsp[-1].str));
                                            expr->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = expr;
                                        }
#line 3366 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1228 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr = new Expression(g_line, (yyvsp[-1].str));
                                            expr->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = expr;
                                        }
#line 3376 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1234 "c.y" /* yacc.c:1646  */
    {
                                            size_t len = strlen((yyvsp[-1].str));
                                            char*  str = (char*)malloc(len + 32);
                                            sprintf(str, "(%s)", (yyvsp[-1].str));
                                            Expression* expr1 = new Expression(g_line, "sizeof");
                                            Expression* expr2 = new Expression(g_line, str);
                                            expr1->pushSibling(expr2);
                                            (yyval.expr) = expr1;
                                        }
#line 3390 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1246 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3398 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1250 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3406 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1254 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3414 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1258 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3422 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1262 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3430 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1266 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3438 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1272 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                        }
#line 3446 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1276 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr1 = new Expression(g_line, "[");
                                            Expression* expr2 = new Expression(g_line, "]");
                                            Expression* base  = (yyvsp[-3].expr);
                                            base->pushSibling(expr1);
                                            base->pushSibling((yyvsp[-1].expr));
                                            base->pushSibling(expr2);
                                            (yyval.expr) = base;
                                        }
#line 3460 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1286 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr1 = new Expression(g_line, "(");
                                            Expression* expr2 = new Expression(g_line, ")");
                                            Expression* base  = (yyvsp[-2].expr);
                                            base->pushSibling(expr1);
                                            base->pushSibling(expr2);
                                            (yyval.expr) = base;
                                            dprintf("postfix expression", "%s\n", base->toString());
                                        }
#line 3474 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1296 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr1 = new Expression(g_line, "(");
                                            Expression* expr2 = new Expression(g_line, ")");
                                            Expression* base  = (yyvsp[-3].expr);
                                            base->pushSibling(expr1);
                                            base->pushSibling((yyvsp[-1].expr));
                                            base->pushSibling(expr2);
                                            (yyval.expr) = base;
                                            dprintf("postfix expression", "%s\n", base->toString());
                                        }
#line 3489 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1307 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr1 = new Expression(g_line, (yyvsp[-1].str));
                                            Expression* expr2 = new Expression(g_line, (yyvsp[0].str));
                                            Expression* base = (yyvsp[-2].expr);
                                            base->pushSibling(expr1);
                                            base->pushSibling(expr2);
                                            (yyval.expr) = base;
                                        }
#line 3502 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1316 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr1 = new Expression(g_line, (yyvsp[-1].str));
                                            Expression* expr2 = new Expression(g_line, (yyvsp[0].str));
                                            Expression* base = (yyvsp[-2].expr);
                                            base->pushSibling(expr1);
                                            base->pushSibling(expr2);
                                            (yyval.expr) = base;
                                        }
#line 3515 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1325 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr = new Expression(g_line, (yyvsp[0].str));
                                            Expression* base = (yyvsp[-1].expr);
                                            base->pushSibling(expr);
                                            (yyval.expr) = base;
                                        }
#line 3526 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1332 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr = new Expression(g_line, (yyvsp[0].str));
                                            Expression* base = (yyvsp[-1].expr);
                                            base->pushSibling(expr);
                                            (yyval.expr) = base;
                                        }
#line 3537 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1341 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[0].str));
                                            (yyval.expr) = expr;
                                        }
#line 3546 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1346 "c.y" /* yacc.c:1646  */
    {
                                            Expression *expr = new Expression(g_line, (yyvsp[0].str));
                                            (yyval.expr) = expr;
                                        }
#line 3555 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1351 "c.y" /* yacc.c:1646  */
    {
                                            Expression* expr = new Expression(g_line, (yyvsp[0].str));
                                            (yyval.expr) = expr;
                                        }
#line 3564 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1356 "c.y" /* yacc.c:1646  */
    {
                                            Expression* base = new Expression(g_line, "(");
                                            Expression* expr = new Expression(g_line, ")");
                                            base->pushSibling((yyvsp[-1].expr));
                                            base->pushSibling(expr);
                                            (yyval.expr) = base;
                                        }
#line 3576 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1366 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3584 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1370 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3592 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1374 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3600 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1389 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr); 
                                            dprintf("Expression1", "%s\n", (yyvsp[0].expr)->toString());
                                        }
#line 3609 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1394 "c.y" /* yacc.c:1646  */
    {
                                            /* 境界が分かるように "," もExpressionにしておく */
                                            Expression* expr1 = new Expression(g_line, (yyvsp[-1].str));
                                            Expression* expr2 = (yyvsp[0].expr);
                                            Expression* base = (yyvsp[-2].expr);
                                            base->pushSibling(expr1);
                                            base->pushSibling(expr2);
                                            (yyval.expr) = base;
                                            dprintf("Expression2", "%s\n", base->toString());
                                        }
#line 3624 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1407 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                            dprintf("Assignment Expression List1", "%s\n", (yyvsp[0].expr)->toString());
                                        }
#line 3633 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1412 "c.y" /* yacc.c:1646  */
    {
                                            Expression* base = (yyvsp[-2].expr);
                                            Expression* expr = new Expression(g_line, (yyvsp[-1].str));
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                            dprintf("Assignment Expression List2", "%s\n", base->toString());
                                        }
#line 3646 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1423 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.expr) = (yyvsp[0].expr);
                                            dprintf("Assignment Expression1", "%s\n", (yyvsp[0].expr)->toString());
                                        }
#line 3655 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1428 "c.y" /* yacc.c:1646  */
    {
                                            /* operatorを考慮しだすと複雑になるのでexpressionに含める */
                                            Expression* expr = new Expression(g_line, (yyvsp[-1].str));
                                            Expression* base = (yyvsp[-2].expr);
                                            base->pushSibling(expr);
                                            base->pushSibling((yyvsp[0].expr));
                                            (yyval.expr) = base;
                                            dprintf("Assignment Expression2", "%s\n", base->toString());
                                        }
#line 3669 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1440 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3677 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1444 "c.y" /* yacc.c:1646  */
    {
                                            (yyval.str) = (yyvsp[0].str);
                                        }
#line 3685 ".yaccwork/cy.cpp" /* yacc.c:1646  */
    break;


#line 3689 ".yaccwork/cy.cpp" /* yacc.c:1646  */
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
#line 1449 "c.y" /* yacc.c:1906  */


