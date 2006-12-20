#include "sstack.h"

int sstack_push(struct sstack *st, void *dat)
{
  register unsigned char *dp;
  register unsigned char *sp;
  unsigned int es;

  if (st->u == st->a) return 0;
  
  es = st->es;
  dp = ((unsigned char *) st->x) + (st->u * es);
  sp = dat;

  for (;;) {
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
  }
  ++st->u;
  return 1;
}
