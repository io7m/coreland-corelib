#include "array.h"

int array_catn(struct array *a, const void *dat, unsigned long len)
{
  unsigned long clen = len * a->es;

  if (!len) return 0;
  if (clen / len != a->es) return 0;
  return array_catb(a, dat, clen);
}
