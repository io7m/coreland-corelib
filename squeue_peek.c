#include "squeue.h"

int squeue_peek(struct squeue *sq, void **p)
{
  if (!sq->u) return 0;
  *p = ((char *) sq->x) + (sq->hpos * sq->es);
  return 1;
}
