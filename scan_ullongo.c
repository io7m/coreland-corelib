#include "scan.h"
#include "sd_longlong.h"

#if defined(HAVE_LONGLONG)
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
        break;
    }
  }

  END:
  if (ull) *ull = res;
  return pos;
}
#endif
