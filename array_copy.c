#include "alloc.h"
#include "array.h"
#include "bin.h"
#include "uint32.h"
#include "uint64.h"

int array_copy(array* b, const array* a)
{
  uint64 u;
  uint32 es;

  u = a->u;
  es = a->es;

  if (b->x) array_free(b);
  if (!array_init(b, u, es)) return 0;
  
  bin_copy(a->x, b->x, u * es);
  b->u = u;
  b->es = es;

  return 1;
}
