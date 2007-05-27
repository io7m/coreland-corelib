#include <stdio.h>
#include "../scan.h"

static const struct {
  unsigned long len;
  long num;
  const char *str;
} tests[] = {
  { 1, 0, "0" },
  { 1, 1, "1" },
  { 3, 255, "255" },
  { 5, 32767, "32767" },
  { 5, 65536, "65536" },
  { 10, 1234567890, "1234567890" },
  { 10, 2147483647, "2147483647" },
  { 3, 123, "123 456" },

  { 2, -1, "-1" },
  { 4, -255, "-255" },
  { 6, -32767, "-32767" },
  { 6, -65536, "-65536" },
  { 11, -1234567890, "-1234567890" },
  { 11, -2147483647, "-2147483647" },
  { 4, -123, "-123 456" },
 
  { 1, 0, "-" },
};

int main(void)
{
  unsigned int ind;
  long num;
  unsigned long len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    num = 0;
    len = scan_long(tests[ind].str, &num);
    if (len != tests[ind].len) {
      printf("[%u] fail: len %lu != %lu\n", ind, len, tests[ind].len);
      return 1;
    }
    if (num != tests[ind].num) {
      printf("[%u] fail: num %ld != %ld\n", ind, num, tests[ind].num);
      return 1;
    }
    printf("[%u] %s %ld\n", ind, tests[ind].str, num);
  }
  return 0;
}
