#include "sstack.h"

unsigned long sstack_size(const struct sstack *st)
{
  return st->u;
}
