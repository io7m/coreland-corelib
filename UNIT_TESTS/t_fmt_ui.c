#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  unsigned int num;
  const char *str;
  unsigned int (*fmt)(char *, unsigned int);
} tests[] = {
  { 1, 0, "0", fmt_uint },
  { 1, 0, "0", fmt_uinto },
  { 1, 0, "0", fmt_uintx },
  { 1, 0, "0", fmt_uintb },

  { 1, 1, "1", fmt_uint },
  { 1, 1, "1", fmt_uinto },
  { 1, 1, "1", fmt_uintx },
  { 1, 1, "1", fmt_uintb },

  { 3, 127, "127", fmt_uint },
  { 3, 127, "177", fmt_uinto },
  { 2, 127, "7f", fmt_uintx },
  { 7, 127, "1111111", fmt_uintb },

  { 5, 32767, "32767", fmt_uint },
  { 5, 32767, "77777", fmt_uinto },
  { 4, 32767, "7fff", fmt_uintx },
  { 15, 32767, "111111111111111", fmt_uintb },

  { 3, 255, "255", fmt_uint },
  { 3, 255, "377", fmt_uinto },
  { 2, 255, "ff", fmt_uintx },
  { 8, 255, "11111111", fmt_uintb },

  { 5, 65535, "65535", fmt_uint },
  { 6, 65535, "177777", fmt_uinto },
  { 4, 65535, "ffff", fmt_uintx },
  { 16, 65535, "1111111111111111", fmt_uintb },
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
