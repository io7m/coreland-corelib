#include "array.h"

void *array_index(const struct array *a, unsigned long p)
{
  unsigned int es = a->es;
  unsigned long u = a->u;
  unsigned long ind = p * es;

  if (ind > (es * u)) return 0;
  return ((char *) a->x) + ind;
}

void *array_index_ub(const struct array *a, unsigned long p)
{
  unsigned int es = a->es;
  unsigned long al = a->a;
  unsigned long ind = p * es;

  if (ind > (es * al)) return 0;
  return ((char *) a->x) + ind;
}
