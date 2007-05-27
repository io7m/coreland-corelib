#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  long num;
  const char *str;
  unsigned int (*fmt)(char *, long);
} tests[] = {
  { 1, 0, "0", fmt_long },
  { 1, 0, "0", fmt_longo },
  { 1, 0, "0", fmt_longx },
  { 1, 0, "0", fmt_longb },

  { 1, 1, "1", fmt_long },
  { 1, 1, "1", fmt_longo },
  { 1, 1, "1", fmt_longx },
  { 1, 1, "1", fmt_longb },

  { 3, 127, "127", fmt_long },
  { 3, 127, "177", fmt_longo },
  { 2, 127, "7f", fmt_longx },
  { 7, 127, "1111111", fmt_longb },

  { 5, 32767, "32767", fmt_long },
  { 5, 32767, "77777", fmt_longo },
  { 4, 32767, "7fff", fmt_longx },
  { 15, 32767, "111111111111111", fmt_longb },

  { 10, 2147483647, "2147483647", fmt_long },
  { 11, 2147483647, "17777777777", fmt_longo },
  { 8, 2147483647, "7fffffff", fmt_longx },
  { 31, 2147483647, "1111111111111111111111111111111", fmt_longb },

  { 2, -1, "-1", fmt_long },
  { 2, -1, "-1", fmt_longo },
  { 2, -1, "-1", fmt_longx },
  { 2, -1, "-1", fmt_longb },

  { 4, -127, "-127", fmt_long },
  { 4, -127, "-177", fmt_longo },
  { 3, -127, "-7f", fmt_longx },
  { 8, -127, "-1111111", fmt_longb },

  { 6, -32767, "-32767", fmt_long },
  { 6, -32767, "-77777", fmt_longo },
  { 5, -32767, "-7fff", fmt_longx },
  { 16, -32767, "-111111111111111", fmt_longb },

  { 11, -2147483647, "-2147483647", fmt_long },
  { 12, -2147483647, "-17777777777", fmt_longo },
  { 9, -2147483647, "-7fffffff", fmt_longx },
  { 32, -2147483647, "-1111111111111111111111111111111", fmt_longb },
};

int main(void)
{
  char cnum[FMT_ULONG];
  unsigned long ind;
  unsigned int len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    cnum[tests[ind].fmt(cnum, tests[ind].num)] = 0;
    if (!str_same(cnum, tests[ind].str)) {
      printf("[%lu] fail: num %s != %s\n", ind, cnum, tests[ind].str);
      return 1;
    }
    len = tests[ind].fmt(FMT_LEN, tests[ind].num);
    if (len != tests[ind].len) {
      printf("[%lu] fail: len %u != %u\n", ind, len, tests[ind].len);
      return 1;
    }
    printf("[%lu] %s %u\n", ind, cnum, len);
  }
  return 0;
}
