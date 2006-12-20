#include <math.h> /* severe problems on PPC if this is not included */
#include "scan.h"

unsigned int scan_double(const char *str, double *d)
{
  const char *ptr;
  double td;
  double dd;
  double xd; 
  unsigned int pos;
  unsigned int div;
  char ch;

  ptr = str;
  td = 0;
  dd = 0;
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
        ch -= '0'; td = (td * 10) + ch; ++pos;
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
        ch -= '0'; xd = (double) ch / pow(10, div); dd += xd;
        ++pos;
        ++div;
        break;
      default:
        goto END;
    }
  }

  END:

  td = dd + td;
  if (ptr[0] == '-') td = -td;
  *d = td;
  return pos;
}
