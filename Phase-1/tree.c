#include "tree.h"
#include "encode.h"
#include <stdlib.h>

MyDeclList create_id_decl_list(ST_ID id) {
  MyDecl *node = (MyDecl *) malloc(sizeof(MyDecl));
  node->tag = MD_ID;
  node->u.id_decl.id = id;
  return node;
}

MyDeclList create_ptr_decl_list(MyDeclList list) {
  MyDeclList node = (MyDeclList) malloc(sizeof(MyDecl));
  node->tag = MD_PTR;
  node->next = list;
  return node;
}
MyDeclList create_array_decl_list(MyDeclList list, EXPR expr) {

  if (expr->tag != INTCONST) {
    error("illegal size specifier: %d", expr->tag);
  }
  int dim = expr->u.int_const_val;
  if (dim == 0) {
    error ("illegal array dimension");
  }

  MyDeclList node = (MyDeclList) malloc(sizeof(MyDecl));
  node->tag = MD_ARRAY;
  node->u.arr_decl.dim = dim;
  node->next = list;
  return node;
}
MyDeclList create_func_decl_list(MyDeclList list, PARAM_LIST plist) {
  MyDeclList node = (MyDeclList) malloc(sizeof(MyDecl));
  node->tag = MD_FUNC;
  node->u.func_decl.plist = plist;
  node->next = list;
  return node;
}

void install_into_symtab(TYPE type, MyDeclList decl) {
  MyDeclList head = decl;
  
  while(head->tag != MD_ID) {
    switch(head->tag) {
      case MD_PTR:
        type = ty_build_ptr(type, NO_QUAL);
        break;
      case MD_ARRAY:
        type = ty_build_array(type, DIM_PRESENT, head->u.arr_decl.dim);
		MyDecl *m = head->next;
		if(m != NULL && m->tag == MD_FUNC)
			error("cannot have function returning array");
		break;
      case MD_FUNC:
		type = ty_build_func(type, PROTOTYPE, head->u.func_decl.plist);
		MyDecl *n = head->next;
		if(n != NULL && n->tag == MD_ARRAY)
			error("cannot have array of functions ");
		if(n != NULL && n->tag == MD_FUNC)
			error("cannot have function returning function");
    }
    head = head->next;
    if(head == NULL)
      bug("head should never be null");
  }

  ST_DR dataRec = stdr_alloc();
  dataRec->tag = GDECL;
  dataRec->u.decl.type=type;
  dataRec->u.decl.sc = NO_SC;
  
  ST_ID id = head->u.id_decl.id;
  BOOLEAN exists = st_install(id, dataRec);
  if(exists == FALSE){
	  error("duplicate declaration of %s", st_get_id_str(id));
	  error("duplicate definition of `%s'",st_get_id_str(id));
  }
  encode_global_decl(type, id);
}


EXPR create_int_constant(int val) {
  EXPR expr = (EXPR) malloc(sizeof(EXPR_NODE));
  expr->tag = INTCONST;
  expr->type = TYSIGNEDINT;
  expr->u.int_const_val = val;
  expr->lvalue = FALSE;
  return expr;
}

EXPR create_double_constant(double val) {
  EXPR expr = (EXPR) malloc(sizeof(EXPR_NODE));
  expr->tag = DOUBLECONST;
  expr->type = TYDOUBLE;
  expr->u.double_const_val = val;
  expr->lvalue = FALSE;
  return expr;
}

PARAM_LIST create_param_list(TYPE type, MyDeclList decl) {
  MyDeclList head = decl;
  while(head->tag != MD_ID) {
    switch(head->tag) {
      case MD_PTR:
        type = ty_build_ptr(type, NO_QUAL);
        break;
      case MD_ARRAY:
        type = ty_build_array(type, DIM_PRESENT, head->u.arr_decl.dim);
        break;
      case MD_FUNC:
        type = ty_build_func(type, PROTOTYPE, head->u.func_decl.plist);
    }
    head = head->next;
    if(head == NULL)
      bug("head should never be null");
  }

  PARAM_LIST list = plist_alloc();
  list->id = head->u.id_decl.id;
  list->type = type;
  list->sc = NO_SC;
  list->qu = NO_QUAL;
  list->err = FALSE;
  list->is_ref = FALSE;
  
  return list;

}

PARAM_LIST add_to_param_list(PARAM_LIST list, PARAM_LIST node) {
  //PARAM_LIST t = list;
  
  /*while(t != NULL) {
	  if(t->id == node->id)
		  error("duplicate parameter declaration for `%s'",node->id);
	  t = t->next;
  }*/
  node->next = list;
  list->prev = node;
  
  return node;
}

