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
    BOOLEAN found_ref_param = FALSE;

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
    BINOP_TYPE y_binoptr;
    UNOP_TYPE  y_unoptr;
    EXPR_LIST y_expr_list;
    STMT y_stmt;
	
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
%type <y_expr> primary_expr postfix_expr expr expr_opt
%type <y_expr> constant_expr conditional_expr logical_or_expr logical_and_expr inclusive_or_expr
%type <y_expr> exclusive_or_expr and_expr equality_expr relational_expr shift_expr additive_expr
%type <y_expr> multiplicative_expr cast_expr unary_expr assignment_expr
%type <y_plist> parameter_declaration parameter_list parameter_type_list 

%type <y_binoptr> assignment_operator
%type <y_unoptr> unary_operator

%type <y_expr_list> argument_expr_list_opt argument_expr_list

%type <y_string> if_action

%start translation_unit
%%

 /*******************************
  * Expressions                 *
  *******************************/

primary_expr
	: identifier           { debug("creating var expr for: %s", st_get_id_str($1)); $$ = create_var_expr($1);  debug("created var expr for: %s", st_get_id_str($1));  }
	| INT_CONSTANT         { $$ = create_int_constant($1);    }
	| DOUBLE_CONSTANT      { $$ = create_double_constant($1); }
	| STRING_LITERAL       { $$ = create_string_constant($1);   }
	| '(' expr ')'         {  $$ = $2;  }
	;

postfix_expr
	: primary_expr
	| postfix_expr '[' expr ']'                     { $$ = create_arr_access_expr($1, $3); }
	| postfix_expr '(' argument_expr_list_opt ')'   { debug("Creating func call"); $$ = create_func_call_expr($1, $3);  }
	| postfix_expr '.' identifier                   {}
	| postfix_expr PTR_OP identifier                {}
	| postfix_expr INC_OP                           { $$ = create_unary_expr($1, POST_INC);  }
	| postfix_expr DEC_OP                           { $$ = create_unary_expr($1, POST_DEC);  }
	;

argument_expr_list_opt
	: /* null derive */         { $$ = NULL; }
	| argument_expr_list
	;

argument_expr_list
	: assignment_expr                           { debug("creating expr list"); $$ = create_expr_list($1); }
	| argument_expr_list ',' assignment_expr    { debug("appending to expr list"); $$ = append_to_expr_list($1, $3); }
	;

unary_expr
	: postfix_expr
	| INC_OP unary_expr        {    $$ = create_unary_expr($2, PRE_INC);   }
	| DEC_OP unary_expr        {    $$ = create_unary_expr($2, PRE_DEC); }
	| unary_operator cast_expr {    $$ = create_unary_expr($2, $1);  }
	| SIZEOF unary_expr        {}
	| SIZEOF '(' type_name ')' {}
	;

unary_operator
	: '&'       {   $$ = ADDR_OF; }
	| '*'       {   $$ = STAR; }
	| '+'       {   $$ = PLUS; }
	| '-'       {   $$ = MINUS; }
	| '~'       {   $$ = NEGATE; }
	| '!'       {   $$ = NOT; }
	;

cast_expr
	: unary_expr
	| '(' type_name ')' cast_expr    {}
	;

multiplicative_expr
	: cast_expr
	| multiplicative_expr '*' cast_expr         { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, MUL);   }
	| multiplicative_expr '/' cast_expr         { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, DIV);   }
	| multiplicative_expr '%' cast_expr         { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, MOD);   }
	;

additive_expr
	: multiplicative_expr
	| additive_expr '+' multiplicative_expr     {
	                                                validate_binary_operands($1, $3);
	                                                $$ = create_binary_expr($1, $3, ADD);
	                                            }
	| additive_expr '-' multiplicative_expr     {  validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, SUB);   }
	;

shift_expr
	: additive_expr
	| shift_expr LEFT_OP additive_expr
	| shift_expr RIGHT_OP additive_expr
	;

