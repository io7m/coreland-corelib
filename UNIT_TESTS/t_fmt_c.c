#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  char num;
  const char *str;
  unsigned int (*fmt)(char *, char);
} tests[] = {
  { 1, 0, "0", fmt_char },
  { 1, 0, "0", fmt_charo },
  { 1, 0, "0", fmt_charx },
  { 1, 0, "0", fmt_charb },

  { 1, 1, "1", fmt_char },
  { 1, 1, "1", fmt_charo },
  { 1, 1, "1", fmt_charx },
  { 1, 1, "1", fmt_charb },

  { 3, 127, "127", fmt_char },
  { 3, 127, "177", fmt_charo },
  { 2, 127, "7f", fmt_charx },
  { 7, 127, "1111111", fmt_charb },

  { 2, -1, "-1", fmt_char },
  { 2, -1, "-1", fmt_charo },
  { 2, -1, "-1", fmt_charx },
  { 2, -1, "-1", fmt_charb },

  { 4, -127, "-127", fmt_char },
  { 4, -127, "-177", fmt_charo },
  { 3, -127, "-7f", fmt_charx },
  { 8, -127, "-1111111", fmt_charb },
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
