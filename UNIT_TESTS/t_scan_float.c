#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "../scan.h"

struct ssfloat_str {
  unsigned int sz;
  const char *str;
  float ff;
  double fd;
};

#define FLOAT 1
#define DOUBLE 2

static struct ssfloat_str ssfloats[] = {
  { FLOAT,  "-32.123",    -32.123,        0.0 },
  { DOUBLE, "-12304.100",     0.0, -12304.100 },
  { FLOAT,  "340282346638528859811704183484516925440.000000", FLT_MAX, 0.0},
  { DOUBLE, "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000", 0.0, DBL_MAX},
  { 0, 0, 0.0, 0.0 },
};

#define MAX_ERROR 0.000001

/* floating point imprecision on intel at least */

int approx_equald(double a, double b, double merr)
{
  double tmp;
  if (b > a) { tmp = a; a = b; b = tmp; }
  if (b < 0.0f) b = -b;
  if (a < 0.0f) a = -a;
  tmp = a - b;
  return (tmp <= merr);
}
int approx_equalf(float a, float b, float merr)
{
  float tmp;
  if (b > a) { tmp = a; a = b; b = tmp; }
  if (b < 0.0f) b = -b;
  if (a < 0.0f) a = -a;
  tmp = a - b;
  return (tmp <= merr);
}

int main()
{
  float ff;
  double fd;
  unsigned int i;

  i = 0;
  for (;;) {
    switch (ssfloats[i].sz) {
      case 0: return 0; break;
      case FLOAT:
        ff = 0;
        scan_float(ssfloats[i].str, &ff);
        if (!approx_equalf(ff, ssfloats[i].ff, MAX_ERROR)) {
          printf("fail: scan_float: [%u] ff == %f\n", i, ff); return 1;
        }
        break;
      case DOUBLE:
        fd = 0;
        scan_double(ssfloats[i].str, &fd);
        if (!approx_equald(fd, ssfloats[i].fd, MAX_ERROR)) {
          printf("fail: scan_double: [%u] fd == %f\n", i, fd); return 1;
        }
        break;
      default: break;
    }
    ++i;
  }

  return 0;
}
