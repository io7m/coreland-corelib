#include "alloc.h"
#include "iarray.h"

int iarray_init(struct iarray *ia, unsigned long num)
{
  struct iarray_node *in;
  struct iarray_node *nt;
  unsigned long nx;

  nx = num + IARRAY_OVERALLOC;
  if (!iarray_newnodes(&in, &nt, nx)) return 0;

  ia->a = nx;
  ia->u = 0;
  ia->head = in;
  ia->tail = nt;
  return 1;
}
