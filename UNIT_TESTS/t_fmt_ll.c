#include "../sd_longlong.h"

#if defined(HAVE_LONGLONG)
#define CORELIB_USE_LONGLONG

#include <stdio.h>
#include "t_assert.h"
#include "../fmt.h"
#include "../str.h"

static const struct {
  unsigned int len;
  long long num;
  const char *str;
  unsigned int (*fmt)(char *, long long);
} tests[] = {
  { 1, 0, "0", fmt_longlong },
  { 1, 0, "0", fmt_longlongo },
  { 1, 0, "0", fmt_longlongx },
  { 1, 0, "0", fmt_longlongb },

  { 1, 1, "1", fmt_longlong },
  { 1, 1, "1", fmt_longlongo },
  { 1, 1, "1", fmt_longlongx },
  { 1, 1, "1", fmt_longlongb },

  { 3, 127, "127", fmt_longlong },
  { 3, 127, "177", fmt_longlongo },
  { 2, 127, "7f", fmt_longlongx },
  { 7, 127, "1111111", fmt_longlongb },

  { 5, 32767, "32767", fmt_longlong },
  { 5, 32767, "77777", fmt_longlongo },
  { 4, 32767, "7fff", fmt_longlongx },
  { 15, 32767, "111111111111111", fmt_longlongb },

  { 10, 2147483647, "2147483647", fmt_longlong },
  { 11, 2147483647, "17777777777", fmt_longlongo },
  { 8, 2147483647, "7fffffff", fmt_longlongx },
  { 31, 2147483647, "1111111111111111111111111111111", fmt_longlongb },

  { 19, 9223372036854775807LL, "9223372036854775807", fmt_longlong },
  { 21, 9223372036854775807LL, "777777777777777777777", fmt_longlongo },
  { 16, 9223372036854775807LL, "7fffffffffffffff", fmt_longlongx },
  { 63, 9223372036854775807LL, "111111111111111111111111111111111111111111111111111111111111111", fmt_longlongb },

  { 2, -1, "-1", fmt_longlong },
  { 2, -1, "-1", fmt_longlongo },
  { 2, -1, "-1", fmt_longlongx },
  { 2, -1, "-1", fmt_longlongb },

  { 4, -127, "-127", fmt_longlong },
  { 4, -127, "-177", fmt_longlongo },
  { 3, -127, "-7f", fmt_longlongx },
  { 8, -127, "-1111111", fmt_longlongb },

  { 6, -32767, "-32767", fmt_longlong },
  { 6, -32767, "-77777", fmt_longlongo },
  { 5, -32767, "-7fff", fmt_longlongx },
  { 16, -32767, "-111111111111111", fmt_longlongb },

  { 11, -2147483647, "-2147483647", fmt_longlong },
  { 12, -2147483647, "-17777777777", fmt_longlongo },
  { 9, -2147483647, "-7fffffff", fmt_longlongx },
  { 32, -2147483647, "-1111111111111111111111111111111", fmt_longlongb },

  { 20, -9223372036854775807LL, "-9223372036854775807", fmt_longlong },
  { 22, -9223372036854775807LL, "-777777777777777777777", fmt_longlongo },
  { 17, -9223372036854775807LL, "-7fffffffffffffff", fmt_longlongx },
  { 64, -9223372036854775807LL, "-111111111111111111111111111111111111111111111111111111111111111", fmt_longlongb },
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
