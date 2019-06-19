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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

FILE *file; // To generate .j file for Jasmin

void semantic_error(char errormsg[100], int sem_line);
int error_flag;
char sem_error_msg[100];

void syntax_error(char errormsg[100]);
int syntax_flag;
char syn_error_msg[100];

char function_name[100];

/* Symbol table function - you can add new function if needed. */
struct symbol
{
	int index;
	char name[100];
	char kind[100];
	char type[100];
	int scope;
	char attribute[100];
	int register_num;
	int func_decla;
};

struct scope
{
	struct symbol table[30];
};

int lookup_symbol(char[], char[]);
void create_symbol();
void insert_symbol(char[], char[], char[], char[], int);
void dump_symbol(int);
int dump_flag;

struct scope global_table[40];
int table_num;

struct scope temp_dump_table;
void clear_temp_table();
void fill_temp_table();

void init_func_table();
void insert_func_table(char[]);
int lookup_func_table(char[]);
struct func_table
{
	int flag;
	char name[100];
}implement_func_table[30];
int func_flag;

int lookup_register_num(char[]);
char* lookup_type(char[]);
int register_site;

char func_para_type[100];
char* lookup_attribute(char[]);
char* changeto_java_type();
void gen_print(char[]);
void gen_ID(char[]);
struct expre {
	int kind;
	int regnum;
	int i_val;
	float f_val;
	char type[30];
}expre_factor[2];
int expre_site;
void set_expre_factor(int, int, int, float, char[]);
void clear_expre_factor();

int func_index;
void gen_function();
struct check_index {
	int has;
	int cur_func_index;
}check_index;
void set_para(char[]);
void set_func_decla(int);
int get_func_decla();


#line 163 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    MOD = 262,
    ASGN = 263,
    ADDASGN = 264,
    SUBASGN = 265,
    MULASGN = 266,
    DIVASGN = 267,
    MODASGN = 268,
    AND = 269,
    OR = 270,
    NOT = 271,
    PRINT = 272,
    IF = 273,
    ELSE = 274,
    FOR = 275,
    WHILE = 276,
    RET = 277,
    START_COMMENT = 278,
    END_COMMENT = 279,
    CPLUS_COMMENT = 280,
    I_CONST = 281,
    F_CONST = 282,
    S_CONST = 283,
    TRUE = 284,
    FALSE = 285,
    INC = 286,
    DEC = 287,
    MT = 288,
    LT = 289,
    MTE = 290,
    LTE = 291,
    EQ = 292,
    NE = 293,
    ID = 294,
    INT = 295,
    FLOAT = 296,
    BOOL = 297,
    STRING = 298,
    VOID = 299,
    SEMICOLON = 300,
    LB = 301,
    RB = 302,
    LCB = 303,
    RCB = 304,
    LSB = 305,
    RSB = 306,
    COMMA = 307
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define MOD 262
#define ASGN 263
#define ADDASGN 264
#define SUBASGN 265
#define MULASGN 266
#define DIVASGN 267
#define MODASGN 268
#define AND 269
#define OR 270
#define NOT 271
#define PRINT 272
#define IF 273
#define ELSE 274
#define FOR 275
#define WHILE 276
#define RET 277
#define START_COMMENT 278
#define END_COMMENT 279
#define CPLUS_COMMENT 280
#define I_CONST 281
#define F_CONST 282
#define S_CONST 283
#define TRUE 284
#define FALSE 285
#define INC 286
#define DEC 287
#define MT 288
#define LT 289
#define MTE 290
#define LTE 291
#define EQ 292
#define NE 293
#define ID 294
#define INT 295
#define FLOAT 296
#define BOOL 297
#define STRING 298
#define VOID 299
#define SEMICOLON 300
#define LB 301
#define RB 302
#define LCB 303
#define RCB 304
#define LSB 305
#define RSB 306
#define COMMA 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 102 "compiler_hw3.y" /* yacc.c:355  */

	struct atom {
   		int i_val;
    	double f_val;
    	char* string_val;
		char type[30];
	}atom;

