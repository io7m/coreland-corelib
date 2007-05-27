#include "sd_longlong.h"
#include "fmt.h"

#if defined(HAVE_LONGLONG)
unsigned int fmt_ulonglongb(char *str, unsigned long long ul)
{
  unsigned long long quo;
  unsigned int len;

  len = 1;
  quo = ul;

  /* number of digits */
  while (quo > 1) { ++len; quo >>= 1; }

  /* digits -> ascii base2 */
  if (str) {
    str += len;
    do { *--str = '0' + (ul & 1); ul >>= 1; } while(ul);
  }
  return len;
}

unsigned int fmt_longlongb(char *str, long long lo)
{
  unsigned int len = 0;
  unsigned long long ul;

  if (lo < 0) {
    if (str) *str++ = '-';
    ++len;
    ul = -lo;
  } else
    ul = lo;

  return len + fmt_ulonglongb(str, ul);
}
#endif
