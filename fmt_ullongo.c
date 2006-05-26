#include "fmt.h"

unsigned int fmt_ulonglongo(char *s, unsigned long long ul)
{
  unsigned long long len; 
  unsigned long long q;
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

