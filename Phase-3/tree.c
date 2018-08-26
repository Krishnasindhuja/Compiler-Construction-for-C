#include "tree.h"
#include "encode.h"
#include <string.h>
#include "symtab.h"
#include <stdlib.h>

/* helper methods */
void init_stack() {
    stmtStack = (STMT) malloc(sizeof(STMT_REC));
}

EXPR alloc_expr() {
    EXPR expr = (EXPR) malloc(sizeof(EXPR_NODE));
    if (expr == NULL)
        fatal("No more memory to do dynamic allocation");
    return expr;
}

EXPR_LIST alloc_expr_list() {
    EXPR_LIST list = (EXPR_LIST) malloc(sizeof(EXPR_LIST_NODE));
    if (list == NULL)
        fatal("No more memory to do dynamic allocation");
    return list;
}

char *getExprType(int ordinal) {
    switch (ordinal) {
        case 0:
            return "INTCONST";
        case 1:
            return "DOUBLECONST";
        case 2:
            return "STRINGCONST";
        case 3:
            return "VAR";
        case 4:
            return "UNOP";
        case 5:
            return "BINOP";
        case 6:
	return "FCALL";
        case 7:
            return "CONVERT";

    }
    bug("unknown expr type: %d", ordinal);
}

char *getBinOp(int ordinal) {

    switch (ordinal) {
        case 0:
            return "+";
        case 1:
            return "-";
        case 2:
            return "*";
        case 3:
            return "/";
        case 4:
            return "%";
        case 5:
            return "=";
        case 6:
            return "==";
        case 7:
            return "!=";
        case 8:
            return "<=";
        case 9:
            return ">=";
        case 10:
            return "<";
        case 11:
            return ">";
        case 12:
            return "[]";
        case 13:
            return "&&";
        case 14:
            return "||";

    }
    bug("unkonwn ordinal for binop: %d", ordinal);
}

char *getUnOp(int ordinal) {
    switch (ordinal) {
        case 0:
            return "++p";
        case 1:
            return "--p";
        case 2:
            return "p++";
        case 3:
            return "p--";
        case 4:
            return "&";
        case 5:
            return "*";
        case 6:
            return "unary +";
        case 7:
            return "unary -";
        case 8:
            return "~";
        case 9:
            return "!";
        case 10:
            return "deref";

    }
    bug("unknown unop type: %d", ordinal);
}

EXPR convert_to_expr(EXPR expr, TYPETAG from, TYPETAG to) {
    EXPR res = alloc_expr();
    res->tag = CONVERT;
    res->type = ty_build_basic(to);
    res->lvalue = FALSE;
    res->u.conv.operand = expr;
    res->u.conv.from = from;
    res->u.conv.to = to;
    return res;
}

EXPR unary_convert(EXPR expr) {
    TYPETAG typetag = ty_query(expr->type);

    if (typetag == TYSIGNEDCHAR || typetag == TYSIGNEDSHORTINT || typetag == TYUNSIGNEDCHAR ||
        typetag == TYUNSIGNEDSHORTINT) {
        return convert_to_expr(expr, typetag, TYSIGNEDINT);
    }
    if (typetag == TYFLOAT) {
        return convert_to_expr(expr, typetag, TYDOUBLE);
    } else {
        return expr;
    }
}


void print_expr(EXPR expr) {
    return;
    debug("--------------");
    if (expr == NULL) {
        debug("expr is null");
        debug("---------------");
        return;
    } else
        debug("expr is not null");

    debug(" lvalue: %s", expr->lvalue == FALSE ? "false" : "true");
    if (expr->type == NULL)
        debug("type: null");
    else {
        debug("Expr tag: %s", getExprType(expr->tag));
    }
    if (expr->tag == UNOP) {
        debug("unop type: %s", getUnOp(expr->u.unop.op));
        print_expr(expr->u.unop.operand);
    }
    else if (expr->tag == BINOP) {
        debug("binop type: %s", getBinOp(expr->u.binop.op));
        debug("left");
        print_expr(expr->u.binop.left);
        debug("right");
        print_expr(expr->u.binop.right);
    } else if (expr->tag == INTCONST) {
        debug("Int constant: %d", expr->u.int_const_val);
    } else if (expr->tag == DOUBLECONST) {
        debug("double constant: %f", expr->u.double_const_val);
    } else if (expr->tag == VAR) {
        debug("var expr: %s", st_get_id_str(expr->u.var_name));
    }
    else if (expr->tag == FCALL) {
        debug("func call: %s(", expr->u.fcall.fname);
        debug(");");
    } else if (expr -> tag == CONVERT) {
        debug("convert: %d type to %d", ty_query(expr->type), (ty_query(expr->u.conv.operand->type)));
    }
    else {
        bug("unknown expr type: %d", expr->tag);
    }
    debug("--------------");
}


