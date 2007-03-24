#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "../scan_fspec.h"

struct test {
  const char *str;
  float64 fd;
};

static const struct test tests[] = {
  { "0", 0.0 },
  { "-0", -0.0 },
  { "0.0", 0.0 },
  { "-0.0", -0.0 },
  { "1", 1.0 },
  { "-1", -1.0 },
  { "1.0", 1.0 },
  { "1.00", 1.0 },
  { "1.000", 1.0 },
  { "1.0000", 1.0 },
  { "-1.0", -1.0 },
  { "-1.00", -1.0 },
  { "-1.000", -1.0 },
  { "-1.0000", -1.0 },
  { "0.1", 0.1 },
  { "0.01", 0.01 },
  { "0.001", 0.001 },
  { "0.0001", 0.0001 },
  { "0.00001", 0.00001 },
  { "0.000001", 0.000001 },
  { "0.0000001", 0.0000001 },
  { "0.00000001", 0.00000001 },
  { "0.000000001", 0.000000001 },
  { "0.0000000001", 0.0000000001 },
  { "0.00000000001", 0.00000000001 },
  { "0.000000000001", 0.000000000001 },
  { "0.0000000000001", 0.0000000000001 },
  { "0.00000000000001", 0.00000000000001 },
  { "0.000000000000001", 0.000000000000001 },
  { "-0.1", -0.1 },
  { "-0.01", -0.01 },
  { "-0.001", -0.001 },
  { "-0.0001", -0.0001 },
  { "-0.00001", -0.00001 },
  { "-0.000001", -0.000001 },
  { "-0.0000001", -0.0000001 },
  { "-0.00000001", -0.00000001 },
  { "-0.000000001", -0.000000001 },
  { "-0.0000000001", -0.0000000001 },
  { "-0.00000000001", -0.00000000001 },
  { "-0.000000000001", -0.000000000001 },
  { "-0.0000000000001", -0.0000000000001 },
  { "-0.00000000000001", -0.00000000000001 },
  { "-0.000000000000001", -0.000000000000001 },
  { "1.234567890", 1.234567890 },
  { "12.34567890", 12.34567890 },
  { "123.4567890", 123.4567890 },
  { "1234.567890", 1234.567890 },
  { "12345.67890", 12345.67890 },
  { "123456.7890", 123456.7890 },
  { "1234567.890", 1234567.890 },
  { "12345678.90", 12345678.90 },
  { "123456789.0", 123456789.0 },
  { "-1.234567890", -1.234567890 },
  { "-12.34567890", -12.34567890 },
  { "-123.4567890", -123.4567890 },
  { "-1234.567890", -1234.567890 },
  { "-12345.67890", -12345.67890 },
  { "-123456.7890", -123456.7890 },
  { "-1234567.890", -1234567.890 },
  { "-12345678.90", -12345678.90 },
  { "-123456789.0", -123456789.0 },
  { "1e1", 1e1 },
  { "1e-1", 1e-1 },
  { "1e10", 1e10 },
  { "1e-10", 1e-10 },
  { "-1e1", -1e1 },
  { "-1e-1", -1e-1 },
  { "-1e10", -1e10 },
  { "-1e-10", -1e-10 },
  { "1.0e1", 1.0e1 },
  { "1.0e-1", 1.0e-1 },
  { "1.0e10", 1.0e10 },
  { "1.0e-10", 1.0e-10 },
  { "-1.0e1", -1.0e1 },
  { "-1.0e-1", -1.0e-1 },
  { "-1.0e10", -1.0e10 },
  { "-1.0e-10", -1.0e-10 },
};

#define MAX_ERROR 0.00000000000001

int approx_equald(float64 a, float64 b, float64 merr)
{
  float64 tmp;
  if (b > a) { tmp = a; a = b; b = tmp; }
  if (b < 0.0f) b = -b;
  if (a < 0.0f) a = -a;
  tmp = a - b;
  return (tmp <= merr);
}

int main()
{
  float64 ff;
  float64 fd;
  unsigned int ind;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    fd = 0;
    scan_float64(tests[ind].str, &fd);
    if (!approx_equald(fd, tests[ind].fd, MAX_ERROR)) {
      printf("fail: scan_float64: [%u] %f != %f\n", ind, fd, tests[ind].fd);
      return 1;
    }
    printf("[%u] %s %f\n", ind, tests[ind].str, tests[ind].fd);
  }

  return 0;
}