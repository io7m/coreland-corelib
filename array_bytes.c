#include "array.h"

unsigned long array_bytes(const struct array* a)
{
  return a->u * a->es;
}
