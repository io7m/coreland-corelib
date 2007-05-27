#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  unsigned long num;
  const char *str;
  unsigned int (*fmt)(char *, unsigned long);
} tests[] = {
  { 1, 0, "0", fmt_ulong },
  { 1, 0, "0", fmt_ulongo },
  { 1, 0, "0", fmt_ulongx },
  { 1, 0, "0", fmt_ulongb },

  { 1, 1, "1", fmt_ulong },
  { 1, 1, "1", fmt_ulongo },
  { 1, 1, "1", fmt_ulongx },
  { 1, 1, "1", fmt_ulongb },

  { 3, 127, "127", fmt_ulong },
  { 3, 127, "177", fmt_ulongo },
  { 2, 127, "7f", fmt_ulongx },
  { 7, 127, "1111111", fmt_ulongb },

  { 5, 32767, "32767", fmt_ulong },
  { 5, 32767, "77777", fmt_ulongo },
  { 4, 32767, "7fff", fmt_ulongx },
  { 15, 32767, "111111111111111", fmt_ulongb },

  { 10, 2147483647, "2147483647", fmt_ulong },
  { 11, 2147483647, "17777777777", fmt_ulongo },
  { 8, 2147483647, "7fffffff", fmt_ulongx },
  { 31, 2147483647, "1111111111111111111111111111111", fmt_ulongb },

  { 3, 255, "255", fmt_ulong },
  { 3, 255, "377", fmt_ulongo },
  { 2, 255, "ff", fmt_ulongx },
  { 8, 255, "11111111", fmt_ulongb },

  { 5, 65535, "65535", fmt_ulong },
  { 6, 65535, "177777", fmt_ulongo },
  { 4, 65535, "ffff", fmt_ulongx },
  { 16, 65535, "1111111111111111", fmt_ulongb },

  { 10, 4294967295UL, "4294967295", fmt_ulong },
  { 11, 4294967295UL, "37777777777", fmt_ulongo },
  { 8, 4294967295UL, "ffffffff", fmt_ulongx },
  { 32, 4294967295UL, "11111111111111111111111111111111", fmt_ulongb },
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
