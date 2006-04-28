#include "scan.h"
#include "uint32.h"
#include "uint64.h"

unsigned int scan_u32(const char *s, uint32 *ul)
{
  uint64 x;
  unsigned int ret;
  ret = scan_u64(s, &x);
  *ul = (uint32) x;
  return ret;
}
