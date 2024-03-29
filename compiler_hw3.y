/*	Definition section */
%{
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
struct arith_flag {
	int flag;
	char operator[3];
	int global;
	int regnum;
	char name[30];
}arith_flag;
void gen_asgn(char[], char[]);
void gen_load_arith();

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

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
	struct atom {
   		int i_val;
    	double f_val;
    	char* string_val;
		char type[30];
		int id_reg;
	}atom;
}

/* Token without return */
%token ADD SUB MUL DIV MOD
%token AND OR NOT
%token PRINT 
%token RET
%token START_COMMENT END_COMMENT CPLUS_COMMENT

/* Token with return, which need to sepcify type */
%token <atom> I_CONST
%token <atom> F_CONST
%token <atom> S_CONST
%token <atom> TRUE
%token <atom> FALSE
%token <atom> INC 
%token <atom> DEC
%token <atom> MT LT MTE LTE EQ NE
%token <atom> ID INT FLOAT BOOL STRING VOID
%token <atom> SEMICOLON
%token <atom> LB RB LCB RCB LSB RSB COMMA
%token <atom> ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token <atom> IF ELSE FOR WHILE

/* Nonterminal with return, which need to sepcify type */
%type <atom> type
%type <atom> func_end func func_parameter
%type <atom> initializer
%type <atom> factor mul_expression_stat add_expression_stat expression_stat arithmetic_postfix
%type <atom> relational
%type <atom> const
%type <atom> print_func print_type
%type <atom> expression
%type <atom> asgn
%type <atom> iteration_stat

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat
    |
;

stat
    : declaration 
	| declaration_func
	| comment_stat
;

func_stat
    : declaration 
    | expression
	| iteration_stat
    | print_func
	| comment_stat
	| RET return_stat 
;

func_mul_stat
	: func_stat func_mul_stat
	| func_stat
;

return_stat
	: initializer SEMICOLON
	| expression_stat SEMICOLON 
	| SEMICOLON
;

func
	: func_parameter RB
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
	func_end
	{
		//if(!strcmp($3.string_val, ";")) {
		if(!strcmp($4.string_val, ";")) {
			table_num--;
		}
	}
	| RB func_end
	{
		if(!strcmp($2.string_val, ";")) {
			table_num--;
		}
	}
;

func_end
	: SEMICOLON
	{
		if(get_func_decla() == 1) {
			// redefine function
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, global_table[0].table[check_index.cur_func_index].name);
		}
		else set_func_decla(1);
		$$.string_val = ";";
		register_site = 0;
	}
	| LCB 
	{
		gen_function();
	}
	func_mul_stat RCB
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
;

