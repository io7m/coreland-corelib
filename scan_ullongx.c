#include "scan.h"

unsigned int scan_ulonglongx(const char *s, unsigned long long *ul)
{
  unsigned long long p;
  unsigned long long r;
  char c;

  p = 0;
  r = 0;

  for (;;) {
    c = s[p];
    if (!c) break;
    if (c > 'f') break;
    if (c < '0') break;
    if ((c >= ':') && (c <= '@')) break;
    if ((c >= '[') && (c <= '`')) break;  
   
    if ((c >= '0') && (c <= '9')) c -= '0';
    if ((c >= 'A') && (c <= 'F')) c = c - 'A' + 10;
    if ((c >= 'a') && (c <= 'f')) c = c - 'a' + 10;

    r = (r << 4) + (unsigned char) c;
    ++p;
  }
  if (ul) *ul = (unsigned long long) r;
  return p;
}

