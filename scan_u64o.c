#include "scan.h"
#include "uint64.h"

unsigned int scan_u64o(const char *s, uint64 *ul)
{
  const char *t;
  uint64 n;
  char c;

  t = s;
  n = 0;
  for (;;) {
    c = *t;
    if (!c) break;
    if (c >= '0' && c < '8') {
      c -= '0';
      n = (n * 8) + c; ++t;
    } else break;
  }
  *ul = n;
  return t - s;
}

