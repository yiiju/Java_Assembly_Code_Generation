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

int has_error = 0;
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
//int func_flag;

int lookup_register_num(char[]);
char* lookup_type(char[]);
int register_site;

char func_para_type[100];
char* lookup_attribute(char[]);
char* changeto_java_type();
void gen_print(char[]);
void gen_ID(char[]);

int func_index;
void gen_function();
struct check_index {
	int has;
	int cur_func_index;
}check_index;
void set_para(char[]);
void set_func_decla(int);
int get_func_decla();
void gen_arith_post(char[], char[]);
void gen_arith_pre(char[], char[]);
void gen_asgn(char[], char[]);

char* create_label_name(char[], int);
void gen_relation(char[], char[]);

int if_label;
#define MAXSTACK 100
int if_label_stack[MAXSTACK];
int top;
void push_if_label_stack(int);
int pop_if_label_stack();
int get_top_if_stack();
int if_label_table[100];
void gen_relation_inverse(char[], char[]);
void init();


#line 171 "y.tab.c" /* yacc.c:339  */

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
    AND = 263,
    OR = 264,
    NOT = 265,
    PRINT = 266,
    RET = 267,
    START_COMMENT = 268,
    END_COMMENT = 269,
    CPLUS_COMMENT = 270,
    I_CONST = 271,
    F_CONST = 272,
    S_CONST = 273,
    TRUE = 274,
    FALSE = 275,
    INC = 276,
    DEC = 277,
    MT = 278,
    LT = 279,
    MTE = 280,
    LTE = 281,
    EQ = 282,
    NE = 283,
    ID = 284,
    INT = 285,
    FLOAT = 286,
    BOOL = 287,
    STRING = 288,
    VOID = 289,
    SEMICOLON = 290,
    LB = 291,
    RB = 292,
    LCB = 293,
    RCB = 294,
    LSB = 295,
    RSB = 296,
    COMMA = 297,
    ASGN = 298,
    ADDASGN = 299,
    SUBASGN = 300,
    MULASGN = 301,
    DIVASGN = 302,
    MODASGN = 303,
    IF = 304,
    ELSE = 305,
    FOR = 306,
    WHILE = 307
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define MOD 262
#define AND 263
#define OR 264
#define NOT 265
#define PRINT 266
#define RET 267
#define START_COMMENT 268
#define END_COMMENT 269
#define CPLUS_COMMENT 270
#define I_CONST 271
#define F_CONST 272
#define S_CONST 273
#define TRUE 274
#define FALSE 275
#define INC 276
#define DEC 277
#define MT 278
#define LT 279
#define MTE 280
#define LTE 281
#define EQ 282
#define NE 283
#define ID 284
#define INT 285
#define FLOAT 286
#define BOOL 287
#define STRING 288
#define VOID 289
#define SEMICOLON 290
#define LB 291
#define RB 292
#define LCB 293
#define RCB 294
#define LSB 295
#define RSB 296
#define COMMA 297
#define ASGN 298
#define ADDASGN 299
#define SUBASGN 300
#define MULASGN 301
#define DIVASGN 302
#define MODASGN 303
#define IF 304
#define ELSE 305
#define FOR 306
#define WHILE 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 110 "compiler_hw3.y" /* yacc.c:355  */

	struct atom {
   		int i_val;
    	double f_val;
    	char* string_val;
		char type[30];
		int id_reg;
	}atom;

