#include "sstack.h"

unsigned long sstack_bytes(const struct sstack *st)
{
  return st->u * st->es;
}
