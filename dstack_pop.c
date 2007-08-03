#include "dstack.h"

int dstack_pop(struct dstack *st, void **p)
{
  unsigned long sz;
  void *xp;

  sz = array_SIZE(&st->x);
  if (sz) {
    xp = array_index(&st->x, sz - 1);
    array_chop(&st->x, sz - 1);
    return !!(*p = xp);
  } else return 0;
}
