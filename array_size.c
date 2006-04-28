#include "alloc.h"
#include "array.h"
#include "bin.h"
#include "uint32.h"
#include "uint64.h"

uint64 array_size(array *a)
{
  return a->u;
}