#line 316 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 333 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   150,   154,   155,   156,   160,   161,   162,
     163,   164,   165,   169,   170,   174,   175,   176,   181,   180,
     222,   233,   245,   244,   262,   306,   346,   382,   381,   411,
     418,   428,   438,   451,   455,   459,   463,   470,   480,   489,
     499,   498,   518,   527,   531,   556,   563,   568,   573,   580,
     585,   590,   608,   615,   626,   637,   648,   659,   674,   681,
     720,   757,   780,   803,   803,   803,   810,   810,   811,   810,
     820,   821,   825,   825,   826,   825,   832,   832,   842,   843,
     854,   855,   856,   857,   858,   859,   863,   870,   877,   883,
     889,   895,   901,   918,   919,   923,   924,   925,   929,   930,
     931,   932,   933,   934,   938,   939,   944,   945,   946,   947,
     948
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "MOD",
  "ASGN", "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND",
  "OR", "NOT", "PRINT", "IF", "ELSE", "FOR", "WHILE", "RET",
  "START_COMMENT", "END_COMMENT", "CPLUS_COMMENT", "I_CONST", "F_CONST",
  "S_CONST", "TRUE", "FALSE", "INC", "DEC", "MT", "LT", "MTE", "LTE", "EQ",
  "NE", "ID", "INT", "FLOAT", "BOOL", "STRING", "VOID", "SEMICOLON", "LB",
  "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "$accept", "program", "stat",
  "func_stat", "func_mul_stat", "return_stat", "func", "$@1", "func_end",
  "$@2", "declaration", "declaration_func", "$@3", "func_parameter",
  "func_call", "const", "expression", "$@4", "expression_stat",
  "add_expression_stat", "mul_expression_stat", "factor", "iteration_stat",
  "$@5", "$@6", "$@7", "$@8", "$@9", "haselse", "haselseif", "$@10",
  "$@11", "$@12", "$@13", "moreelseif", "relational", "print_func",
  "print_type", "comment_stat", "initializer", "asgn",
  "arithmetic_postfix", "type", YY_NULLPTR
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
     305,   306,   307
};
# endif

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -91,     4,   -91,    25,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -11,   -91,    -3,   136,   -91,   -91,
     -16,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -24,    86,
     197,    20,    62,   -91,     9,    12,    87,   -91,   -91,    31,
     -91,   143,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    86,
      86,    86,    86,    86,    86,   -91,   -91,   -14,   -91,   -38,
      13,   -91,   -91,   -91,   -91,   -26,   -91,   150,   -91,    20,
      62,    62,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    42,
     -91,   -91,   165,   184,   -14,    16,   -91,    19,    26,    33,
     115,     7,   -91,   184,    22,   -91,   -91,   -91,   -91,   -91,
      56,    57,   -91,   -91,    72,    86,    86,   -91,   -91,   203,
      52,   -91,   -91,   -91,   -91,   -91,   -91,    77,    86,    65,
     -91,   -91,    69,     5,     6,    55,    68,    73,    74,   -91,
     150,   150,   -91,   -91,    81,   -22,   216,   -91,   -91,    75,
      88,    91,    94,   103,   104,   105,   106,   -91,   -91,   -91,
     110,   111,   -91,   -91,   -91,   -91,    85,   122,   113,   -91,
     -91,   -91,   -91,   -91,   184,   184,   102,   123,   -91,   -91,
     152,   -12,   -91,   127,   -91,   -91,    86,   184,   150,   125,
     142,   -91,   151,   -91,   184,   149,   -91,   181,   -12,   -91,
     -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    93,   106,   107,   108,   109,   110,
       2,     4,     5,     6,     0,    94,     0,     0,    25,    27,
       0,    53,    54,    95,    96,    97,   104,   105,    57,     0,
       0,    45,    48,    52,     0,     0,     0,    55,    56,     0,
      59,     0,    80,    81,    82,    83,    84,    85,    26,     0,
       0,     0,     0,     0,     0,    24,    60,     0,    28,     0,
       0,    33,    35,    36,    62,     0,    32,    34,    58,    44,
      46,    47,    49,    50,    51,    21,    22,    20,    18,     0,
      30,    61,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,    43,    14,     0,     7,     8,     9,    10,    11,
       0,     0,    19,    29,     0,     0,     0,    17,    12,     0,
       0,    98,    99,   100,   101,   102,   103,     0,     0,     0,
      13,    23,     0,     0,     0,     0,     0,     0,     0,    86,
      66,    63,    16,    15,     0,     0,     0,    38,    39,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    40,    37,
       0,     0,    88,    89,    87,    92,     0,     0,     0,    90,
      91,    67,    64,    41,     0,     0,     0,     0,    68,    65,
      71,     0,    69,     0,    76,    70,     0,     0,    72,     0,
       0,    77,     0,    73,     0,     0,    74,    79,     0,    75,
      78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   -91,   -90,   -91,   -91,   -91,   119,   -91,
     207,   -91,   -91,   -91,    93,   130,   -91,   -91,   -17,   164,
     -10,    39,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    29,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   213,   128,
     -91,   -27,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    10,    93,    94,   108,    58,    84,    77,    83,
      95,    12,    36,    59,    65,    66,    96,   158,    67,    31,
      32,    33,    97,   146,   165,   145,   164,   170,   172,   175,
     180,   184,   187,   177,   189,    49,    98,   129,    99,    34,
     118,    35,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,    40,    14,   120,     2,    17,   173,    26,    27,    78,
      37,    38,    41,    17,    79,   111,   112,   113,   114,   115,
     116,    81,    39,    50,    51,   148,    82,     3,    16,     4,
      82,    75,   139,   140,    76,    20,   174,    60,    26,    27,
      70,    71,    18,    19,     5,     6,     7,     8,     9,    15,
      18,    56,    80,   117,    55,   103,   100,    21,    22,    61,
      62,    63,    26,    27,   119,   104,   100,    52,    53,    54,
      28,   121,   105,   109,   166,   167,   124,    29,    64,   106,
      85,    20,     5,     6,     7,     8,     9,   179,   130,   131,
      20,    72,    73,    74,   185,   122,   123,   133,   125,   126,
     127,   136,   141,    21,    22,    61,    62,    63,    26,    27,
     137,   128,    21,    22,   138,   142,    28,    26,    27,    20,
     143,   144,   150,    29,   134,    28,   147,     5,     6,     7,
       8,     9,    29,   161,    57,   151,   152,   100,   100,   153,
      20,    21,    22,    23,    24,    25,    26,    27,   154,   155,
     100,   168,   156,   157,    28,   159,   160,   100,   163,   178,
     107,    29,    21,    22,    23,    24,    25,    26,    27,    20,
     162,   171,   169,   176,   181,    28,    42,    43,    44,    45,
      46,    47,    29,    42,    43,    44,    45,    46,    47,   182,
      68,    21,    22,    61,    62,    63,    26,    27,   186,   183,
     188,    87,    88,   102,    28,    89,    90,     3,    11,     4,
     135,    29,    86,    69,    13,    26,    27,   190,   110,     0,
       0,     0,     0,    91,     5,     6,     7,     8,     9,    92,
      42,    43,    44,    45,    46,    47,    42,    43,    44,    45,
      46,    47,    48,     0,     0,     0,     0,     0,   132,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,   149
};

