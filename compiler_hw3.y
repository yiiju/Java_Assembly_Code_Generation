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
	}atom;
}

/* Token without return */
%token ADD SUB MUL DIV MOD
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token PRINT 
%token IF ELSE FOR WHILE
%token SEMICOLON
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

/* Nonterminal with return, which need to sepcify type */
%type <atom> type
%type <atom> func_end func
%type <atom> SEMICOLON
%type <atom> initializer
%type <atom> factor mul_expression_stat add_expression_stat expression_stat arithmetic_postfix
%type <atom> relational
%type <atom> const
%type <atom> print_func print_type

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
	| expression_stat SEMICOLON { expre_site = 0; }
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
	/*
		if(!strcmp($3.string_val, ";")) {
			table_num--;
			func_flag = 1;
		}
		*/
		//else func_flag = 1;
	}
	| RB func_end
	{
		if(!strcmp($2.string_val, ";")) {
			table_num--;
			func_flag = 1;
		}
		//else func_flag = 1;
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
					else booltype = 0.0;
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
					if(!strcmp($4.string_val, "true")) booltype = 1;
					else booltype = 0;
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
    			fprintf(file, "\tldc 0\n");
				if(!strcmp($1.string_val, "string")) {
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
				int regnum = lookup_register_num($2.string_val);
				if(!strcmp($1.string_val, "string")) {
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
			strcat(sem_error_msg, $2.string_val);
		}
	}
;

declaration_func
	: type ID LB 
	{ 
		int has = lookup_symbol($2.string_val, "global"); 
		int index = lookup_symbol($2.string_val, "insert");
		check_index.cur_func_index = index;
		if(has == -1) {
			// first time
			check_index.has = 0;
			if(index != -1) {
				insert_symbol($2.string_val, "function", $1.string_val, "", index);
			}
		}
		else {
			// declare or define before
			check_index.has = 1;
			if(!strcmp($1.string_val, global_table[0].table[has].name)) {
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
		strcpy($$.type, "string");
	}
	| expression_stat
	{
		expre_site = 0;
	}
	| TRUE
	{
		strcpy($$.type, "bool");
	}
	| FALSE
	{
		strcpy($$.type, "bool");
	}
;

expression
	: ID asgn expression_stat SEMICOLON
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $1.string_val);
		}
		expre_site = 0;
	}
	| ID arithmetic_postfix SEMICOLON
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $1.string_val);
		}
	}
	| arithmetic_postfix ID SEMICOLON
	{
		if(lookup_symbol($2.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $2.string_val);
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
		char* paratype;
		changeto_java_type(paratype);
		char* returntype = lookup_type($1.string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "\tinvokestatic compiler_hw3/%s(%s)%s\n", $1.string_val, paratype, returntype);
	} SEMICOLON
	| ID LB RB SEMICOLON
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared function ");
			strcat(sem_error_msg, $1.string_val);
		}
	}
	| SEMICOLON
;

