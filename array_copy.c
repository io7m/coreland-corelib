#include "alloc.h"
#include "array.h"
#include "bin.h"

int array_copy(struct array *b, const struct array *a)
{
  unsigned long u;
  unsigned int es;

  u = a->u;
  es = a->es;

  if (b->x) array_free(b);
  if (!array_init(b, u, es)) return 0;
  
  bin_copy(a->x, b->x, u * es);
  b->u = u;
  b->es = es;

  return 1;
}
