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
    LB = 272,
    RB = 273,
    LCB = 274,
    RCB = 275,
    LSB = 276,
    RSB = 277,
    COMMA = 278,
    PRINT = 279,
    IF = 280,
    ELSE = 281,
    FOR = 282,
    WHILE = 283,
    SEMICOLON = 284,
    RET = 285,
    START_COMMENT = 286,
    END_COMMENT = 287,
    CPLUS_COMMENT = 288,
    I_CONST = 289,
    F_CONST = 290,
    S_CONST = 291,
    TRUE = 292,
    FALSE = 293,
    INC = 294,
    DEC = 295,
    MT = 296,
    LT = 297,
    MTE = 298,
    LTE = 299,
    EQ = 300,
    NE = 301,
    ID = 302,
    INT = 303,
    FLOAT = 304,
    BOOL = 305,
    STRING = 306,
    VOID = 307
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
#define LB 272
#define RB 273
#define LCB 274
#define RCB 275
#define LSB 276
#define RSB 277
#define COMMA 278
#define PRINT 279
#define IF 280
#define ELSE 281
#define FOR 282
#define WHILE 283
#define SEMICOLON 284
#define RET 285
#define START_COMMENT 286
#define END_COMMENT 287
#define CPLUS_COMMENT 288
#define I_CONST 289
#define F_CONST 290
#define S_CONST 291
#define TRUE 292
#define FALSE 293
#define INC 294
#define DEC 295
#define MT 296
#define LT 297
#define MTE 298
#define LTE 299
#define EQ 300
#define NE 301
#define ID 302
#define INT 303
#define FLOAT 304
#define BOOL 305
#define STRING 306
#define VOID 307

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
#define YYLAST   248

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
       0,   150,   150,   151,   155,   156,   157,   161,   162,   163,
     164,   165,   166,   170,   171,   175,   176,   177,   182,   181,
     224,   235,   247,   246,   260,   304,   344,   380,   379,   443,
     450,   460,   470,   483,   487,   491,   495,   502,   512,   521,
     531,   530,   550,   559,   563,   588,   595,   600,   605,   612,
     617,   622,   640,   647,   658,   669,   680,   691,   725,   732,
     771,   808,   831,   854,   854,   854,   861,   861,   862,   861,
     871,   872,   876,   876,   877,   876,   883,   883,   893,   894,
     905,   906,   907,   908,   909,   910,   914,   921,   928,   934,
     940,   946,   952,   969,   970,   974,   975,   976,   980,   981,
     982,   983,   984,   985,   989,   990,   995,   996,   997,   998,
     999
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "MOD",
  "ASGN", "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND",
  "OR", "NOT", "LB", "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "PRINT",
  "IF", "ELSE", "FOR", "WHILE", "SEMICOLON", "RET", "START_COMMENT",
  "END_COMMENT", "CPLUS_COMMENT", "I_CONST", "F_CONST", "S_CONST", "TRUE",
  "FALSE", "INC", "DEC", "MT", "LT", "MTE", "LTE", "EQ", "NE", "ID", "INT",
  "FLOAT", "BOOL", "STRING", "VOID", "$accept", "program", "stat",
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

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -87,     8,   -87,   -26,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -23,   -87,     9,   106,   -87,   -87,
     -25,    92,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -12,
     174,    41,   107,   -87,    46,     0,    18,   -87,   -87,   164,
      14,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,    92,
      92,    92,    92,    92,    92,   -87,   -87,    44,   -87,     7,
      15,   -87,   -87,   -87,   -87,   -87,    53,   -87,   198,    41,
     107,   107,   -87,   -87,   -87,   -87,   -87,   -87,   -87,    43,
     -87,   -87,   130,   150,    44,    34,   -87,    70,    94,   108,
     -87,    68,     3,   150,   104,   -87,   -87,   -87,   -87,   -87,
      81,    83,   -87,   -87,    -1,    92,    92,   -87,   -87,   182,
     109,   -87,   -87,   -87,   -87,   -87,   -87,    82,    92,   123,
     -87,   -87,   125,    11,   -13,   115,   117,   137,   139,   -87,
     198,   198,   -87,   -87,   129,    59,   192,   -87,   -87,   141,
     143,   133,   134,   142,   144,   154,   158,   -87,   -87,   -87,
     155,   156,   -87,   -87,   -87,   -87,   167,   168,   159,   -87,
     -87,   -87,   -87,   -87,   150,   150,   171,   172,   -87,   -87,
     169,     4,   -87,   -87,   176,   -87,   150,    92,   184,   198,
     -87,   178,   175,   -87,   150,   193,   -87,   186,     4,   -87,
     -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    93,   106,   107,   108,   109,   110,
       2,     4,     5,     6,     0,    94,     0,     0,    27,    25,
       0,     0,    53,    54,    95,    96,    97,   104,   105,    57,
       0,    45,    48,    52,     0,     0,     0,    55,    56,     0,
       0,    59,    26,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,     0,    24,    60,     0,    28,     0,
       0,    58,    62,    33,    35,    36,     0,    32,    34,    44,
      46,    47,    49,    50,    51,    22,    21,    20,    18,     0,
      30,    61,     0,     0,     0,     0,    31,     0,     0,     0,
      43,     0,     0,    14,     0,     7,     8,     9,    10,    11,
       0,     0,    19,    29,     0,     0,     0,    17,    12,     0,
       0,    98,    99,   100,   101,   102,   103,     0,     0,     0,
      13,    23,     0,     0,     0,     0,     0,     0,     0,    86,
      66,    63,    16,    15,     0,     0,     0,    38,    39,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    40,    37,
       0,     0,    88,    89,    87,    92,     0,     0,     0,    90,
      91,    67,    64,    41,     0,     0,     0,     0,    68,    65,
      71,     0,    69,    76,     0,    70,     0,     0,     0,    72,
      77,     0,     0,    73,     0,     0,    74,    79,     0,    75,
      78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -86,   -87,   -87,   -87,   138,   -87,
     213,   -87,   -87,   -87,   112,   148,   -87,   -87,   -17,   183,
      33,    97,   -87,   -87,   -87,   -87,   -87,   -87,   -87,    57,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   230,   157,
     -87,   -28,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    10,    93,    94,   108,    58,    84,    77,    83,
      95,    12,    36,    59,    66,    67,    96,   158,    68,    31,
      32,    33,    97,   146,   165,   145,   164,   170,   172,   175,
     181,   184,   187,   176,   189,    49,    98,   129,    99,    34,
     118,    35,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,    41,    14,   124,    39,    40,    15,   120,     2,    37,
      38,   111,   112,   113,   114,   115,   116,    17,    20,    17,
     117,   139,   140,   173,    16,    78,    18,    27,    28,   174,
      79,    21,    62,   125,   126,   127,    57,    60,    19,     3,
      19,     4,    27,    28,    50,    51,   128,    56,    22,    23,
      63,    64,    65,    27,    28,   100,     5,     6,     7,     8,
       9,    29,    80,    75,   119,   100,     5,     6,     7,     8,
       9,    81,    20,    76,   109,    55,    82,   148,   166,   167,
      85,   103,    82,    70,    71,    21,    20,   104,   130,   131,
     178,     5,     6,     7,     8,     9,    20,   107,   185,    21,
     134,   136,    22,    23,    24,    25,    26,    27,    28,    21,
      20,   105,    52,    53,    54,    29,    22,    23,    63,    64,
      65,    27,    28,    21,   121,   106,    22,    23,   122,    29,
     123,    27,    28,   141,    20,   142,   100,   100,   133,    29,
      22,    23,    24,    25,    26,    27,    28,    21,   100,    72,
      73,    74,   137,    29,   138,   143,   100,   144,   147,   150,
     179,   151,   152,   153,    22,    23,    63,    64,    65,    27,
      28,   154,   156,   155,    87,    88,   157,    29,    89,    90,
      91,     3,    61,     4,   159,   160,   161,   162,   163,    27,
      28,   168,   169,   177,   183,   171,   182,    92,     5,     6,
       7,     8,     9,    42,   180,    43,    44,    45,    46,    47,
      48,   132,   188,   186,    11,    43,    44,    45,    46,    47,
      48,   149,   102,    43,    44,    45,    46,    47,    48,   135,
      86,    13,    69,    43,    44,    45,    46,    47,    48,    43,
      44,    45,    46,    47,    48,   190,     0,     0,   110
};