declaration
    : type ID ASGN initializer SEMICOLON 
	{
		int index = lookup_symbol($2.string_val, "insert"); 
		if(index != -1) {
			insert_symbol($2.string_val, "variable", $1.string_val, "\0", index);
			// global declaration
			if(table_num == 0) {
				char type_descriptor[20];
				if(!strcmp($1.string_val, "bool")) {
					strcpy(type_descriptor,"F");
					float booltype;
					if(!strcmp($4.string_val, "true")) booltype = 1.0;
					else booltype = 2.0;
    				fprintf(file, ".field public static %s %s = %f\n", $2.string_val, type_descriptor, booltype);
				}
				else if(!strcmp($1.string_val, "string")) {
					strcpy(type_descriptor,"Ljava/lang/String;");
					char *strconst = strtok($4.string_val, "\"");
    				fprintf(file, ".field public static %s %s = \"%s\"\n", $2.string_val, type_descriptor, strconst);
				}
			}
			// local declaration
			else {
				if(!strcmp($1.string_val, "bool")) {
					int booltype;
					if(!strcmp($4.string_val, "true")) booltype = 1.0;
					else booltype = 2.0;
					fprintf(file, "\tldc %d\n", booltype);
					fprintf(file, "\tistore %d\n", index);
				}
				else if(!strcmp($1.string_val, "string")) {
					char *strconst = strtok($4.string_val, "\"");
					fprintf(file, "\tldc \"%s\"\n", strconst);
					fprintf(file, "\tastore %d\n", index);
				}
			}
		}
		else {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared variable ");
			strcat(sem_error_msg, $2.string_val);
		}
	}
    | type ID SEMICOLON
	{
		int index = lookup_symbol($2.string_val, "insert"); 
		if(index != -1) {
			insert_symbol($2.string_val, "variable", $1.string_val, "\0", index);
			// global declaration
			if(table_num == 0) {
				char type_descriptor[20];
				if(!strcmp($1.string_val, "string")) {
					strcpy(type_descriptor, "Ljava/lang/String;");
    				fprintf(file, ".field public static %s %s\n", $2.string_val, type_descriptor);
				}
				else {
					// float, int, bool
					strcpy(type_descriptor, "F");
    				fprintf(file, ".field public static %s %s\n", $2.string_val, type_descriptor);
				}
			}
			// local declaration
			else {
				char type_descriptor[20];
    			fprintf(file, "\tldc 0.0\n");
				int regnum = lookup_register_num($2.string_val);
				if(!strcmp($1.string_val, "string")) {
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
			strcat(sem_error_msg, $2.string_val);
		}
	}
	| type ID ASGN expression_stat SEMICOLON
	{
		int index = lookup_symbol($2.string_val, "insert"); 
		if(index != -1) {
			insert_symbol($2.string_val, "variable", $1.string_val, "\0", index);
			// global declaration
			if(table_num == 0) {
				char type_descriptor[30];
				// float, int
				strcpy(type_descriptor, "F");
				fprintf(file, ".field public static %s %s = %f\n", $2.string_val, type_descriptor, $4.f_val);	
			}
			// local declaration
			else {
				gen_load_arith();
				int regnum = lookup_register_num($2.string_val);
				if(!strcmp($1.string_val, "string")) {
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
			strcat(sem_error_msg, $2.string_val);
		}
	}
;

declaration_func
	: type ID LB 
	{ 
		int has = lookup_symbol($2.string_val, "global"); 
		int index = lookup_symbol($2.string_val, "insert");
		if(has == -1) {
			// first time
			check_index.cur_func_index = index;
			check_index.has = 0;
			if(index != -1) {
				insert_symbol($2.string_val, "function", $1.string_val, "", index);
			}
		}
		else {
			// declare or define before
			check_index.cur_func_index = has;
			check_index.has = 1;
			if(strcmp($1.string_val, global_table[0].table[has].type)) {
				// return type not the same
				error_flag = 1;
				bzero(sem_error_msg, 100);
				strcat(sem_error_msg, "function return type is not the same");
			}
		}
		table_num++; 
		create_symbol();
	}
	func
;

func_parameter
	: func_parameter COMMA type ID
	{
		int index = lookup_symbol($4.string_val, "insert"); 
		if(index != -1) {
			insert_symbol($4.string_val, "parameter", $3.string_val, "\0", index);
		}
	}
	| type ID
	{
		int index = lookup_symbol($2.string_val, "insert"); 
		if(index != -1) {
			insert_symbol($2.string_val, "parameter", $1.string_val, "\0", index);
		}
	}
;

func_call
	: func_call COMMA const
	{
		if(strcmp(func_para_type, "")) {
			strcat(func_para_type, ", ");
			strcat(func_para_type, $3.type);
		}
		else {
			strcpy(func_para_type, $3.type);
		}
	}
	| const
	{
		if(strcmp(func_para_type, "")) {
			strcat(func_para_type, ", ");
			strcat(func_para_type, $1.type);
		}
		else {
			strcpy(func_para_type, $1.type);
		}
	}
;

const
	: S_CONST
	{
		fprintf(file, "\tldc \"%s\"\n", $1.string_val);
		strcpy($$.type, "string");
	}
	| expression_stat
	| TRUE
	{
		fprintf(file, "\tldc 1.0\n");
		strcpy($$.type, "bool");
	}
	| FALSE
	{
		fprintf(file, "\tldc 2.0\n");
		strcpy($$.type, "bool");
	}
;

expression
	: ID asgn 
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $1.string_val);
		}
		else {
			int regnum = lookup_register_num($1.string_val);
			// int, float, bool
			if(strcmp($2.string_val, "=")) {
				fprintf(file, "\tfload %d\n", regnum);
			}
		}
	}
	expression_stat SEMICOLON
	{
		if(!strcmp($2.string_val, "%=")) {
			// check int type
			//if(!strcmp($1.type, "int") && !strcmp($3.type, "int")) {
			if(!strcmp($1.type, "int") && !strcmp($4.type, "int")) {
				// expre is TOS
				//if($3.id_reg != -1) {
				if($4.id_reg != -1) {
					// ID
					//fprintf(file, "\tfstore %d\n", $3.id_reg);
					fprintf(file, "\tfstore %d\n", $4.id_reg);
					fprintf(file, "\tf2i\n");
					//fprintf(file, "\tfload %d\n", $3.id_reg);
					fprintf(file, "\tfload %d\n", $4.id_reg);
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
		else gen_asgn($1.string_val, $2.string_val);
		
		gen_load_arith();
		int regnum = lookup_register_num($1.string_val);
		fprintf(file, "\tfstore %d\n", regnum);
	}
	| ID ASGN initializer SEMICOLON
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $1.string_val);
		}
		else {
			// local declaration
			int regnum = lookup_register_num($1.string_val);
			strcpy($1.type, lookup_type($1.string_val));
			if(!strcmp($1.type, "bool")) {
				int booltype;
				if(!strcmp($3.string_val, "true")) booltype = 1.0;
				else booltype = 2.0;
				fprintf(file, "\tldc %d\n", booltype);
				fprintf(file, "\tfstore %d\n", regnum);
			}
			else if(!strcmp($1.type, "string")) {
				char *strconst = strtok($3.string_val, "\"");
				fprintf(file, "\tldc \"%s\"\n", strconst);
				fprintf(file, "\tastore %d\n", regnum);
			}
		}
	}
	| ID arithmetic_postfix SEMICOLON
	{
		gen_arith_post($1.string_val, $2.string_val);
		if(lookup_symbol($1.string_val, "semantic") != -1) {
			// assign to factor
			$$.f_val = -1.0;
			strcpy($$.type, lookup_type($1.string_val));
		}
		arith_flag.flag = 0;
	}
	| arithmetic_postfix ID SEMICOLON
	{
		gen_arith_pre($2.string_val, $1.string_val);
		if(lookup_symbol($2.string_val, "semantic") != -1) {
			// assign to factor
			$$.f_val = -1.0;
			strcpy($$.type, lookup_type($2.string_val));
		}
		arith_flag.flag = 0;
	}
	| ID LB func_call RB 
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, $1.string_val);
		}
		else if(strcmp(lookup_attribute($1.string_val), func_para_type)) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		else {
			char paratype[100];
			strcpy(paratype, changeto_java_type());
			char* returntype = lookup_type($1.string_val);
			if(!strcmp(returntype, "void")) returntype = "V";
			else returntype = "F";
			fprintf(file, "\tinvokestatic compiler_hw3/%s(%s)%s\n", $1.string_val, paratype, returntype);
		}
	} SEMICOLON
	{
		memset(func_para_type, '\0', sizeof(func_para_type));
	}
	| ID LB RB SEMICOLON
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, $1.string_val);
		}
		if(strcmp(lookup_attribute($1.string_val), "")) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		char* returntype = lookup_type($1.string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "\tinvokestatic compiler_hw3/%s()%s\n", $1.string_val, returntype);
		// assign function return to factor
		$$.f_val = -1.0;
	}
	| SEMICOLON