static const yytype_int16 yycheck[] =
{
      17,    28,     1,    93,     0,     8,    18,    31,    32,    47,
      26,    27,    29,     8,    52,     8,     9,    10,    11,    12,
      13,    47,    46,     3,     4,    47,    52,    23,    39,    25,
      52,    45,    26,    27,    48,     4,    48,    36,    31,    32,
      50,    51,    45,    46,    40,    41,    42,    43,    44,    24,
      45,    39,    39,    46,    45,    39,    83,    26,    27,    28,
      29,    30,    31,    32,    91,    46,    93,     5,     6,     7,
      39,    49,    46,    90,   164,   165,     4,    46,    47,    46,
      79,     4,    40,    41,    42,    43,    44,   177,   105,   106,
       4,    52,    53,    54,   184,    39,    39,    45,    26,    27,
      28,   118,    47,    26,    27,    28,    29,    30,    31,    32,
      45,    39,    26,    27,    45,    47,    39,    31,    32,     4,
      47,    47,    47,    46,    47,    39,    45,    40,    41,    42,
      43,    44,    46,    48,    47,    47,    45,   164,   165,    45,
       4,    26,    27,    28,    29,    30,    31,    32,    45,    45,
     177,    49,    47,    47,    39,    45,    45,   184,    45,   176,
      45,    46,    26,    27,    28,    29,    30,    31,    32,     4,
      48,    19,    49,    46,    49,    39,    33,    34,    35,    36,
      37,    38,    46,    33,    34,    35,    36,    37,    38,    47,
      47,    26,    27,    28,    29,    30,    31,    32,    49,    48,
      19,    17,    18,    84,    39,    21,    22,    23,     1,    25,
     117,    46,    82,    49,     1,    31,    32,   188,    90,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      33,    34,    35,    36,    37,    38,    33,    34,    35,    36,
      37,    38,    45,    -1,    -1,    -1,    -1,    -1,    45,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,    23,    25,    40,    41,    42,    43,    44,
      55,    63,    64,    91,    95,    24,    39,     8,    45,    46,
       4,    26,    27,    28,    29,    30,    31,    32,    39,    46,
      71,    72,    73,    74,    92,    94,    65,    26,    27,    46,
      94,    71,    33,    34,    35,    36,    37,    38,    45,    88,
       3,     4,     5,     6,     7,    45,    39,    47,    59,    66,
      95,    28,    29,    30,    47,    67,    68,    71,    47,    72,
      73,    73,    74,    74,    74,    45,    48,    61,    47,    52,
      39,    47,    52,    62,    60,    95,    68,    17,    18,    21,
      22,    39,    45,    56,    57,    63,    69,    75,    89,    91,
      94,    95,    61,    39,    46,    46,    46,    45,    58,    71,
      92,     8,     9,    10,    11,    12,    13,    46,    93,    94,
      57,    49,    39,    39,     4,    26,    27,    28,    39,    90,
      71,    71,    45,    45,    47,    67,    71,    45,    45,    26,
      27,    47,    47,    47,    47,    78,    76,    45,    47,    45,
      47,    47,    45,    45,    45,    45,    47,    47,    70,    45,
      45,    48,    48,    45,    79,    77,    57,    57,    49,    49,
      80,    19,    81,    18,    48,    82,    46,    86,    71,    57,
      83,    49,    47,    48,    84,    57,    49,    85,    19,    87,
      82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    58,    60,    59,
      59,    61,    62,    61,    63,    63,    63,    65,    64,    66,
      66,    67,    67,    68,    68,    68,    68,    69,    69,    69,
      70,    69,    69,    69,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    76,    77,    75,    78,    79,    80,    75,
      81,    81,    83,    84,    85,    82,    86,    82,    87,    87,
      88,    88,    88,    88,    88,    88,    89,    90,    90,    90,
      90,    90,    90,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    95,    95,    95,    95,
      95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     1,     0,     4,
       2,     1,     0,     4,     5,     3,     5,     0,     5,     4,
       2,     3,     1,     1,     1,     1,     1,     4,     3,     3,
       0,     6,     4,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     1,     2,     2,     1,     3,     2,
       2,     4,     3,     0,     0,     9,     0,     0,     0,    11,
       2,     0,     0,     0,     0,    11,     0,     4,     2,     0,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       4,     4,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
        case 16:
#line 175 "compiler_hw3.y" /* yacc.c:1646  */
    { expre_site = 0; }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 181 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char attr[100];
		bzero(attr, 100);
		int flag = 0;
		for(int i=0;i<30;i++) {
			if(global_table[1].table[i].index != -1) {
				if(!strcmp(global_table[1].table[i].kind, "parameter")) {
					if(flag == 1) {
						strcat(attr, ", ");
					}
					strcat(attr, global_table[1].table[i].type);
					flag = 1;
				}
			}
			else break;
		}
		if(check_index.has == 0) {
			// first
			set_para(attr);
			// fill func_para_type
			strcpy(func_para_type, global_table[0].table[check_index.cur_func_index].attribute);
		}
		else {
			// check parameter
			if(strcmp(attr, global_table[0].table[check_index.cur_func_index].attribute)) {
				// paramater is not the same
				error_flag = 1;
				bzero(sem_error_msg, 100);
				strcat(sem_error_msg, "function formal parameter is not the same");
			}
		}
	}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 214 "compiler_hw3.y" /* yacc.c:1646  */
    {
		//if(!strcmp($3.string_val, ";")) {
		if(!strcmp((yyvsp[0].atom).string_val, ";")) {
			table_num--;
			func_flag = 1;
		}
		//else func_flag = 1;
	}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[0].atom).string_val, ";")) {
			table_num--;
			func_flag = 1;
		}
		//else func_flag = 1;
	}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 234 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(get_func_decla() == 1) {
			// redefine function
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, global_table[0].table[check_index.cur_func_index].name);
		}
		else set_func_decla(1);
	}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 245 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gen_function();
	}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 249 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(!strcmp(global_table[0].table[check_index.cur_func_index].type, "void")) fprintf(file, "\treturn\n");
		else fprintf(file, "\tfreturn\n");
		fprintf(file, ".end method\n");
		register_site = 0;
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 263 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[-3].atom).string_val, "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[-3].atom).string_val, "variable", (yyvsp[-4].atom).string_val, "\0", index);
			// global declaration
			if(table_num == 0) {
				char type_descriptor[20];
				if(!strcmp((yyvsp[-4].atom).string_val, "bool")) {
					strcpy(type_descriptor,"F");
					float booltype;
					if(!strcmp((yyvsp[-1].atom).string_val, "true")) booltype = 1.0;
					else booltype = 0.0;
    				fprintf(file, ".field public static %s %s = %f\n", (yyvsp[-3].atom).string_val, type_descriptor, booltype);
				}
				else if(!strcmp((yyvsp[-4].atom).string_val, "string")) {
					strcpy(type_descriptor,"Ljava/lang/String;");
					char *strconst = strtok((yyvsp[-1].atom).string_val, "\"");
    				fprintf(file, ".field public static %s %s = \"%s\"\n", (yyvsp[-3].atom).string_val, type_descriptor, strconst);
				}
			}
			// local declaration
			else {
				if(!strcmp((yyvsp[-4].atom).string_val, "bool")) {
					int booltype;
					if(!strcmp((yyvsp[-1].atom).string_val, "true")) booltype = 1;
					else booltype = 0;
					fprintf(file, "\tldc %d\n", booltype);
					fprintf(file, "\tistore %d\n", index);
				}
				else if(!strcmp((yyvsp[-4].atom).string_val, "string")) {
					char *strconst = strtok((yyvsp[-1].atom).string_val, "\"");
					fprintf(file, "\tldc \"%s\"\n", strconst);
					fprintf(file, "\tastore %d\n", index);
				}
			}
		}
		else {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
	}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 307 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[-1].atom).string_val, "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[-1].atom).string_val, "variable", (yyvsp[-2].atom).string_val, "\0", index);
			// global declaration
			if(table_num == 0) {
				char type_descriptor[20];
				if(!strcmp((yyvsp[-2].atom).string_val, "string")) {
					strcpy(type_descriptor, "Ljava/lang/String;");
    				fprintf(file, ".field public static %s %s\n", (yyvsp[-1].atom).string_val, type_descriptor);
				}
				else {
					// float, int, bool
					strcpy(type_descriptor, "F");
    				fprintf(file, ".field public static %s %s\n", (yyvsp[-1].atom).string_val, type_descriptor);
				}
			}
			// local declaration
			else {
				char type_descriptor[20];
    			fprintf(file, "\tldc 0\n");
				if(!strcmp((yyvsp[-2].atom).string_val, "string")) {
					strcpy(type_descriptor, "Ljava/lang/String;");
					fprintf(file, "\tastore 0\n");
				}
				else {
					// float, int, bool
					strcpy(type_descriptor, "F");
    				fprintf(file, "\tfstore 0\n");
				}
			}
		}
		else {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, (yyvsp[-1].atom).string_val);
		}
	}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 347 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[-3].atom).string_val, "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[-3].atom).string_val, "variable", (yyvsp[-4].atom).string_val, "\0", index);
			// global declaration
			if(table_num == 0) {
				char type_descriptor[30];
				// float, int
				strcpy(type_descriptor, "F");
				fprintf(file, ".field public static %s %s = %f\n", (yyvsp[-3].atom).string_val, type_descriptor, (yyvsp[-1].atom).f_val);	
			}
			// local declaration
			else {
				int regnum = lookup_register_num((yyvsp[-3].atom).string_val);
				if(!strcmp((yyvsp[-4].atom).string_val, "string")) {
					fprintf(file, "\tastore %d\n", regnum);
				}
				else {
					// float, int, bool
					fprintf(file, "\tfstore %d\n", regnum);
				}
			}
			expre_site = 0;
		}
		else {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
	}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 382 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		int has = lookup_symbol((yyvsp[-1].atom).string_val, "global"); 
		int index = lookup_symbol((yyvsp[-1].atom).string_val, "insert");
		if(has == -1) {
			// first time
			check_index.cur_func_index = index;
			check_index.has = 0;
			if(index != -1) {
				insert_symbol((yyvsp[-1].atom).string_val, "function", (yyvsp[-2].atom).string_val, "", index);
			}
		}
		else {
			// declare or define before
			check_index.cur_func_index = has;
			check_index.has = 1;
			if(strcmp((yyvsp[-2].atom).string_val, global_table[0].table[has].type)) {
				// return type not the same
				error_flag = 1;
				bzero(sem_error_msg, 100);
				strcat(sem_error_msg, "function return type is not the same");
			}
		}
		table_num++; 
		create_symbol();
	}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 412 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[0].atom).string_val, "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[0].atom).string_val, "parameter", (yyvsp[-1].atom).string_val, "\0", index);
		}
	}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 419 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[0].atom).string_val, "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[0].atom).string_val, "parameter", (yyvsp[-1].atom).string_val, "\0", index);
		}
	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 429 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(strcmp(func_para_type, "")) {
			strcat(func_para_type, ", ");
			strcat(func_para_type, (yyvsp[0].atom).type);
		}
		else {
			strcpy(func_para_type, (yyvsp[0].atom).type);
		}
	}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 439 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(strcmp(func_para_type, "")) {
			strcat(func_para_type, ", ");
			strcat(func_para_type, (yyvsp[0].atom).type);
		}
		else {
			strcpy(func_para_type, (yyvsp[0].atom).type);
		}
	}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 452 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy((yyval.atom).type, "string");
	}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 456 "compiler_hw3.y" /* yacc.c:1646  */
    {
		expre_site = 0;
	}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 460 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy((yyval.atom).type, "bool");
	}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 464 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy((yyval.atom).type, "bool");
	}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 471 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
		expre_site = 0;
	}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 481 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-2].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-2].atom).string_val);
		}
	}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 490 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-1].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-1].atom).string_val);
		}
	}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 499 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(lookup_symbol((yyvsp[-3].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
		if(strcmp(lookup_attribute((yyvsp[-3].atom).string_val), func_para_type)) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		char* paratype;
		changeto_java_type(paratype);
		char* returntype = lookup_type((yyvsp[-3].atom).string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "\tinvokestatic compiler_hw3/%s(%s)%s\n", (yyvsp[-3].atom).string_val, paratype, returntype);
	}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 519 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
	}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 532 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int flag = 0;
		if(!strcmp((yyvsp[-1].atom).string_val, ">")) {
			if((yyvsp[-2].atom).f_val > (yyvsp[0].atom).f_val) flag = 1;
		}
		else if(!strcmp((yyvsp[-1].atom).string_val, "<")) {
			if((yyvsp[-2].atom).f_val < (yyvsp[0].atom).f_val) flag = 1;
		}
		else if(!strcmp((yyvsp[-1].atom).string_val, ">=")) {
			if((yyvsp[-2].atom).f_val >= (yyvsp[0].atom).f_val) flag = 1;
		}
		else if(!strcmp((yyvsp[-1].atom).string_val, "<=")) {
			if((yyvsp[-2].atom).f_val <= (yyvsp[0].atom).f_val) flag = 1;
		}
		else if(!strcmp((yyvsp[-1].atom).string_val, "==")) {
			if((yyvsp[-2].atom).f_val == (yyvsp[0].atom).f_val) flag = 1;
		}
		else if(!strcmp((yyvsp[-1].atom).string_val, "!=")) {
			if((yyvsp[-2].atom).f_val != (yyvsp[0].atom).f_val) flag = 1;
		}
		if(flag == 1) (yyval.atom).f_val = 1.0;
		else (yyval.atom).f_val = 0.0;
		strcpy((yyval.atom).type, "bool");
	}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 557 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom) = (yyvsp[0].atom);
	}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 564 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tfadd\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 569 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tfsub\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 574 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom) = (yyvsp[0].atom);
	}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 581 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tfmul\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 586 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tfdiv\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 591 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char type1[30], type2[30];
		strcpy(type1, (yyvsp[-2].atom).type);
		strcpy(type2, (yyvsp[0].atom).type);
		if(!strcmp(type1, "int") && !strcmp(type2, "int")) {

			fprintf(file, "\tirem\n");
		}
		else {
			// semantic error
			// Modulo operator (%) with floating point operands
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Modulo operator (%) with floating point operands");
		}
		(yyval.atom).f_val = -1.0;
	}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 609 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom) = (yyvsp[0].atom);
	}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 616 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, $1.i_val, -1, "int");
			fprintf(file, "\tldc %f\n", (float)(yyvsp[0].atom).i_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = (float)(yyvsp[0].atom).i_val;
		strcpy((yyval.atom).type, "int");
	}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 627 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, -1, $1.f_val, "float");
			fprintf(file, "\tldc %f\n", (yyvsp[0].atom).f_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = (yyvsp[0].atom).f_val;
		strcpy((yyval.atom).type, "float");
	}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 638 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, -$2.i_val, -1, "int");
			fprintf(file, "\tldc -%f\n", (float)(yyvsp[0].atom).i_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = -(float)(yyvsp[0].atom).i_val;
		strcpy((yyval.atom).type, "int");
	}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 649 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, -1, -$2.i_val, "float");
			fprintf(file, "\tldc -%f\n", (yyvsp[0].atom).f_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = -(yyvsp[0].atom).f_val;
		strcpy((yyval.atom).type, "float");
	}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 660 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[0].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[0].atom).string_val);
		}
		else {
			gen_ID((yyvsp[0].atom).string_val);
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[0].atom).string_val));
		}
	}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 675 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// set_expre_factor(0, -1, -1, -$2.i_val, "float");
		// assign to factor
		(yyval.atom).f_val = -1.0;
		//strcpy($$.type, lookup_type($2.string_val));
	}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 682 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-1].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-1].atom).string_val);
		}
		else {
			int regnum = lookup_register_num((yyvsp[-1].atom).string_val);
			// global variable
			if(regnum == -1) {
				fprintf(file, "\tgetstatic compiler_hw3/%s\n", (yyvsp[-1].atom).string_val);	
			}
			// local variable
			else {
				// only int has ++ and --
				if(!strcmp((yyvsp[0].atom).string_val, "++")) {
					fprintf(file, "\tfload %d\n", regnum);
					fprintf(file, "\tldc 1.0\n");
					fprintf(file, "\tfadd\n");
					fprintf(file, "\tfstore %d\n", regnum);
					fprintf(file, "\tfload %d\n", regnum);
					fprintf(file, "\tfsub\n");
				}
				else {
					fprintf(file, "\tfload %d\n", regnum);
					fprintf(file, "\tldc 1.0\n");
					fprintf(file, "\tfsub\n");
					fprintf(file, "\tfstore %d\n", regnum);
					fprintf(file, "\tfload %d\n", regnum);
					fprintf(file, "\tfadd\n");
				}
			}
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[-1].atom).string_val));
		}
	}
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 721 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[0].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[0].atom).string_val);
		}
		else {
			int regnum = lookup_register_num((yyvsp[0].atom).string_val);
			// global variable
			if(regnum == -1) {
				fprintf(file, "\tgetstatic compiler_hw3/%s\n", (yyvsp[0].atom).string_val);
			}
			// local variable
			else {
				// only int has ++ and --
				if(!strcmp((yyvsp[-1].atom).string_val, "++")) {
					fprintf(file, "\tfload %d\n", regnum);
					fprintf(file, "\tldc 1.0\n");
					fprintf(file, "\tfadd\n");
					fprintf(file, "\tfstore %d\n", regnum); // store back to register
					fprintf(file, "\tfload %d\n", regnum); // put on TOS
				}
				else {
					fprintf(file, "\tfload %d\n", regnum);
					fprintf(file, "\tldc 1.0\n");
					fprintf(file, "\tfsub\n");
					fprintf(file, "\tfstore %d\n", regnum); // store back to register
					fprintf(file, "\tfload %d\n", regnum); // put on TOS
				}
			}
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[0].atom).string_val));
		}
	}
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 758 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
		if(strcmp(lookup_attribute((yyvsp[-3].atom).string_val), func_para_type)) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		char paratype[100];
		strcpy(paratype, changeto_java_type());
		char* returntype = lookup_type((yyvsp[-3].atom).string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "\tinvokestatic compiler_hw3/%s(%s)%s\n", (yyvsp[-3].atom).string_val, paratype, returntype);
		memset(func_para_type, '\0', sizeof(func_para_type));
		// assign function return to factor
		(yyval.atom).f_val = -1.0;
	}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 781 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-2].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, (yyvsp[-2].atom).string_val);
		}
		if(strcmp(lookup_attribute((yyvsp[-2].atom).string_val), "")) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		char* returntype = lookup_type((yyvsp[-2].atom).string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "\tinvokestatic compiler_hw3/%s()%s\n", (yyvsp[-2].atom).string_val, returntype);
		// assign function return to factor
		(yyval.atom).f_val = -1.0;
	}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 803 "compiler_hw3.y" /* yacc.c:1646  */
    { expre_site = 0; }
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 803 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 804 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 810 "compiler_hw3.y" /* yacc.c:1646  */
    { expre_site = 0; }
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 810 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 811 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 825 "compiler_hw3.y" /* yacc.c:1646  */
    { expre_site = 0; }
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 825 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 826 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 832 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 833 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 864 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gen_print((yyvsp[0].atom).type);
	}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 871 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char *strconst = strtok((yyvsp[-2].atom).string_val, "\"");
		fprintf(file, "\tldc %s\n", strconst);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "string");
	}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 878 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc %f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "int");
	}
