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
  { 1, 0, "0" },
  { 1, 1, "1" },

  { 8, 255, "11111111" },
  { 15, 32767, "111111111111111" },
  { 17, 65536, "10000000000000000" },
  { 31, 1234567890, "1001001100101100000001011010010" },
  { 31, 0x7FFFFFFFLL, "1111111111111111111111111111111" },
  { 63, 0x7FFFFFFFFFFFFFFFLL, "111111111111111111111111111111111111111111111111111111111111111" },
  { 7, 123, "1111011 111001000" },

  { 2, -1, "-1" },
  { 9, -255, "-11111111" },
  { 16, -32767, "-111111111111111" },
  { 18, -65536, "-10000000000000000" },
  { 32, -1234567890, "-1001001100101100000001011010010" },
  { 32, -0x7FFFFFFFLL, "-1111111111111111111111111111111" },
  { 64, -0x7FFFFFFFFFFFFFFFLL, "-111111111111111111111111111111111111111111111111111111111111111" },
  { 8, -123, "-1111011 111001000" },
 
  { 0, 0, "2" },
  { 1, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  long long num;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    num = 0;
    len = scan_longlongb(tests[ind].str, &num);
    if (len != tests[ind].len) {
      printf("[%u] fail: len %lu != %lu (%lld %s)\n", ind, len, tests[ind].len, num, tests[ind].str);
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