relational_expr
	: shift_expr
	| relational_expr '<' shift_expr        { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, LT);   }
	| relational_expr '>' shift_expr        { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, GT);   }
	| relational_expr LE_OP shift_expr      { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, LTE);   }
	| relational_expr GE_OP shift_expr      { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, GTE);   }
	;

equality_expr
	: relational_expr
	| equality_expr EQ_OP relational_expr   { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, EQUAL_TO);   }
	| equality_expr NE_OP relational_expr   { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, NOT_EQUAL_TO); }
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
	| logical_and_expr AND_OP inclusive_or_expr     { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, LGCL_AND);   }
	;

logical_or_expr
	: logical_and_expr
	| logical_or_expr OR_OP logical_and_expr        { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, LGCL_OR);   }
	;

conditional_expr
	: logical_or_expr                                {   $$ = $1;   }
	| logical_or_expr '?' expr ':' conditional_expr  {              }
	;

assignment_expr
	: conditional_expr
	| unary_expr assignment_operator assignment_expr    { validate_binary_operands($1, $3); $$ = create_binary_expr($1, $3, $2); }
	;

assignment_operator
	: '='                   { $$ = ASSIGN; }
	| MUL_ASSIGN            {}
	| DIV_ASSIGN            {}
	| MOD_ASSIGN            {}
	| ADD_ASSIGN            {}
	| SUB_ASSIGN            {}
	| LEFT_ASSIGN           {}
	| RIGHT_ASSIGN          {}
	| AND_ASSIGN            {}
	| XOR_ASSIGN            {}
	| OR_ASSIGN             {}
	;

expr
	: assignment_expr
	| expr ',' assignment_expr  { $$ = $3;}
	;

constant_expr
	: conditional_expr
	;

expr_opt
	: /* null derive */     { $$ = NULL; }
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
														 if($1 == SHORT_SPEC &&
														    (($2 == SHORT_SPEC) || ($2 == FLOAT_SPEC) || ($2 == LONG_SPEC)
														    || ($2 == CHAR_SPEC)))
															error("illegal size specifier");
														 if($1 == LONG_SPEC && (($2 == SHORT_SPEC) ||
														    ($2 == FLOAT_SPEC) || ($2 == LONG_SPEC) || ($2 == CHAR_SPEC)))
															error("illegal size specifier");
														 if($1 == SIGNED_SPEC && (($2 == DOUBLE_SPEC) || ($2 == CHAR_SPEC)))
															error("illegal sign specifier");
														}
	| type_qualifier                                   {}
	| type_qualifier declaration_specifiers            {}
	;

init_declarator_list
	: init_declarator                                                          {}
	| init_declarator_list ',' { $<y_bucket>$ = $<y_bucket>0; } init_declarator  {$<y_bucket>3; /*to get rid of warning*/}
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
	| pointer declarator          {
	                                $$ = create_ptr_decl_list($2);
	                                // to make sure that an incorrect non-param decl does not effect the param decls
	                                //found_ref_param = FALSE;
	                              }
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
	| direct_declarator '(' ')'                   {
                                                    $$ = create_func_decl_list($1, NULL);
                                                  }
	;

pointer
	: '*' specifier_qualifier_list_opt
        | '&'                               { found_ref_param = TRUE;}
	;

parameter_type_list
	: parameter_list
	| parameter_list ',' ELIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration        {
	                                                    $$ = add_to_param_list($1, $3);
	                                                    found_ref_param = FALSE;
	                                                  }
	;

parameter_declaration
	: declaration_specifiers declarator				   {
                                                            $$ = create_param_list(build_base($1), $2, found_ref_param);
                                                            found_ref_param = FALSE;
	                                                   }
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
	| { /* p3 */st_enter_block(); } compound_statement { st_exit_block(); /* p3 s_pop(); */}
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
	: '{' '}'                           {}
	| '{' statement_list '}'            {}
	| '{' declaration_list '}'          {}
	| '{' declaration_list {
	                            /* p3 */ //install_local_decls(); and alloc space in current activation_record
	                            //by some offset from frame pointer
	                            //1. for each decl call b_alloc_local_var(8);
	                            //2. install into symtab with that offset
	                            //allocate_local_vars($2);

	                       }
	      statement_list '}'            {}
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
	: expr_opt ';'      { if($1 != NULL) {
	                        //eval expr
	                        encode_expr_eval($1);
	                        if(ty_query($1->type) != TYVOID)
	                            b_pop();
	                      }
	                    }
	;

