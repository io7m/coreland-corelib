#include "sstack.h"

int sstack_pop(struct sstack *st, void **p)
{
  if (st->u) {
    sstack_peek(st, p); --st->u; return 1;
  } else
    return 0;
}
