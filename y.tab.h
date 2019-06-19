/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    IF = 267,
    ELSE = 268,
    FOR = 269,
    WHILE = 270,
    RET = 271,
    START_COMMENT = 272,
    END_COMMENT = 273,
    CPLUS_COMMENT = 274,
    I_CONST = 275,
    F_CONST = 276,
    S_CONST = 277,
    TRUE = 278,
    FALSE = 279,
    INC = 280,
    DEC = 281,
    MT = 282,
    LT = 283,
    MTE = 284,
    LTE = 285,
    EQ = 286,
    NE = 287,
    ID = 288,
    INT = 289,
    FLOAT = 290,
    BOOL = 291,
    STRING = 292,
    VOID = 293,
    SEMICOLON = 294,
    LB = 295,
    RB = 296,
    LCB = 297,
    RCB = 298,
    LSB = 299,
    RSB = 300,
    COMMA = 301,
    ASGN = 302,
    ADDASGN = 303,
    SUBASGN = 304,
    MULASGN = 305,
    DIVASGN = 306,
    MODASGN = 307
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
#define IF 267
#define ELSE 268
#define FOR 269
#define WHILE 270
#define RET 271
#define START_COMMENT 272
#define END_COMMENT 273
#define CPLUS_COMMENT 274
#define I_CONST 275
#define F_CONST 276
#define S_CONST 277
#define TRUE 278
#define FALSE 279
#define INC 280
#define DEC 281
#define MT 282
#define LT 283
#define MTE 284
#define LTE 285
#define EQ 286
#define NE 287
#define ID 288
#define INT 289
#define FLOAT 290
#define BOOL 291
#define STRING 292
#define VOID 293
#define SEMICOLON 294
#define LB 295
#define RB 296
#define LCB 297
#define RCB 298
#define LSB 299
#define RSB 300
#define COMMA 301
#define ASGN 302
#define ADDASGN 303
#define SUBASGN 304
#define MULASGN 305
#define DIVASGN 306
#define MODASGN 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 95 "compiler_hw3.y" /* yacc.c:1909  */

	struct atom {
   		int i_val;
    	double f_val;
    	char* string_val;
		char type[30];
		int id_reg;
	}atom;

#line 168 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