#line 2439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 884 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc %f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "float");
	}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 890 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc %f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "int");
	}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 896 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc %f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "float");
	}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 902 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-2].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-2].atom).string_val);
		}
		else {
			gen_ID((yyvsp[-2].atom).string_val);
			(yyval.atom) = (yyvsp[-2].atom);
			strcpy((yyval.atom).type, lookup_type((yyvsp[-2].atom).string_val));
		}
	}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2491 "y.tab.c" /* yacc.c:1646  */
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
#line 951 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;
	
	table_num = 0;
	create_symbol();
	init_func_table();
	register_site = 0;

    file = fopen("compiler_hw3.j","w");
     
    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
	
 	yyparse();
	if(syntax_flag == 1) {
		printf("%d: %s\n", yylineno, buf);
		if(error_flag == 1) {
			//printf("%d: %s\n", yylineno, buf);
			semantic_error(sem_error_msg, yylineno);
		}
		syntax_error(syn_error_msg);
	}
	if(syntax_flag == 0) {
		dump_symbol(0);
		printf("\nTotal lines: %d \n",yylineno-1);
	}

    fclose(file);

    return 0;
}

void yyerror(char *s)
{
	syntax_flag = 1;
	strcpy(syn_error_msg, s);
}

void syntax_error(char errormsg[100]) {
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", errormsg);
    printf("\n|-----------------------------------------------|\n\n");
}

