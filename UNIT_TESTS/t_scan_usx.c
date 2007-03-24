#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  unsigned short u;
  const char *str;
} tests[] = {
  { 1, 0U, "0" },
  { 1, 1U, "1" },
  { 2, 0xffU, "ff" },
  { 2, 0xffU, "FF" },
  { 4, 0x7fffU, "7fff" },
  { 4, 0x7fffU, "7FFF" },
  { 4, 0xffffU, "ffff" },
  { 4, 0xFFFFU, "FFFF" },
  { 4, 0xabcdU, "abcd" },
  { 4, 0xabcdU, "ABCD" },
  { 4, 0xcdefU, "cdef" },
  { 4, 0xcdefU, "CDEF" },
  { 3, 0x123, "123 456" },
  { 0, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  unsigned short u;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    u = 0;
    len = scan_ushortx(tests[ind].str, &u);
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
