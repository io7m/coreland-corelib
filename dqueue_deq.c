#include "dqueue.h"

int dqueue_deq(struct dqueue *dq, void **p)
{
  if (!dq->u) return 0;
  *p = ((char *) dq->x) + (dq->hpos * dq->es);
  dq->hpos = (dq->hpos + 1) % dq->a;
  --dq->u;
  return 1;
}
