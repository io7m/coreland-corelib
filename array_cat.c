#include "alloc.h"
#include "array.h"
#include "bin.h"

int array_cat(struct array *a, void *dat)
{
  unsigned long au;
  unsigned long aa;
  unsigned long na;
  unsigned long b1;
  unsigned long b2;
  unsigned int es;

  au = a->u;
  aa = a->a;
  es = a->es;

  if ((au + 1) < au) return 0;

  if ((au + 1) > aa) {
    na = aa + 1 + ARRAY_OVERALLOC;
    if (na < aa) return 0;
    b1 = aa * es;
    if (b1 / aa != es) return 0;
    b2 = na * es;
    if (b2 / na != es) return 0;
    if (!alloc_re((void **) &a->x, b1, b2)) return 0;
    a->a = na;
  }

  b1 = au * es;
  if (au)
    if (b1 / au != es) return 0;

  bin_copy(dat, ((char *) a->x) + b1, es);
  ++a->u;
  return 1;
}
