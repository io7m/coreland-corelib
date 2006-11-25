#include "alloc.h"
#include "array.h"
#include "bin.h"

unsigned long array_size(const struct array *a)
{
  return a->u;
}
