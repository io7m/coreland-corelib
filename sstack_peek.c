#include "sstack.h"

int sstack_peek(struct sstack *st, void **p)
{
  if (st->u) {
    return !!(*p = ((char *) st->x) + ((st->u - 1) * st->es));
  } else
    return 0;
}
