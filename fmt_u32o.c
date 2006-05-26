#include "fmt_spec.h"
#include "uint32.h"
#include "uint64.h"

unsigned int fmt_u32o(char *s, uint32 uio)
{
  return fmt_u64o(s, (uint64) uio);
}

