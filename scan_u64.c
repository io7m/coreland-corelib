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
