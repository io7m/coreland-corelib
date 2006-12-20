#include "squeue.h"

int squeue_deq(struct squeue *sq, void **p)
{
  if (!sq->u) return 0;
  *p = sq->x + (sq->hpos * sq->es);
  sq->hpos = (sq->hpos + 1) % sq->a;
  --sq->u;
  return 1;
}
