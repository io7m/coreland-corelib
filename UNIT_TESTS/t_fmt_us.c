#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  unsigned short num;
  const char *str;
  unsigned int (*fmt)(char *, unsigned short);
} tests[] = {
  { 1, 0, "0", fmt_ushort },
  { 1, 0, "0", fmt_ushorto },
  { 1, 0, "0", fmt_ushortx },
  { 1, 0, "0", fmt_ushortb },

  { 1, 1, "1", fmt_ushort },
  { 1, 1, "1", fmt_ushorto },
  { 1, 1, "1", fmt_ushortx },
  { 1, 1, "1", fmt_ushortb },

  { 3, 127, "127", fmt_ushort },
  { 3, 127, "177", fmt_ushorto },
  { 2, 127, "7f", fmt_ushortx },
  { 7, 127, "1111111", fmt_ushortb },

  { 5, 32767, "32767", fmt_ushort },
  { 5, 32767, "77777", fmt_ushorto },
  { 4, 32767, "7fff", fmt_ushortx },
  { 15, 32767, "111111111111111", fmt_ushortb },

  { 3, 255U, "255", fmt_ushort },
  { 3, 255U, "377", fmt_ushorto },
  { 2, 255U, "ff", fmt_ushortx },
  { 8, 255U, "11111111", fmt_ushortb },

  { 5, 65535U, "65535", fmt_ushort },
  { 6, 65535U, "177777", fmt_ushorto },
  { 4, 65535U, "ffff", fmt_ushortx },
  { 16, 65535U, "1111111111111111", fmt_ushortb },
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
