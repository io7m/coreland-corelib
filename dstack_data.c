#include "dstack.h"

const void *dstack_data(const struct dstack *st)
{
  return array_DATA(&st->x);
}
