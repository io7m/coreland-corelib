#include <float.h>
#include <math.h>
#include "fmt.h"
#include "sd_math.h"
#include "sd_inline.h"

#if !defined(HAVE_MATH_FABSF)
static inline float fabsf(float x) { return (float) fabs(x); }
#endif
#if !defined(HAVE_MATH_FLOORF)
static inline float floorf(float x) { return (float) floor(x); }
#endif
#if !defined(HAVE_MATH_CEILF)
static inline float ceilf(float x) { return (float) ceil(x); }
#endif
#if !defined(HAVE_MATH_FMODF)
static inline float fmodf(float x, float y) { return (float) fmod(x, y); }
#endif
#if !defined(HAVE_MATH_POWF)
static inline float powf(float x, float y) { return (float) pow(x, y); }
#endif
#if !defined(HAVE_MATH_ROUNDF)
  #if defined(HAVE_MATH_ROUND)
  static inline float roundf(float x) { return (float) round(x); }
  #else
  static inline float roundf(float x)
  {
    return (float) floor(x + 0.5);
  }
  #endif
#endif

#if defined(HAVE_MATH_LRINTF)
  #define FLOAT_CAST(n) lrintf((n))
#else
  #define FLOAT_CAST(n) (long)(n)
#endif

#if defined(HAVE_MATH_ISINF)
  #define IS_INFINITE(n) isinf((n))
#else
  #if defined(HAVE_MATH_ISFINITE)
    #define IS_INFINITE(n) !isfinite((n))
  #endif
#endif

#define IS_NAN(n)       isnan((n))
#define IS_NEGATIVE(n)  (((n) >> 31) & 0x00000001)

/* IEEE 754 single precision only */

unsigned int fmt_float(char *str, float flo, unsigned int rnd)
{
  unsigned int len = 0;
  unsigned int pos = 0;
  unsigned int sci = 0;
  unsigned long num;
  union real {
    unsigned long n;
    float f; 
  } real;
  float ftmp;
  long exp;

  if (rnd > FLT_DIG) rnd = FLT_DIG;
  if (!rnd) return 0;

  real.f = flo;

  /* check infinity */
  if (IS_INFINITE(real.f)) {
    if (str) {
      str[0] = 'i';
      str[1] = 'n';
      str[2] = 'f';
    }
    return 3;
  }

  /* check nan */
  if (IS_NAN(real.f)) {
    if (str) {
      str[0] = 'n';
      str[1] = 'a';
      str[2] = 'n';
    }
    return 3;
  }

  /* if number is negative, convert to positive */
  if (IS_NEGATIVE(real.n)) {
    if (str) *str++ = '-';
    ++len;
    real.f = fabsf(real.f);
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
  num = FLOAT_CAST(floorf(real.f));
  pos = fmt_ulong(str, num);
  len += pos;
  if (str) str += pos;

  /* radix point */
  len += 1;
  if (str) *str++ = '.';

  /* format fractional */
  while (rnd--) {
    real.f = fmodf(real.f, 1);
    real.f = real.f * 10;
    if (!rnd) real.f = roundf(real.f);
    num = FLOAT_CAST(floorf(real.f));
    pos = fmt_ulong(str, num);
    len += pos;
    if (str) str += pos;
  }

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
