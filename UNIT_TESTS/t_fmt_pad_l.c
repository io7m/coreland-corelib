#include <stdio.h>
#include <math.h>
#include "../fmt.h"
#include "../str.h"

struct fmt_test {
  long num;
  unsigned int pad;
  unsigned int ch;
  unsigned int (*fmt)(char *, long);
  unsigned int len;
  const char *str;
  unsigned int flags;
};

static const struct fmt_test tests[] = {
  { 0, 0, 0, fmt_long, 1, "0", 0 },
  { 0, 1, '_', fmt_long, 1, "0", 0 },
  { 0, 2, '_', fmt_long, 2, "_0", 0 },
  { 0, 3, '_', fmt_long, 3, "__0", 0 },
  { 0, 4, '_', fmt_long, 4, "___0", 0 },
  { 0, 5, '_', fmt_long, 5, "____0", 0 },
  { 0, 6, '_', fmt_long, 6, "_____0", 0 },
  { 0, 7, '_', fmt_long, 7, "______0", 0 },
  { 0, 8, '_', fmt_long, 8, "_______0", 0 },
  { 0, 9, '_', fmt_long, 9, "________0", 0 },
  { 0, 10, '_', fmt_long, 10, "_________0", 0 },
  { 0, 11, '_', fmt_long, 11, "__________0", 0 },
  { 0, 12, '_', fmt_long, 12, "___________0", 0 },
  { 0, 13, '_', fmt_long, 13, "____________0", 0 },
  { 0, 14, '_', fmt_long, 14, "_____________0", 0 },
  { 0, 15, '_', fmt_long, 15, "______________0", 0 },
  { 0, 16, '_', fmt_long, 16, "_______________0", 0 },

  { 2147483647, 16, '_', fmt_long, 16, "______2147483647", 0 },
  { 0x7fffffff, 16, '_', fmt_longx, 16, "________7fffffff", 0 },
  { 017777777777, 16, '_', fmt_longo, 16, "_____17777777777", 0 },
  { 2147483647, 1, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 2, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 3, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 4, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 5, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 6, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 7, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 8, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 9, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 10, '_', fmt_long, 10, "2147483647", 0 },
  { 2147483647, 11, '_', fmt_long, 11, "_2147483647", 0 },
  { 2147483647, 12, '_', fmt_long, 12, "__2147483647", 0 },
  { 2147483647, 13, '_', fmt_long, 13, "___2147483647", 0 },
  { 2147483647, 14, '_', fmt_long, 14, "____2147483647", 0 },
  { 2147483647, 15, '_', fmt_long, 15, "_____2147483647", 0 },
  { 2147483647, 16, '_', fmt_long, 16, "______2147483647", 0 },

  { -2147483647, 16, '_', fmt_long, 16, "_____-2147483647", FMT_PAD_SIGN_POST },
  { -0x7fffffff, 16, '_', fmt_longx, 16, "_______-7fffffff", FMT_PAD_SIGN_POST },
  { -017777777777, 16, '_', fmt_longo, 16, "____-17777777777", FMT_PAD_SIGN_POST },
  { -2147483647, 1, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 2, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 3, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 4, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 5, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 6, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 7, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 8, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 9, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 10, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 11, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 12, '_', fmt_long, 12, "_-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 13, '_', fmt_long, 13, "__-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 14, '_', fmt_long, 14, "___-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 15, '_', fmt_long, 15, "____-2147483647", FMT_PAD_SIGN_POST },
  { -2147483647, 16, '_', fmt_long, 16, "_____-2147483647", FMT_PAD_SIGN_POST },

  { -2147483647, 16, '_', fmt_long, 16, "-_____2147483647", FMT_PAD_SIGN_PRE },
  { -0x7fffffff, 16, '_', fmt_longx, 16, "-_______7fffffff", FMT_PAD_SIGN_PRE },
  { -017777777777, 16, '_', fmt_longo, 16, "-____17777777777", FMT_PAD_SIGN_PRE },
  { -2147483647, 1, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 2, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 3, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 4, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 5, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 6, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 7, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 8, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 9, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 10, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 11, '_', fmt_long, 11, "-2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 12, '_', fmt_long, 12, "-_2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 13, '_', fmt_long, 13, "-__2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 14, '_', fmt_long, 14, "-___2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 15, '_', fmt_long, 15, "-____2147483647", FMT_PAD_SIGN_PRE },
  { -2147483647, 16, '_', fmt_long, 16, "-_____2147483647", FMT_PAD_SIGN_PRE },
};

int main(void)
{
  char cnum[FMT_ULONG];
  unsigned int ind;
  unsigned int len;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct fmt_test); ++ind) {
    len = fmt_pad_long(cnum, tests[ind].num, tests[ind].pad, tests[ind].ch,
                             tests[ind].fmt, tests[ind].flags);
    cnum[len] = 0;
    if (len != tests[ind].len) {
      printf("[%u] fail: len %u != %u %s %s\n", ind, len, tests[ind].len, cnum, tests[ind].str);
      return 1;
    }
    len = fmt_pad_long(FMT_LEN, tests[ind].num, tests[ind].pad, tests[ind].ch,
                                tests[ind].fmt, tests[ind].flags);
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
