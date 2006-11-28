#include "alloc.h"
#include "array.h"
#include "bin.h"

int array_cat(struct array *a, void *dat)
{
  unsigned long au;
  unsigned long aa;
  unsigned long na;
  unsigned int es;

  au = a->u;
  aa = a->a;
  es = a->es;

  if ((au + 1) < au) return 0; /* detect int overflow */

  if ((au + 1) > aa) {
    na = aa + 1 + ARRAY_OVERALLOC;
    if (!alloc_re((void **) &a->x, aa * es, na * es)) return 0;
    a->a = na;
  }

  bin_copy(dat, a->x + (au * es), es);
  a->u++;
  return 1;
}
