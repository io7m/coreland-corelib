#include "dstack.h"

void dstack_free(struct dstack *st)
{
  array_free(&st->x);
}
