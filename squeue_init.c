#include "squeue.h"

void squeue_init(struct squeue *sq, void *x, unsigned long sz, unsigned int es)
{
  sq->x = x;
  sq->a = sz;
  sq->u = 0;
  sq->es = es;
  sq->hpos = 0;
  sq->tpos = sz - 1;
}