;

expression_stat
	: expression_stat relational add_expression_stat
	{
		fprintf(file, "\tfsub\n");
		fprintf(file, "\tf2i\n");
		$$.string_val = $2.string_val;
		strcpy($$.type, "bool");
	}
	| add_expression_stat
	{
		$$ = $1;
	}
;

add_expression_stat
	: add_expression_stat ADD mul_expression_stat
	{
		gen_load_arith();
		fprintf(file, "\tfadd\n");
		$$.f_val = -1.0;
	}
	| add_expression_stat SUB mul_expression_stat
	{
		gen_load_arith();
		fprintf(file, "\tfsub\n");
		$$.f_val = -1.0;
	}
	| mul_expression_stat
	{
		$$ = $1;
	}
;

mul_expression_stat
	: mul_expression_stat MUL factor
	{
		gen_load_arith();
		fprintf(file, "\tfmul\n");
		$$.f_val = -1.0;
	}
	| mul_expression_stat DIV factor
	{
		gen_load_arith();
		if((!strcmp($3.type, "float") && $3.f_val == 0) || 
			(!strcmp($3.type, "int") && $3.i_val == 0)) {
			// semantic error
			// Variables of numbers that divided by zero
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Variables of numbers that divided by zero");
			
		}
		fprintf(file, "\tfdiv\n");
		$$.f_val = -1.0;
	}
	| mul_expression_stat MOD factor
	{
		char type1[30], type2[30];
		strcpy(type1, $1.type);
		strcpy(type2, $3.type);
		if(!strcmp(type1, "int") && !strcmp(type2, "int")) {
			// $3 is TOS
			if($3.id_reg != -1) {
				// ID
				fprintf(file, "\tfstore %d\n", $3.id_reg);
				fprintf(file, "\tf2i\n");
				fprintf(file, "\tfload %d\n", $3.id_reg);
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
		$$.f_val = -1.0;
	}
	| factor
	{
		$$ = $1;
	}
;

factor
	: I_CONST
	{
		// local declaration
		if(table_num != 0) {
			fprintf(file, "\tldc %f\n", (float)$1.i_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = (float)$1.i_val;
		$$.id_reg = -1;
		strcpy($$.type, "int");
	}
	| F_CONST
	{
		// local declaration
		if(table_num != 0) {
			fprintf(file, "\tldc %f\n", $1.f_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = $1.f_val;
		$$.id_reg = -1;
		strcpy($$.type, "float");
	}
	| SUB I_CONST
	{
		// local declaration
		if(table_num != 0) {
			fprintf(file, "\tldc -%f\n", (float)$2.i_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = -(float)$2.i_val;
		$$.id_reg = -1;
		strcpy($$.type, "int");
	}
	| SUB F_CONST
	{
		// local declaration
		if(table_num != 0) {
			fprintf(file, "\tldc -%f\n", $2.f_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = -$2.f_val;
		$$.id_reg = -1;
		strcpy($$.type, "float");
	}
	| ID
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $1.string_val);
		}
		else {
			gen_ID($1.string_val);
			// assign to factor
			$$.id_reg = lookup_register_num($1.string_val);
			strcpy($$.type, lookup_type($1.string_val));
		}
	}
	| LB expression_stat RB
	{
		// assign to factor
		$$.f_val = -1.0;
		//strcpy($$.type, lookup_type($2.string_val));
	}
	| ID arithmetic_postfix
	{	
		gen_arith_post($1.string_val, $2.string_val);
		if(lookup_symbol($1.string_val, "semantic") != -1) {
			// assign to factor
			$$.f_val = -1.0;
			strcpy($$.type, lookup_type($1.string_val));
		}
	}
	| arithmetic_postfix ID
	{
		gen_arith_pre($2.string_val, $1.string_val);
		if(lookup_symbol($2.string_val, "semantic") != -1) {
			// assign to factor
			$$.f_val = -1.0;
			strcpy($$.type, lookup_type($2.string_val));
		}
	}
	| ID LB func_call RB
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, $1.string_val);
		}
		if(strcmp(lookup_attribute($1.string_val), func_para_type)) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		char paratype[100];
		strcpy(paratype, changeto_java_type());
		char* returntype = lookup_type($1.string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "\tinvokestatic compiler_hw3/%s(%s)%s\n", $1.string_val, paratype, returntype);
		memset(func_para_type, '\0', sizeof(func_para_type));
		// assign function return to factor
		$$.f_val = -1.0;
	}
	| ID LB RB
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, $1.string_val);
		}
		if(strcmp(lookup_attribute($1.string_val), "")) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		char* returntype = lookup_type($1.string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "\tinvokestatic compiler_hw3/%s()%s\n", $1.string_val, returntype);
		// assign function return to factor
		$$.f_val = -1.0;
	}
;

iteration_stat
	: WHILE LB 
	{
		char label_name[30];
		strcpy(label_name, create_label_name("BEGIN_WHILE_", $1.i_val));
		fprintf(file, "%s:\n", label_name);
	}
	expression_stat RB 
	{
		char exit_label_name[30], true_label_name[30];
		strcpy(true_label_name, create_label_name("TRUE_WHILE_", $1.i_val));
		gen_relation($4.string_val, true_label_name);
		strcpy(exit_label_name, create_label_name("EXIT_WHILE_", $1.i_val));
		fprintf(file, "\tgoto %s\n", exit_label_name);
	}
	LCB 
	{ 
		table_num++; 
		create_symbol(); 
	
		char label_name[30];
		strcpy(label_name, create_label_name("TRUE_WHILE_", $1.i_val));
		fprintf(file, "%s:\n", label_name);
	} 
	func_mul_stat RCB
	{
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;

		char begin_label_name[30], label_name[30];
		strcpy(begin_label_name, create_label_name("BEGIN_WHILE_", $1.i_val));
		fprintf(file, "\tgoto %s\n", begin_label_name);
		strcpy(label_name, create_label_name("EXIT_WHILE_", $1.i_val));
		fprintf(file, "%s:\n", label_name);
	}
	| IF LB expression_stat RB 
	{
		if_label++;
		push_if_label_stack(if_label);
		char if_label_name[30], else_label_name[30];
		strcpy(if_label_name, create_label_name("IF_", if_label));
		strcat(if_label_name, "_");
		strcpy(if_label_name, create_label_name(if_label_name, ++if_label_table[if_label]));
		gen_relation_inverse($3.string_val, if_label_name);
	}
	LCB { table_num++; create_symbol(); }  func_mul_stat RCB
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
	} haselse {
		char exit_label_name[30];
		int tos = get_top_if_stack();
		strcpy(exit_label_name, create_label_name("EXIT_IF_", tos));
		fprintf(file, "%s:\n", exit_label_name);
		pop_if_label_stack();
	}