#line 325 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 342 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

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
       0,   161,   161,   162,   166,   167,   168,   172,   173,   174,
     175,   176,   177,   181,   182,   186,   187,   188,   193,   192,
     233,   243,   257,   256,   274,   318,   359,   394,   393,   423,
     430,   440,   450,   463,   468,   469,   474,   483,   482,   537,
     562,   571,   581,   580,   605,   625,   629,   636,   643,   648,
     653,   660,   665,   679,   712,   719,   730,   741,   752,   763,
     778,   784,   793,   802,   825,   849,   855,   863,   848,   885,
     894,   895,   884,   921,   922,   927,   935,   936,   926,   954,
     954,   970,   971,   975,   976,   977,   978,   979,   980,   984,
     991,   998,  1004,  1010,  1016,  1022,  1039,  1040,  1044,  1045,
    1046,  1050,  1054,  1058,  1062,  1066,  1070,  1077,  1078,  1083,
    1084,  1085,  1086,  1087
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "MOD", "AND",
  "OR", "NOT", "PRINT", "RET", "START_COMMENT", "END_COMMENT",
  "CPLUS_COMMENT", "I_CONST", "F_CONST", "S_CONST", "TRUE", "FALSE", "INC",
  "DEC", "MT", "LT", "MTE", "LTE", "EQ", "NE", "ID", "INT", "FLOAT",
  "BOOL", "STRING", "VOID", "SEMICOLON", "LB", "RB", "LCB", "RCB", "LSB",
  "RSB", "COMMA", "ASGN", "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN",
  "MODASGN", "IF", "ELSE", "FOR", "WHILE", "$accept", "program", "stat",
  "func_stat", "func_mul_stat", "return_stat", "func", "$@1", "func_end",
  "$@2", "declaration", "declaration_func", "$@3", "func_parameter",
  "func_call", "const", "expression", "$@4", "$@5", "expression_stat",
  "add_expression_stat", "mul_expression_stat", "factor", "iteration_stat",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "haselse", "haselseif",
  "$@12", "$@13", "$@14", "$@15", "moreelseif", "relational", "print_func",
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
     -91,     4,   -91,     0,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,    10,   -91,   -23,   -91,   -91,   137,
     222,    56,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    29,
     168,   197,    75,    90,   -91,   -14,    13,    53,   -91,     3,
      15,   -91,   -91,    65,   -91,   175,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   168,   168,   168,   168,   168,   168,   -91,
     -91,   -91,   -91,   -91,   -91,   104,   -91,   -91,   -91,   -91,
     -91,    33,   -91,   237,   -91,    75,    90,    90,   -91,   -91,
     -91,    -6,    53,    19,   -91,   159,    16,   111,    11,   -91,
      30,    57,    -6,    50,   -91,   -91,   -91,   -91,   -91,    71,
      74,   -91,   -91,   -91,    45,   -91,   -91,   210,    79,    88,
      93,   -91,   -91,   -91,   -91,   -91,   -91,    83,   168,   -91,
     -91,   -91,    91,   -25,   127,    86,   108,   113,   114,   -91,
     -91,   -91,   126,    34,   129,   168,   -91,   182,   168,   -91,
     128,   130,   133,   134,   135,   136,   -91,   -91,   -91,   216,
     -91,   190,   139,   147,   -91,   -91,   -91,   -91,   148,   -91,
     149,   -91,   -91,   -91,   -91,   -91,   153,    -6,   -91,   154,
      -6,   -91,   155,   142,   -91,    -8,   -91,   -91,   150,   -91,
      -6,   168,   157,   237,   -91,   174,   188,   -91,    -6,   189,
     -91,   179,    -8,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    96,   109,   110,   111,   112,   113,
       2,     4,     5,     6,     0,    97,     0,    25,    27,     0,
       0,     0,    55,    56,    98,    99,   100,   107,   108,    59,
       0,     0,    47,    50,    54,     0,     0,     0,    28,     0,
       0,    57,    58,     0,    61,     0,    83,    84,    85,    86,
      87,    88,    26,     0,     0,     0,     0,     0,     0,    24,
      62,    21,    22,    20,    18,     0,    30,    33,    35,    36,
      64,     0,    32,    34,    60,    46,    48,    49,    51,    52,
      53,     0,     0,     0,    63,     0,     0,     0,     0,    45,
       0,     0,    14,     0,     7,     8,     9,    10,    11,     0,
       0,    19,    29,    31,     0,    17,    12,     0,     0,     0,
     101,   102,   103,   104,   105,   106,    37,     0,     0,    65,
      13,    23,     0,     0,     0,     0,     0,     0,     0,    89,
      16,    15,     0,     0,     0,     0,    40,     0,     0,    41,
       0,     0,     0,     0,     0,     0,    44,    42,    39,     0,
      69,     0,     0,     0,    91,    92,    90,    95,     0,    38,
       0,    66,    93,    94,    43,    70,     0,     0,    67,     0,
       0,    71,     0,    74,    68,     0,    72,    79,     0,    73,
       0,     0,     0,    75,    80,     0,     0,    76,     0,     0,
      77,    82,     0,    78,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   -91,   -90,   -91,   -91,   -91,   164,   -91,
     229,   -91,   -91,   -91,   122,   162,   -91,   -91,   -91,   -19,
     195,    94,    64,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,    58,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     248,   -79,   -91,   -28,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    10,    92,    93,   106,    38,    82,    63,    81,
      94,    12,    20,    39,    71,    72,    95,   135,   158,    73,
      32,    33,    34,    96,   138,   166,   170,   160,   167,   173,
     176,   179,   185,   188,   191,   180,   193,    53,    97,   129,
      98,    35,   116,    36,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    44,   120,    14,     2,    86,    87,     3,   108,     4,
      17,    45,    17,    18,    15,    27,    28,     3,    19,     4,
      19,    59,    40,    88,     5,     6,     7,     8,     9,    89,
     177,   134,    27,    28,     5,     6,     7,     8,     9,    16,
      64,   178,    60,    90,    66,    65,    91,   109,   102,   124,
      27,    28,   104,    99,   110,   111,   112,   113,   114,   115,
     117,   125,   126,   127,    99,    43,   118,    83,   107,    21,
      84,   147,    41,    42,   128,    85,    85,   169,    54,    55,
     172,    22,    23,    67,    68,    69,    27,    28,    61,   121,
     182,    62,    21,   119,    29,    56,    57,    58,   189,   137,
     122,    30,    70,   123,    22,    23,    67,    68,    69,    27,
      28,    24,    25,    26,   131,    21,   149,    29,   136,   151,
      78,    79,    80,   142,    30,   132,   139,    22,    23,    24,
      25,    26,    27,    28,     5,     6,     7,     8,     9,    99,
      29,    21,    99,   140,   141,   143,   105,    30,    76,    77,
     144,   145,    99,    22,    23,    24,    25,    26,    27,    28,
      99,   146,   183,    21,   148,   152,    29,   153,   154,   155,
     156,   157,    21,    30,   162,    22,    23,    67,    68,    69,
      27,    28,   163,   164,    22,    23,   181,   165,    29,    27,
      28,   168,   175,   171,   174,    30,   184,    29,    46,    47,
      48,    49,    50,    51,    30,    46,    47,    48,    49,    50,
      51,   186,    74,    46,    47,    48,    49,    50,    51,   150,
      46,    47,    48,    49,    50,    51,   187,   161,   190,   192,
      11,   133,    52,    46,    47,    48,    49,    50,    51,    46,
      47,    48,    49,    50,    51,   130,   101,   103,    75,    13,
     194,   159,     5,     6,     7,     8,     9,     0,     0,    37,
      46,    47,    48,    49,    50,    51
};

