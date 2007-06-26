#include "dqueue.h"

const void *dqueue_data(const struct dqueue *dq)
{
  return dq->x;
}