;

haselse
	: ELSE haselseif
	|
;

haselseif
	: IF LB expression_stat 
	{
		char label_name[30];
		int tos = get_top_if_stack();
		strcpy(label_name, create_label_name("IF_", tos));
		strcat(label_name, "_");
		strcpy(label_name, create_label_name(label_name, ++if_label_table[tos]));
		gen_relation_inverse($3.string_val, label_name);
	}
	RB LCB { table_num++; create_symbol(); } func_mul_stat RCB
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

	} moreelseif
	| LCB { table_num++; create_symbol(); } func_mul_stat RCB
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
;

moreelseif
	: ELSE haselseif
	|
;

relational
	: MT
	| LT
	| MTE
	| LTE
	| EQ
	| NE
;

print_func
	: PRINT LB print_type
	{
		gen_print($3.type);
	}
;

print_type
	: S_CONST RB SEMICOLON
	{
		char *strconst = strtok($1.string_val, "\"");
		fprintf(file, "\tldc \"%s\"\n", strconst);
		$$ = $1;
		strcpy($$.type, "string");
	}
	| I_CONST RB SEMICOLON
	{
		fprintf(file, "\tldc %f\n", (float)$1.i_val);
		$$ = $1;
		strcpy($$.type, "int");
	}
	| F_CONST RB SEMICOLON
	{
		fprintf(file, "\tldc %f\n", $1.f_val);
		$$ = $1;
		strcpy($$.type, "float");
	}
	| SUB I_CONST RB SEMICOLON
	{
		fprintf(file, "\tldc -%f", (float)$2.i_val);
		$$ = $2;
		strcpy($$.type, "int");
	}
	| SUB F_CONST RB SEMICOLON
	{
		fprintf(file, "\tldc -%f", $2.f_val);
		$$ = $2;
		strcpy($$.type, "float");
	}
	| ID RB SEMICOLON
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $1.string_val);
		}
		else {
			gen_ID($1.string_val);
			$$ = $1;
			strcpy($$.type, lookup_type($1.string_val));
		}
	}