expression_stat
	: expression_stat relational add_expression_stat
	{
		int flag = 0;
		if(!strcmp($2.string_val, ">")) {
			if($1.f_val > $3.f_val) flag = 1;
		}
		else if(!strcmp($2.string_val, "<")) {
			if($1.f_val < $3.f_val) flag = 1;
		}
		else if(!strcmp($2.string_val, ">=")) {
			if($1.f_val >= $3.f_val) flag = 1;
		}
		else if(!strcmp($2.string_val, "<=")) {
			if($1.f_val <= $3.f_val) flag = 1;
		}
		else if(!strcmp($2.string_val, "==")) {
			if($1.f_val == $3.f_val) flag = 1;
		}
		else if(!strcmp($2.string_val, "!=")) {
			if($1.f_val != $3.f_val) flag = 1;
		}
		if(flag == 1) $$.f_val = 1.0;
		else $$.f_val = 0.0;
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
		fprintf(file, "\tfadd\n");
		$$.f_val = -1.0;
	}
	| add_expression_stat SUB mul_expression_stat
	{
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
		fprintf(file, "\tfmul\n");
		$$.f_val = -1.0;
	}
	| mul_expression_stat DIV factor
	{
		fprintf(file, "\tfdiv\n");
		$$.f_val = -1.0;
	}
	| mul_expression_stat MOD factor
	{
		char type1[30], type2[30];
		strcpy(type1, $1.type);
		strcpy(type2, $3.type);
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
			//set_expre_factor(0, -1, $1.i_val, -1, "int");
			fprintf(file, "\tldc %f\n", (float)$1.i_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = (float)$1.i_val;
		strcpy($$.type, "int");
	}
	| F_CONST
	{
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, -1, $1.f_val, "float");
			fprintf(file, "\tldc %f\n", $1.f_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = $1.f_val;
		strcpy($$.type, "float");
	}
	| SUB I_CONST
	{
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, -$2.i_val, -1, "int");
			fprintf(file, "\tldc -%f\n", (float)$2.i_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = -(float)$2.i_val;
		strcpy($$.type, "int");
	}
	| SUB F_CONST
	{
		// local declaration
		if(table_num != 0) {
			//set_expre_factor(0, -1, -1, -$2.i_val, "float");
			fprintf(file, "\tldc -%f\n", $2.f_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = -$2.f_val;
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
			$$.f_val = -1.0;
			strcpy($$.type, lookup_type($1.string_val));
		}
	}
	| LB expression_stat RB
	{
		// set_expre_factor(0, -1, -1, -$2.i_val, "float");
		// assign to factor
		$$.f_val = -1.0;
		//strcpy($$.type, lookup_type($2.string_val));
	}
	| ID arithmetic_postfix
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $1.string_val);
		}
		else {
			int regnum = lookup_register_num($1.string_val);
			// global variable
			if(regnum == -1) {
				fprintf(file, "\tgetstatic compiler_hw3/%s\n", $1.string_val);	
			}
			// local variable
			else {
				// only int has ++ and --
				if(!strcmp($2.string_val, "++")) {
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
			$$.f_val = -1.0;
			strcpy($$.type, lookup_type($1.string_val));
		}
	}
	| arithmetic_postfix ID
	{
		if(lookup_symbol($2.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $2.string_val);
		}
		else {
			int regnum = lookup_register_num($2.string_val);
			// global variable
			if(regnum == -1) {
				fprintf(file, "\tgetstatic compiler_hw3/%s\n", $2.string_val);
			}
			// local variable
			else {
				// only int has ++ and --
				if(!strcmp($1.string_val, "++")) {
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
	: WHILE LB expression_stat { expre_site = 0; } RB LCB { table_num++; create_symbol(); } func_mul_stat RCB
	{
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
	| IF LB expression_stat { expre_site = 0; } RB LCB { table_num++; create_symbol(); }  func_mul_stat RCB
	{
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	} haselse
;

haselse
	: ELSE haselseif
	|
;

haselseif
	: IF LB expression_stat { expre_site = 0; } RB LCB { table_num++; create_symbol(); } func_mul_stat RCB
	{
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	} moreelseif
	| LCB { table_num++; create_symbol(); } func_mul_stat RCB
	{
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
;

moreelseif
	: ELSE haselseif
	|
;

/*
mul_stat
	: stat mul_stat
	| stat
;
*/

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
		fprintf(file, "\tldc %s\n", strconst);
		$$ = $1;
		strcpy($$.type, "string");
	}
	| I_CONST RB SEMICOLON
	{
		fprintf(file, "\tldc %f", $1.f_val);
		$$ = $1;
		strcpy($$.type, "int");
	}
	| F_CONST RB SEMICOLON
	{
		fprintf(file, "\tldc %f", $1.f_val);
		$$ = $1;
		strcpy($$.type, "float");
	}
	| SUB I_CONST RB SEMICOLON
	{
		fprintf(file, "\tldc %f", $2.f_val);
		$$ = $2;
		strcpy($$.type, "int");
	}
	| SUB F_CONST RB SEMICOLON
	{
		fprintf(file, "\tldc %f", $2.f_val);
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
	| ADDASGN
	| SUBASGN
	| MULASGN
	| DIVASGN
	| MODASGN
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
