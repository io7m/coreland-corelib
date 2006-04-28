#include <stdio.h>
#include "../float32.h"
#include "../float64.h"

/* the printf statements in this file are questionable due to
   floating point number size silliness. the test should still
   work but the diagnostics on failure may be wrong */

int main()
{
  float32 f32;
  float64 f64;
  unsigned char c32[sizeof(float32)];
  unsigned char c64[sizeof(float64)];

  f32 = 12.567f;
  float32_packl(c32, f32);
  float32_unpackl(c32, &f32);
  if (f32 != 12.567f) {
    printf("float32_unpackl: f32 == %f\n", f32); return 1;
  }
  f32 = 16.123f;
  float32_packb(c32, f32);
  float32_unpackb(c32, &f32);
  if (f32 != 16.123f) {
    printf("float32_unpackl: f32 == %f\n", f32); return 1;
  }

  f64 = 12.567f;
  float64_packl(c64, f64);
  float64_unpackl(c64, &f64);
  if (f64 != 12.567f) {
    printf("float64_unpackl: f64 == %f\n", f64); return 1;
  }
  f64 = 16.123f;
  float64_packb(c64, f64);
  float64_unpackb(c64, &f64);
  if (f64 != 16.123f) {
    printf("float64_unpackl: f64 == %f\n", f64); return 1;
  }

  return 0;
}
