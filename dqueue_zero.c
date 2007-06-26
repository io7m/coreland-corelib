#include "dqueue.h"

void dqueue_zero(struct dqueue *dq)
{
  dq->x = 0;
  dq->u = 0;
  dq->a = 0;
  dq->hpos = 0;
  dq->tpos = 0;
  dq->es = 0;
}
