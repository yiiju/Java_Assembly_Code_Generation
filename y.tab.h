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
#line 110 "compiler_hw3.y" /* yacc.c:1909  */

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
