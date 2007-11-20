#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "../scan.h"

struct test {
  const char *str;
  double fd;
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

int approx_equald(double a, double b, double merr)
{
  double tmp;
  if (b > a) { tmp = a; a = b; b = tmp; }
  if (b < 0.0f) b = -b;
  if (a < 0.0f) a = -a;
  tmp = a - b;
  return (tmp <= merr);
}

int main(void)
{
  double fd;
  unsigned int ind;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    fd = 0;
    len = scan_double(tests[ind].str, &fd);
    if (!approx_equald(fd, tests[ind].fd, MAX_ERROR)) {
      printf("fail: scan_double: [%u] %f != %f\n", ind, fd, tests[ind].fd);
      return 1;
    }
    if (len != str_len(tests[ind].str)) {
      printf("fail: scan_double: [%u] len %lu != %lu\n", ind, len,
                                                         str_len(tests[ind].str));
      return 1;
    }
    printf("[%u] %s %f\n", ind, tests[ind].str, tests[ind].fd);
  }

  return 0;
}
