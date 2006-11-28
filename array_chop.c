#include "array.h"

void array_chop(struct array *a, unsigned long sz)
{
  if (sz <= a->u) a->u = sz;
}
