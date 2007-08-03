#include "dstack.h"

int dstack_push(struct dstack *st, void *dat)
{
  return array_cat(&st->x, dat);
}
