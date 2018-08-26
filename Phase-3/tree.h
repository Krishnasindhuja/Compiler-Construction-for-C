#ifndef TREE_H
#define TREE_H
#include "symtab.h"
#include "types.h"
#include "bucket.h"
#include BACKEND_HEADER_FILE
#include "message.h"
#include <stdlib.h>

enum MYDECLTAG { MD_ID, MD_PTR, MD_ARRAY, MD_FUNC };
enum MY_EXPR_TAG { INTCONST, DOUBLECONST, STRINGCONST, VAR, UNOP, BINOP, FCALL, CONVERT };
typedef enum { PRE_INC, PRE_DEC, POST_INC, POST_DEC, ADDR_OF, STAR, PLUS, MINUS, NEGATE, NOT, DEREF } UNOP_TYPE;
typedef enum { ADD, SUB, MUL, DIV, MOD, ASSIGN, EQUAL_TO,
                NOT_EQUAL_TO, LTE, GTE, LT, GT, NE, ARR_ACCESS,
                LGCL_AND, LGCL_OR
             } BINOP_TYPE;

typedef enum {INT_VAL, DOUBLE_VAL} EXPR_VAL_TAG;


typedef struct {
    EXPR_VAL_TAG tag;
    union {
        int int_val;
        double double_val;
    };
} EXPR_VALUE;

typedef struct {
  enum MYDECLTAG tag;
  union {
    struct {
      ST_ID id;
    }id_decl;
    struct {
      int dim;
    }arr_decl;
    struct {
        PARAM_LIST plist;
    }func_decl;
  }u;
  struct MyDecl *next;
} MyDecl, *MyDeclList;

struct en;

struct el;
typedef struct el *EXPR_LIST, EXPR_LIST_NODE;

struct en {
  enum MY_EXPR_TAG tag;
  TYPE type;
  BOOLEAN lvalue;
  union {
    long int_const_val;
    double double_const_val;
    char *str_const_val;
    ST_ID var_name;
     struct {
        UNOP_TYPE op;
        struct en *operand;
     } unop;
     struct {
        BINOP_TYPE op;
        struct en *left, *right;
     } binop;
     struct {
        struct en *fname;
        EXPR_LIST actual_args;
     } fcall;
      struct {
         TYPETAG from;
          TYPETAG to;
          struct en *operand;
      }conv;
  }u;
};

struct el {
    struct en *expr;
    struct el *next;

};


typedef struct en EXPR_NODE, *EXPR;

typedef enum  { WHILE_TYPE, FOR_TYPE, SWITCH_TYPE } STMT_TYPE;

typedef struct {
    STMT_TYPE tag;
    int blockNo;
    char *start;
    char *end;
} STMT_REC, *STMT;

struct sr;

typedef struct {
    STMT stmt;
    int count;
    struct sr *next;
}STACK_REC, *STACK;

STACK stmtStack;

int s_count();
STMT s_pop();
STMT s_peek();
void s_push(STMT element);

MyDeclList create_id_decl_list(ST_ID id);
MyDeclList create_ptr_decl_list(MyDeclList list);
MyDeclList create_array_decl_list(MyDeclList list, EXPR expr);
MyDeclList create_func_decl_list(MyDeclList list, PARAM_LIST plist);

EXPR create_int_constant(int val);
EXPR create_double_constant(double val);
EXPR create_string_constant(char *val);

void install_into_symtab(TYPE type, MyDeclList decl);

PARAM_LIST create_param_list(TYPE type, MyDeclList decl, BOOLEAN is_ref);
PARAM_LIST add_to_param_list(PARAM_LIST list, PARAM_LIST node);

EXPR create_var_expr(ST_ID id);

EXPR create_arr_access_expr(EXPR id, EXPR index);
EXPR_LIST create_expr_list(EXPR expr);
EXPR_LIST append_to_expr_list(EXPR_LIST list, EXPR node);

EXPR create_binary_expr(EXPR left, EXPR right, BINOP_TYPE op);
EXPR create_unary_expr(EXPR expr, UNOP_TYPE op);
EXPR create_func_call_expr(EXPR funcName, EXPR_LIST argExprs);
void validate_binary_operands(EXPR left, EXPR right);


// temply here
char *getExprType(int ordinal);
void print_expr(EXPR expr);


char * func_prologue(TYPE type, MyDeclList declList);
void func_epilogue(char *funcName);


#endif
