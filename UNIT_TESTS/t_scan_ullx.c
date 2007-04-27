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
  { 1, 0ULL, "0" },
  { 1, 1ULL, "1" },
  { 2, 0xffULL, "ff" },
  { 2, 0xffULL, "FF" },
  { 4, 0x7fffULL, "7fff" },
  { 4, 0x7fffULL, "7FFF" },
  { 5, 0x10000ULL, "10000" },
  { 8, 0x12345678ULL, "12345678" },
  { 6, 0xabcdefULL, "abcdef" },
  { 6, 0xabcdefULL, "ABCDEF" },
  { 8, 0xffffffffULL, "ffffffff" },
  { 8, 0xffffffffULL, "FFFFFFFF" },
  { 3, 0x123, "123 456" },
  { 0, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  unsigned long long u;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    u = 0;
    len = scan_ulonglongx(tests[ind].str, &u);
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
