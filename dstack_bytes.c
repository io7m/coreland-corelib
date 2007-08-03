#include "dstack.h"

unsigned long dstack_bytes(const struct dstack *st)
{
  return array_BYTES(&st->x);
}
