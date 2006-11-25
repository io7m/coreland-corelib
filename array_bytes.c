#include "alloc.h"
#include "array.h"
#include "bin.h"

unsigned long array_bytes(const struct array* a)
{
  return a->u * a->es;
}
