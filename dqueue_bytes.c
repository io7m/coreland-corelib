#include "dqueue.h"

unsigned long dqueue_bytes(const struct dqueue *dq)
{
  return dq->u * dq->es;
}