void print_expr_list(EXPR_LIST list) {
    debug("expr list:");
    if (list == NULL) {
        debug("null expr list");
        return;
    }

    EXPR_LIST t = list;
    while (t->next != NULL) {
        print_expr(t->expr);
        t = t->next;
    }
}

/* end helper methods */

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
        error("illegal array dimension");
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

    while (head->tag != MD_ID) {
        switch (head->tag) {
            case MD_PTR:
                type = ty_build_ptr(type, NO_QUAL);
                break;
            case MD_ARRAY:
                type = ty_build_array(type, DIM_PRESENT, head->u.arr_decl.dim);
                MyDecl *m = head->next;
                if (m != NULL && m->tag == MD_FUNC)
                    error("cannot have function returning array");
                break;
            case MD_FUNC:
                type = ty_build_func(type, PROTOTYPE, head->u.func_decl.plist);
                MyDecl *n = head->next;
                if (n != NULL && n->tag == MD_ARRAY)
                    error("cannot have array of functions ");
                if (n != NULL && n->tag == MD_FUNC)
                    error("cannot have function returning function");
        }
        head = head->next;
        if (head == NULL)
            bug("head should never be null");
    }

    int blockNo = st_get_cur_block();
    ST_ID id = head->u.id_decl.id;
    BOOLEAN exists = FALSE;

    if (blockNo == 0) {
        // install global vars
        ST_DR dataRec = stdr_alloc();
        dataRec->tag = GDECL;
        dataRec->u.decl.type = type;
        dataRec->u.decl.sc = NO_SC;


        exists = st_install(id, dataRec);
        encode_global_decl(type, id);
    } else {
        ST_DR dataRec = stdr_alloc();
        dataRec->tag = LDECL;
        dataRec->u.decl.type = type;
        dataRec->u.decl.sc = NO_SC;
        dataRec->u.decl.binding = encode_local_decl(type, dataRec);

        exists = st_install(id, dataRec);
    }

    if (exists == FALSE) {
        error("duplicate declaration for %s", st_get_id_str(id));
        error("duplicate definition of `%s'", st_get_id_str(id));
    }

}



EXPR create_int_constant(int val) {
    EXPR expr = alloc_expr();
    expr->tag = INTCONST;
    expr->type = ty_build_basic(TYSIGNEDINT);
    expr->u.int_const_val = val;
    expr->lvalue = FALSE;
    return expr;
}

EXPR create_double_constant(double val) {
    EXPR expr = alloc_expr();
    expr->tag = DOUBLECONST;
    expr->type = ty_build_basic(TYDOUBLE);
    expr->u.double_const_val = val;
    expr->lvalue = FALSE;
    return expr;
}

EXPR create_string_constant(char *val) {
    EXPR expr = alloc_expr();
    expr->tag = STRINGCONST;
    expr->type = ty_build_ptr(ty_build_basic(TYSIGNEDCHAR), NO_QUAL);
    expr->u.str_const_val = val;
    expr->lvalue = FALSE;
    return expr;
}

