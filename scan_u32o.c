#include "scan_spec.h"
#include "uint32.h"
#include "uint64.h"

unsigned int scan_u32o(const char *s, uint32 *ul)
{
  return scan_u64o(s, (uint64 *) ul);
}

