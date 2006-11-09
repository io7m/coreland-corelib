#include "alloc.h"
#include "array.h"
#include "bin.h"

char *array_index(array* a, unsigned long p)
{
  unsigned int es = a->es;
  unsigned long u = a->u;
  unsigned long ind = p * es;

  if (ind > (es * u)) return 0;
  return a->x + ind;
}
