#include "alloc.h"
#include "iarray.h"

void iarray_remove(struct iarray *ia, unsigned long ind)
{
  struct iarray_node *in;

  if (iarray_nindex(ia, ind, &in)) {
    dealloc(in->data);
    in->data = 0;
    in->len = 0;
    --ia->u;
  }
}
