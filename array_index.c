#include "alloc.h"
#include "array.h"
#include "bin.h"
#include "uint32.h"
#include "uint64.h"

char *array_index(array* a, uint64 p)
{
  uint32 es = a->es;
  uint64 u = a->u;
  uint64 ind = p * es;

  if (ind > (es * u)) return 0;
  return a->x + ind;
}
