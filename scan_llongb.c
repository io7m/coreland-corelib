#include <limits.h>
#include "scan.h"
#include "sd_inline.h"
#include "sd_longlong.h"

#if defined(SD_HAVE_LONGLONG)
static inline unsigned long long power2(unsigned long long p)
{
  register unsigned long long x = 1;
  for (;;) {
    if (!p) return x; x *= 2; --p;
  }
}
unsigned int scan_ulonglongb(const char *str, unsigned long long *ul)
{
  register unsigned long long res;
  register unsigned int pos;
  register unsigned int len;
  register unsigned int end;
  register char ch;

  len = 0;
  pos = 0;
  res = 0;
  
  for (;;) {
    ch = str[pos];
    switch (ch) {
      case '1':
      case '0':
        ++pos;
        break;
      default:
        goto SUM;
    }
  }

  SUM:
  if (!pos) return 0;
  len = pos;
  end = pos - 1;
  pos = 0;

  for (;;) {
    ch = str[end];
    switch (ch) {
      case '0':
      case '1':
        res += (ch - '0') * power2(pos);
        break;
      default:
        goto END;
    }
    if (!end) break;
    ++pos;
    --end;
  }

  END:
  if (ul) *ul = res;
  return len;
}

unsigned int scan_longlongb(const char *str, long long *lo)
{
  unsigned long long utmp = 0;
  long long tmp = 0;
  unsigned int len = 0;
  int sign = 0;

  if (*str == '-') { ++str; ++len; sign = 1; }
  len += scan_ulonglongb(str, &utmp);
  tmp = (long long) utmp;
  if (sign) tmp = -tmp;

  *lo = tmp;
  return len;
}
#endif
