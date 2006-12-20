#include "squeue.h"

unsigned long squeue_bytes(const struct squeue *sq)
{
  return sq->u * sq->es;
}
