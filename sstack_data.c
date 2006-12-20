#include "sstack.h"

const void *sstack_data(const struct sstack *st)
{
  return st->x;
}
