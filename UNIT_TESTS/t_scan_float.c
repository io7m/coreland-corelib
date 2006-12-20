#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
  { FLOAT,  "-32.123",    -32.123f,        0.0f },
  { DOUBLE, "-12304.100",     0.0f, -12304.100f },
  { 0, 0, 0.0f, 0.0f },
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
