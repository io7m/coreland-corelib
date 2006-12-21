#include <math.h> /* severe problems on PPC if this is not included */
#include "scan_fspec.h"

unsigned int scan_float64(const char *str, float64 *f)
{
  const char *ptr;
  float64 tf;
  float64 df;
  float64 xf; 
  unsigned int pos;
  unsigned int div;
  char ch;

  ptr = str;
  tf = 0;
  df = 0;
  div = 1;
  pos = 0;

  if (str[0] == '-') ++str;

  for (;;) {
    ch = str[pos];
    switch (ch) {
      case 0:
        goto END;
        break;
      case '.':
        goto DECIMAL_POINT;
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        ch -= '0'; tf = (tf * 10) + ch; ++pos;
        break;
      default:
        goto END;
    }
  }

  DECIMAL_POINT:
  ++pos;

  for (;;) {
    ch = str[pos];
    switch (ch) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        ch -= '0'; xf = (float64) ch / pow(10, div); df += xf;
        ++pos;
        ++div;
        break;
      default:
        goto END;
    }
  }

  END:

  tf = df + tf;
  if (ptr[0] == '-') tf = -tf;
  *f = tf;
  return pos;
}
