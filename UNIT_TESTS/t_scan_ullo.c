#include <stdio.h>
#include "../sd_longlong.h"

#if defined(HAVE_LONGLONG)
#define CORELIB_USE_LONGLONG
#include "../scan.h"

static const struct {
  unsigned long len;
  unsigned long long u;
  const char *str;
} tests[] = {
  { 1, 0U, "0" },
  { 1, 1U, "1" },
  { 3, 0255U, "255" },
  { 5, 032767U, "32767" },
  { 5, 065536U, "65536" },
  { 7, 01234567U, "1234567" },
  { 11, 037777777777U, "37777777777" },
  { 22, 02000000000000000000000U, "2000000000000000000000" },
  { 3, 0123, "123 456" },
  { 0, 0, "8" },
  { 0, 0, "9" },
  { 0, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  unsigned long long u;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    u = 0;
    len = scan_ulonglongo(tests[ind].str, &u);
    if (len != tests[ind].len) {
      printf("[%u] fail: len %lu != %lu\n", ind, len, tests[ind].len);
      return 1;
    }
    if (u != tests[ind].u) {
      printf("[%u] fail: u %llu != %llu\n", ind, u, tests[ind].u);
      return 1;
    }
    printf("[%u] %s %llu\n", ind, tests[ind].str, u);
  }
  return 0;
}
#else
int main(void)
{
  return 0;
}
#endif
