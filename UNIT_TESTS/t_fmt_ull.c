#include "../sd_longlong.h"

#if defined(HAVE_LONGLONG)
#define CORELIB_USE_LONGLONG

#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  unsigned long long num;
  const char *str;
  unsigned int (*fmt)(char *, unsigned long long);
} tests[] = {
  { 1, 0, "0", fmt_ulonglong },
  { 1, 0, "0", fmt_ulonglongo },
  { 1, 0, "0", fmt_ulonglongx },
  { 1, 0, "0", fmt_ulonglongb },

  { 1, 1, "1", fmt_ulonglong },
  { 1, 1, "1", fmt_ulonglongo },
  { 1, 1, "1", fmt_ulonglongx },
  { 1, 1, "1", fmt_ulonglongb },

  { 3, 127, "127", fmt_ulonglong },
  { 3, 127, "177", fmt_ulonglongo },
  { 2, 127, "7f", fmt_ulonglongx },
  { 7, 127, "1111111", fmt_ulonglongb },

  { 5, 32767, "32767", fmt_ulonglong },
  { 5, 32767, "77777", fmt_ulonglongo },
  { 4, 32767, "7fff", fmt_ulonglongx },
  { 15, 32767, "111111111111111", fmt_ulonglongb },

  { 10, 2147483647, "2147483647", fmt_ulonglong },
  { 11, 2147483647, "17777777777", fmt_ulonglongo },
  { 8, 2147483647, "7fffffff", fmt_ulonglongx },
  { 31, 2147483647, "1111111111111111111111111111111", fmt_ulonglongb },

  { 19, 9223372036854775807LL, "9223372036854775807", fmt_ulonglong },
  { 21, 9223372036854775807LL, "777777777777777777777", fmt_ulonglongo },
  { 16, 9223372036854775807LL, "7fffffffffffffff", fmt_ulonglongx },
  { 63, 9223372036854775807LL, "111111111111111111111111111111111111111111111111111111111111111", fmt_ulonglongb },

  { 3, 255, "255", fmt_ulonglong },
  { 3, 255, "377", fmt_ulonglongo },
  { 2, 255, "ff", fmt_ulonglongx },
  { 8, 255, "11111111", fmt_ulonglongb },

  { 5, 65535, "65535", fmt_ulonglong },
  { 6, 65535, "177777", fmt_ulonglongo },
  { 4, 65535, "ffff", fmt_ulonglongx },
  { 16, 65535, "1111111111111111", fmt_ulonglongb },

  { 10, 4294967295ULL, "4294967295", fmt_ulonglong },
  { 11, 4294967295ULL, "37777777777", fmt_ulonglongo },
  { 8, 4294967295ULL, "ffffffff", fmt_ulonglongx },
  { 32, 4294967295ULL, "11111111111111111111111111111111", fmt_ulonglongb },

  { 20, 18446744073709551615ULL, "18446744073709551615", fmt_ulonglong },
  { 22, 18446744073709551615ULL, "1777777777777777777777", fmt_ulonglongo },
  { 16, 18446744073709551615ULL, "ffffffffffffffff", fmt_ulonglongx },
  { 64, 18446744073709551615ULL, "1111111111111111111111111111111111111111111111111111111111111111", fmt_ulonglongb },
};

int main(void)
{
  char cnum[FMT_ULONGLONG];
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

#else
int main(void)
{
  return 0;
}
#endif