void semantic_error(char errormsg[100], int sem_line) {
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", sem_line, buf);
    printf("| %s", errormsg);
    printf("\n|-----------------------------------------------|\n\n");	
}

void create_symbol() {
	for(int i=0;i<30;i++) {
		global_table[table_num].table[i].index = -1;
		strcpy(global_table[table_num].table[i].name, "\0");
		strcpy(global_table[table_num].table[i].kind, "\0");
		strcpy(global_table[table_num].table[i].type, "\0");
		global_table[table_num].table[i].scope = table_num;
		strcpy(global_table[table_num].table[i].attribute, "\0");
		global_table[table_num].table[i].register_num = -1;
		global_table[table_num].table[i].func_decla = -1;
	}
}
void insert_symbol(char name[], char kind[], char type[], char attribute[], int index) {
	global_table[table_num].table[index].index = index;
	strcpy(global_table[table_num].table[index].name, name);
	strcpy(global_table[table_num].table[index].kind, kind);
	strcpy(global_table[table_num].table[index].type, type);
	global_table[table_num].table[index].scope = table_num;
	strcpy(global_table[table_num].table[index].attribute, attribute);
	if(table_num != 0) {
		global_table[table_num].table[index].register_num = register_site;
		register_site++;
	}
}

void set_para(char attribute[]) {
	strcpy(global_table[0].table[check_index.cur_func_index].attribute, attribute);
}

