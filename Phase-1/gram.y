/*
 *
 * yacc/bison input for simplified C++ parser
 *
 */

%{

#include "defs.h"
#include "types.h"
#include "symtab.h"
#include "bucket.h"
#include "tree.h"
#include "message.h"

    int yylex();
    int yyerror(char *s);

%}

%union {
	int	y_int;
	double	y_double;
	char *	y_string;
  ST_ID y_stid;
  TYPE y_type;
  BUCKET_PTR y_bucket;
  TYPE_SPECIFIER y_tpspec;
  MyDeclList y_mydecl_list;
  EXPR y_expr;
  PARAM_LIST y_plist;
	};

%token <y_string> IDENTIFIER STRING_LITERAL SIZEOF
%token <y_int> INT_CONSTANT
%token <y_double> DOUBLE_CONSTANT
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token BAD

%type <y_stid> identifier
%type <y_bucket> declaration_specifiers
%type <y_tpspec> type_specifier
%type <y_mydecl_list> declarator direct_declarator init_declarator init_declarator_list
%type <y_expr> primary_expr postfix_expr
%type <y_expr> constant_expr conditional_expr logical_or_expr logical_and_expr inclusive_or_expr
%type <y_expr> exclusive_or_expr and_expr equality_expr relational_expr shift_expr additive_expr
%type <y_expr> multiplicative_expr cast_expr unary_expr
%type <y_plist> parameter_declaration parameter_list parameter_type_list

%start translation_unit
%%

 /*******************************
  * Expressions                 *
  *******************************/

primary_expr
	: identifier           {}
	| INT_CONSTANT         { $$ = create_int_constant($1); }
	| DOUBLE_CONSTANT      { $$ = create_double_constant($1); }
	| STRING_LITERAL       {}
	| '(' expr ')'         {}
	;

postfix_expr
	: primary_expr
	| postfix_expr '[' expr ']'
	| postfix_expr '(' argument_expr_list_opt ')'
	| postfix_expr '.' identifier
	| postfix_expr PTR_OP identifier
	| postfix_expr INC_OP
	| postfix_expr DEC_OP
	;

argument_expr_list_opt
	: /* null derive */
	| argument_expr_list
	;

argument_expr_list
	: assignment_expr
	| argument_expr_list ',' assignment_expr
	;

unary_expr
	: postfix_expr
	| INC_OP unary_expr        {}
	| DEC_OP unary_expr        {}
	| unary_operator cast_expr {}
	| SIZEOF unary_expr        {}
	| SIZEOF '(' type_name ')' {}
	;

unary_operator
	: '&' | '*' | '+' | '-' | '~' | '!'
	;

cast_expr
	: unary_expr
	| '(' type_name ')' cast_expr    {}
	;

multiplicative_expr
	: cast_expr
	| multiplicative_expr '*' cast_expr
	| multiplicative_expr '/' cast_expr
	| multiplicative_expr '%' cast_expr
	;

additive_expr
	: multiplicative_expr
	| additive_expr '+' multiplicative_expr
	| additive_expr '-' multiplicative_expr
	;

shift_expr
	: additive_expr
	| shift_expr LEFT_OP additive_expr
	| shift_expr RIGHT_OP additive_expr
	;

relational_expr
	: shift_expr
	| relational_expr '<' shift_expr
	| relational_expr '>' shift_expr
	| relational_expr LE_OP shift_expr
	| relational_expr GE_OP shift_expr
	;

equality_expr
	: relational_expr
	| equality_expr EQ_OP relational_expr
	| equality_expr NE_OP relational_expr
	;

and_expr
	: equality_expr
	| and_expr '&' equality_expr
	;

exclusive_or_expr
	: and_expr
	| exclusive_or_expr '^' and_expr
	;

inclusive_or_expr
	: exclusive_or_expr
	| inclusive_or_expr '|' exclusive_or_expr
	;

logical_and_expr
	: inclusive_or_expr
	| logical_and_expr AND_OP inclusive_or_expr
	;

logical_or_expr
	: logical_and_expr
	| logical_or_expr OR_OP logical_and_expr
	;

conditional_expr
	: logical_or_expr
	| logical_or_expr '?' expr ':' conditional_expr
	;

assignment_expr
	: conditional_expr
	| unary_expr assignment_operator assignment_expr
	;

assignment_operator
	: '=' | MUL_ASSIGN | DIV_ASSIGN | MOD_ASSIGN | ADD_ASSIGN | SUB_ASSIGN
	| LEFT_ASSIGN | RIGHT_ASSIGN | AND_ASSIGN | XOR_ASSIGN | OR_ASSIGN
	;

expr
	: assignment_expr
	| expr ',' assignment_expr
	;

constant_expr
	: conditional_expr
	;

expr_opt
	: /* null derive */
	| expr
	;

 /*******************************
  * Declarations                *
  *******************************/

declaration
	: declaration_specifiers ';'     { error("No declarator in declaration"); }
	| declaration_specifiers init_declarator_list ';'   {}
	;

