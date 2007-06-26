#include "alloc.h"
#include "dqueue.h"

int dqueue_init(struct dqueue *dq, unsigned long sz, unsigned int es)
{
  char *x;
  if (!sz) return 0;

  x = alloc(sz * es);
  if (!x) return 0;

  dq->a = sz;
  dq->u = 0;
  dq->es = es;
  dq->x = x;
  dq->hpos = 0;
  dq->tpos = sz - 1;
  return 1;
}
