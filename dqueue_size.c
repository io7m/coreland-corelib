#include "dqueue.h"

unsigned long dqueue_size(const struct dqueue *dq)
{
  return dq->u;
}
