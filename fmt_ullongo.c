#include "fmt.h"

unsigned int fmt_ulonglongo(char *str, unsigned long long ul)
{
  unsigned long long quo;
  unsigned int len; 

  len = 1;
  quo = ul;
  
  /* no. digits */
  while (quo > 7) { ++len; quo >>= 3; }
  
  /* digit -> ascii (base10) */
  if (str) {
    str += len;
    do { *--str = '0' + (ul & 7); ul >>= 3; } while (ul);
  }
  return len;
}

