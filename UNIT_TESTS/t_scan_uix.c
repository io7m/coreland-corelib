#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  unsigned int u;
  const char *str;
} tests[] = {
  { 1, 0U, "0" },
  { 1, 1U, "1" },
  { 2, 0xffU, "ff" },
  { 2, 0xffU, "FF" },
  { 4, 0x7fffU, "7fff" },
  { 4, 0x7fffU, "7FFF" },
  { 5, 0x10000U, "10000" },
  { 8, 0x12345678U, "12345678" },
  { 6, 0xabcdefU, "abcdef" },
  { 6, 0xabcdefU, "ABCDEF" },
  { 8, 0xffffffffU, "ffffffff" },
  { 8, 0xffffffffU, "FFFFFFFF" },
  { 3, 0x123, "123 456" },
  { 0, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  unsigned int u;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    u = 0;
    len = scan_uintx(tests[ind].str, &u);
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
