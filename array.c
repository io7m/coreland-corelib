#include "alloc.h"
#include "array.h"
#include "bin.h"

int array_init(array *a, unsigned long n, unsigned int es)
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
