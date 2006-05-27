#include "scan.h"
#include "uint64.h"

unsigned int scan_u64(const char *s, uint64 *ul)
{
  uint64 p;
  uint64 r;
  uint64 c;

  p = 0;
  r = 0;
  
  for (;;) {
    c = s[p];
    if (!c) break;
    if ((c < '0') || (c > '9')) break;
    c -= '0';
    r = (r * 10) + c;
    ++p;
  }
  if (ul) *ul = r;
  return p;
}

