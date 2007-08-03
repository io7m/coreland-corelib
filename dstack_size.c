#include "dstack.h"

unsigned long dstack_size(const struct dstack *st)
{
  return array_SIZE(&st->x);
}
