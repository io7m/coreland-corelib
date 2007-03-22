#include <float.h>
#include <math.h>
#include "fmt.h"

/* IEEE 754 double precision only */

#if defined(HAVE_LONGLONG)
  #define DOUBLE_EXPONENT_MASK  0x7FF0000000000000ULL
  #define DOUBLE_MANTISSA_MASK  0x000FFFFFFFFFFFFFULL
  #define DOUBLE_INF            0x7FF0000000000000ULL
  #define DOUBLE_NEG_INF        0xFFF0000000000000ULL
#else
  #define DOUBLE_EXPONENT_MASK  0x7FF0000000000000UL
  #define DOUBLE_MANTISSA_MASK  0x000FFFFFFFFFFFFFUL
  #define DOUBLE_INF            0x7FF0000000000000UL
  #define DOUBLE_NEG_INF        0xFFF0000000000000UL
#endif

#define DOUBLE_SIGN_BITS      63

unsigned int fmt_double(char *str, double d, unsigned int rnd)
{
  unsigned int len = 0;
  unsigned int pos;

  /* try and get the largest available integer type for double */
#if defined(HAVE_LONGLONG)
  #define DL_CAST(n) ((unsigned long long)(n))
  union {
    unsigned long long u;
    double d;
  } real;
  unsigned long long num;
  unsigned long long sign;
  unsigned int (*fmt_func)(char *, unsigned long long) = fmt_ulonglong;
#else
  #define DL_CAST(n) ((unsigned long)(n))
  union {
    unsigned long u;
    double d;
  } real;
  unsigned long num;
  unsigned long sign;
  unsigned int (*fmt_func)(char *, unsigned long) = fmt_ulong;
#endif

  if (!rnd) return 0;

  real.d = d;
  sign = real.u >> DOUBLE_SIGN_BITS;

  /* check infinity */
  if ((real.u & DOUBLE_EXPONENT_MASK) == DOUBLE_INF &&
      (real.u & DOUBLE_MANTISSA_MASK) == 0) {
    if (str) {
      str[0] = 'i';
      str[1] = 'n';
      str[2] = 'f';
    }
    return 3;
  }

  /* check negative infinity */
  if ((real.u & DOUBLE_EXPONENT_MASK) == DOUBLE_NEG_INF &&
      (real.u & DOUBLE_MANTISSA_MASK) == 0) {
    if (str) {
      str[0] = '-';
      str[1] = 'i';
      str[2] = 'n';
      str[3] = 'f';
    }
    return 4;
  }

  /* check nan */
  if ((real.u & DOUBLE_EXPONENT_MASK) == DOUBLE_INF &&
      (real.u & DOUBLE_MANTISSA_MASK) != 0) {
    if (str) {
      str[0] = 'n';
      str[1] = 'a';
      str[2] = 'n';
    }
    return 3;
  }

  if (sign) { ++len; if (str) *str++ = '-'; }

  /* treat number as positive */
  real.d = fabs(real.d);

  /* integral */
  num = DL_CAST(floor(real.d));
  pos = fmt_func(str, num);
  len += pos;
  if (str) str += pos;

  /* radix point */
  len += 1;
  if (str) *str++ = '.';

  /* extract fractional */
  real.d = fmod(real.d, 1);
  real.d = real.d * pow(10, rnd);
  real.d = round(real.d);

  num = DL_CAST(floor(real.d));
  pos = fmt_func(str, num);
  len += pos;

  return len;
}
