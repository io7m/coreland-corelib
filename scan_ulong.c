#include "scan.h"

unsigned int scan_ulong(const char *str, unsigned long *ul)
{
  unsigned int pos;
  unsigned int r;
  unsigned int ch;

  pos = 0;
  r = 0;
  
  for (;;) {
    ch = str[pos];
    if (!ch) break;
    if ((ch < '0') || (ch > '9')) break;
    ch -= '0';
    r = (r * 10) + ch;
    ++pos;
  }
  if (ul) *ul = r;
  return pos;
}
