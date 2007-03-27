#include <float.h>
#include <math.h>
#include "sd_math.h"
#include "fmt.h"

#if !defined(HAVE_MATH_ROUND)
static double round(double x)
{
  return floor(x + 0.5);
}
#endif

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

#define DOUBLE_SIGN_BITS 63

unsigned int fmt_double(char *str, double d, unsigned int rnd)
{
  unsigned int len = 0;
  unsigned int pos = 0;
  unsigned int sci = 0;

  /* try and get the largest available integer type for double */
#if defined(HAVE_LONGLONG)
  #define DL_CAST(n) ((unsigned long long)(n))
  union {
    unsigned long long u;
    double d;
  } real;
  unsigned long long num;
  unsigned long long sign;
  long long exp;
  unsigned int (*fmt_func)(char *, unsigned long long) = fmt_ulonglong;
#else
  #define DL_CAST(n) ((unsigned long)(n))
  union {
    unsigned long u;
    double d;
  } real;
  unsigned long num;
  unsigned long sign;
  long exp;
  unsigned int (*fmt_func)(char *, unsigned long) = fmt_ulong;
#endif
  double dtmp;

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

  /* if number is negative, convert to positive */
  if (sign) {
    if (str) *str++ = '-';
    ++len;
    real.d = fabs(d);
  }

  /* zero is a special case */
  if (real.d == 0.0) goto FORMAT;

  /* work out if scientific notation is required */
  dtmp = real.d;
  exp = 0;
  while (dtmp >= 10.0) { ++exp; dtmp *= 0.1; }
  while (dtmp < 1.0) { --exp; dtmp *= 10.0; }

  if (exp >= DBL_DIG || exp <= -DBL_DIG) {
    real.d = dtmp;
    sci = 1;
  }

  FORMAT:

  /* format integral */
  num = DL_CAST(floor(real.d));
  pos = fmt_func(str, num);
  len += pos;
  if (str) str += pos;

  /* radix point */
  len += 1;
  if (str) *str++ = '.';

  real.d = fmod(real.d, 1);
  real.d = real.d * pow(10, rnd);
  real.d = round(real.d);

  /* format fractional */
  num = DL_CAST(floor(real.d));
  pos = fmt_func(str, num);
  len += pos;
  if (str) str += pos;

  /* sci notation */
  if (sci) {
    if (str) *str++ = 'e';
    ++len;
    if (exp < 0) {
      if (str) *str++ = '-';
      ++len;
      exp = -exp;
    }
    pos = fmt_func(str, exp);
    len += pos;
    if (str) str += pos;
  }

  return len;
}
