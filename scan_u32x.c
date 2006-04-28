#include "scan.h"
#include "uint32.h"

unsigned int scan_u32x(const char *s, uint32 *ul)
{
  uint64 x;
  unsigned int ret;
  ret = scan_u64x(s, &x);
  *ul = (uint32) x;
  return ret;
}
