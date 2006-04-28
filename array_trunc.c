#include "alloc.h"
#include "array.h"
#include "bin.h"
#include "uint32.h"
#include "uint64.h"

void array_trunc(array* a, uint64 sz)
{
  uint32 es;
  uint64 rb;

  if (sz >= a->u) return;
  es = a->es;
  rb = sz * es;

  bin_zero(a->x + rb, (a->a * es) - rb);
  a->u = sz;
}
