#include "fmt_spec.h"
#include "uint32.h"
#include "uint64.h"

unsigned int fmt_u32(char *s, uint32 ui)
{
  return fmt_u64(s, (uint64) ui);
}

unsigned int fmt_u32x(char *s, uint32 uix)
{
  return fmt_u64x(s, (uint64) uix);
}

unsigned int fmt_u32o(char *s, uint32 uio)
{
  return fmt_u64o(s, (uint64) uio);
}
