#include "fmt.h"

unsigned int fmt_ulong(char *str, unsigned long ul)
{
  unsigned long quo;
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

