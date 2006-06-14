#include "scan_spec.h"
#include "uint64.h"

unsigned int scan_u64x(const char *s, uint64 *ul)
{
  uint64 p;
  uint64 r;
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
  if (ul) *ul = (uint64) r;
  return p;
}

