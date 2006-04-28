#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../scan_float.h"
#include "../int32.h"
#include "../int64.h"
#include "../float32.h"
#include "../float64.h"

struct ssfloat_str {
  unsigned int sz;
  const char *str;
  float32 f32;
  float64 f64;
};

static struct ssfloat_str ssfloats[] = {
  { 32, "-32.123",    -32.123f,        0.0f },
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
  float32 f32;
  float64 f64;
  unsigned int i;

  i = 0;
  for (;;) {
    switch (ssfloats[i].sz) {
      case 0: return 0; break;
      case 32:
        f32 = 0;
        scan_f32(ssfloats[i].str, &f32);
        if (!approx_equal32(f32, ssfloats[i].f32, MAX_ERROR)) {
          printf("scan_f32: [%u] f32 == %f\n", i, f32); return 1;
        }
        break;
      case 64:
        f64 = 0;
        scan_f64(ssfloats[i].str, &f64);
        if (!approx_equal64(f64, ssfloats[i].f64, MAX_ERROR)) {
          printf("scan_f64: [%u] f64 == %f\n", i, f64); return 1;
        }
        break;
      default: break;
    }
    ++i;
  }

  return 0;
}
