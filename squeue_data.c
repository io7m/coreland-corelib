#include "squeue.h"

const void *squeue_data(const struct squeue *sq)
{
  return sq->x;
}
