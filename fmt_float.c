#include <float.h>
#include <math.h>
#include "fmt.h"

/* IEEE 754 single precision only */

#define FLOAT_SIGN_BITS     31
#define FLOAT_MANTISSA_BITS 23
#define FLOAT_EXPONENT_MASK 0x0ff00000
#define FLOAT_EXPONENT_BITS 8

unsigned int fmt_float(char *str, float f, unsigned int rnd)
{
  unsigned int len = 0;
  union {
    float f;
    unsigned long u;
  } real;
  signed long expo;
  signed long mant;
  signed long sign;
  unsigned int ind;

  if (!rnd) return 0;

  real.f = f;
  real.f *= powf(10, rnd);

  printf("%f\n", real.f);

  real.f = roundf(real.f);

  printf("%f\n", real.f);

  real.f /= powf(10, rnd);

  sign = real.u >> FLOAT_SIGN_BITS;
  expo = real.u >> FLOAT_MANTISSA_BITS;
  mant = real.u & FLOAT_EXPONENT_MASK;

  /* format string */
  if (sign) {
    ++len;
    if (str) *str++ = '-';
  }

  printf("%f\n", real.f);
  return len;
}

/*
  if (!expo && !mant) {
    if (sign) {
      if (str) *str++ = '-';
      ++len;
    }
    if (rnd > 1) {
      if (str) {
        str[0] = '0';
        str[1] = '.';
        str += 2;
      }
      len += 2;
      rnd -= 1;
      for (ind = 0; ind < rnd; ++ind) {
        if (str) *str++ = '0';
        ++len;
      }
      return len;
    } else {
      if (str) *str = '0';
      return 1;
    }
  }
*/
