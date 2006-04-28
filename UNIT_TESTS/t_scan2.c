#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../scan.h"

struct mfloat_str {
  unsigned int sz;
  const char *str;
  float f;
  double d;
};

static struct mfloat_str mfloats[] = {
  { 1, "-32.123",    -32.123f,        0.0f },
  { 1, "12.4",       12.4f,           0.0f },
  { 1, "-256",       256.0f,          0.0f },
  { 2, "-12304.100",     0.0f, -12304.100f },
  { 2, "2245.0203",      0.0f,  2245.0203f },
  { 2, "123045.213",     0.0f, 123045.213f },
  { 0, 0, 0.0f, 0.0f },
};

#define MAX_FERROR 0.001
#define MAX_DERROR 0.01

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
  float f;
  double d;
  unsigned int i;

  i = 0;
  for (;;) {
    switch (mfloats[i].sz) {
      case 0: return 0; break;
      case 1:
        f = 0;
        scan_float(mfloats[i].str, &f);
        if (!approx_equalf(f, mfloats[i].f, MAX_FERROR)) {
          printf("scan_float: [%u] f == %f\n", i, f); return 1;
        }
        break;
      case 2:
        d = 0;
        scan_double(mfloats[i].str, &d);
        if (!approx_equald(d, mfloats[i].d, MAX_DERROR)) {
          printf("scan_double: [%u] d == %f\n", i, d); return 1;
        }
        break;
      default: break;
    }
    ++i;
  }

  return 0;
}
