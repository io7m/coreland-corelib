#include "scan_spec.h"
#include "uint32.h"
#include "uint64.h"

unsigned int scan_u32x(const char *s, uint32 *ul)
{
  return scan_u64x(s, (uint64 *) ul);
}

