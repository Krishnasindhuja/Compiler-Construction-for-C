#ifndef TREE_H
#define TREE_H
#include "symtab.h"
#include "types.h"
#include "bucket.h"
#include "message.h"
#include <stdlib.h>

enum MYDECLTAG { MD_ID, MD_PTR, MD_ARRAY, MD_FUNC };
enum MY_EXPR_TAG { INTCONST, DOUBLECONST, VAR, UNOP, BINOP, FCALL };

typedef struct {
  enum MYDECLTAG tag;
  union {
    struct {
      ST_ID id;
    }id_decl;
    struct {
      int dim;
    }arr_decl;
    //add for later projects
    struct {
        PARAM_LIST plist;
    }func_decl;
  }u;
  struct MyDecl *next;
} MyDecl, *MyDeclList;

typedef struct {
  enum MY_EXPR_TAG tag;
  TYPE type;
  BOOLEAN lvalue;
  union {
    long int_const_val;
    double double_const_val;
    ST_ID var_name;
    // struct {
    //   UNOP_TYPE op;
    // } unop;
    // struct {
    //   BINOP_TYPE op;
    //   struct EXPR_NODE *left_arg, *right_arg;
    // } binop;
    // struct {
    //   struct EXPR_NODE *fname;
    //   EXPR_LIST actual_args;
    // }fcall;
  }u;
}EXPR_NODE, *EXPR;

MyDeclList create_id_decl_list(ST_ID id);
MyDeclList create_ptr_decl_list(MyDeclList list);
MyDeclList create_array_decl_list(MyDeclList list, EXPR expr);
MyDeclList create_func_decl_list(MyDeclList list, PARAM_LIST plist);

EXPR create_int_constant(int val);
EXPR create_double_constant(double val);

void install_into_symtab(TYPE type, MyDeclList decl);

#endif
