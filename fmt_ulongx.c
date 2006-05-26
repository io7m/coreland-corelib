#include "fmt.h"

unsigned int fmt_ulongx(char *s, unsigned long ul)
{
  unsigned long len; 
  unsigned long q;
  unsigned char c;
  len = 1; q = ul;
  
  /* number of digits */
  while (q > 15) { ++len; q /= 16; }
  
  /* digits -> ascii base16 */
  if (s) {
    s += len;
    do { 
      c = '0' + (ul & 15);
      if (c > '0' + 9) c += 'a' - '0' - 10;
      *--s = c;
      ul /= 16;
    } while (ul);
  }
  return len;
}

