#include "scan.h"
#include "sd_longlong.h"

#if defined(SD_HAVE_LONGLONG)
unsigned int scan_ulonglongo(const char *str, unsigned long long *ull)
{
  register unsigned long long res;
  register unsigned int pos;
  register char ch;

  pos = 0;
  res = 0;

  for (;;) {
    ch = str[pos];
    switch (ch) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
        ch -= '0'; res = (res * 8) + ch; ++pos;
        break;
      default:
        goto END;
    }
  }

  END:
  if (ull) *ull = res;
  return pos;
}

unsigned int scan_longlongo(const char *str, long long *lo)
{
  unsigned long long utmp = 0;
  long long tmp = 0;
  unsigned int len = 0;
  int sign = 0;

  if (*str == '-') { ++str; ++len; sign = 1; }
  len += scan_ulonglongo(str, &utmp);
  tmp = (long long) utmp;
  if (sign) tmp = -tmp;

  *lo = tmp;
  return len;
}
#endif