static const yytype_int16 yycheck[] =
{
      19,    29,    92,     1,     0,    11,    12,    13,    87,    15,
      35,    30,    35,    36,    14,    21,    22,    13,    43,    15,
      43,    35,    20,    29,    30,    31,    32,    33,    34,    35,
      38,   110,    21,    22,    30,    31,    32,    33,    34,    29,
      37,    49,    29,    49,    29,    42,    52,    36,    29,     4,
      21,    22,    36,    81,    43,    44,    45,    46,    47,    48,
      88,    16,    17,    18,    92,    36,    36,    65,    87,     4,
      37,    37,    16,    17,    29,    42,    42,   167,     3,     4,
     170,    16,    17,    18,    19,    20,    21,    22,    35,    39,
     180,    38,     4,    36,    29,     5,     6,     7,   188,   118,
      29,    36,    37,    29,    16,    17,    18,    19,    20,    21,
      22,    18,    19,    20,    35,     4,   135,    29,    35,   138,
      56,    57,    58,    37,    36,    37,    35,    16,    17,    18,
      19,    20,    21,    22,    30,    31,    32,    33,    34,   167,
      29,     4,   170,    16,    17,    37,    35,    36,    54,    55,
      37,    37,   180,    16,    17,    18,    19,    20,    21,    22,
     188,    35,   181,     4,    35,    37,    29,    37,    35,    35,
      35,    35,     4,    36,    35,    16,    17,    18,    19,    20,
      21,    22,    35,    35,    16,    17,    36,    38,    29,    21,
      22,    38,    50,    39,    39,    36,    39,    29,    23,    24,
      25,    26,    27,    28,    36,    23,    24,    25,    26,    27,
      28,    37,    37,    23,    24,    25,    26,    27,    28,    37,
      23,    24,    25,    26,    27,    28,    38,    37,    39,    50,
       1,   109,    35,    23,    24,    25,    26,    27,    28,    23,
      24,    25,    26,    27,    28,    35,    82,    85,    53,     1,
     192,    35,    30,    31,    32,    33,    34,    -1,    -1,    37,
      23,    24,    25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,    13,    15,    30,    31,    32,    33,    34,
      55,    63,    64,    93,    97,    14,    29,    35,    36,    43,
      65,     4,    16,    17,    18,    19,    20,    21,    22,    29,
      36,    72,    73,    74,    75,    94,    96,    37,    59,    66,
      97,    16,    17,    36,    96,    72,    23,    24,    25,    26,
      27,    28,    35,    90,     3,     4,     5,     6,     7,    35,
      29,    35,    38,    61,    37,    42,    29,    18,    19,    20,
      37,    67,    68,    72,    37,    73,    74,    74,    75,    75,
      75,    62,    60,    97,    37,    42,    11,    12,    29,    35,
      49,    52,    56,    57,    63,    69,    76,    91,    93,    96,
      97,    61,    29,    68,    36,    35,    58,    72,    94,    36,
      43,    44,    45,    46,    47,    48,    95,    96,    36,    36,
      57,    39,    29,    29,     4,    16,    17,    18,    29,    92,
      35,    35,    37,    67,    94,    70,    35,    72,    77,    35,
      16,    17,    37,    37,    37,    37,    35,    37,    35,    72,
      37,    72,    37,    37,    35,    35,    35,    35,    71,    35,
      80,    37,    35,    35,    35,    38,    78,    81,    38,    57,
      79,    39,    57,    82,    39,    50,    83,    38,    49,    84,
      88,    36,    57,    72,    39,    85,    37,    38,    86,    57,
      39,    87,    50,    89,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    58,    60,    59,
      59,    61,    62,    61,    63,    63,    63,    65,    64,    66,
      66,    67,    67,    68,    68,    68,    68,    70,    69,    69,
      69,    69,    71,    69,    69,    69,    72,    72,    73,    73,
      73,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    77,    78,    79,    76,    80,
      81,    82,    76,    83,    83,    85,    86,    87,    84,    88,
      84,    89,    89,    90,    90,    90,    90,    90,    90,    91,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    96,    96,    97,
      97,    97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     1,     0,     4,
       2,     1,     0,     4,     5,     3,     5,     0,     5,     4,
       2,     3,     1,     1,     1,     1,     1,     0,     5,     4,
       3,     3,     0,     6,     4,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     2,     2,     1,
       3,     2,     2,     4,     3,     0,     0,     0,    10,     0,
       0,     0,    11,     2,     0,     0,     0,     0,    11,     0,
       4,     2,     0,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     4,     4,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
        case 18:
#line 193 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 226 "compiler_hw3.y" /* yacc.c:1646  */
    {
		//if(!strcmp($3.string_val, ";")) {
		if(!strcmp((yyvsp[0].atom).string_val, ";")) {
			table_num--;
			//func_flag = 1;
		}
	}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 234 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[0].atom).string_val, ";")) {
			table_num--;
			//func_flag = 1;
		}
	}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 244 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(get_func_decla() == 1) {
			// redefine function
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, global_table[0].table[check_index.cur_func_index].name);
		}
		else set_func_decla(1);
		(yyval.atom).string_val = ";";
		register_site = 0;
	}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 257 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gen_function();
	}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 261 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 275 "compiler_hw3.y" /* yacc.c:1646  */
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
					else booltype = 2.0;
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
					if(!strcmp((yyvsp[-1].atom).string_val, "true")) booltype = 1.0;
					else booltype = 2.0;
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
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 319 "compiler_hw3.y" /* yacc.c:1646  */
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
    			fprintf(file, "\tldc 0.0\n");
				int regnum = lookup_register_num((yyvsp[-1].atom).string_val);
				if(!strcmp((yyvsp[-2].atom).string_val, "string")) {
					strcpy(type_descriptor, "Ljava/lang/String;");
					fprintf(file, "\tastore %d\n", regnum);
				}
				else {
					// float, int, bool
					strcpy(type_descriptor, "F");
    				fprintf(file, "\tfstore %d\n", regnum);
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
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 360 "compiler_hw3.y" /* yacc.c:1646  */
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
		}
		else {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
	}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 394 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 424 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[0].atom).string_val, "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[0].atom).string_val, "parameter", (yyvsp[-1].atom).string_val, "\0", index);
		}
	}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 431 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int index = lookup_symbol((yyvsp[0].atom).string_val, "insert"); 
		if(index != -1) {
			insert_symbol((yyvsp[0].atom).string_val, "parameter", (yyvsp[-1].atom).string_val, "\0", index);
		}
	}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 441 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(strcmp(func_para_type, "")) {
			strcat(func_para_type, ", ");
			strcat(func_para_type, (yyvsp[0].atom).type);
		}
		else {
			strcpy(func_para_type, (yyvsp[0].atom).type);
		}
	}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 451 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(strcmp(func_para_type, "")) {
			strcat(func_para_type, ", ");
			strcat(func_para_type, (yyvsp[0].atom).type);
		}
		else {
			strcpy(func_para_type, (yyvsp[0].atom).type);
		}
	}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 464 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc \"%s\"\n", (yyvsp[0].atom).string_val);
		strcpy((yyval.atom).type, "string");
	}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 470 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc 1.0\n");
		strcpy((yyval.atom).type, "bool");
	}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 475 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc 2.0\n");
		strcpy((yyval.atom).type, "bool");
	}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 483 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-1].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-1].atom).string_val);
		}
		else {
			int regnum = lookup_register_num((yyvsp[-1].atom).string_val);
			// int, float, bool
			if(strcmp((yyvsp[0].atom).string_val, "=")) {
				fprintf(file, "\tfload %d\n", regnum);
			}
		}
	}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 499 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(!strcmp((yyvsp[-3].atom).string_val, "%=")) {
			// check int type
			//if(!strcmp($1.type, "int") && !strcmp($3.type, "int")) {
			if(!strcmp((yyvsp[-4].atom).type, "int") && !strcmp((yyvsp[-1].atom).type, "int")) {
				// expre is TOS
				//if($3.id_reg != -1) {
				if((yyvsp[-1].atom).id_reg != -1) {
					// ID
					//fprintf(file, "\tfstore %d\n", $3.id_reg);
					fprintf(file, "\tfstore %d\n", (yyvsp[-1].atom).id_reg);
					fprintf(file, "\tf2i\n");
					//fprintf(file, "\tfload %d\n", $3.id_reg);
					fprintf(file, "\tfload %d\n", (yyvsp[-1].atom).id_reg);
					fprintf(file, "\tf2i\n");
				}
				else {
					// constant
					fprintf(file, "\tfstore 49\n");
					fprintf(file, "\tf2i\n");
					fprintf(file, "\tfload 49\n");
					fprintf(file, "\tf2i\n");
				}
				fprintf(file, "\tirem\n");
				fprintf(file, "\ti2f\n");
			}
			else {
				// semantic error
				// Modulo operator (%) with floating point operands
				error_flag = 1;
				bzero(sem_error_msg, 100);
				strcat(sem_error_msg, "Modulo operator (%) with floating point operands");
			}
		}
		else gen_asgn((yyvsp[-4].atom).string_val, (yyvsp[-3].atom).string_val);
		int regnum = lookup_register_num((yyvsp[-4].atom).string_val);
		fprintf(file, "\tfstore %d\n", regnum);
	}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 538 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
		else {
			// local declaration
			int regnum = lookup_register_num((yyvsp[-3].atom).string_val);
			strcpy((yyvsp[-3].atom).type, lookup_type((yyvsp[-3].atom).string_val));
			if(!strcmp((yyvsp[-3].atom).type, "bool")) {
				int booltype;
				if(!strcmp((yyvsp[-1].atom).string_val, "true")) booltype = 1.0;
				else booltype = 2.0;
				fprintf(file, "\tldc %d\n", booltype);
				fprintf(file, "\tfstore %d\n", regnum);
			}
			else if(!strcmp((yyvsp[-3].atom).type, "string")) {
				fprintf(file, "\tldc \"%s\"\n", (yyvsp[-1].atom).string_val);
				fprintf(file, "\tastore %d\n", regnum);
			}
		}
	}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 563 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gen_arith_post((yyvsp[-2].atom).string_val, (yyvsp[-1].atom).string_val);
		if(lookup_symbol((yyvsp[-2].atom).string_val, "semantic") != -1) {
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[-2].atom).string_val));
		}
	}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 572 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gen_arith_pre((yyvsp[-1].atom).string_val, (yyvsp[-2].atom).string_val);
		if(lookup_symbol((yyvsp[-1].atom).string_val, "semantic") != -1) {
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[-1].atom).string_val));
		}
	}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 581 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
		else if(strcmp(lookup_attribute((yyvsp[-3].atom).string_val), func_para_type)) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		else {
			char paratype[100];
			strcpy(paratype, changeto_java_type());
			char* returntype = lookup_type((yyvsp[-3].atom).string_val);
			if(!strcmp(returntype, "void")) returntype = "V";
			else returntype = "F";
			fprintf(file, "\tinvokestatic compiler_hw3/%s(%s)%s\n", (yyvsp[-3].atom).string_val, paratype, returntype);
		}
	}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 602 "compiler_hw3.y" /* yacc.c:1646  */
    {
		memset(func_para_type, '\0', sizeof(func_para_type));
	}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 606 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-3].atom).string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, (yyvsp[-3].atom).string_val);
		}
		if(strcmp(lookup_attribute((yyvsp[-3].atom).string_val), "")) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		char* returntype = lookup_type((yyvsp[-3].atom).string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "\tinvokestatic compiler_hw3/%s()%s\n", (yyvsp[-3].atom).string_val, returntype);
		// assign function return to factor
		(yyval.atom).f_val = -1.0;
	}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 630 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tfsub\n");
		fprintf(file, "\tf2i\n");
		(yyval.atom).string_val = (yyvsp[-1].atom).string_val;
		strcpy((yyval.atom).type, "bool");
	}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 637 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom) = (yyvsp[0].atom);
	}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 644 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tfadd\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 649 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tfsub\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 654 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom) = (yyvsp[0].atom);
	}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 661 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tfmul\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 666 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if((!strcmp((yyvsp[0].atom).type, "float") && (yyvsp[0].atom).f_val == 0) || 
			(!strcmp((yyvsp[0].atom).type, "int") && (yyvsp[0].atom).i_val == 0)) {
			// semantic error
			// Variables of numbers that divided by zero
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Variables of numbers that divided by zero");
			
		}
		fprintf(file, "\tfdiv\n");
		(yyval.atom).f_val = -1.0;
	}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 680 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char type1[30], type2[30];
		strcpy(type1, (yyvsp[-2].atom).type);
		strcpy(type2, (yyvsp[0].atom).type);
		if(!strcmp(type1, "int") && !strcmp(type2, "int")) {
			// $3 is TOS
			if((yyvsp[0].atom).id_reg != -1) {
				// ID
				fprintf(file, "\tfstore %d\n", (yyvsp[0].atom).id_reg);
				fprintf(file, "\tf2i\n");
				fprintf(file, "\tfload %d\n", (yyvsp[0].atom).id_reg);
				fprintf(file, "\tf2i\n");
			}
			else {
				// constant
				fprintf(file, "\tfstore 49\n");
				fprintf(file, "\tf2i\n");
				fprintf(file, "\tfload 49\n");
				fprintf(file, "\tf2i\n");
			}
			fprintf(file, "\tirem\n");
			fprintf(file, "i2f\n");
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
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 713 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom) = (yyvsp[0].atom);
	}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 720 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			fprintf(file, "\tldc %f\n", (float)(yyvsp[0].atom).i_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = (float)(yyvsp[0].atom).i_val;
		(yyval.atom).id_reg = -1;
		strcpy((yyval.atom).type, "int");
	}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 731 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			fprintf(file, "\tldc %f\n", (yyvsp[0].atom).f_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = (yyvsp[0].atom).f_val;
		(yyval.atom).id_reg = -1;
		strcpy((yyval.atom).type, "float");
	}
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 742 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			fprintf(file, "\tldc -%f\n", (float)(yyvsp[0].atom).i_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = -(float)(yyvsp[0].atom).i_val;
		(yyval.atom).id_reg = -1;
		strcpy((yyval.atom).type, "int");
	}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 753 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// local declaration
		if(table_num != 0) {
			fprintf(file, "\tldc -%f\n", (yyvsp[0].atom).f_val);
		}
		// assign to factor for checking global declaration
		(yyval.atom).f_val = -(yyvsp[0].atom).f_val;
		(yyval.atom).id_reg = -1;
		strcpy((yyval.atom).type, "float");
	}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 764 "compiler_hw3.y" /* yacc.c:1646  */
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
			(yyval.atom).id_reg = lookup_register_num((yyvsp[0].atom).string_val);
			strcpy((yyval.atom).type, lookup_type((yyvsp[0].atom).string_val));
		}
	}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 779 "compiler_hw3.y" /* yacc.c:1646  */
    {
		// assign to factor
		(yyval.atom).f_val = -1.0;
		//strcpy($$.type, lookup_type($2.string_val));
	}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 785 "compiler_hw3.y" /* yacc.c:1646  */
    {	
		gen_arith_post((yyvsp[-1].atom).string_val, (yyvsp[0].atom).string_val);
		if(lookup_symbol((yyvsp[-1].atom).string_val, "semantic") != -1) {
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[-1].atom).string_val));
		}
	}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 794 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gen_arith_pre((yyvsp[0].atom).string_val, (yyvsp[-1].atom).string_val);
		if(lookup_symbol((yyvsp[0].atom).string_val, "semantic") != -1) {
			// assign to factor
			(yyval.atom).f_val = -1.0;
			strcpy((yyval.atom).type, lookup_type((yyvsp[0].atom).string_val));
		}
	}
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 803 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 826 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 849 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char label_name[30];
		strcpy(label_name, create_label_name("BEGIN_WHILE_", (yyvsp[-1].atom).i_val));
		fprintf(file, "%s:\n", label_name);
	}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 855 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char exit_label_name[30], true_label_name[30];
		strcpy(true_label_name, create_label_name("TRUE_WHILE_", (yyvsp[-4].atom).i_val));
		gen_relation((yyvsp[-1].atom).string_val, true_label_name);
		strcpy(exit_label_name, create_label_name("EXIT_WHILE_", (yyvsp[-4].atom).i_val));
		fprintf(file, "\tgoto %s\n", exit_label_name);
	}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 863 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		table_num++; 
		create_symbol(); 
	
		char label_name[30];
		strcpy(label_name, create_label_name("TRUE_WHILE_", (yyvsp[-6].atom).i_val));
		fprintf(file, "%s:\n", label_name);
	}
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 872 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;

		char begin_label_name[30], label_name[30];
		strcpy(begin_label_name, create_label_name("BEGIN_WHILE_", (yyvsp[-9].atom).i_val));
		fprintf(file, "\tgoto %s\n", begin_label_name);
		strcpy(label_name, create_label_name("EXIT_WHILE_", (yyvsp[-9].atom).i_val));
		fprintf(file, "%s:\n", label_name);
	}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 885 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if_label++;
		push_if_label_stack(if_label);
		char if_label_name[30], else_label_name[30];
		strcpy(if_label_name, create_label_name("IF_", if_label));
		strcat(if_label_name, "_");
		strcpy(if_label_name, create_label_name(if_label_name, ++if_label_table[if_label]));
		gen_relation_inverse((yyvsp[-1].atom).string_val, if_label_name);
	}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 894 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 895 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
		
		char exit_label_name[30], label_name[30];
		int tos = get_top_if_stack();
		// goto EXIT_IF_x
		strcpy(exit_label_name, create_label_name("EXIT_IF_", tos));
		fprintf(file, "\tgoto %s\n", exit_label_name);
		// IF_x_x:
		strcpy(label_name, create_label_name("IF_", tos));
		strcat(label_name, "_");
		strcpy(label_name, create_label_name(label_name, if_label_table[tos]));
		fprintf(file, "%s:\n", label_name);
	}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 911 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char exit_label_name[30];
		int tos = get_top_if_stack();
		strcpy(exit_label_name, create_label_name("EXIT_IF_", tos));
		fprintf(file, "%s:\n", exit_label_name);
		pop_if_label_stack();
	}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 927 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char label_name[30];
		int tos = get_top_if_stack();
		strcpy(label_name, create_label_name("IF_", tos));
		strcat(label_name, "_");
		strcpy(label_name, create_label_name(label_name, ++if_label_table[tos]));
		gen_relation_inverse((yyvsp[0].atom).string_val, label_name);
	}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 935 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 936 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;

		char exit_label_name[30], label_name[30];
		int tos = get_top_if_stack();
		// goto EXIT_IF_x
		strcpy(exit_label_name, create_label_name("EXIT_IF_", tos));
		fprintf(file, "\tgoto %s\n", exit_label_name);
		// IF_x_x:
		strcpy(label_name, create_label_name("IF_", tos));
		strcat(label_name, "_");
		strcpy(label_name, create_label_name(label_name, if_label_table[tos]));
		fprintf(file, "%s:\n", label_name);

	}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 954 "compiler_hw3.y" /* yacc.c:1646  */
    { table_num++; create_symbol(); }
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 955 "compiler_hw3.y" /* yacc.c:1646  */
    {
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;

		char exit_label_name[30], label_name[30];
		int tos = get_top_if_stack();
		// goto EXIT_IF_x
		strcpy(exit_label_name, create_label_name("EXIT_IF_", tos));
		fprintf(file, "\tgoto %s\n", exit_label_name);
	}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 985 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gen_print((yyvsp[0].atom).type);
	}
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 992 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char *strconst = strtok((yyvsp[-2].atom).string_val, "\"");
		fprintf(file, "\tldc \"%s\"\n", strconst);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "string");
	}
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 999 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc %f\n", (float)(yyvsp[-2].atom).i_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "int");
	}
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1005 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc %f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "float");
	}
