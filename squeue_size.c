#include "squeue.h"

unsigned long squeue_size(const struct squeue *sq)
{
  return sq->u;
}
