#include "scan.h"

unsigned int scan_ulongo(const char *s, unsigned long *ul)
{
  const char *t;
  unsigned long n;
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

