#include "alloc.h"
#include "array.h"
#include "bin.h"

int array_cat(array *a, void* i)
{
  unsigned long old_u;
  unsigned long old_a;
  unsigned long new_a;
  unsigned int es;

  old_u = a->u;
  old_a = a->a;
  es = a->es;

  if ((old_u + 1) < old_u) return 0; /* detect int overflow */

  if ((old_u + 1) > old_a) {
    new_a = old_a + 1 + ARRAY_OVERALLOC;
    if (!alloc_re((void **) &a->x, old_a * es, new_a * es)) return 0;
    a->a = new_a;
  }

  bin_copy((char *)i, a->x + (old_u * es), es);
  a->u++;
  return 1;
}
