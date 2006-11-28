#include "array.h"

int array_copy(struct array *b, const struct array *a)
{
  register char *dp;
  register char *sp;
  unsigned long nb;
  unsigned long u;
  unsigned int es;

  u = a->u;
  es = a->es;

  if (b->x) array_free(b);
  if (!array_init(b, u, es)) return 0;
  
  dp = b->x;
  sp = a->x;
  nb = u * es;

  for (;;) {
    if (!nb) break; *dp++ = *sp++; --nb;
    if (!nb) break; *dp++ = *sp++; --nb;
    if (!nb) break; *dp++ = *sp++; --nb;
    if (!nb) break; *dp++ = *sp++; --nb;
  }
  
  b->u = u;
  b->es = es;
  return 1;
}
