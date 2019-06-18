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
#line 102 "compiler_hw3.y" /* yacc.c:1909  */

	struct atom {
   		int i_val;
    	double f_val;
    	char* string_val;
		char type[30];
	}atom;

#line 167 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