void set_func_decla(int flag) {
	global_table[0].table[check_index.cur_func_index].func_decla = flag;
}

int get_func_decla() {
	return global_table[0].table[check_index.cur_func_index].func_decla;
}

int lookup_symbol(char name[], char type[]) {
	if(!strcmp(type, "insert")) {
		int i;
		// redeclard variable, return -1
		for(i=0;i<30;i++) {
			if(!strcmp(global_table[table_num].table[i].name, name)) {
				return -1;
			}
		}
		for(i=0;i<30;i++) {
			if(global_table[table_num].table[i].index == -1) {
				strcpy(global_table[table_num].table[i].name, name);
				return i;
			}
		}
	}
	else if(!strcmp(type, "global")) {
		for(int i=0;i<30;i++) {
			if(!strcmp(global_table[0].table[i].name, name)) {
				return i;
			}
		}
		return -1;
	}
	else {
		// check before scope
		// undeclared variable, return -1 
		int i;
		for (int j=0;j<=table_num;j++) {
			for(i=0;i<30;i++) {
				if(!strcmp(global_table[j].table[i].name, name)) {
					return 1;
				}
			}
		}
		return -1;
	}
}
void dump_symbol(int scope) {
	if(scope == 0) {
		if(global_table[0].table[0].index != -1) {
			printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
					"Index", "Name", "Kind", "Type", "Scope", "Attribute");
		}
		int has = 0;
		for(int i=0;i<30;i++) {
			if(global_table[0].table[i].index != -1) {
				has = 1;
				printf("%-10d%-10s%-12s%-10s%-10d%-s\n",
						global_table[0].table[i].index, 
						global_table[0].table[i].name, 
						global_table[0].table[i].kind, 
						global_table[0].table[i].type, 
						global_table[0].table[i].scope, 
						global_table[0].table[i].attribute);
				continue;
			}
			if(has == 1) printf("\n");
			break;
		}
	}
	else {
		if(temp_dump_table.table[0].index != -1) {
			printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
					"Index", "Name", "Kind", "Type", "Scope", "Attribute");
		}
		int has = 0;
		for(int i=0;i<30;i++) {
			if(temp_dump_table.table[i].index != -1) {
				has = 1;
				printf("%-10d%-10s%-12s%-10s%-10d%-s\n",
						temp_dump_table.table[i].index, 
						temp_dump_table.table[i].name, 
						temp_dump_table.table[i].kind, 
						temp_dump_table.table[i].type, 
						temp_dump_table.table[i].scope, 
						temp_dump_table.table[i].attribute);
				continue;
			}
			if(has == 1) printf("\n");
			break;
		}
	}
}

