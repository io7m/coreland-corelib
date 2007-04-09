#include <stdio.h>
#include "../sstring.h"
#include "t_assert.h"

#define BSIZE 32

int main(void)
{
  unsigned long len;
  static char buf[BSIZE];
  struct sstring str = sstring_INIT(buf);

  test_assert(str.a == BSIZE);
  test_assert(str.len == 0);

  sstring_cats(&str, "ABCDEFGH");
  sstring_0(&str);
  test_assert(str.len == 8);

  /* should truncate */
  sstring_cats(&str, "12345678ABCDEFGH12345678ABCDEFGH");
  sstring_0(&str);
  test_assert(str.len == (BSIZE - 1));
  test_assert(str.s[BSIZE - 1] == 0);
  test_assert(str.s[BSIZE - 2] == '7');

  sstring_trunc(&str);
  test_assert(str.a == BSIZE);
  test_assert(str.len == 0);

  /* should truncate */
  sstring_cpys(&str, "ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH");
  sstring_0(&str);
  test_assert(str.len == (BSIZE - 1));
  test_assert(str.s[BSIZE - 1] == 0);
  test_assert(str.s[BSIZE - 2] == '7');

  /* should not change */
  sstring_chop(&str, BSIZE * 2);
  test_assert(str.len == (BSIZE - 1));
  test_assert(str.s[BSIZE - 1] == 0);
  test_assert(str.s[BSIZE - 2] == '7');

  /* should chop correctly */
  len = BSIZE / 2;
  sstring_chop(&str, len);
  sstring_0(&str);
  test_assert(str.len == len);
  test_assert(str.s[len] == 0);
  test_assert(str.s[len - 1] == '8');

  return 0;
}
