#include "alloc.h"
#include "array.h"
#include "bin.h"
#include "uint32.h"
#include "uint64.h"

uint64 array_bytes(array* a)
{
  return a->u * a->es;
}
