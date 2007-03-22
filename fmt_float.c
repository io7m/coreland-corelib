#include <float.h>
#include <math.h>
#include "fmt.h"

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
  } real;
  unsigned long num;
  unsigned long sign;

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

  if (sign) { ++len; if (str) *str++ = '-'; }

  /* treat number as positive */
  real.f = fabsf(real.f);

  /* integral */
  num = (unsigned long) floorf(real.f);
  pos = fmt_ulong(str, num);
  len += pos;
  if (str) str += pos;

  /* radix point */
  len += 1;
  if (str) *str++ = '.';

  /* extract fractional */
  real.f = fmodf(real.f, 1);
  real.f = real.f * powf(10, rnd);
  real.f = roundf(real.f);

  num = (unsigned long) floorf(real.f);
  pos = fmt_ulong(str, num);
  len += pos;

  return len;
}
