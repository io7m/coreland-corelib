#include <stdio.h>
#include "../error.h"
#include "../str.h"
#include "t_assert.h"

int main(void)
{
  const char *s = "ABCD1234EFGHXXXX";
  const char *t = "ABCD1234EFGHXXXX";
  const char *u = "AbCdEfGh";
  const char *v = "aBcDeFgH";
  char *x;
  long i;
  unsigned long pos;

  test_assert(str_chr(s, 'D') == 3);

  i = str_char(s, 'D', &pos);
  test_assert(i == 1);
  test_assert(pos == 3);

  test_assert(str_diff(s, t) == 0);
  test_assert(str_same(s, t));
  test_assert(str_ndiff(s, t, 8) == 0);
  test_assert(str_nsame(s, t, 8) == 1);

  test_assert(str_casei_diff(u, v) == 0);
  test_assert(str_casei_same(u, v) == 1);
  test_assert(str_casei_ndiff(u, v, 8) == 0);
  test_assert(str_casei_nsame(u, v, 8) == 1);;

  test_assert(str_rchr(s, 'X') == 15);

  i = str_rchar(s, 'X', &pos);
  test_assert(i == 1);
  test_assert(pos == 15);

  test_assert(str_dup(s, &x));

  test_assert(str_same(s, x) == 1);
  test_assert(str_nsame(s, x, 8) == 1);

  test_assert(str_starts(s, "ABCD") == 1);
  test_assert(str_starts(s, "XYZA") == 0);
  test_assert(str_starts(s, "1234EFGH1234EFGH1234EFGH") == 0);

  test_assert(str_ends(s, "XXXX") == 1);
  test_assert(str_ends(s, "ABCD") == 0);
  test_assert(str_ends(s, "GH1234EFGH123GH1234EFGH123") == 0);

  test_assert(str_len(s) == 16);
  
  str_toupper(x);
  test_assert(x[0] == 'A');
  str_tolower(x);
  test_assert(x[0] == 'a');

  return 0;
}
