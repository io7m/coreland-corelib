#include "scan.h"

unsigned int scan_ulonglong(const char *s, unsigned long long *ul)
{
  unsigned long long p;
  unsigned long long r;
  unsigned long long c;

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

