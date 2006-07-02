#include "alloc.h"
#include "array.h"
#include "bin.h"
#include "uint32.h"
#include "uint64.h"

int array_cat(array *a, void* i)
{
  uint64 old_u;
  uint64 old_a;
  uint64 new_a;
  uint32 es;

  old_u = a->u;
  old_a = a->a;
  es = a->es;

  if ((old_u + 1) < old_u) return 0; /* detect int overflow */

  if ((old_u + 1) > old_a) {
    new_a = old_a + ARRAY_OVERALLOC;
    if (!alloc_re((void **) &a->x, old_a * es, new_a * es)) return 0;
    a->a = new_a;
  }

  bin_copy((char *)i, a->x + (old_u * es), es);
  a->u++;
  return 1;
}
