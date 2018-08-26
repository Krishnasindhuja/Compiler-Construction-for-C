#ifndef ENCODE_H
#define ENCODE_H
#include "types.h"
#include "symtab.h"
#include "tree.h"
#include BACKEND_HEADER_FILE

void encode_global_decl(TYPE type, ST_ID id);
int encode_local_decl(TYPE type, ST_ID id);
void encode_expr_eval(EXPR expr);
#endif
