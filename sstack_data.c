#include "sstack.h"

void *sstack_data(const struct sstack *st)
{
  return st->x;
}
