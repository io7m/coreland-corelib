#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../scan_fspec.h"

struct ssfloat_str {
  unsigned int sz;
  const char *str;
  float32 ff;
  float64 fd;
};

static struct ssfloat_str ssfloats[] = {
  { 32,  "-32.123",    -32.123f,        0.0f },
  { 64, "-12304.100",     0.0f, -12304.100f },
  { 0, 0, 0.0f, 0.0f },
};

#define MAX_ERROR 0.000001

/* floating point imprecision on intel at least */

int approx_equal64(float64 a, float64 b, float64 merr)
{
  float64 tmp;
  if (b > a) { tmp = a; a = b; b = tmp; }
  if (b < 0.0f) b = -b;
  if (a < 0.0f) a = -a;
  tmp = a - b;
  return (tmp <= merr);
}
int approx_equal32(float32 a, float32 b, float32 merr)
{
  float32 tmp;
  if (b > a) { tmp = a; a = b; b = tmp; }
  if (b < 0.0f) b = -b;
  if (a < 0.0f) a = -a;
  tmp = a - b;
  return (tmp <= merr);
}

int main()
{
  float32 ff;
  float64 fd;
  unsigned int i;

  i = 0;
  for (;;) {
    switch (ssfloats[i].sz) {
      case 0: return 0; break;
      case 32:
        ff = 0;
        scan_float32(ssfloats[i].str, &ff);
        if (!approx_equal32(ff, ssfloats[i].ff, MAX_ERROR)) {
          printf("fail: scan_float32: [%u] ff == %f\n", i, ff); return 1;
        }
        break;
      case 64:
        fd = 0;
        scan_float64(ssfloats[i].str, &fd);
        if (!approx_equal64(fd, ssfloats[i].fd, MAX_ERROR)) {
          printf("fail: scan_float64: [%u] fd == %f\n", i, fd); return 1;
        }
        break;
      default: break;
    }
    ++i;
  }

  return 0;
}