;

comment_stat
	: CPLUS_COMMENT 
	| START_COMMENT END_COMMENT
;

initializer
	: S_CONST
	| TRUE
	| FALSE
;

asgn
	: ASGN
	{
		$$.string_val = "=";
	}
	| ADDASGN
	{
		$$.string_val = "+=";
	}
	| SUBASGN
	{
		$$.string_val = "-=";
	}
	| MULASGN
	{
		$$.string_val = "*=";
	}
	| DIVASGN
	{
		$$.string_val = "/=";
	}
	| MODASGN
	{
		$$.string_val = "%=";
	}
;

arithmetic_postfix
	: INC
	| DEC 
;

/* actions can be taken when meet the token or rule */
type
    : INT
    | FLOAT
    | BOOL
    | STRING
    | VOID
;

%%

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
	arith_flag.flag = 0;
	memset(arith_flag.operator, '\0', sizeof(arith_flag.operator));
	arith_flag.global = -1;
	arith_flag.regnum = -1;
	memset(arith_flag.name, '\0', sizeof(arith_flag.name));
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
			fprintf(file, "\tgetstatic compiler_hw3/%s F\n", string);	
			fprintf(file, "\tldc 1.0\n");
			fprintf(file, "\tfadd\n");
			fprintf(file, "\tputstatic compiler_hw3/%s F\n", string);
			arith_flag.global = 1;
			strcpy(arith_flag.name, string);
		}
		// local variable
		else {
			// only int has ++ and --
			if(!strcmp(arith, "++")) {
				fprintf(file, "\tfload %d\n", regnum);
				fprintf(file, "\tldc 1.0\n");
				fprintf(file, "\tfadd\n");
				fprintf(file, "\tfstore %d\n", regnum);
/*
				fprintf(file, "\tfload %d\n", regnum);
				fprintf(file, "\tldc 1.0\n");
				fprintf(file, "\tfsub\n");
*/
			}
			else {
				fprintf(file, "\tfload %d\n", regnum);
				fprintf(file, "\tldc 1.0\n");
				fprintf(file, "\tfsub\n");
				fprintf(file, "\tfstore %d\n", regnum);
/*
				fprintf(file, "\tfload %d\n", regnum);
				fprintf(file, "\tldc 1.0\n");
				fprintf(file, "\tfadd\n");
			*/
			}
			arith_flag.global = 0;
			arith_flag.regnum = regnum;
		}
		arith_flag.flag = 1;
		strcpy(arith_flag.operator, arith);
	}
}