selection_statement
	: IF '(' expr ')' if_action statement   { b_label($5);  }

																			
| IF '(' expr ')' if_action statement ELSE { debug("in if stmt");
                                              char *end = new_symbol();
                                              b_jump(end);
                                              $<y_string>$ = end;
                                              b_label($5);
                                              debug("laying down label: %s", $5);
                                             }
                                             statement {  debug("after else"); debug("ll:%s", $<y_string>8); b_label($<y_string>8);  }
| SWITCH '(' expr ')' statement				
;

if_action
	: /* empty */ {
	                  debug("if action");
	                  TYPETAG type = ty_query($<y_expr>-1->type);
                      encode_expr_eval($<y_expr>-1);
                      char * label = new_symbol();
                      b_cond_jump(type, B_ZERO, label);
                      $$ = label;
                      debug("if action end");
                  }
	
iteration_statement
	: WHILE '(' expr ')' { $<y_stmt>$ = start_while($3); } statement {
                                        debug("end of while: %s", $<y_stmt>5->start == NULL ? "null": $<y_stmt>5->start);
                                        b_jump($<y_stmt>5->start);
                                        b_label($<y_stmt>5->end);
                                        s_pop();
	                                }
	| DO statement WHILE '(' expr ')' ';'
	| FOR '(' expr_opt ';' expr_opt ';' expr_opt ')'    {
                                                                    if ($3 != NULL) {
                                                                        TYPETAG type = ty_query($3->type);
                                                                        encode_expr_eval($3);
                                                                        if (type != TYVOID)
                                                                            b_pop();
                                                                    }


																	char *start_label = new_symbol();
	                                                                char *exit_label = new_symbol();
																	STMT stmt = (STMT) malloc(sizeof(STMT_REC));
                                                                    stmt->tag = FOR_TYPE;
                                                                    stmt->start = start_label;
                                                                    stmt->end = exit_label;
                                                                    s_push(stmt);
																	b_label(start_label);

																	if($5 != NULL) {
																	    TYPETAG type = ty_query($5->type);
																	    encode_expr_eval($5);
																	    b_cond_jump(type, B_ZERO, exit_label);
																	}
																	$<y_stmt>$ = stmt;
																}
													statement   {
													                if($7 != NULL) {
                                                                        TYPETAG type = ty_query($7->type);
                                                                        encode_expr_eval($7);
                                                                        if (type != TYVOID)
                                                                            b_pop();
                                                                    }
                                                                    b_jump($<y_stmt>9->start);
                                                                    b_label($<y_stmt>9->end);
                                                                    s_pop();
													            }
	;


jump_statement
	: GOTO identifier ';'
	| CONTINUE ';'
	| BREAK ';'					{
                                    STMT stmt = s_pop();
                                    if (stmt == NULL)
                                        error("break not inside switch or loop");
                                    else {
                                        b_jump(stmt->end);
                                        debug("break dest: %s", stmt->end == NULL ? "null" : stmt->end);
                                    }
	                            }
	| RETURN expr_opt ';'		{
	                                if( $2 != NULL){
	                                    encode_expr_eval($2);
										TYPETAG typetag = ty_query($2->type);
										b_convert(typetag, TYSIGNEDINT);
										if(typetag != NULL)
										    b_encode_return(typetag);
									}
									else
										b_encode_return(TYVOID);
								}
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
	: declarator {  $<y_string>$ = func_prologue(ty_build_basic(TYSIGNEDINT), $1); }  compound_statement { func_epilogue($<y_string>2); }
	| declaration_specifiers declarator {  $<y_string>$ = func_prologue(build_base($1), $2); } compound_statement { func_epilogue($<y_string>3); }
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
