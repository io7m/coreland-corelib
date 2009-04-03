#include <float.h>
#include <math.h>
#include <limits.h>
#include "sd_math.h"
#include "sd_inline.h"
#include "sd_longlong.h"

#if defined(HAVE_LONGLONG)
  #define CORELIB_USE_LONGLONG
#endif

#include "fmt.h"

#if defined(HAVE_LONGLONG)
  #if defined(HAVE_MATH_LLRINT)
    #define DOUBLE_CAST(n) llrint((n))
  #else
    #define DOUBLE_CAST(n) (long long)(n)
  #endif
#else
  #if defined(HAVE_MATH_LRINT)
    #define DOUBLE_CAST(n) lrint((n))
  #else
    #define DOUBLE_CAST(n) (long)(n)
  #endif
#endif

/* try and get the largest available integer type for double */
#if defined(HAVE_LONGLONG)
union real {
  double d;
  unsigned long long n;
};
typedef unsigned int (fmt_func)(char *, unsigned long long);
#else
union real {
  double d;
  unsigned long n;
};
typedef unsigned int (fmt_func)(char *, unsigned long);
#endif

#if !defined(HAVE_MATH_ROUND)
static inline double round(double x)
{
  return floor(x + 0.5);
}
#endif

/* IEEE 754 double precision only */

static inline unsigned int is_negative(double d)
{
  union real real;
  real.d = d;

#if defined(HAVE_MATH_SIGNBIT)
  return signbit(real.d);
#else
  if (sizeof(real.n) == sizeof(double) && sizeof(double) * CHAR_BIT == 64)
    return (real.n >> 63) & 1;    
  else
    return real.d != fabs(real.d);
#endif
}

static inline unsigned int is_nan(double d)
{
  return isnan(d);
}

#if defined(HAVE_MATH_FINITE)
  #include <ieeefp.h>
#endif

static inline unsigned int is_infinite(double d)
{
  union real real;
  real.d = d;

#if defined(HAVE_MATH_ISINF)
  return isinf(d);
#else
  #if defined(HAVE_MATH_ISFINITE)
    return !isfinite(d);
  #else
    #if defined(HAVE_MATH_FINITE)
      return !finite(d);
    #else
      return real.n == 0x7FF0000000000000;
    #endif
  #endif
#endif
}

static inline unsigned int fmt_integral(char *str, double d, fmt_func *fmt)
{
  return fmt(str, DOUBLE_CAST(floor(d)));
}

unsigned int fmt_double(char *str, double dou, unsigned int rnd)
{
  unsigned int len = 0;
  unsigned int pos = 0;
  unsigned int sci = 0;

#if defined(HAVE_LONGLONG)
  unsigned long long num;
  long long exp = 0;
  fmt_func *fmt_func = fmt_ulonglong;
#else
  unsigned long num;
  long exp = 0;
  fmt_func *fmt_func = fmt_ulong;
#endif
  double dtmp;
  union real real;

  if (rnd > DBL_DIG) rnd = DBL_DIG;
  if (!rnd) return 0;

  real.d = dou;

  /* check infinity */
  if (is_infinite(real.d)) {
    if (str) {
      str[0] = 'i';
      str[1] = 'n';
      str[2] = 'f';
    }
    return 3;
  }

  /* check nan */
  if (is_nan(real.d)) {
    if (str) {
      str[0] = 'n';
      str[1] = 'a';
      str[2] = 'n';
    }
    return 3;
  }

  /* check sign bit */
  if (is_negative(real.d)) {
    if (str) *str++ = '-';
    ++len;
    real.d = fabs(real.d);
  }

  /* check zero */
  if (real.d == 0.0) goto FORMAT;

  /* work out if scientific notation is required */
  dtmp = real.d;
  while (dtmp >= 10.0) { ++exp; dtmp *= 0.1; }
  while (dtmp < 1.0) { --exp; dtmp *= 10.0; }

  if (exp >= DBL_DIG || exp <= -DBL_DIG) {
    real.d = dtmp;
    sci = 1;
  }

  FORMAT:

  /* format integral */
  pos = fmt_integral(str, real.d, fmt_func);
  len += pos;
  if (str) str += pos;

  /* radix point */
  len += 1;
  if (str) *str++ = '.';

  /* format fractional */
  while (rnd--) {
    real.d = fmod(real.d, 1);
    real.d = real.d * 10;
    if (!rnd) real.d = round(real.d);
    num = DOUBLE_CAST(floor(real.d));
    pos = fmt_func(str, num);
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
    pos = fmt_func(str, exp);
    len += pos;
    if (str) str += pos;
  }

  return len;
}
