#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  unsigned char num;
  const char *str;
  unsigned int (*fmt)(char *, unsigned char);
} tests[] = {
  { 1, 0, "0", fmt_uchar },
  { 1, 0, "0", fmt_ucharo },
  { 1, 0, "0", fmt_ucharx },
  { 1, 0, "0", fmt_ucharb },

  { 1, 1, "1", fmt_uchar },
  { 1, 1, "1", fmt_ucharo },
  { 1, 1, "1", fmt_ucharx },
  { 1, 1, "1", fmt_ucharb },

  { 3, 127, "127", fmt_uchar },
  { 3, 127, "177", fmt_ucharo },
  { 2, 127, "7f", fmt_ucharx },
  { 7, 127, "1111111", fmt_ucharb },

  { 3, 255, "255", fmt_uchar },
  { 3, 255, "377", fmt_ucharo },
  { 2, 255, "ff", fmt_ucharx },
  { 8, 255, "11111111", fmt_ucharb },
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
