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
    INT = 258,
    FLOAT = 259,
    STRING = 260,
    BOOL = 261,
    VOID = 262,
    ADD = 263,
    SUB = 264,
    MUL = 265,
    DIV = 266,
    MOD = 267,
    ASGN = 268,
    ADDASGN = 269,
    SUBASGN = 270,
    MULASGN = 271,
    DIVASGN = 272,
    MODASGN = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    LB = 277,
    RB = 278,
    LCB = 279,
    RCB = 280,
    LSB = 281,
    RSB = 282,
    COMMA = 283,
    PRINT = 284,
    IF = 285,
    ELSE = 286,
    FOR = 287,
    WHILE = 288,
    ID = 289,
    SEMICOLON = 290,
    RET = 291,
    START_COMMENT = 292,
    END_COMMENT = 293,
    CPLUS_COMMENT = 294,
    I_CONST = 295,
    F_CONST = 296,
    S_CONST = 297,
    TRUE = 298,
    FALSE = 299,
    INC = 300,
    DEC = 301,
    MT = 302,
    LT = 303,
    MTE = 304,
    LTE = 305,
    EQ = 306,
    NE = 307
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define STRING 260
#define BOOL 261
#define VOID 262
#define ADD 263
#define SUB 264
#define MUL 265
#define DIV 266
#define MOD 267
#define ASGN 268
#define ADDASGN 269
#define SUBASGN 270
#define MULASGN 271
#define DIVASGN 272
#define MODASGN 273
#define AND 274
#define OR 275
#define NOT 276
#define LB 277
#define RB 278
#define LCB 279
#define RCB 280
#define LSB 281
#define RSB 282
#define COMMA 283
#define PRINT 284
#define IF 285
#define ELSE 286
#define FOR 287
#define WHILE 288
#define ID 289
#define SEMICOLON 290
#define RET 291
#define START_COMMENT 292
#define END_COMMENT 293
#define CPLUS_COMMENT 294
#define I_CONST 295
#define F_CONST 296
#define S_CONST 297
#define TRUE 298
#define FALSE 299
#define INC 300
#define DEC 301
#define MT 302
#define LT 303
#define MTE 304
#define LTE 305
#define EQ 306
#define NE 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 81 "compiler_hw3.y" /* yacc.c:1909  */

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
