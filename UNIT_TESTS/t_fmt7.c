#include <stdio.h>
#include "../fmt.h"
#include "../str.h"

struct fmt_test {
  long num;
  unsigned int (*fmt)(char *, long);
  unsigned int len;
  const char *str;
};

static const struct fmt_test tests[] = {
  { 0, fmt_long, 1, "0" },
  { 0, fmt_longx, 1, "0" },
  { 0, fmt_longb, 1, "0" },
  { 0, fmt_longo, 1, "0" },

  { 1, fmt_long, 1, "1" },
  { 1, fmt_longx, 1, "1" },
  { 1, fmt_longb, 1, "1" },
  { 1, fmt_longo, 1, "1" },

  { -1, fmt_long, 2, "-1" },
  { -1, fmt_longx, 2, "-1" },
  { -1, fmt_longb, 2, "-1" },
  { -1, fmt_longo, 2, "-1" },

  { 0x7fffffff, fmt_long, 10, "2147483647" },
  { 0x7fffffff, fmt_longx, 8, "7fffffff" },
  { 0x7fffffff, fmt_longb, 31, "1111111111111111111111111111111" },
  { 0x7fffffff, fmt_longo, 11, "17777777777" },

  { 0xff, fmt_long, 3, "255" },
  { 0xff, fmt_longx, 2, "ff" },
  { 0xff, fmt_longb, 8, "11111111" },
  { 0xff, fmt_longo, 3, "377" },

  { -0xff, fmt_long, 4, "-255" },
  { -0xff, fmt_longx, 3, "-ff" },
  { -0xff, fmt_longb, 9, "-11111111" },
  { -0xff, fmt_longo, 4, "-377" },
};

int main(void)
{
  char cnum[FMT_ULONG];
  unsigned int ind;
  unsigned int len;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct fmt_test); ++ind) {
    len = tests[ind].fmt(cnum, tests[ind].num);
    cnum[len] = 0;
    if (len != tests[ind].len) {
      printf("[%u] fail: len %u != %u %s %s\n", ind, len, tests[ind].len, cnum, tests[ind].str);
      return 1;
    }
    len = tests[ind].fmt(FMT_LEN, tests[ind].num);
    if (len != tests[ind].len) {
      printf("[%u] fail: FMT_LEN len %u != %u\n", ind, len, tests[ind].len);
      return 1;
    }
    if (!str_same(cnum, tests[ind].str)) {
      printf("[%u] fail: %s != %s\n", ind, cnum, tests[ind].str);
      return 1;
    }
    printf("[%u] pass: %s == %s\n", ind, tests[ind].str, cnum);
  }
  return 0;
}
