#include "squeue.h"

int squeue_deq(struct squeue *sq, void **p)
{
  unsigned int es;

  if (!sq->u) return 0;

  *p = sq->x + ((sq->hpos + 1) % sq->a);
  return 1;
}
