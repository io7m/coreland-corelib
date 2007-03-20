#include <stdio.h>
#include "../fmt.h"
#include "../str.h"

struct fmt_test {
  float num;
  char *str;
  unsigned int prec;
};

static const struct fmt_test tests[] = {
  { 0.0, "0.000000", 0 },
  { 0.0, "0.0",      1 },
  { 0.0, "0.00",     2 },
  { 0.0, "0.000",    3 },
  { 0.0, "0.0000",   4 },
  { 0.0, "0.00000",  5 },
  { 0.0, "0.000000", 6 },
  { -0.0, "-0.000000", 0 },
  { -1.0, "-0.100000", 0 },
};

int main(void)
{
  char cnum[FMT_FLOAT];
  unsigned int ind;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct fmt_test); ++ind) {
    cnum[fmt_float(cnum, tests[ind].num, tests[ind].prec)] = 0;
    if (!str_same(cnum, tests[ind].str)) {
      printf("fail: [%u] %s != %s\n", ind, cnum, tests[ind].str);
      return 1;
    }
  }

  return 0;
}
