#include <stdio.h>
#include "../sstring.h"

#define BSIZE 32

int main()
{
  unsigned long len;
  static char buf[BSIZE];
  struct sstring str = sstring_INIT(buf);

  if (str.a != BSIZE) { printf("str.a == %u\n", str.a); return 1; }
  if (str.len != 0) { printf("str.len == %u\n", str.len); return 1; }

  sstring_cats(&str, "ABCDEFGH");
  sstring_0(&str);
  if (str.len != 8) { printf("(1) cats: len == %u\n", str.len); return 1; }

  /* should truncate */
  sstring_cats(&str, "12345678ABCDEFGH12345678ABCDEFGH");
  sstring_0(&str);
  if (str.len != (BSIZE - 1)) {
    printf("(2) cats: len == %u\n", str.len); return 1;
  }
  if (str.s[BSIZE - 1] != 0) {
    printf("(2) cats: s[%u] == %c\n", BSIZE - 1, str.s[BSIZE - 1]); return 1;
  }
  if (str.s[BSIZE - 2] != '7') {
    printf("(2) cats: s[%u] == %c\n", BSIZE - 2, str.s[BSIZE - 2]); return 1;
  }

  sstring_trunc(&str);
  if (str.a != BSIZE) { printf("(3) trunc: a == %u\n", str.a); return 1; }
  if (str.len != 0) { printf("(3) trunc: len == %u\n", str.len); return 1; }

  /* should truncate */
  sstring_cpys(&str, "ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH");
  sstring_0(&str);
  if (str.len != (BSIZE - 1)) {
    printf("(3) cpys: len == %u\n", str.len); return 1;
  }
  if (str.s[BSIZE - 1] != 0) {
    printf("(3) cpys: s[%u] == %c\n", BSIZE - 1, str.s[BSIZE - 1]); return 1;
  }
  if (str.s[BSIZE - 2] != '7') {
    printf("(3) cpys: s[%u] == %c\n", BSIZE - 2, str.s[BSIZE - 2]); return 1;
  }

  /* should not change */
  sstring_chop(&str, BSIZE * 2);
  if (str.len != (BSIZE - 1)) {
    printf("(4) chop: len == %u\n", str.len); return 1;
  }
  if (str.s[BSIZE - 1] != 0) {
    printf("(4) chop: s[%u] == %c\n", BSIZE - 1, str.s[BSIZE - 1]); return 1;
  }
  if (str.s[BSIZE - 2] != '7') {
    printf("(4) chop: s[%u] == %c\n", BSIZE - 2, str.s[BSIZE - 2]); return 1;
  }

  /* should chop correctly */
  len = BSIZE / 2;
  sstring_chop(&str, len);
  sstring_0(&str);
  if (str.len != len) {
    printf("(5) chop: len == %u\n", str.len); return 1;
  }
  if (str.s[len] != 0) {
    printf("(5) chop: s[%u] == %c\n", len, str.s[len]); return 1;
  }
  if (str.s[len - 1] != '8') {
    printf("(6) chop: s[%u] == %c\n", len - 1, str.s[len - 1]); return 1;
  }

  return 0;
}
