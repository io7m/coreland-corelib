#include "alloc.h"
#include "array.h"
#include "bin.h"

int array_cat(struct array *a, void *dat)
{
  unsigned long au;
  unsigned long aa;
  unsigned long tmpa;
  unsigned long tmpb1;
  unsigned long tmpb2;
  unsigned int es;

  au = a->u;
  aa = a->a;
  es = a->es;

  if ((au + 1) < au) return 0;

  if ((au + 1) > aa) {
    tmpa = aa + 1 + ARRAY_OVERALLOC;
    if (tmpa < aa) return 0;
    tmpb1 = aa * es;
    if (tmpb1 / aa != es) return 0;
    tmpb2 = tmpa * es;
    if (tmpb2 / tmpa != es) return 0;
    if (!alloc_re((void **) &a->x, tmpb1, tmpb2)) return 0;
    a->a = tmpa;
  }

  tmpb1 = au * es;
  if (au)
    if (tmpb1 / au != es) return 0;

  bin_copy(dat, a->x + tmpb1, es);
  a->u++;
  return 1;
}