#line 2578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1011 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc -%f", (float)(yyvsp[-2].atom).i_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "int");
	}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1017 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "\tldc -%f", (yyvsp[-2].atom).f_val);
		(yyval.atom) = (yyvsp[-2].atom);
		strcpy((yyval.atom).type, "float");
	}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1023 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1051 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom).string_val = "=";
	}
#line 2624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1055 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom).string_val = "+=";
	}
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1059 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom).string_val = "-=";
	}
#line 2640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1063 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom).string_val = "*=";
	}
#line 2648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1067 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom).string_val = "/=";
	}
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1071 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.atom).string_val = "%=";
	}
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2668 "y.tab.c" /* yacc.c:1646  */
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
#line 1090 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;
	
	table_num = 0;
	create_symbol();
	init();

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
	
	if(has_error == 1) {
		remove("./compiler_hw3.j");
	}
    
	return 0;
}

void init()
{
	init_func_table();
	register_site = 0;
	has_error = 0;
	if_label = -1;
	for(int i=0;i<100;i++) {
		if_label_table[i] = -1;
		if_label_stack[i] = 0;
	}
}

void yyerror(char *s)
{
	syntax_flag = 1;
	strcpy(syn_error_msg, s);
}

void syntax_error(char errormsg[100]) {
    has_error = 1;
	printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", errormsg);
    printf("\n|-----------------------------------------------|\n\n");
}

