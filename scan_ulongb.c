#include "scan.h"

unsigned int scan_ulongb(const char *str, unsigned long *ul)
{
  register unsigned long res;
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
      case '0':
      case '1':
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
        res += (ch - '0') * (1 << pos);
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
