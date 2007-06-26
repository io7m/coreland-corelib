#include "alloc.h"
#include "dqueue.h"

void dqueue_free(struct dqueue *dq)
{
  dq->es = 0;
  dq->a = 0;
  dq->u = 0;
  dq->hpos = 0;
  dq->tpos = 0;

  dealloc(dq->x);
  dq->x = 0;
}
