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

void gencode_function();

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

char call_func_parameter_type[100];
char* lookup_attribute(char[]);
char* changeto_java_type();

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
%token INT FLOAT STRING BOOL VOID
%token ADD SUB MUL DIV MOD
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token PRINT 
%token IF ELSE FOR WHILE
%token ID SEMICOLON
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

/* Nonterminal with return, which need to sepcify type */
%type <atom> type
%type <atom> ID INT FLOAT BOOL STRING VOID
%type <atom> func_end
%type <atom> SEMICOLON
%type <atom> initializer
%type <atom> factor mul_expression_stat add_expression_stat expression_stat arithmetic_postfix
%type <atom> relational
%type <atom> const

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
    | expression
	| iteration_stat
    | print_func
	| comment_stat
	| RET return_stat
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
	: func_parameter RB func_end 
	{
		if(!strcmp($3.string_val, ";")) {
			table_num--;
			func_flag = 1;
		}
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
	| LCB func_mul_stat RCB
	{ 
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
					int booltype;
					if(!strcmp($4.string_val, "true")) booltype = 1.0;
					else booltype = 0;
    				fprintf(file, ".field public static %s %s = %d\n", $2.string_val, type_descriptor, booltype);
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
					fprintf(file, "    ldc %d\n", booltype);
					fprintf(file, "    istore %d\n", index);
				}
				else if(!strcmp($1.string_val, "string")) {
					char *strconst = strtok($4.string_val, "\"");
					fprintf(file, "    ldc %s\n", strconst);
					fprintf(file, "    astore %d\n", index);
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
    			fprintf(file, "    ldc 0\n");
				if(!strcmp($1.string_val, "string")) {
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
					fprintf(file, "    astore %d\n", regnum);
				}
				else {
					// float, int, bool
					fprintf(file, "    fstore %d\n", regnum);
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
		table_num++; 
		create_symbol(); 
		/*
		int index = lookup_func_table($2);
		if(index == 2) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Redeclared function ");
			strcat(sem_error_msg, $2);
		}
		*/
	} func
	{
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
	}
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
		if(strcmp(call_func_parameter_type, "")) {
			strcat(call_func_parameter_type, ", ");
			strcat(call_func_parameter_type, $3.type);
		}
		else {
			strcpy(call_func_parameter_type, $3.type);
		}
	}
	| const
	{
		if(strcmp(call_func_parameter_type, "")) {
			strcat(call_func_parameter_type, ", ");
			strcat(call_func_parameter_type, $1.type);
		}
		else {
			strcpy(call_func_parameter_type, $1.type);
		}
	}
;

const
	: S_CONST
	{
		strcpy($$.type, "string");
	}
	| expression_stat
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
		if(strcmp(lookup_attribute($1.string_val), call_func_parameter_type)) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		char* paratype;
		changeto_java_type(paratype);
		char* returntype = lookup_type($1.string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "    invokestatic compiler_hw3/%s(%s)%s\n", $1.string_val, paratype, returntype);
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
		fprintf(file, "    fadd\n");
		$$.f_val = -1.0;
	}
	| add_expression_stat SUB mul_expression_stat
	{
		fprintf(file, "    fsub\n");
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
		fprintf(file, "    fmul\n");
		$$.f_val = -1.0;
	}
	| mul_expression_stat DIV factor
	{
		fprintf(file, "    fdiv\n");
		$$.f_val = -1.0;
	}
	| mul_expression_stat MOD factor
	{
		char type1[30], type2[30];
		strcpy(type1, $1.type);
		strcpy(type2, $3.type);
		if(!strcmp(type1, "int") && !strcmp(type2, "int")) {
			fprintf(file, "    frem\n");
		}
		else {
			// semantic error
			// Modulo operator (%) with floating point operands
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
			fprintf(file, "    ldc %f\n", (float)$1.i_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = (float)$1.i_val;
		strcpy($$.type, "int");
	}
	| F_CONST
	{
		// local declaration
		if(table_num != 0) {
			fprintf(file, "    ldc %f\n", $1.f_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = $1.f_val;
		strcpy($$.type, "float");
	}
	| SUB I_CONST
	{
		// local declaration
		if(table_num != 0) {
			fprintf(file, "    ldc -%f\n", (float)$2.i_val);
		}
		// assign to factor for checking global declaration
		$$.f_val = -(float)$2.i_val;
		strcpy($$.type, "int");
	}
	| SUB F_CONST
	{
		// local declaration
		if(table_num != 0) {
			fprintf(file, "    ldc -%f\n", $2.f_val);
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
		}
		// assign to factor
		$$.f_val = -1.0;
		strcpy($$.type, lookup_type($1.string_val));
	}
	| LB expression_stat RB
	{
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
				fprintf(file, "    getstatic compiler_hw3/%s\n", $1.string_val);	
			}
			// local variable
			else {
				// only int has ++ and --
				if(!strcmp($2.string_val, "++")) {
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
				fprintf(file, "    getstatic compiler_hw3/%s\n", $2.string_val);
			}
			// local variable
			else {
				// only int has ++ and --
				if(!strcmp($1.string_val, "++")) {
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
		if(strcmp(lookup_attribute($1.string_val), call_func_parameter_type)) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "function formal parameter is not the same");
		}
		char paratype[100];
		strcpy(paratype, changeto_java_type());
		char* returntype = lookup_type($1.string_val);
		if(!strcmp(returntype, "void")) returntype = "V";
		else returntype = "F";
		fprintf(file, "    invokestatic compiler_hw3/%s(%s)%s\n", $1.string_val, paratype, returntype);
		memset(call_func_parameter_type, '\0', sizeof(call_func_parameter_type));
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
		fprintf(file, "    invokestatic compiler_hw3/%s()%s\n", $1.string_val, returntype);
		// assign function return to factor
		$$.f_val = -1.0;
	}
;

iteration_stat
	: WHILE LB expression_stat RB LCB { table_num++; create_symbol(); } func_mul_stat RCB
	{
		dump_flag = 1; 
		clear_temp_table();
		fill_temp_table();
		table_num--;
	}
	| IF LB expression_stat RB LCB { table_num++; create_symbol(); }  func_mul_stat RCB
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
	: IF LB expression_stat RB LCB { table_num++; create_symbol(); } func_mul_stat RCB
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
;

print_type
	: S_CONST RB SEMICOLON
	| I_CONST RB SEMICOLON
	| F_CONST RB SEMICOLON
	| SUB I_CONST RB SEMICOLON
	| SUB F_CONST RB SEMICOLON
	| ID RB SEMICOLON
	{
		if(lookup_symbol($1.string_val, "semantic") == -1) {
			error_flag = 1;
			bzero(sem_error_msg, 100);
			strcat(sem_error_msg, "Undeclared variable ");
			strcat(sem_error_msg, $1.string_val);
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
	
	fprintf(file, ".method public static main([Ljava/lang/String;)V\n");
 
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
	strcpy(temp_attr, call_func_parameter_type);
	char* delim = ", ";
  	char* type;
	type = strtok(temp_attr, delim);
 	while (type != NULL)
  	{
		if(!strcmp(type, "string")) strcat(new_type, "Ljava/lang/String;");
		else strcat(new_type, "F");
    	type = strtok(NULL, delim);
  	}   
	char* javatype = new_type;
	return javatype;
}

/* code generation functions */
void gencode_function() {

}
