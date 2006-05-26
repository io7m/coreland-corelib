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

unsigned int scan_ulonglongo(const char *s, unsigned long long *ul)
{
  const char *t;
  unsigned long long n;
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