static const yytype_int16 yycheck[] =
{
      17,    29,     1,     4,    21,    17,    32,    93,     0,    34,
      35,     8,     9,    10,    11,    12,    13,     8,     4,     8,
      17,    34,    35,    19,    47,    18,    17,    39,    40,    25,
      23,    17,    18,    34,    35,    36,    18,    36,    29,    31,
      29,    33,    39,    40,     3,     4,    47,    47,    34,    35,
      36,    37,    38,    39,    40,    83,    48,    49,    50,    51,
      52,    47,    47,    19,    92,    93,    48,    49,    50,    51,
      52,    18,     4,    29,    91,    29,    23,    18,   164,   165,
      79,    47,    23,    50,    51,    17,     4,    17,   105,   106,
     176,    48,    49,    50,    51,    52,     4,    29,   184,    17,
      18,   118,    34,    35,    36,    37,    38,    39,    40,    17,
       4,    17,     5,     6,     7,    47,    34,    35,    36,    37,
      38,    39,    40,    17,    20,    17,    34,    35,    47,    47,
      47,    39,    40,    18,     4,    18,   164,   165,    29,    47,
      34,    35,    36,    37,    38,    39,    40,    17,   176,    52,
      53,    54,    29,    47,    29,    18,   184,    18,    29,    18,
     177,    18,    29,    29,    34,    35,    36,    37,    38,    39,
      40,    29,    18,    29,    24,    25,    18,    47,    28,    29,
      30,    31,    18,    33,    29,    29,    19,    19,    29,    39,
      40,    20,    20,    17,    19,    26,    18,    47,    48,    49,
      50,    51,    52,    29,    20,    41,    42,    43,    44,    45,
      46,    29,    26,    20,     1,    41,    42,    43,    44,    45,
      46,    29,    84,    41,    42,    43,    44,    45,    46,   117,
      82,     1,    49,    41,    42,    43,    44,    45,    46,    41,
      42,    43,    44,    45,    46,   188,    -1,    -1,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,    31,    33,    48,    49,    50,    51,    52,
      55,    63,    64,    91,    95,    32,    47,     8,    17,    29,
       4,    17,    34,    35,    36,    37,    38,    39,    40,    47,
      71,    72,    73,    74,    92,    94,    65,    34,    35,    71,
      17,    94,    29,    41,    42,    43,    44,    45,    46,    88,
       3,     4,     5,     6,     7,    29,    47,    18,    59,    66,
      95,    18,    18,    36,    37,    38,    67,    68,    71,    72,
      73,    73,    74,    74,    74,    19,    29,    61,    18,    23,
      47,    18,    23,    62,    60,    95,    68,    24,    25,    28,
      29,    30,    47,    56,    57,    63,    69,    75,    89,    91,
      94,    95,    61,    47,    17,    17,    17,    29,    58,    71,
      92,     8,     9,    10,    11,    12,    13,    17,    93,    94,
      57,    20,    47,    47,     4,    34,    35,    36,    47,    90,
      71,    71,    29,    29,    18,    67,    71,    29,    29,    34,
      35,    18,    18,    18,    18,    78,    76,    29,    18,    29,
      18,    18,    29,    29,    29,    29,    18,    18,    70,    29,
      29,    19,    19,    29,    79,    77,    57,    57,    20,    20,
      80,    26,    81,    19,    25,    82,    86,    17,    57,    71,
      20,    83,    18,    19,    84,    57,    20,    85,    26,    87,
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
#line 176 "compiler_hw3.y" /* yacc.c:1646  */
    { expre_site = 0; }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 182 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 215 "compiler_hw3.y" /* yacc.c:1646  */
    {
	/*
		if(!strcmp($3.string_val, ";")) {
			table_num--;
			func_flag = 1;
		}
		*/
		//else func_flag = 1;
	}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 225 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[0].atom).string_val, ";")) {
			table_num--;
			func_flag = 1;
		}
		//else func_flag = 1;
	}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 236 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 247 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gen_function();
	}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 251 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 261 "compiler_hw3.y" /* yacc.c:1646  */
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
					fprintf(file, "    ldc %d\n", booltype);
					fprintf(file, "    istore %d\n", index);
				}
				else if(!strcmp((yyvsp[-4].atom).string_val, "string")) {
					char *strconst = strtok((yyvsp[-1].atom).string_val, "\"");
					fprintf(file, "    ldc \"%s\"\n", strconst);
					fprintf(file, "    astore %d\n", index);
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
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 305 "compiler_hw3.y" /* yacc.c:1646  */
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
    			fprintf(file, "    ldc 0\n");
				if(!strcmp((yyvsp[-2].atom).string_val, "string")) {
					strcpy(type_descriptor, "Ljava/lang/String;");
					fprintf(file, "    astore 0\n");
				}
				else {
					// float, int, bool
					strcpy(type_descriptor, "F");
    				fprintf(file, "    fstore 0\n");
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
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 345 "compiler_hw3.y" /* yacc.c:1646  */
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
					fprintf(file, "    astore %d\n", regnum);
				}
				else {
					// float, int, bool
					fprintf(file, "    fstore %d\n", regnum);
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
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 380 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		int has = lookup_symbol((yyvsp[-1].atom).string_val, "global"); 
		int index = lookup_symbol((yyvsp[-1].atom).string_val, "insert");
		check_index.cur_func_index = index;
		if(has == -1) {
			// first time
			check_index.has = 0;
			if(index != -1) {
				insert_symbol((yyvsp[-1].atom).string_val, "function", (yyvsp[-2].atom).string_val, "", index);
			}
		}
		else {
			// declare or define before
			check_index.has = 1;
			if(!strcmp((yyvsp[-2].atom).string_val, global_table[0].table[has].name)) {
				// return type not the same
				error_flag = 1;
				bzero(sem_error_msg, 100);
				strcat(sem_error_msg, "function return type is not the same");
			}
		}
		table_num++; 
		create_symbol();
		
	/*	
		int index = lookup_symbol($2.string_val, "insert"); 
		if(index != -1) {
			char attr[100];
			bzero(attr, 100);
			int flag = 0;
			for(int i=0;i<30;i++) {
				if(global_table[table_num+1].table[i].index != -1) {
					if(!strcmp(global_table[table_num+1].table[i].kind, "parameter")) {
						if(flag == 1) {
							strcat(attr, ", ");
						}
						strcat(attr, global_table[table_num+1].table[i].type);
						flag = 1;
					}
				}
				else break;
			}
			insert_symbol($2.string_val, "function", $1.string_val, attr, index);
		}
		if(func_flag == 1) {
			index = lookup_func_table($2.string_val);
			if(index == 2) {
				error_flag = 1;
				bzero(sem_error_msg, 100);
				strcat(sem_error_msg, "Redeclared function ");
				strcat(sem_error_msg, $2.string_val);
			}
			else insert_func_table($2.string_val);
			func_flag = 0;
		}
		func_index = lookup_symbol($2.string_val, "global");
		printf("debug decla func %d\n", func_index);
	*/
	}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 444 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[0].atom).string_val, "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[0].atom).string_val, "parameter", (yyvsp[-1].atom).string_val, "\0", index);
		}
	}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 451 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[0].atom).string_val, "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[0].atom).string_val, "parameter", (yyvsp[-1].atom).string_val, "\0", index);
		}
	}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 461 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(strcmp(func_para_type, "")) {
			strcat(func_para_type, ", ");
			strcat(func_para_type, (yyvsp[0].atom).type);
		}
		else {
			strcpy(func_para_type, (yyvsp[0].atom).type);
		}
	}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 471 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(strcmp(func_para_type, "")) {
			strcat(func_para_type, ", ");
			strcat(func_para_type, (yyvsp[0].atom).type);
		}
		else {
			strcpy(func_para_type, (yyvsp[0].atom).type);
		}
	}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 484 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy((yyval.atom).type, "string");
	}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 488 "compiler_hw3.y" /* yacc.c:1646  */
    {
		expre_site = 0;
	}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 492 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy((yyval.atom).type, "bool");
	}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 496 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy((yyval.atom).type, "bool");
	}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 503 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
		expre_site = 0;
	}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 513 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-2].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-2].atom).string_val);
		}
	}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 522 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-1].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-1].atom).string_val);
		}
	}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 531 "compiler_hw3.y" /* yacc.c:1646  */
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
		fprintf(file, "    invokestatic compiler_hw3/%s(%s)%s\n", (yyvsp[-3].atom).string_val, paratype, returntype);
	}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 551 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
	}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 564 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 589 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom) = (yyvsp[0].atom);
	}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 596 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "    fadd\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 601 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "    fsub\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 606 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom) = (yyvsp[0].atom);
	}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 613 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "    fmul\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 618 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "    fdiv\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 623 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char type1[30], type2[30];
		strcpy(type1, (yyvsp[-2].atom).type);
		strcpy(type2, (yyvsp[0].atom).type);
		if(!strcmp(type1, "int") && !strcmp(type2, "int")) {

			fprintf(file, "    irem\n");
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
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 641 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom) = (yyvsp[0].atom);
	}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 648 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, $1.i_val, -1, "int");
			fprintf(file, "    ldc %f\n", (float)(yyvsp[0].atom).i_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = (float)(yyvsp[0].atom).i_val;
		strcpy((yyval.atom).type, "int");
	}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 659 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, -1, $1.f_val, "float");
			fprintf(file, "    ldc %f\n", (yyvsp[0].atom).f_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = (yyvsp[0].atom).f_val;
		strcpy((yyval.atom).type, "float");
	}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 670 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, -$2.i_val, -1, "int");
			fprintf(file, "    ldc -%f\n", (float)(yyvsp[0].atom).i_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = -(float)(yyvsp[0].atom).i_val;
		strcpy((yyval.atom).type, "int");
	}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 681 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, -1, -$2.i_val, "float");
			fprintf(file, "    ldc -%f\n", (yyvsp[0].atom).f_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = -(yyvsp[0].atom).f_val;
		strcpy((yyval.atom).type, "float");
	}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 692 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[0].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[0].atom).string_val);
		}
		else {
			gen_ID((yyvsp[0].atom).string_val);
			/*
			int regnum = lookup_register_num($1.string_val);
			// global variable
			if(regnum == -1) {
				fprintf(file, "    getstatic compiler_hw3/%s\n", $1.string_val);	
			}
			// local variable
			else {
				char type[30];
				strcpy(type, lookup_type($1.string_val));
				if(!strcmp(type, "string")) {
					fprintf(file, "    aload %d\n", regnum);
				}
				else {
					// float, int, bool
					fprintf(file, "    fload %d\n", regnum);
				}
			}
			*/
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[0].atom).string_val));
		}
	}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 726 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// set_expre_factor(0, -1, -1, -$2.i_val, "float");
		// assign to factor
		(yyval.atom).f_val = -1.0;
		//strcpy($$.type, lookup_type($2.string_val));
	}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 733 "compiler_hw3.y" /* yacc.c:1646  */
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
				fprintf(file, "    getstatic compiler_hw3/%s\n", (yyvsp[-1].atom).string_val);	
			}
			// local variable
			else {
				// only int has ++ and --
				if(!strcmp((yyvsp[0].atom).string_val, "++")) {
					fprintf(file, "    fload %d\n", regnum);
					fprintf(file, "    ldc 1.0\n");
					fprintf(file, "    fadd\n");
					fprintf(file, "    fstore %d\n", regnum);
					fprintf(file, "    fload %d\n", regnum);
					fprintf(file, "    fsub\n");
				}
				else {
					fprintf(file, "    fload %d\n", regnum);
					fprintf(file, "    ldc 1.0\n");
					fprintf(file, "    fsub\n");
					fprintf(file, "    fstore %d\n", regnum);
					fprintf(file, "    fload %d\n", regnum);
					fprintf(file, "    fadd\n");
				}
			}
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[-1].atom).string_val));
		}
	}
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 772 "compiler_hw3.y" /* yacc.c:1646  */
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
				fprintf(file, "    getstatic compiler_hw3/%s\n", (yyvsp[0].atom).string_val);
			}
			// local variable
			else {
				// only int has ++ and --
				if(!strcmp((yyvsp[-1].atom).string_val, "++")) {
					fprintf(file, "    fload %d\n", regnum);
					fprintf(file, "    ldc 1.0\n");
					fprintf(file, "    fadd\n");
					fprintf(file, "    fstore %d\n", regnum); // store back to register
					fprintf(file, "    fload %d\n", regnum); // put on TOS
				}
				else {
					fprintf(file, "    fload %d\n", regnum);
					fprintf(file, "    ldc 1.0\n");
					fprintf(file, "    fsub\n");
					fprintf(file, "    fstore %d\n", regnum); // store back to register
					fprintf(file, "    fload %d\n", regnum); // put on TOS
				}
			}
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[0].atom).string_val));
		}
	}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 809 "compiler_hw3.y" /* yacc.c:1646  */
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
		fprintf(file, "    invokestatic compiler_hw3/%s(%s)%s\n", (yyvsp[-3].atom).string_val, paratype, returntype);
		memset(func_para_type, '\0', sizeof(func_para_type));
		// assign function return to factor
		(yyval.atom).f_val = -1.0;
	}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 832 "compiler_hw3.y" /* yacc.c:1646  */
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
		fprintf(file, "    invokestatic compiler_hw3/%s()%s\n", (yyvsp[-2].atom).string_val, returntype);
		// assign function return to factor
		(yyval.atom).f_val = -1.0;
	}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 854 "compiler_hw3.y" /* yacc.c:1646  */
    { expre_site = 0; }
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 854 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 855 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 861 "compiler_hw3.y" /* yacc.c:1646  */
    { expre_site = 0; }
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 861 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 862 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 876 "compiler_hw3.y" /* yacc.c:1646  */
    { expre_site = 0; }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 876 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 877 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 2439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 883 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 884 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 915 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gen_print((yyvsp[0].atom).type);
	}
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 922 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char *strconst = strtok((yyvsp[-2].atom).string_val, "\"");
		fprintf(file, "    ldc %s\n", strconst);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "string");
	}
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 929 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "    ldc %f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "int");
	}
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 935 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "    ldc %f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "float");
	}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 941 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "    ldc %f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "int");
	}
