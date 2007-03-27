#include <float.h>
#include <math.h>
#include "fmt.h"
#include "sd_math.h"

#if !defined(HAVE_MATH_FABSF)
static float fabsf(float x) { return (float) fabs(x); }
#endif
#if !defined(HAVE_MATH_FLOORF)
static float floorf(float x) { return (float) floor(x); }
#endif
#if !defined(HAVE_MATH_CEILF)
static float ceilf(float x) { return (float) ceil(x); }
#endif
#if !defined(HAVE_MATH_FMODF)
static float fmodf(float x, float y) { return (float) fmod(x, y); }
#endif
#if !defined(HAVE_MATH_POWF)
static float powf(float x, float y) { return (float) pow(x, y); }
#endif
#if !defined(HAVE_MATH_ROUNDF)
  #if defined(HAVE_MATH_ROUND)
    static float roundf(float x) { return (float) round(x); }
  #else
    static float roundf(float x)
    {
      return (float) floor(x + 0.5);
    }
  #endif
#endif

/* IEEE 754 single precision only */

#define FLOAT_EXPONENT_MASK  0x7F800000UL
#define FLOAT_MANTISSA_MASK  0x007FFFFFUL
#define FLOAT_INF            0x7F800000UL
#define FLOAT_NEG_INF        0xFFF00000UL
#define FLOAT_SIGN_BITS      31

unsigned int fmt_float(char *str, float f, unsigned int rnd)
{
  unsigned int len = 0;
  unsigned int pos = 0;
  unsigned int sci = 0;

  union {
    unsigned long u;
    float f;
  } real;
  unsigned long num;
  unsigned long sign;
  float ftmp;
  long exp;

  if (!rnd) return 0;

  real.f = f;
  sign = real.u >> FLOAT_SIGN_BITS;

  /* check infinity */
  if ((real.u & FLOAT_EXPONENT_MASK) == FLOAT_INF &&
      (real.u & FLOAT_MANTISSA_MASK) == 0) {
    if (str) {
      str[0] = 'i';
      str[1] = 'n';
      str[2] = 'f';
    }
    return 3;
  }

  /* check negative infinity */
  if ((real.u & FLOAT_EXPONENT_MASK) == FLOAT_NEG_INF &&
      (real.u & FLOAT_MANTISSA_MASK) == 0) {
    if (str) {
      str[0] = '-';
      str[1] = 'i';
      str[2] = 'n';
      str[3] = 'f';
    }
    return 4;
  }

  /* check nan */
  if ((real.u & FLOAT_EXPONENT_MASK) == FLOAT_INF &&
      (real.u & FLOAT_MANTISSA_MASK) != 0) {
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
    real.f = fabsf(f);
  }

  /* zero is a special case */
  if (real.f == 0.0) goto FORMAT;

  /* work out if scientific notation is required */
  ftmp = real.f;
  exp = 0;
  while (ftmp >= 10.0) { ++exp; ftmp *= 0.1; }
  while (ftmp < 1.0) { --exp; ftmp *= 10.0; }

  if (exp >= FLT_DIG || exp <= -FLT_DIG) {
    real.f = ftmp;
    sci = 1;
  }

  FORMAT:

  /* format integral */
  num = (unsigned long) floorf(real.f);
  pos = fmt_ulong(str, num);
  len += pos;
  if (str) str += pos;

  /* radix point */
  len += 1;
  if (str) *str++ = '.';

  real.f = fmodf(real.f, 1);
  real.f = real.f * powf(10, rnd);
  real.f = roundf(real.f);

  /* format fractional */
  num = (unsigned long) floorf(real.f);
  pos = fmt_ulong(str, num);
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
    pos = fmt_ulong(str, exp);
    len += pos;
    if (str) str += pos;
  }

  return len;
}
