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
    INC = 268,
    DEC = 269,
    MT = 270,
    LT = 271,
    MTE = 272,
    LTE = 273,
    EQ = 274,
    NE = 275,
    ASGN = 276,
    ADDASGN = 277,
    SUBASGN = 278,
    MULASGN = 279,
    DIVASGN = 280,
    MODASGN = 281,
    AND = 282,
    OR = 283,
    NOT = 284,
    LB = 285,
    RB = 286,
    LCB = 287,
    RCB = 288,
    LSB = 289,
    RSB = 290,
    COMMA = 291,
    PRINT = 292,
    IF = 293,
    ELSE = 294,
    FOR = 295,
    WHILE = 296,
    ID = 297,
    SEMICOLON = 298,
    RET = 299,
    START_COMMENT = 300,
    END_COMMENT = 301,
    CPLUS_COMMENT = 302,
    I_CONST = 303,
    F_CONST = 304,
    S_CONST = 305,
    TRUE = 306,
    FALSE = 307
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
#define INC 268
#define DEC 269
#define MT 270
#define LT 271
#define MTE 272
#define LTE 273
#define EQ 274
#define NE 275
#define ASGN 276
#define ADDASGN 277
#define SUBASGN 278
#define MULASGN 279
#define DIVASGN 280
#define MODASGN 281
#define AND 282
#define OR 283
#define NOT 284
#define LB 285
#define RB 286
#define LCB 287
#define RCB 288
#define LSB 289
#define RSB 290
#define COMMA 291
#define PRINT 292
#define IF 293
#define ELSE 294
#define FOR 295
#define WHILE 296
#define ID 297
#define SEMICOLON 298
#define RET 299
#define START_COMMENT 300
#define END_COMMENT 301
#define CPLUS_COMMENT 302
#define I_CONST 303
#define F_CONST 304
#define S_CONST 305
#define TRUE 306
#define FALSE 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 75 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    double f_val;
    char* string_val;
//	bool bool_val;

#line 165 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
