#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  char num;
  const char *str;
} tests[] = {
  { 1, 0, "0" },
  { 2, -1, "-1" },
  { 3, -0x7f, "-7f" },
  { 3, -0x7f, "-7F" },
  { 3, -0x12, "-12 456" },
  { 1, 1, "1" },
  { 2, 0x7f, "7f" },
  { 2, 0x7f, "7F" },
  { 2, 0x12, "12 456" },
  { 1, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  char num;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    num = 0;
    len = scan_charx(tests[ind].str, &num);
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
