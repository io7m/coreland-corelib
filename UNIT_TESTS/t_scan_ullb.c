#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  unsigned long long u;
  const char *str;
} tests[] = {
  { 1, 0ULL, "0" },
  { 1, 1ULL, "1" },
  { 8, 255ULL, "11111111" },
  { 15, 32767ULL, "111111111111111" },
  { 17, 65536ULL, "10000000000000000" },
  { 31, 1234567890ULL, "1001001100101100000001011010010" },
  { 32, 0xFFFFFFFFULL, "11111111111111111111111111111111" },
  { 64, 0xFFFFFFFFFFFFFFFFULL, "10000000000000000000000000000000000000000000000000000000000000000" },
  { 7, 123, "1111011 111001000" },
  { 0, 0, "2" },
  { 0, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  unsigned long long u;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    u = 0;
    len = scan_ulonglongb(tests[ind].str, &u);
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
