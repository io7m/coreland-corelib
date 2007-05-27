#include "scan.h"

unsigned int scan_ulong(const char *str, unsigned long *ul)
{
  register unsigned long res;
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
      case '8':
      case '9':
        ch -= '0'; res = (res * 10) + ch; ++pos;
        break;
      default:
        goto END;
        break;
    }
  }

  END:
  if (ul) *ul = res;
  return pos;
}

unsigned int scan_long(const char *str, long *lo)
{
  unsigned long utmp = 0;
  long tmp = 0;
  unsigned int len = 0;
  int sign = 0;

  if (*str == '-') { ++str; ++len; sign = 1; }
  len += scan_ulong(str, &utmp);
  tmp = (long) utmp;
  if (sign) tmp = -tmp;

  *lo = tmp;
  return len;
}
