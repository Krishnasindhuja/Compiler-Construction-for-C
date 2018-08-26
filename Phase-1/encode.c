#include "encode.h"

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
