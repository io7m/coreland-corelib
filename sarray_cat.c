#include "sarray.h"

int sarray_cat(struct sarray *sa, void *dat)
{
  register unsigned char *dp;
  register unsigned char *sp;
  unsigned int es;

  if (sa->u == sa->a) return 0;
  
  es = sa->es;
  dp = sa->x + (sa->u * es);
  sp = dat;

  for (;;) {
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
  }

  ++sa->u;
  return 1;
}
