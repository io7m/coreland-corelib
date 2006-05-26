#include "fmt_spec.h"
#include "uint64.h"

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