#line 2505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 947 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "    ldc %f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "float");
	}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 953 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2537 "y.tab.c" /* yacc.c:1646  */
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
#line 1002 "compiler_hw3.y" /* yacc.c:1906  */


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

	fprintf(file, "\treturn\n"
                  ".end method\n");
    
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
	for(int j=0;j<=table_num;j++) {
		for(int i=0;i<30;i++) {
			if(!strcmp(global_table[j].table[i].name, name)) {
				return global_table[j].table[i].register_num;
			}
		}
	}
}

char* lookup_type(char name[]) {
	for(int j=0;j<=table_num;j++) {
		for(int i=0;i<30;i++) {
			if(!strcmp(global_table[j].table[i].name, name)) {
				return global_table[j].table[i].type;
			}
		}
	}
}

char* lookup_attribute(char name[]) {
	for(int j=0;j<=table_num;j++) {
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
	fprintf(file, "    getstatic java/lang/System/out Ljava/io/PrintStream;\n");
	fprintf(file, "    swap\n");
	if(!strcmp(type, "string")) type = "Ljava/lang/String;";
	else type = "F";
	fprintf(file, "    invokevirtual java/io/PrintStream/println(%s)V\n", type);
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
		fprintf(file, "    getstatic compiler_hw3/%s\n", value);	
	}
	// local variable
	else {
		char type[30];
		//set_expre_factor(1, regnum, -1, -1, type);
		if(!strcmp(type, "string")) {
			fprintf(file, "    aload %d\n", regnum);
		}
		else {
			// float, int, bool
			fprintf(file, "    fload %d\n", regnum);
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
		printf("debug %s\n",func_para_type);
		memset(func_para_type, '\0', sizeof(func_para_type));
		fprintf(file, ".method public static %s(%s)%s\n", name, attr, type);
	}
	fprintf(file, ".limit stack 50\n");
	fprintf(file, ".limit locals 50\n");
}
