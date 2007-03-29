#include <float.h>
#include <math.h>
#include "sd_math.h"
#include "sd_inline.h"
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

#if !defined(HAVE_MATH_ROUND)
static inline double round(double x)
{
  return floor(x + 0.5);
}
#endif

#if defined(HAVE_MATH_ISINF)
  #define IS_INFINITE(n) isinf((n))
#else
  #if defined(HAVE_MATH_ISFINITE)
    #define IS_INFINITE(n) !isfinite((n))
  #else
    #if defined(HAVE_MATH_FINITE)
      #include <ieeefp.h>
      #define IS_INFINITE(n) !finite((n))
    #endif
  #endif
#endif

#define IS_NAN(n)       isnan((n))
#define IS_NEGATIVE(n)  (((n) >> 63) & 0x00000001)

/* IEEE 754 double precision only */

unsigned int fmt_double(char *str, double dou, unsigned int rnd)
{
  unsigned int len = 0;
  unsigned int pos = 0;
  unsigned int sci = 0;

  /* try and get the largest available integer type for double */
#if defined(HAVE_LONGLONG)
  union {
    double d;
    unsigned long long n;
  } real;
  unsigned long long num;
  long long exp;
  unsigned int (*fmt_func)(char *, unsigned long long) = fmt_ulonglong;
#else
  union {
    double d;
    unsigned long n;
  } real;
  unsigned long num;
  long exp;
  unsigned int (*fmt_func)(char *, unsigned long) = fmt_ulong;
#endif
  double dtmp;

  if (rnd > DBL_DIG) rnd = DBL_DIG;
  if (!rnd) return 0;

  real.d = dou;

  /* check infinity */
  if (IS_INFINITE(real.d)) {
    if (str) {
      str[0] = 'i';
      str[1] = 'n';
      str[2] = 'f';
    }
    return 3;
  }

  /* check nan */
  if (IS_NAN(real.d)) {
    if (str) {
      str[0] = 'n';
      str[1] = 'a';
      str[2] = 'n';
    }
    return 3;
  }

  if (IS_NEGATIVE(real.n)) {
    if (str) *str++ = '-';
    ++len;
    real.d = fabs(real.d);
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
  num = DOUBLE_CAST(floor(real.d));
  pos = fmt_func(str, num);
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
