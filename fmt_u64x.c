#include "fmt_spec.h"
#include "uint64.h"

unsigned int fmt_u64x(char *s, uint64 ul)
{
  uint64 len; 
  uint64 q;
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