void gen_arith_pre(char string[100], char arith[100]) {
	int regnum = lookup_register_num(string);
	// global variable
	if(regnum == -1) {
		fprintf(file, "\tgetstatic compiler_hw3/%s F\n", string);
		fprintf(file, "\tldc 1.0\n");
		fprintf(file, "\tfadd\n");
		fprintf(file, "\tputstatic compiler_hw3/%s F\n", string); // store back to global
		arith_flag.global = 1;
		strcpy(arith_flag.name, string);
	}
	// local variable
	else {
		// only int has ++ and --
		if(!strcmp(arith, "++")) {
			fprintf(file, "\tfload %d\n", regnum);
			fprintf(file, "\tldc 1.0\n");
			fprintf(file, "\tfadd\n");
			fprintf(file, "\tfstore %d\n", regnum); // store back to register
//			fprintf(file, "\tfload %d\n", regnum); // put on TOS
		}
		else {
			fprintf(file, "\tfload %d\n", regnum);
			fprintf(file, "\tldc 1.0\n");
			fprintf(file, "\tfsub\n");
			fprintf(file, "\tfstore %d\n", regnum); // store back to register
//			fprintf(file, "\tfload %d\n", regnum); // put on TOS
		}
		arith_flag.global = 0;
		arith_flag.regnum = regnum;
	}
	arith_flag.flag = 2;
	strcpy(arith_flag.operator, arith);
}

void gen_load_arith() {
	// postfix ++ and --
	if(arith_flag.flag == 1) {
		if(arith_flag.global == 0) {
			//local
			fprintf(file, "\tfload %d\n", arith_flag.regnum);
		}
		else {
			// global
			fprintf(file, "\tgetstatic compiler_hw3/%s F", arith_flag.name);
		}
		fprintf(file, "\tldc 1.0\n");
		if(!strcmp(arith_flag.operator, "++")) {
			fprintf(file, "\tfsub\n");
		}
		else fprintf(file, "\tfadd\n");
	}
	// prefix ++ and --
	else if(arith_flag.flag == 2) {
		if(arith_flag.global == 0) {
			//local
			fprintf(file, "\tfload %d\n", arith_flag.regnum);
		}
		else {
			// global
			fprintf(file, "\tgetstatic compiler_hw3/%s F", arith_flag.name);
		}
	}
	arith_flag.flag = 0;
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
