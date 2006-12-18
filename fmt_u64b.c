#include "fmt_spec.h"
#include "uint64.h"

unsigned int fmt_u64b(char *s, uint64 ul)
{
  uint64 len; 
  uint64 q;
  len = 1; q = ul;
  
  /* no. digits */
  while (q > 1) { ++len; q >>= 1; }
  
  /* digit -> ascii (base2) */
  if (s) {
    s += len;
    do { *--s = '0' + (ul & 1); ul >>= 1; } while (ul);
  }
  return len;
}

