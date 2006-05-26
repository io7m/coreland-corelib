#include "fmt_spec.h"
#include "uint32.h"
#include "uint64.h"

unsigned int fmt_u32x(char *s, uint32 uix)
{
  return fmt_u64x(s, (uint64) uix);
}

