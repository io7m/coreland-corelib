#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  int num;
  const char *str;
} tests[] = {
  { 1, 0U, "0" },
  { 2, -1, "-1" },
  { 3, -0xff, "-ff" },
  { 3, -0xff, "-FF" },
  { 5, -0x7fff, "-7fff" },
  { 5, -0x7fff, "-7FFF" },
  { 6, -0x10000, "-10000" },
  { 9, -0x12345678, "-12345678" },
  { 7, -0xabcdef, "-abcdef" },
  { 7, -0xabcdef, "-ABCDEF" },
  { 9, -0xffffffff, "-ffffffff" },
  { 9, -0xffffffff, "-FFFFFFFF" },
  { 4, -0x123, "-123 456" },
  { 1, 1, "1" },
  { 2, 0xff, "ff" },
  { 2, 0xff, "FF" },
  { 4, 0x7fff, "7fff" },
  { 4, 0x7fff, "7FFF" },
  { 5, 0x10000, "10000" },
  { 8, 0x12345678, "12345678" },
  { 6, 0xabcdef, "abcdef" },
  { 6, 0xabcdef, "ABCDEF" },
  { 8, 0xffffffff, "ffffffff" },
  { 8, 0xffffffff, "FFFFFFFF" },
  { 3, 0x123, "123 456" },
  { 1, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  int num;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    num = 0;
    len = scan_intx(tests[ind].str, &num);
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
