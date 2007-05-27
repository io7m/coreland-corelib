#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  int num;
  const char *str;
  unsigned int (*fmt)(char *, int);
} tests[] = {
  { 1, 0, "0", fmt_int },
  { 1, 0, "0", fmt_into },
  { 1, 0, "0", fmt_intx },
  { 1, 0, "0", fmt_intb },

  { 1, 1, "1", fmt_int },
  { 1, 1, "1", fmt_into },
  { 1, 1, "1", fmt_intx },
  { 1, 1, "1", fmt_intb },

  { 3, 127, "127", fmt_int },
  { 3, 127, "177", fmt_into },
  { 2, 127, "7f", fmt_intx },
  { 7, 127, "1111111", fmt_intb },

  { 5, 32767, "32767", fmt_int },
  { 5, 32767, "77777", fmt_into },
  { 4, 32767, "7fff", fmt_intx },
  { 15, 32767, "111111111111111", fmt_intb },

  { 2, -1, "-1", fmt_int },
  { 2, -1, "-1", fmt_into },
  { 2, -1, "-1", fmt_intx },
  { 2, -1, "-1", fmt_intb },

  { 4, -127, "-127", fmt_int },
  { 4, -127, "-177", fmt_into },
  { 3, -127, "-7f", fmt_intx },
  { 8, -127, "-1111111", fmt_intb },

  { 6, -32767, "-32767", fmt_int },
  { 6, -32767, "-77777", fmt_into },
  { 5, -32767, "-7fff", fmt_intx },
  { 16, -32767, "-111111111111111", fmt_intb },
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
