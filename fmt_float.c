#include <float.h>
#include <math.h>
#include <limits.h>
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

union real {
  unsigned int n;
  float f;
} real;
typedef unsigned int fmt_func(char *, unsigned long);

static inline unsigned int is_infinite(float f)
{
  union real real;
  real.f = f;

#if defined(HAVE_MATH_ISINF)
  return isinf(f);
#else
  #if defined(HAVE_MATH_ISFINITE)
    return !isfinite(f);
  #else
    #if defined(HAVE_MATH_FINITE)
      #include <ieeefp.h>
      return !finite(f);
    #else
      return real.n == 0x7F800000;
    #endif
  #endif
#endif
}

static inline unsigned int is_negative(float f)
{
  union real real;
  real.f = f;

#if defined(HAVE_MATH_SIGNBIT)
  return signbit(real.f);
#endif

  if (sizeof(real.n) == sizeof(float) && sizeof(float) * CHAR_BIT == 32)
    return (real.n >> 31) & 1;    
  else
    return real.f != fabsf(real.f);
}

static inline unsigned int is_nan(float f)
{
  return isnan(f);
}

static inline unsigned int fmt_integral(char *str, float f, fmt_func *fmt)
{
  return fmt(str, FLOAT_CAST(floorf(f)));
}

/* IEEE 754 single precision only */

unsigned int fmt_float(char *str, float flo, unsigned int rnd)
{
  unsigned int len = 0;
  unsigned int pos = 0;
  unsigned int sci = 0;
  unsigned long num;
  union real real;
  fmt_func *fmt_func = fmt_ulong;
  float ftmp;
  long exp;

  if (rnd > FLT_DIG) rnd = FLT_DIG;
  if (!rnd) return 0;

  real.f = flo;

  /* check infinity */
  if (is_infinite(real.f)) {
    if (str) {
      str[0] = 'i';
      str[1] = 'n';
      str[2] = 'f';
    }
    return 3;
  }

  /* check nan */
  if (is_nan(real.f)) {
    if (str) {
      str[0] = 'n';
      str[1] = 'a';
      str[2] = 'n';
    }
    return 3;
  }

  /* if number is negative, convert to positive */
  if (is_negative(real.f)) {
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
  pos = fmt_integral(str, real.f, fmt_func);
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
