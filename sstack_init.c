#include "sstack.h"

void sstack_init(struct sstack *st, void *x, unsigned long sz, unsigned int es)
{
  st->x = x;
  st->a = sz;
  st->u = 0;
  st->es = es;
}
