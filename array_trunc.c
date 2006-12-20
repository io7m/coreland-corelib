#include "array.h"

void array_trunc(struct array *a)
{
  array_chop(a, 0);
}