void clear_temp_table() {
	for(int i=0;i<30;i++) {
		temp_dump_table.table[i].index = -1;
		strcpy(temp_dump_table.table[i].name, "\0");
		strcpy(temp_dump_table.table[i].kind, "\0");
		strcpy(temp_dump_table.table[i].type, "\0");
		temp_dump_table.table[i].scope = table_num;
		strcpy(temp_dump_table.table[i].attribute, "\0");
	}
}

void fill_temp_table() {
	for(int i=0;i<30;i++) {
		temp_dump_table.table[i].index = global_table[table_num].table[i].index;
		strcpy(temp_dump_table.table[i].name, global_table[table_num].table[i].name);
		strcpy(temp_dump_table.table[i].kind, global_table[table_num].table[i].kind);
		strcpy(temp_dump_table.table[i].type, global_table[table_num].table[i].type);
		temp_dump_table.table[i].scope = table_num;
		strcpy(temp_dump_table.table[i].attribute, global_table[table_num].table[i].attribute);
	}
}

void init_func_table() {
	for(int i=0;i<30;i++) {
		implement_func_table[i].flag = -1;
	}
}

void insert_func_table(char name[]) {
	for(int i=0;i<30;i++) {
		if(!strcmp(implement_func_table[i].name, name)) {
			return;
		}
		if(implement_func_table[i].flag == -1) {
			strcpy(implement_func_table[i].name, name);
			implement_func_table[i].flag = 1;
			return;
		}
	}
}

