#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  short num;
  const char *str;
} tests[] = {
  { 1, 0, "0" },

  { 1, 1, "1" },
  { 2, 0xff, "ff" },
  { 2, 0xff, "FF" },
  { 4, 0x7fff, "7fff" },
  { 4, 0x7fff, "7FFF" },
  { 3, 0xabc, "abc" },
  { 3, 0xabc, "ABC" },
  { 3, 0xcde, "cde" },
  { 3, 0xcde, "CDE" },
  { 3, 0x123, "123 456" },

  { 2, -1, "-1" },
  { 3, -0xff, "-ff" },
  { 3, -0xff, "-FF" },
  { 5, -0x7fff, "-7fff" },
  { 5, -0x7fff, "-7FFF" },
  { 4, -0xabc, "-abc" },
  { 4, -0xabc, "-ABC" },
  { 4, -0xcde, "-cde" },
  { 4, -0xcde, "-CDE" },
  { 4, -0x123, "-123 456" },

  { 1, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  short num;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    num = 0;
    len = scan_shortx(tests[ind].str, &num);
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
