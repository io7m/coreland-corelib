#include "squeue.h"

void *squeue_data(const struct squeue *sq)
{
  return sq->x;
}