PARAM_LIST create_param_list(TYPE type, MyDeclList decl, BOOLEAN is_ref) {
    MyDeclList head = decl;
    while (head->tag != MD_ID) {
        switch (head->tag) {
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
        if (head == NULL)
            bug("head should never be null");
    }

    PARAM_LIST list = plist_alloc();
    list->id = head->u.id_decl.id;
    list->type = type;
    list->sc = NO_SC;
    list->qu = NO_QUAL;
    list->err = FALSE;
    list->is_ref = is_ref;
    debug("is_ref : %s", is_ref == FALSE ? "false" : "true");

    return list;

}

PARAM_LIST add_to_param_list(PARAM_LIST list, PARAM_LIST node) {
    PARAM_LIST t = list;

    while (t != NULL) {
        if (t->id == node->id)
            error("duplicate parameter declaration for `%s'", st_get_id_str(t->id));
        t = t->next;
    }
    node->next = list;
    list->prev = node;

    return node;
}

EXPR deref_expr(EXPR expr) {
    EXPR d = alloc_expr();
    d->type = expr->type;
    d->lvalue = FALSE;
    d->tag = UNOP;
    d->u.unop.op = DEREF;
    d->u.unop.operand = expr;
    return d;
}

EXPR create_var_expr(ST_ID id) {
    EXPR expr = alloc_expr();
    expr->tag = VAR;
    expr->lvalue = TRUE;
    expr->u.var_name = id;
    int block;
    ST_DR decl = st_lookup(id, &block);
    expr->type = decl->u.typename.type;
    return deref_expr(expr);
}

EXPR create_arr_access_expr(EXPR id, EXPR index) {
    EXPR expr = alloc_expr();
    expr->tag = BINOP;
    expr->lvalue = TRUE;
    //expr->type = ;
    expr->u.binop.left = id;
    expr->u.binop.right = index;
    return expr;
}

EXPR convert_func_to_ptr(EXPR expr) {
    EXPR res = alloc_expr();
    res->tag = UNOP;
    res->lvalue = TRUE;
    res->type = expr->type;
    res->u.unop.op = STAR;
    res->u.unop.operand = expr;
    return res;
}

EXPR convert_array_to_pointer(EXPR expr) {
    EXPR res = alloc_expr();
    res->tag = UNOP;
    res->lvalue = TRUE;
    res->type = ty_build_ptr(expr->type, NO_QUAL);
    res->u.unop.op = STAR;
    res->u.unop.operand = expr;
    return res;
}

EXPR create_unary_expr(EXPR operand, UNOP_TYPE op) {
    debug("Creating unary expr: %s", getUnOp(op));
    EXPR expr = alloc_expr();
    expr->tag = UNOP;
    if (op == STAR)
        expr->lvalue = TRUE;
    expr->type = operand->type;
    expr->u.unop.operand = operand;
    expr->u.unop.op = op;
    debug("before unary convert:");
    print_expr(expr);
    expr = unary_convert(expr);
    debug("after unary convert");
    print_expr(expr);
return expr;
}

EXPR fold_int_constants(int val1, int val2, BINOP_TYPE optype) {
    switch (optype) {
        case ADD:
            return create_int_constant(val1 + val2);
        case SUB:
            return create_int_constant(val1 - val2);
        case MUL:
            return create_int_constant(val1 * val2);
        case DIV:
            return create_int_constant(val1 / val2);
        case MOD:
            return create_int_constant(val1 % val2);
        case EQUAL_TO:
            return create_int_constant(val1 == val2);
        case NOT_EQUAL_TO:
            return create_int_constant(val1 != val2);
        case LTE:
            return create_int_constant(val1 <= val2);
        case GTE:
            return create_int_constant(val1 >= val2);
        case LT:
            return create_int_constant(val1 < val2);
        case GT:
            return create_int_constant(val1 > val2);
        case LGCL_AND:
            return create_int_constant(val1 && val2);
        case LGCL_OR:
            return create_int_constant(val1 || val2);
    }
}

EXPR fold_double_constants(int val1, int val2, BINOP_TYPE optype) {
    switch (optype) {
        case ADD:
            return create_double_constant(val1 + val2);
        case SUB:
            return create_double_constant(val1 - val2);
        case MUL:
            return create_double_constant(val1 * val2);
        case DIV:
            return create_double_constant(val1 / val2);
        case EQUAL_TO:
            return create_int_constant(val1 == val2);
        case NOT_EQUAL_TO:
            return create_int_constant(val1 != val2);
        case LTE:
            return create_int_constant(val1 <= val2);
        case GTE:
            return create_int_constant(val1 >= val2);
        case LT:
            return create_int_constant(val1 < val2);
        case GT:
            return create_int_constant(val1 > val2);
        case LGCL_AND:
            return create_int_constant(val1 && val2);
        case LGCL_OR:
            return create_int_constant(val1 || val2);
    }
}

EXPR fold_int_double_constants(int val1, double val2, BINOP_TYPE optype) {
    switch (optype) {
        case ADD:
            return create_double_constant(val1 + val2);
        case SUB:
            return create_double_constant(val1 - val2);
        case MUL:
            return create_double_constant(val1 * val2);
        case DIV:
            return create_double_constant(val1 / val2);
        case EQUAL_TO:
            return create_int_constant(val1 == val2);
        case NOT_EQUAL_TO:
            return create_int_constant(val1 != val2);
        case LTE:
            return create_int_constant(val1 <= val2);
        case GTE:
            return create_int_constant(val1 >= val2);
        case LT:
            return create_int_constant(val1 < val2);
        case GT:
            return create_int_constant(val1 > val2);
        case LGCL_AND:
            return create_int_constant(val1 && val2);
        case LGCL_OR:
            return create_int_constant(val1 || val2);
    }
}



EXPR fold_if_necessary(EXPR expr) {
    if (expr->tag == BINOP) {
        EXPR left = fold_if_necessary(expr->u.binop.left);
        EXPR right = fold_if_necessary(expr->u.binop.right);
        BINOP_TYPE optype = expr->u.binop.op;

        enum MY_EXPR_TAG leftTag = left->tag;
        enum    MY_EXPR_TAG rightTag = right->tag;
        debug("left tag: %d, right: %d", leftTag, rightTag);
        if (leftTag == INTCONST && rightTag == INTCONST) {
            return fold_int_constants(left->u.int_const_val, right->u.int_const_val, optype);
        } else if(leftTag == DOUBLECONST && rightTag == DOUBLECONST) {
            return fold_double_constants(left->u.double_const_val, right->u.double_const_val, optype);
        } else if(leftTag == INTCONST && rightTag == DOUBLECONST) {
            return fold_int_double_constants(left->u.int_const_val, right->u.double_const_val, optype);
        } else if(leftTag == DOUBLECONST && rightTag == INTCONST) {
            return fold_int_double_constants(right->u.double_const_val, left->u.int_const_val, optype);
        } else
            return expr;
    } else if(expr->tag == UNOP) {
        EXPR operand = fold_if_necessary(expr->u.unop.operand);
        UNOP_TYPE op = expr->u.unop.op;
        if (operand->tag == INTCONST && op == MINUS) {
            return create_int_constant(operand->u.int_const_val * -1);
        } else if(operand->tag == DOUBLECONST && op == MINUS) {
            return create_double_constant(operand->u.double_const_val * -1);
        } else
            return expr;
    }
    return expr;
}

EXPR create_assign_expr(EXPR left, EXPR right) {
    EXPR expr = alloc_expr();
    expr->tag = BINOP;
    expr->lvalue = FALSE;
    expr->type = left->type;
    expr->u.binop.op = ASSIGN;

    TYPETAG leftTag = ty_query(left->type);
    TYPETAG rightTag = ty_query(right->type);

    //Binary Conversions
    if (leftTag == TYSIGNEDINT && rightTag == TYDOUBLE) {
        expr->u.binop.right = convert_to_expr(right, TYDOUBLE, TYSIGNEDINT);
    } else if (leftTag == TYDOUBLE && rightTag == TYSIGNEDINT) {
        expr->u.binop.right = convert_to_expr(right, TYSIGNEDINT, TYDOUBLE);
    } else {
        expr->u.binop.right = right;
    }

    // find a better way
    // since we are always making a var expr child of deref, we should remove that in case of a
    // assignment

    while (left->lvalue != TRUE) {
        if (left->tag != UNOP && left->tag != CONVERT)
            bug("expected UNOP but found: %s", getExprType(left->tag));
        left = left->u.unop.operand;
    }

    expr->u.binop.left = left;

    debug("assign");
    print_expr(left);
    return expr;

}

EXPR create_binary_expr(EXPR left, EXPR right, BINOP_TYPE op) {
    debug("creating binary expr for: %s", getBinOp(op));
    debug("binop left operand: ");
    print_expr(left);
    debug("binop right operand: ");
    print_expr(right);

    if (op == ASSIGN)
        return create_assign_expr(left, right);

    EXPR expr = alloc_expr();
    expr->tag = BINOP;
    expr->lvalue = FALSE;
    expr->type = right->type;
    expr->u.binop.op = op;

    TYPETAG leftTag = ty_query(left->type);
    TYPETAG rightTag = ty_query(right->type);

    if (leftTag == TYDOUBLE && rightTag == TYSIGNEDINT) {
        expr->u.binop.right = convert_to_expr(right, TYSIGNEDINT, TYDOUBLE);
    } else {
        expr->u.binop.right = right;
    }

    if (leftTag == TYSIGNEDINT && rightTag == TYDOUBLE) {
        expr->u.binop.left = convert_to_expr(left, TYSIGNEDINT, TYDOUBLE);
    } else {
        expr->u.binop.left = left;
    }

    return fold_if_necessary(expr);
}

EXPR_LIST create_expr_list(EXPR expr) {
    EXPR_LIST list = alloc_expr_list();
    list->expr = unary_convert(expr);
    list->next = NULL;
}

EXPR_LIST append_to_expr_list(EXPR_LIST list, EXPR expr) {
    debug("appending to expr list ");
    print_expr_list(list);
    debug("node: ");
    print_expr(expr);
    EXPR_LIST t = list;
    while (t->next != NULL)
        t = t->next;

    EXPR_LIST node = alloc_expr_list();
    node->expr = expr;
    t->next = node;

    return list;
}

EXPR create_func_call_expr(EXPR funcName, EXPR_LIST argExprs) {
    EXPR result = alloc_expr();

    PARAM_LIST parameters;
    PARAMSTYLE style;
    result->type = ty_query_func(funcName->type, &style, &parameters);
    debug("func name: ");
    print_expr(funcName);
    print_expr_list(argExprs);
    result->u.fcall.fname = funcName;
    result->u.fcall.actual_args = argExprs;
    result->tag = FCALL;

    return result;
}

void validate_binary_operands(EXPR left, EXPR right) {
    if (left == NULL)
        bug("left of binary operand is null");
    if (right == NULL)
        bug("right of binary operand is null");
}

char * func_prologue(TYPE type, MyDeclList declList) {
    if(declList->tag != MD_FUNC) {
        error("not a func declararion");
    }
    MyDeclList head = declList;
    while (head->tag != MD_ID) {
        switch (head->tag) {
            case MD_ID:
                break;
            case MD_PTR:
                type = ty_build_ptr(type, NO_QUAL);
                break;
            case MD_ARRAY:
                type = ty_build_array(type, DIM_PRESENT, head->u.arr_decl.dim);
                MyDecl *m = head->next;
                if (m != NULL && m->tag == MD_FUNC)
                    error("cannot have function returning array");
                break;
            case MD_FUNC:
                type = ty_build_func(type, PROTOTYPE, head->u.func_decl.plist);
                MyDecl *n = head->next;
                if (n != NULL && n->tag == MD_ARRAY) {
                    error("cannot have array of functions ");
                }
                if (n != NULL && n->tag == MD_FUNC) {
                    error("cannot have function returning function");
                }
        }
        head = head->next;
        if (head == NULL)
            bug("head should never be null");
    }


    ST_DR dataRec = stdr_alloc();
    dataRec->tag = FDECL;
    dataRec->u.decl.type = type;
    dataRec->u.decl.sc = NO_SC;
    ST_ID id = head->u.id_decl.id;
    int block;
    ST_DR existing = st_lookup(id, &block);

    if (existing == NULL) {
        st_install(id, dataRec);
    } else {
        if (existing->tag == FDECL) {
            error("duplicate function definition %s", st_get_id_str(id));

        }
        else if (existing->tag == GDECL) {
//            if (existing->u.decl.type != TYFUNC) {
//                error("error invalid definition");
//            }

            st_replace(id, dataRec);
        }
    }

    st_enter_block();
    b_func_prologue(st_get_id_str(id));
    PARAM_LIST params;
    PARAMSTYLE style;
    TYPE returnType = ty_query_func(type, &style, &params);
//    int offset;
//    while (params != NULL) {
//        ST_DR entry = stdr_alloc();
//        entry->u.decl.type = params->type;
//        entry->u.decl.sc = params->sc;
//        entry->tag = PDECL;
//        entry->u.decl.is_ref = params->is_ref;
//        offset = b_store_formal_param(ty_query(params->type));
//        b_push_loc_addr(offset);
//        st_install(params->id, entry);
//        params = params->next;
//    }

    return st_get_id_str(id);
}

void func_epilogue(char *funcName) {
    b_func_epilogue(funcName);
    st_exit_block();
}

char *new_label() {
    char *label = new_symbol();
    char *copy = malloc(sizeof(char) * strlen(label));
    strcpy(copy,label);
    return copy;
}

STMT start_while(EXPR expr){
    debug("starting while");
	TYPETAG typetag = ty_query(expr->type);
    char *start = new_symbol();
    char *exit = new_symbol();
    b_label(start);
	encode_expr_eval(expr);
	b_cond_jump( typetag, B_ZERO, exit);
    STMT stmt = (STMT) malloc(sizeof(STMT_REC));
    stmt->tag = WHILE_TYPE;
    stmt->start = start;
    stmt->end = exit;
    s_push(stmt);
    debug("started while start: %s end: %s", stmt->start, stmt->end);
    return stmt;
}




int s_count() {
    return stmtStack->count;
}

STMT s_pop() {
    if(stmtStack == NULL)
        return NULL;
    STMT stmt = stmtStack->stmt;
    stmtStack = stmtStack->next;
    return stmt;
}

STMT s_peek() {
    if (stmtStack == NULL)
        return NULL;
    return stmtStack->stmt;
}

void s_push(STMT element) {
    if (stmtStack == NULL) {
        init_stack();
    }
    STACK s = (STACK) malloc(sizeof(STACK_REC));
    s->count = stmtStack->count + 1;
    s->stmt = element;
    s->next = stmtStack;
    stmtStack = s;
}

