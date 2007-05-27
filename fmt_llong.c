#include "sd_longlong.h"
#include "fmt.h"

#if defined(HAVE_LONGLONG)
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
#endif