void semantic_error(char errormsg[100], int sem_line) {
    has_error = 1;
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
		for (int j=table_num;j>=0;j--) {
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
	if(!strcmp(type, "string")) type = "Ljava/lang/String;";
	else if(!strcmp(type, "int")) {
		fprintf(file, "\tf2i\n");
		type = "I";
	}
	else type = "F";
	fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
	fprintf(file, "\tswap\n");
	fprintf(file, "\tinvokevirtual java/io/PrintStream/println(%s)V\n", type);
}

void gen_ID(char value[100]) {
	int regnum = lookup_register_num(value);
	char type[30];
	strcpy(type, lookup_type(value));
	// global variable
	if(regnum == -1) {
		if(!strcmp(type, "string")) {
			fprintf(file, "\tgetstatic compiler_hw3/%s Ljava/lang/String;\n", value);	
		}
		else {
			// float, int, bool
			fprintf(file, "\tgetstatic compiler_hw3/%s F\n", value);	
		}
	}
	// local variable
	else {
		if(!strcmp(type, "string")) {
			fprintf(file, "\taload %d\n", regnum);
		}
		else {
			// float, int, bool
			fprintf(file, "\tfload %d\n", regnum);
		}
	}
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

void gen_arith_post(char string[100], char arith[100]) {
	if(lookup_symbol(string, "semantic") == -1) {
		error_flag = 1;
		bzero(sem_error_msg, 100);
		strcat(sem_error_msg, "Undeclared variable ");
		strcat(sem_error_msg, string);
	}
	else {
		int regnum = lookup_register_num(string);
		// global variable
		if(regnum == -1) {
			fprintf(file, "\tgetstatic compiler_hw3/%s\n", string);	
		}
		// local variable
		else {
			// only int has ++ and --
			if(!strcmp(arith, "++")) {
				fprintf(file, "\tfload %d\n", regnum);
				fprintf(file, "\tldc 1.0\n");
				fprintf(file, "\tfadd\n");
				fprintf(file, "\tfstore %d\n", regnum);
				fprintf(file, "\tfload %d\n", regnum);
				fprintf(file, "\tldc 1.0\n");
				fprintf(file, "\tfsub\n");
			}
			else {
				fprintf(file, "\tfload %d\n", regnum);
				fprintf(file, "\tldc 1.0\n");
				fprintf(file, "\tfsub\n");
				fprintf(file, "\tfstore %d\n", regnum);
				fprintf(file, "\tfload %d\n", regnum);
				fprintf(file, "\tldc 1.0\n");
				fprintf(file, "\tfadd\n");
			}
		}
	}
}

void gen_arith_pre(char string[100], char arith[100]) {
	int regnum = lookup_register_num(string);
	// global variable
	if(regnum == -1) {
		fprintf(file, "\tgetstatic compiler_hw3/%s\n", string);
	}
	// local variable
	else {
		// only int has ++ and --
		if(!strcmp(arith, "++")) {
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
}

void gen_asgn(char string[100], char asgn[10]) {
	int regnum = lookup_register_num(string);
	// float, int, bool
	if(!strcmp(asgn, "+=")) {
		fprintf(file, "\tfadd\n");
	}
	else if(!strcmp(asgn, "-=")) {
		fprintf(file, "\tfsub\n");
	}
	else if(!strcmp(asgn, "*=")) {
		fprintf(file, "\tfmul\n");
	}	
	else if(!strcmp(asgn, "/=")) {
		fprintf(file, "\tfdiv\n");
	}
}

char* create_label_name(char name[30], int label) {
	char label_num[10], newname[50];
	memset(newname, '\0', sizeof(newname));
	sprintf(label_num, "%d", label);
	strcat(newname, name);
	strcat(newname, label_num);
	char* returnname = newname;
	return returnname;
}

void gen_relation(char asgn[10], char label[30]) {
	if(!strcmp(asgn, ">")) {
		fprintf(file, "\tifgt %s\n", label);
	}
	else if(!strcmp(asgn, "<")) {
		fprintf(file, "\tiflt %s\n", label);
	}
	else if(!strcmp(asgn, ">=")) {
		fprintf(file, "\tifge %s\n", label);
	}
	else if(!strcmp(asgn, "<=")) {
		fprintf(file, "\tifle %s\n", label);
	}
	else if(!strcmp(asgn, "==")) {
		fprintf(file, "\tifeq %s\n", label);
	}
	else if(!strcmp(asgn, "!=")) {
		fprintf(file, "\tifne %s\n", label);
	}
}

void gen_relation_inverse(char asgn[10], char label[30]) {
	if(!strcmp(asgn, ">")) {
		fprintf(file, "\tifle %s\n", label);
	}
	else if(!strcmp(asgn, "<")) {
		fprintf(file, "\tifge %s\n", label);
	}
	else if(!strcmp(asgn, ">=")) {
		fprintf(file, "\tiflt %s\n", label);
	}
	else if(!strcmp(asgn, "<=")) {
		fprintf(file, "\tifgt %s\n", label);
	}
	else if(!strcmp(asgn, "==")) {
		fprintf(file, "\tifne %s\n", label);
	}
	else if(!strcmp(asgn, "!=")) {
		fprintf(file, "\tifeq %s\n", label);
	}
}

void push_if_label_stack(int label) {
	if(top >= MAXSTACK) {
		printf("If_label_stack is full\n");	
	}
	else {
		top++;
		if_label_stack[top] = label;
	}
}

int pop_if_label_stack() {
	int label;
	label = if_label_stack[top];
	top--;
	return label; 
}

int get_top_if_stack() {
	int label;
	label = if_label_stack[top];
	return label;
}
