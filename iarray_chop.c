#include "alloc.h"
#include "iarray.h"

void iarray_chop(struct iarray *ia, unsigned long ind)
{
  struct iarray_node *in;

  if (iarray_nindex(ia, ind, &in)) {
    for (;;) {
      if (in->data) {
        dealloc(in->data);
        in->data = 0;
        in->len = 0;
        --ia->u;
      }
      if (in->next)
        in = in->next;
      else
        break;
    }
  }
}
