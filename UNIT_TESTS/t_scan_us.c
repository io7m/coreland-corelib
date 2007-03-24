#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  unsigned short u;
  const char *str;
} tests[] = {
  { 1, 0U, "0" },
  { 1, 1U, "1" },
  { 3, 255U, "255" },
  { 5, 32767U, "32767" },
  { 5, 65535U, "65535" },
  { 3, 123, "123 456" },
  { 0, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  unsigned short u;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    u = 0;
    len = scan_ushort(tests[ind].str, &u);
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
