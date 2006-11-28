#include "array.h"

void *array_index(const struct array *a, unsigned long p)
{
  unsigned int es = a->es;
  unsigned long u = a->u;
  unsigned long ind = p * es;

  if (ind > (es * u)) return 0;
  return a->x + ind;
}
