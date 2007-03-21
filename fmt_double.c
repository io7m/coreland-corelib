#include <float.h>
#include <math.h>
#include "fmt.h"

/* IEEE 754 double precision only */

#define DOUBLE_SIGN_BITS     63
#define DOUBLE_MANTISSA_BITS 52

#define DOUBLE_EXPONENT_BITS 11
#if defined(HAVE_LONGLONG)
  #define DOUBLE_EXPONENT_MASK 0x7FF0000000000000ULL
#else
  #define DOUBLE_EXPONENT_MASK 0x7FF0000000000000UL
#endif

unsigned int fmt_double(char *str, double d, unsigned int rnd)
{
#if defined(HAVE_LONGLONG)
  union {
    double d;
    unsigned long long u;
  } real;
  unsigned long long mant;
  unsigned long long sign;
  signed long long expo;
#else
  union {
    double d;
    unsigned long u;
  } real;
  unsigned long mant;
  unsigned long sign;
  signed long expo;
#endif
  unsigned int len = 0;
  unsigned int ind;

  if (!rnd) return 0;

  real.d = d;
  real.d *= pow(10, rnd);
  real.d = round(real.d);
  real.d /= pow(10, rnd);

  sign = real.u >> DOUBLE_SIGN_BITS;
  expo = real.u >> DOUBLE_MANTISSA_BITS;
  mant = real.u & DOUBLE_EXPONENT_MASK;

  /* format string */
  if (sign) {
    ++len;
    if (str) *str++ = '-';
  }

  return len;
}