declaration_specifiers
	: storage_class_specifier                          {}
	| storage_class_specifier declaration_specifiers   {}
	| type_specifier                                   { $$ = update_bucket(NULL, $1, NULL); }
	| type_specifier declaration_specifiers            { $$ = update_bucket($2, $1, NULL); 
														 if($1 == SHORT_SPEC && (($2 == SHORT_SPEC) || ($2 == FLOAT_SPEC) | ($2 == LONG_SPEC) | ($2 == CHAR_SPEC)))
															error("illegal size specifier");
														 if($1 == LONG_SPEC && (($2 == SHORT_SPEC) || ($2 == FLOAT_SPEC) || ($2 == LONG_SPEC) | ($2 == CHAR_SPEC)))
															error("illegal size specifier");
														 if($1 == SIGNED_SPEC && ( ($2 == DOUBLE_SPEC) | ($2 == CHAR_SPEC) ) )
															error("illegal sign specifier");
														}
	| type_qualifier                                   {}
	| type_qualifier declaration_specifiers            {}
	;

init_declarator_list
	: init_declarator                                                          {}
	| init_declarator_list ',' { $<y_bucket>$ = $<y_bucket>0; } init_declarator    {}
	;

init_declarator
	: declarator {
                  install_into_symtab(build_base($<y_bucket>0), $1);
               }
	| declarator '=' initializer {}
	;

storage_class_specifier
	: TYPEDEF | EXTERN | STATIC | AUTO | REGISTER
	;

type_specifier
	: VOID                      { $$ = VOID_SPEC; }
  | CHAR                      { $$ = CHAR_SPEC; }
  | SHORT                     { $$ = SHORT_SPEC; }
  | INT                       { $$ = INT_SPEC; }
  | LONG                      { $$ = LONG_SPEC; }
	| FLOAT                     { $$ = FLOAT_SPEC; }
  | DOUBLE                    { $$ = DOUBLE_SPEC; }
  | SIGNED                    { $$ = SIGNED_SPEC; }
  | UNSIGNED                  { $$ = UNSIGNED_SPEC; }
	| struct_or_union_specifier {}
	| enum_specifier            {}
	| TYPE_NAME                 {}
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union identifier '{' struct_declaration_list '}'
	| struct_or_union identifier
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list_opt
	| type_qualifier specifier_qualifier_list_opt
	;

specifier_qualifier_list_opt
	: /* null derive */
	| specifier_qualifier_list

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expr
	| declarator ':' constant_expr
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM identifier '{' enumerator_list '}'
	| ENUM identifier
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: identifier
	| identifier '=' constant_expr
	;

type_qualifier
	: CONST | VOLATILE
	;

declarator
	: direct_declarator           { $$ = $1; }
	| pointer declarator          { $$ = create_ptr_decl_list($2);   }
	;

direct_declarator
	: identifier                                   { $$ = create_id_decl_list($1); }
	| '(' declarator ')'                           { $$ = $2; }
	| direct_declarator '[' ']'
	| direct_declarator '[' constant_expr ']'      {
                                                    $$ = create_array_decl_list($1, $3);
                                                  }
	| direct_declarator '(' parameter_type_list ')' {
                                                    $$ = create_func_decl_list($1, $3);
                                                  }
	| direct_declarator '(' ')'                     {
                                                    $$ = create_func_decl_list($1, NULL);
                                                  }
	;

pointer
	: '*' specifier_qualifier_list_opt
        | '&'
	;

parameter_type_list
	: parameter_list
	| parameter_list ',' ELIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration        { add_to_param_list($1, $3);}
	;

parameter_declaration
	: declaration_specifiers declarator				   {create_param_list(build_base($1), $2);}
	| declaration_specifiers						   {error(" no id in parameter list");}
	| declaration_specifiers abstract_declarator	   {}
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expr ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expr ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expr
	| '{' initializer_list comma_opt '}'
	;

comma_opt
	: /* Null derive */
	| ','
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

 /*******************************
  * Statements                  *
  *******************************/

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: identifier ':' statement
	| CASE constant_expr ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: expr_opt ';'
	;

selection_statement
	: IF '(' expr ')' statement
	| IF '(' expr ')' statement ELSE statement
	| SWITCH '(' expr ')' statement
	;

iteration_statement
	: WHILE '(' expr ')' statement
	| DO statement WHILE '(' expr ')' ';'
	| FOR '(' expr_opt ';' expr_opt ';' expr_opt ')' statement
	;

jump_statement
	: GOTO identifier ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN expr_opt ';'
	;

 /*******************************
  * Top level                   *
  *******************************/

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declarator compound_statement
	| declaration_specifiers declarator compound_statement
	;

 /*******************************
  * Identifiers                 *
  *******************************/

identifier
	: IDENTIFIER { $$ = st_enter_id($1); }
	;
%%

extern int column;

int yyerror(char *s)
{
	error("%s (column %d)",s,column);
        return 0;  /* never reached */
}
