#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  int num;
  const char *str;
} tests[] = {
  { 1, 0, "0" },
  { 1, 1, "1" },
  { 8, 255, "11111111" },
  { 15, 32767, "111111111111111" },
  { 17, 65536, "10000000000000000" },
  { 31, 1234567890, "1001001100101100000001011010010" },
  { 31, 2147483647, "1111111111111111111111111111111" },
  { 7, 123, "1111011 111001000" },
  { 1, 0, "0" },
  { 2, -1, "-1" },
  { 9, -255, "-11111111" },
  { 16, -32767, "-111111111111111" },
  { 18, -65536, "-10000000000000000" },
  { 32, -1234567890, "-1001001100101100000001011010010" },
  { 32, -2147483647, "-1111111111111111111111111111111" },
  { 8, -123, "-1111011 111001000" },
  { 0, 0, "2" },
  { 1, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  int num;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    num = 0;
    len = scan_intb(tests[ind].str, &num);
    if (len != tests[ind].len) {
      printf("[%u] fail: len %lu != %lu\n", ind, len, tests[ind].len);
      return 1;
    }
    if (num != tests[ind].num) {
      printf("[%u] fail: num %d != %d\n", ind, num, tests[ind].num);
      return 1;
    }
    printf("[%u] %s %d\n", ind, tests[ind].str, num);
  }
  return 0;
}
