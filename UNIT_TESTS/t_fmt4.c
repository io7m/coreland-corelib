#include <stdio.h>
#include "../fmt.h"
#include "../str.h"

struct fmt_test {
  float num;
  char *str;
  unsigned int sig;
  unsigned int len;
};

static const struct fmt_test tests[] = {
  { 0.0,      "",          0, 0 },
  { 0.0,      "0",         1, 1 },
  { 0.0,      "0.0",       2, 3 },
  { 0.0,      "0.00",      3, 4 },
  { 0.0,      "0.000",     4, 5 },
  { 0.0,      "0.0000",    5, 6 },
  { 0.0,      "0.00000",   6, 7 },
  { -0.0,     "-0.000000", 7, 9 },
  { -1.0,     "-0.100000", 7, 9 },
  { 1.23456,  "1.23456",   6, 7 },
  { 1.2345,   "1.2345",    5, 6 },
  { 1.234,    "1.234",     4, 5 },
  { 1.23,     "1.23",      3, 4 },
  { 1.2,      "1.2",       2, 3 },
  { 1,        "1",         1, 1 },
};

int main(void)
{
  char cnum[FMT_FLOAT];
  unsigned int ind;
  unsigned int len;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct fmt_test); ++ind) {
    len = fmt_float(FMT_LEN, tests[ind].num, tests[ind].sig);
    if (len != tests[ind].len) {
      printf("fail: [%u] FMT_LEN len %u != %u\n", ind, len, tests[ind].len);
      return 1;
    }
    len = fmt_float(cnum, tests[ind].num, tests[ind].sig);
    if (len != tests[ind].len) {
      printf("fail: [%u] len %u != %u\n", ind, len, tests[ind].len);
      return 1;
    }
    cnum[len] = 0;
    if (!str_same(cnum, tests[ind].str)) {
      printf("fail: [%u] %s != %s\n", ind, cnum, tests[ind].str);
      return 1;
    }
    printf("[%lu] %s == %s\n", ind, tests[ind].str, cnum);
  }

  return 0;
}
