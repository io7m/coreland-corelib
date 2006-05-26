#include "fmt_spec.h"
#include "uint64.h"

unsigned int fmt_u64(char *s, uint64 ul)
{
  uint64 len; 
  uint64 q;
  len = 1; q = ul;
  
  /* no. digits */
  while (q > 9) { ++len; q /= 10; }
  
  /* digit -> ascii (base10) */
  if (s) {
    s += len;
    do { *--s = '0' + (ul % 10); ul /= 10; } while (ul);
  }
  return len;
}

unsigned int fmt_u64o(char *s, uint64 ul)
{
  uint64 len; 
  uint64 q;
  len = 1; q = ul;
  
  /* no. digits */
  while (q > 7) { ++len; q >>= 3; }
  
  /* digit -> ascii (base10) */
  if (s) {
    s += len;
    do { *--s = '0' + (ul & 7); ul >>= 3; } while (ul);
  }
  return len;
}

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
