#include <limits.h>
#include "scan.h"
#include "sd_longlong.h"

#if defined(HAVE_LONGLONG)
unsigned int scan_ulonglongb(const char *str, unsigned long long *ul)
{
  register unsigned long long res;
  register unsigned int pos;
  register unsigned int len;
  register unsigned int end;
  register unsigned int ind;
  register unsigned int mult;
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
        mult = 1;
        for (ind = 0; ind < pos; ++ind) mult <<= 1;
        res += (ch - '0') * mult;
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
#endif
