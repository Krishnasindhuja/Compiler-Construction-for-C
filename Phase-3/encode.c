#include "encode.h"
#include "tree.h"
#include <stdio.h>

void encode_global_decl(TYPE type, ST_ID id) {
  char *name = st_get_id_str(id);
  TYPETAG tag = ty_query(type);

  if (tag == TYFUNC)
    return;

  if(tag == TYARRAY) {
    int size = 1;
    while(tag == TYARRAY) {
      unsigned int dim;
      DIMFLAG dimflag;
      type = ty_query_array(type, &dimflag, &dim);
      tag = ty_query(type);
      size *= dim;
    }

    int alignment = get_size_basic(tag);
    b_global_decl(name, alignment, size * alignment);
    b_skip(size * alignment);
  }else {
    int alignment = get_size_basic(tag);
    int size = alignment;
    b_global_decl(name, alignment, size);
    b_skip(size);
  }
}

int encode_local_decl(TYPE type, ST_ID id) {
  char *name = st_get_id_str(id);
  TYPETAG tag = ty_query(type);

  if (tag == TYFUNC)
    bug("cannot create local functions");

  int size = 1;
  if(tag == TYARRAY) {
    while(tag == TYARRAY) {
      unsigned int dim;
      DIMFLAG dimflag;
      type = ty_query_array(type, &dimflag, &dim);
      tag = ty_query(type);
      size *= dim;
    }
    size *= get_size_basic(tag);

  }else {
    size = get_size_basic(tag);
  }
  return b_alloc_local_vars(size);

}


void encode_incr_decr(EXPR expr, B_INC_DEC_OP op) {
  encode_expr_eval(expr);
  TYPETAG typetag = ty_query(expr->type);
  b_inc_dec(typetag, op, get_size_basic(typetag));
}

void encode_unary_minus(EXPR expr) {
  encode_expr_eval(expr);
  b_negate(ty_query(expr->type));
}

void encode_addr_of(EXPR expr) {
    encode_expr_eval(expr);
}

void encode_negate(EXPR expr) {
  encode_expr_eval(expr);
  b_negate(ty_query(expr->type));
}

void encode_not(EXPR expr) {

}

void encode_deref(EXPR expr) {
  encode_expr_eval(expr);
  b_deref(ty_query(expr->type));
}

void encode_convert(EXPR expr) {
    debug("converting: ");
    print_expr(expr);
    debug("to: %d from: %d", expr->u.conv.to, expr->u.conv.from);
  encode_expr_eval(expr->u.conv.operand);
  b_convert(expr->u.conv.from, expr->u.conv.to);
}


void encode_unary_expr_eval(EXPR expr) {
  EXPR operand = expr->u.unop.operand;
  TYPETAG typetag = ty_query(expr->type);

  switch (expr->u.unop.op) {
    case PRE_INC:
      encode_incr_decr(operand, B_PRE_INC);
          break;
    case PRE_DEC:
      encode_incr_decr(operand, B_PRE_DEC);
          break;
    case POST_INC:
      encode_incr_decr(operand, B_POST_INC);
          break;
    case POST_DEC:
      encode_incr_decr(operand, B_POST_DEC);
          break;
    case ADDR_OF:
      encode_addr_of(operand);
          break;
    case STAR:
      //encode_star(operand);
          break;
    case PLUS:
      break;
    case MINUS:
      encode_unary_minus(operand);
          break;
    case NEGATE:
      encode_negate(operand);
          break;
    case NOT:
      encode_not(operand);
          break;
    case DEREF:
      encode_deref(operand);
          break;
    default:
      bug("unknown unop type", expr->u.unop.op);

  }
}

void encode_binary_expr_eval(EXPR expr) {
  if (expr->u.binop.op == ASSIGN) {
    encode_expr_eval(expr->u.binop.left);
    encode_expr_eval(expr->u.binop.right);
    TYPETAG typetag = ty_query(expr->type);
    b_assign(typetag);
    return;

  }

  encode_expr_eval(expr->u.binop.left);
  encode_expr_eval(expr->u.binop.right);
  TYPETAG typetag = ty_query(expr->type);
  switch (expr->u.binop.op) {
    case ADD:
      b_arith_rel_op(B_ADD, typetag);
      break;
    case SUB:
      b_arith_rel_op(B_SUB, typetag);
      break;
    case MUL:
      b_arith_rel_op(B_MULT, typetag);
      break;
    case DIV:
      b_arith_rel_op(B_DIV, typetag);
      break;
    case MOD:
      b_arith_rel_op(B_MOD, typetag);
      break;
    case EQUAL_TO:
      b_arith_rel_op(B_EQ, typetag);
      break;
    case NOT_EQUAL_TO:
      b_arith_rel_op(B_NE, typetag);
      break;
    case LTE:
      b_arith_rel_op(B_LE, typetag);
      break;
    case GTE:
      b_arith_rel_op(B_GE, typetag);
      break;
    case LT:
      b_arith_rel_op(B_LT, typetag);
      break;
    case GT:
      b_arith_rel_op(B_GT, typetag);
      break;
    case NE:
      b_arith_rel_op(B_NE, typetag);
      break;
    case ARR_ACCESS:
      //TODO
      break;
    case LGCL_AND:
      //TODO
      break;
    case LGCL_OR:
      //TODO
      break;
  }
}

// add code here when we add support for params in funcs
int getArgCount(EXPR_LIST args) {
  int count = 0;
  while (args != NULL) {
    count++;
    args=args->next;
  }
  return count;

}

void encode_func_call_expr_eval(EXPR expr) {
  EXPR_LIST t = expr->u.fcall.actual_args;
  int argCount = getArgCount(t);


  b_alloc_arglist(argCount * 8);


  while (t != NULL) {
    encode_expr_eval(t->expr);
    b_load_arg(ty_query(t->expr->type));
    t = t->next;
  }
  ST_ID fname = expr->u.fcall.fname->u.unop.operand->u.var_name;
  //print_expr(fnameExpr);
  b_funcall_by_name(st_get_id_str(fname), ty_query(expr->type));
}

void encode_var_expr_eval(EXPR expr) {
  //TODO add local var
    int block;
    ST_DR entry = st_lookup(expr->u.var_name, &block);
    if (entry == NULL)
        error("undefined variable: %s", st_get_id_str(expr->u.var_name));
    else {
        if (entry->tag == PDECL)
            b_push_loc_addr(entry->u.decl.binding);
        else
            b_push_ext_addr(st_get_id_str(expr->u.var_name));
    }
}


void encode_expr_eval(EXPR expr) {
  // do a postfix evaluation and push on to the stack
  switch (expr->tag) {
    case UNOP:
      encode_unary_expr_eval(expr);
          break;
    case BINOP:
      encode_binary_expr_eval(expr);
          break;
    case FCALL:
      encode_func_call_expr_eval(expr);
          break;
    case VAR:
      encode_var_expr_eval(expr);
          break;
    case INTCONST:
      b_push_const_int(expr->u.int_const_val);
          break;
    case DOUBLECONST:
      b_push_const_double(expr->u.double_const_val);
          break;
    case STRINGCONST:
      b_push_const_string(expr->u.str_const_val);
          break;
    case CONVERT:
      encode_convert(expr);
          break;
    default:
      bug("unknown expr type: %d", expr->tag);
  }
}

