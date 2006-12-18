#include "fmt.h"

unsigned int fmt_ulongb(char *s, unsigned long ul)
{
  unsigned int len;
  unsigned long q;
  len = 1; q = ul;

  /* number of digits */
  while (q > 1) { ++len; q >>= 1; }

  /* digits -> ascii base2 */
  if (s) {
    s += len;
    do { *--s = '0' + (ul & 1); ul >>= 1; } while(ul);
  }
  return len;
}

