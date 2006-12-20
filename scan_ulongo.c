#include "scan.h"

unsigned int scan_ulongo(const char *str, unsigned long *ul)
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
        ch -= '0'; res = (res * 8) + ch; ++pos;
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
