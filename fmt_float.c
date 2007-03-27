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
      return (float) (fmodf(x, 1) < 0.5) ? floorf(x) : ceilf(x);
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
  unsigned int pos;

  union {
    unsigned long u;
    float f;
  } real_tmp;
  unsigned long num;
  unsigned long sign;

  if (!rnd) return 0;

  real_tmp.f = f;
  sign = real_tmp.u >> FLOAT_SIGN_BITS;

  /* check infinity */
  if ((real_tmp.u & FLOAT_EXPONENT_MASK) == FLOAT_INF &&
      (real_tmp.u & FLOAT_MANTISSA_MASK) == 0) {
    if (str) {
      str[0] = 'i';
      str[1] = 'n';
      str[2] = 'f';
    }
    return 3;
  }

  /* check negative infinity */
  if ((real_tmp.u & FLOAT_EXPONENT_MASK) == FLOAT_NEG_INF &&
      (real_tmp.u & FLOAT_MANTISSA_MASK) == 0) {
    if (str) {
      str[0] = '-';
      str[1] = 'i';
      str[2] = 'n';
      str[3] = 'f';
    }
    return 4;
  }

  /* check nan */
  if ((real_tmp.u & FLOAT_EXPONENT_MASK) == FLOAT_INF &&
      (real_tmp.u & FLOAT_MANTISSA_MASK) != 0) {
    if (str) {
      str[0] = 'n';
      str[1] = 'a';
      str[2] = 'n';
    }
    return 3;
  }

  if (sign) { ++len; if (str) *str++ = '-'; }

  /* treat number as positive */
  real_tmp.f = fabsf(real_tmp.f);

  /* integral */
  num = (unsigned long) floorf(real_tmp.f);
  pos = fmt_ulong(str, num);
  len += pos;
  if (str) str += pos;

  /* radix point */
  len += 1;
  if (str) *str++ = '.';

  /* extract fractional */
  real_tmp.f = fmodf(real_tmp.f, 1);
  real_tmp.f = real_tmp.f * powf(10, rnd);
  real_tmp.f = roundf(real_tmp.f);

  num = (unsigned long) floorf(real_tmp.f);
  pos = fmt_ulong(str, num);
  len += pos;

  return len;
}
