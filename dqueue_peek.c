#include "dqueue.h"

int dqueue_peek(struct dqueue *dq, void **p)
{
  if (!dq->u) return 0;
  *p = ((char *) dq->x) + (dq->hpos * dq->es);
  return 1;
}
