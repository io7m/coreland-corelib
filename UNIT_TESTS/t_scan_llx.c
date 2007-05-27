#include <stdio.h>
#include "../sd_longlong.h"

#if defined(HAVE_LONGLONG)
#define CORELIB_USE_LONGLONG
#include "../scan.h"

static const struct {
  unsigned long len;
  long long num;
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
  long long num;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    num = 0;
    len = scan_longlongx(tests[ind].str, &num);
    if (len != tests[ind].len) {
      printf("[%u] fail: len %lu != %lu\n", ind, len, tests[ind].len);
      return 1;
    }
    if (num != tests[ind].num) {
      printf("[%u] fail: num %lld != %lld\n", ind, num, tests[ind].num);
      return 1;
    }
    printf("[%u] %s %lld\n", ind, tests[ind].str, num);
  }
  return 0;
}
#else
int main(void)
{
  return 0;
}
#endif
