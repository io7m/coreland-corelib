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
  { 3, 255U, "255" },
  { 5, 32767U, "32767" },
  { 5, 65536U, "65536" },
  { 10, 1234567890U, "1234567890" },
  { 10, 4294967295U, "4294967295" },
  { 20, 18446744073709551615ULL, "18446744073709551615" },
  { 3, 123, "123 456" },
  { 0, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  unsigned long long u;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    u = 0;
    len = scan_ulonglong(tests[ind].str, &u);
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


