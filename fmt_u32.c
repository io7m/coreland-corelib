#include "fmt_spec.h"
#include "uint32.h"
#include "uint64.h"

unsigned int fmt_u32(char *s, uint32 ui)
{
  return fmt_u64(s, (uint64) ui);
}

