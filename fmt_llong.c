#include "sd_longlong.h"
#include "fmt.h"

#if defined(SD_HAVE_LONGLONG)
unsigned int fmt_ulonglong(char *str, unsigned long long ul)
{
  unsigned long long quo;
  unsigned int len;

  len = 1;
  quo = ul;

  /* number of digits */
  while (quo > 9) { ++len; quo /= 10; }

  /* digits -> ascii base16 */
  if (str) {
    str += len;
    do { *--str = '0' + (ul % 10); ul /= 10; } while(ul);
  }
  return len;
}

unsigned int fmt_longlong(char *str, long long llo)
{
  unsigned int len = 0;
  unsigned long long ull;

  if (llo < 0) {
    if (str) *str++ = '-';
    ++len;
    ull = -llo;
  } else
    ull = llo;

  return len + fmt_ulonglong(str, ull);
}
#endif
