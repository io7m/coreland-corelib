#include "fmt_spec.h"
#include "uint32.h"
#include "uint64.h"

unsigned int fmt_u32b(char *s, uint32 uib)
{
  return fmt_u64b(s, (uint64) uib);
}

