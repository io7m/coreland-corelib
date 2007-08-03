#include "dstack.h"

int dstack_init(struct dstack *st, unsigned long sz, unsigned int es)
{
  return array_init(&st->x, sz, es);
}
