#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  unsigned short u;
  const char *str;
} tests[] = {
  { 1, 0U, "0" },
  { 1, 1U, "1" },
  { 8, 255U, "11111111" },
  { 15, 32767U, "111111111111111" },
  { 16, 65535U, "1111111111111111" },
  { 7, 123, "1111011 111001000" },
  { 0, 0, "2" },
  { 0, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  unsigned short u;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    u = 0;
    len = scan_ushortb(tests[ind].str, &u);
    if (len != tests[ind].len) {
      printf("[%u] fail: len %lu != %lu\n", ind, len, tests[ind].len);
      return 1;
    }
    if (u != tests[ind].u) {
      printf("[%u] fail: u %u != %u\n", ind, u, tests[ind].u);
      return 1;
    }
    printf("[%u] %s %u\n", ind, tests[ind].str, u);
  }
  return 0;
}
