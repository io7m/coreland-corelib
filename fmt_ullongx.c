#include "fmt.h"

unsigned int fmt_ulonglongx(char *str, unsigned long long ul)
{
  unsigned long long quo;
  unsigned int len; 
  unsigned char ch;

  len = 1;
  quo = ul;
  
  /* number of digits */
  while (quo > 15) { ++len; quo /= 16; }
  
  /* digits -> ascii base16 */
  if (str) {
    str += len;
    do { 
      ch = '0' + (ul & 15);
      if (ch > '0' + 9) ch += 'a' - '0' - 10;
      *--str = ch;
      ul /= 16;
    } while (ul);
  }
  return len;
}

