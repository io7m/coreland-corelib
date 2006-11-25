#include "alloc.h"
#include "iarray.h"

int iarray_cat(struct iarray *ia, void *dat, unsigned long dlen)
{
  unsigned long nx;
  struct iarray_node *in;
  struct iarray_node *nt;
  struct iarray_node *lu;
 
  if (ia->u + 1 < ia->u) return 0; /* detect overflow */

  nx = 1 + IARRAY_OVERALLOC;
  if (ia->u == ia->a) {
    if (!iarray_newnodes(&in, &nt, nx)) return 0;
    if (!iarray_fillnode(in, dat, dlen)) {
      dealloc(in);
      return 0;
    }
    in->prev = ia->tail;
    ia->tail->next = in;
    ia->tail = nt;
    ia->u += 1;
    ia->a += nx;
    return 1;
  }

  in = ia->tail;
  lu = 0;

  for (;;) {
    if (!in->data)
      lu = in;
    else
      break;
    if (in->prev)
      in = in->prev;
    else
      break;
  }

  ++ia->u;
  if (lu)
    return iarray_fillnode(lu, dat, dlen);
  else
    return iarray_fillnode(ia->tail, dat, dlen);
}
