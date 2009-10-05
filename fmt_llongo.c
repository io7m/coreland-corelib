#include "sd_longlong.h"
#include "fmt.h"

#if defined(SD_HAVE_LONGLONG)
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

unsigned int fmt_longlongo(char *str, long long llo)
{
  unsigned int len = 0;
  unsigned long long ull;

  if (llo < 0) {
    if (str) *str++ = '-';
    ++len;
    ull = -llo;
  } else
    ull = llo;

  return len + fmt_ulonglongo(str, ull);
}
#endif
