#include "scan_spec.h"
#include "uint32.h"
#include "uint64.h"

unsigned int scan_u32(const char *s, uint32 *ul)
{
  return scan_u64(s, (uint64 *) ul);
}

