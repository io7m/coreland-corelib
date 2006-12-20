#include "iarray.h"

void iarray_trunc(struct iarray *ia)
{
  iarray_chop(ia, 0);
}
