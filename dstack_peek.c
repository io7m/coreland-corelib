#include "dstack.h"

int dstack_peek(struct dstack *st, void **p)
{
  unsigned long sz = array_SIZE(&st->x);
  void *xp;

  if (sz) {
    xp = array_index(&st->x, sz - 1);
    return !!(*p = xp);
  } else
    return 0;
}