int lookup_func_table(char name[]) {
	for(int i=0;i<30;i++) {
		if(implement_func_table[i].flag == -1) {
			return 1;
		}
		if(!strcmp(implement_func_table[i].name, name)) {
			return 2;
		}
	}
}

int lookup_register_num(char name[]) {
	// check before scope
	for(int j=table_num;j>=0;j--) {
		for(int i=0;i<30;i++) {
			if(!strcmp(global_table[j].table[i].name, name)) {
				return global_table[j].table[i].register_num;
			}
		}
	}
}

char* lookup_type(char name[]) {
	for(int j=table_num;j>=0;j--) {
		for(int i=0;i<30;i++) {
			if(!strcmp(global_table[j].table[i].name, name)) {
				return global_table[j].table[i].type;
			}
		}
	}
}

char* lookup_attribute(char name[]) {
	for(int j=table_num;j>=0;j--) {
		for(int i=0;i<30;i++) {
			if(!strcmp(global_table[j].table[i].name, name)) {
				return global_table[j].table[i].attribute;
			}
		}
	}	
}

char* changeto_java_type() {
	char new_type[100];
	memset(new_type, '\0', sizeof(new_type));
	char temp_attr[100];
	strcpy(temp_attr, func_para_type);
	char* delim = ", ";
  	char* type;
	type = strtok(temp_attr, delim);
 	while (type != NULL)
  	{
		if(!strcmp(type, "string")) strcat(new_type, "Ljava/lang/String;");
		else if(!strcmp(type, "void")) strcat(new_type, "V");
		else strcat(new_type, "F");
    	type = strtok(NULL, delim);
  	}   
	char* javatype = new_type;
	return javatype;
}

void gen_print(char type[30]) {
	fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
	fprintf(file, "\tswap\n");
	if(!strcmp(type, "string")) type = "Ljava/lang/String;";
	else type = "F";
	fprintf(file, "\tinvokevirtual java/io/PrintStream/println(%s)V\n", type);
}

void gen_ID(char value[100]) {
	int regnum = lookup_register_num(value);
	//strcpy(type, lookup_type(value));
	// global variable
	if(regnum == -1) {
		/*
		if(!strcmp(type, "int")) set_expre_factor(2, -1, value, -1, type);
		else if(!strcmp(type, "float")) set_expre_factor(2, -1, -1, value, type);
		*/
		fprintf(file, "\tgetstatic compiler_hw3/%s\n", value);	
	}
	// local variable
	else {
		char type[30];
		//set_expre_factor(1, regnum, -1, -1, type);
		if(!strcmp(type, "string")) {
			fprintf(file, "\taload %d\n", regnum);
		}
		else {
			// float, int, bool
			fprintf(file, "\tfload %d\n", regnum);
		}
	}
}

void clear_expre_factor() {
	expre_factor[expre_site].kind = -1;
	expre_factor[expre_site].regnum = -1;
	expre_factor[expre_site].i_val = -1;
	expre_factor[expre_site].f_val = -1;
	strcpy(expre_factor[expre_site].type, "");
}

void set_expre_factor(int kind, int regnum, int i_val, float f_val, char type[30]) {
	clear_expre_factor();
	expre_factor[expre_site].kind = kind;
	expre_factor[expre_site].regnum = regnum;
	expre_factor[expre_site].i_val = i_val;
	expre_factor[expre_site].f_val = f_val;
	strcpy(expre_factor[expre_site].type, type);
	if(expre_site == 0) expre_site = 1;
	else expre_site = 0;
}

void gen_function() {
	char name[100];
	strcpy(name, global_table[0].table[check_index.cur_func_index].name);
	if(!strcmp(name, "main")) {
		fprintf(file, ".method public static main([Ljava/lang/String;)V\n");
	}
	else {
		strcpy(func_para_type, global_table[0].table[check_index.cur_func_index].attribute);
		char attr[100];
		strcpy(attr, changeto_java_type());
		memset(func_para_type, '\0', sizeof(func_para_type));
		strcpy(func_para_type, global_table[0].table[check_index.cur_func_index].type);
		char type[100];
		strcpy(type, changeto_java_type());
		memset(func_para_type, '\0', sizeof(func_para_type));
		fprintf(file, ".method public static %s(%s)%s\n", name, attr, type);
	}
	fprintf(file, ".limit stack 50\n");
	fprintf(file, ".limit locals 50\n");
}
