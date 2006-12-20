#include "squeue.h"

int squeue_enq(struct squeue *sq, void *p)
{
  register unsigned char *dp;
  register unsigned char *sp;
  unsigned int es;

  if (sq->u == sq->a) return 0;

  sq->tpos = (sq->tpos + 1) % sq->a;
  ++sq->u;

  es = sq->es;
  dp = sq->x + (sq->tpos * es);
  sp = p;
 
  for (;;) {
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
  }
  return 1;
}
