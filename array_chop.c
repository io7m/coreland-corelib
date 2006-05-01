#include "alloc.h"
#include "array.h"
#include "bin.h"
#include "uint32.h"
#include "uint64.h"

void array_chop(array* a, uint64 sz)
{
  if (sz <= a->u) a->u = sz;
}
