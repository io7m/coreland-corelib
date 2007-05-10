#include <stdio.h>
#include <math.h>
#include "../fmt.h"
#include "../str.h"

struct fmt_test {
  unsigned long num;
  unsigned int pad;
  unsigned int ch;
  unsigned int (*fmt)(char *, unsigned long);
  unsigned int len;
  const char *str;
};

static const struct fmt_test tests[] = {
  { 0, 0, 0, fmt_ulong, 1, "0" },
  { 0, 1, '_', fmt_ulong, 1, "0" },
  { 0, 2, '_', fmt_ulong, 2, "_0" },
  { 0, 3, '_', fmt_ulong, 3, "__0" },
  { 0, 4, '_', fmt_ulong, 4, "___0" },
  { 0, 5, '_', fmt_ulong, 5, "____0" },
  { 0, 6, '_', fmt_ulong, 6, "_____0" },
  { 0, 7, '_', fmt_ulong, 7, "______0" },
  { 0, 8, '_', fmt_ulong, 8, "_______0" },
  { 0, 9, '_', fmt_ulong, 9, "________0" },
  { 0, 10, '_', fmt_ulong, 10, "_________0" },
  { 0, 11, '_', fmt_ulong, 11, "__________0" },
  { 0, 12, '_', fmt_ulong, 12, "___________0" },
  { 0, 13, '_', fmt_ulong, 13, "____________0" },
  { 0, 14, '_', fmt_ulong, 14, "_____________0" },
  { 0, 15, '_', fmt_ulong, 15, "______________0" },
  { 0, 16, '_', fmt_ulong, 16, "_______________0" },
  { 4294967295U, 16, '_', fmt_ulong, 16, "______4294967295" },
  { 0xffffffffU, 16, '_', fmt_ulongx, 16, "________ffffffff" },
  { 037777777777U, 16, '_', fmt_ulongo, 16, "_____37777777777" },
  { 4294967295U, 1, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 2, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 3, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 4, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 5, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 6, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 7, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 8, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 9, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 10, '_', fmt_ulong, 10, "4294967295" },
  { 4294967295U, 11, '_', fmt_ulong, 11, "_4294967295" },
  { 4294967295U, 12, '_', fmt_ulong, 12, "__4294967295" },
  { 4294967295U, 13, '_', fmt_ulong, 13, "___4294967295" },
  { 4294967295U, 14, '_', fmt_ulong, 14, "____4294967295" },
  { 4294967295U, 15, '_', fmt_ulong, 15, "_____4294967295" },
  { 4294967295U, 16, '_', fmt_ulong, 16, "______4294967295" },
};

int main(void)
{
  char cnum[FMT_ULONG];
  unsigned int ind;
  unsigned int len;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct fmt_test); ++ind) {
    len = fmt_pad_ulong(cnum, tests[ind].num, tests[ind].pad, tests[ind].ch,
                              tests[ind].fmt);
    cnum[len] = 0;
    if (len != tests[ind].len) {
      printf("[%u] fail: len %u != %u %s %s\n", ind, len, tests[ind].len, cnum, tests[ind].str);
      return 1;
    }
    len = fmt_pad_ulong(FMT_LEN, tests[ind].num, tests[ind].pad, tests[ind].ch,
                                 tests[ind].fmt);
    if (len != tests[ind].len) {
      printf("[%u] fail: FMT_LEN len %u != %u\n", ind, len, tests[ind].len);
      return 1;
    }
    if (!str_same(cnum, tests[ind].str)) {
      printf("[%u] fail: %s != %s\n", ind, cnum, tests[ind].str);
      return 1;
    }
    printf("[%u] pass: %s == %s\n", ind, tests[ind].str, cnum);
  }
  return 0;
}
