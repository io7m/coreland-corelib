#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  short num;
  const char *str;
  unsigned int (*fmt)(char *, short);
} tests[] = {
  { 1, 0, "0", fmt_short },
  { 1, 0, "0", fmt_shorto },
  { 1, 0, "0", fmt_shortx },
  { 1, 0, "0", fmt_shortb },

  { 1, 1, "1", fmt_short },
  { 1, 1, "1", fmt_shorto },
  { 1, 1, "1", fmt_shortx },
  { 1, 1, "1", fmt_shortb },

  { 3, 127, "127", fmt_short },
  { 3, 127, "177", fmt_shorto },
  { 2, 127, "7f", fmt_shortx },
  { 7, 127, "1111111", fmt_shortb },

  { 5, 32767, "32767", fmt_short },
  { 5, 32767, "77777", fmt_shorto },
  { 4, 32767, "7fff", fmt_shortx },
  { 15, 32767, "111111111111111", fmt_shortb },

  { 2, -1, "-1", fmt_short },
  { 2, -1, "-1", fmt_shorto },
  { 2, -1, "-1", fmt_shortx },
  { 2, -1, "-1", fmt_shortb },

  { 4, -127, "-127", fmt_short },
  { 4, -127, "-177", fmt_shorto },
  { 3, -127, "-7f", fmt_shortx },
  { 8, -127, "-1111111", fmt_shortb },

  { 6, -32767, "-32767", fmt_short },
  { 6, -32767, "-77777", fmt_shorto },
  { 5, -32767, "-7fff", fmt_shortx },
  { 16, -32767, "-111111111111111", fmt_shortb },
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
