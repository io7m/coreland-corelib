#include "fmt.h"

unsigned int fmt_ulongo(char *str, unsigned long ul)
{
  unsigned long quo;
  unsigned int len; 

  len = 1;
  quo = ul;
  
  /* no. digits */
  while (quo > 7) { ++len; quo >>= 3; }
  
  /* digit -> ascii (base8) */
  if (str) {
    str += len;
    do { *--str = '0' + (ul & 7); ul >>= 3; } while (ul);
  }
  return len;
}

unsigned int fmt_longo(char *str, long lo)
{
  unsigned int len = 0;
  unsigned long ul;

  if (lo < 0) {
    if (str) *str++ = '-';
    ++len;
    ul = -lo;
  } else
    ul = lo;

  return len + fmt_ulongo(str, ul);
}
