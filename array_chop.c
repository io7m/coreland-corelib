#include "alloc.h"
#include "array.h"
#include "bin.h"

void array_chop(struct array *a, unsigned long sz)
{
  if (sz <= a->u) a->u = sz;
}
