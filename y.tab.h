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
