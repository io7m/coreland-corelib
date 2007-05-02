#include "array.h"

unsigned long array_size(const struct array *a)
{
  return a->u;
}

unsigned long array_size_ub(const struct array *a)
{
  return a->a;
}
