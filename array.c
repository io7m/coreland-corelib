#include "alloc.h"
#include "array.h"
#include "bin.h"
#include "uint32.h"
#include "uint64.h"

/* 0 on failed alloc
   1 on success
   2 on 'already allocated' */

int array_init(array *a, uint64 n, uint32 es)
{
  char *x;
  n += 1 + ARRAY_OVERALLOC;

  x = alloc(n * es);
  if (!x) return 0;
  a->a = n;
  a->u = 0;
  a->es = es;
  a->x = x;
  return 1;
}

void array_free(array *a)
{
  a->es = 0;
  a->a = 0;
  a->u = 0;

  dealloc(a->x);
  a->x = 0;
}
