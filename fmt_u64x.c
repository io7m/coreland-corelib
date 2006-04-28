#include "fmt.h"
#include "uint64.h"

unsigned int fmt_u64x(char *s, uint64 ul)
{
  register uint64 l; 
  register uint64 q;
  register unsigned char c;
  l = 1; q = ul;
  
  /* number of digits */
  while (q > 15) { 
    ++l; 
    q /= 16;
  }
  
  /* digits -> ascii base16 */
  if (s) {
    s += l;
    do { 
      c = '0' + (ul & 15);
      if (c > '0' + 9) c += 'a' - '0' - 10;
      *--s = c;
      ul /= 16;
    } while (ul);
  }
  return l;
}
