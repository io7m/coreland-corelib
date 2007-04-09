#include <stdio.h>
#include "../bin.h"
#include "t_assert.h"

int main(void)
{
  const char *s = "ABCD1234EFGHXXXX";
  char buf[8];
  long i;
  unsigned long pos;

  test_assert(bin_chr(s, 16, 'D') == 3);

  i = bin_char(s, 16, 'D', &pos);
  test_assert(i == 1);
  test_assert(pos == 3); 

  bin_copy(s, buf, 8);

  test_assert(buf[0] == 'A');
  test_assert(buf[1] == 'B');
  test_assert(buf[2] == 'C');
  test_assert(buf[3] == 'D');
  test_assert(buf[4] == '1');
  test_assert(buf[5] == '2');
  test_assert(buf[6] == '3');
  test_assert(buf[7] == '4');

  bin_zero(buf, 8);
  test_assert(buf[0] == 0);

  bin_copyr(buf, s, 8);
  test_assert(buf[0] == 'A');
  test_assert(buf[1] == 'B');
  test_assert(buf[2] == 'C');
  test_assert(buf[3] == 'D');
  test_assert(buf[4] == '1');
  test_assert(buf[5] == '2');
  test_assert(buf[6] == '3');
  test_assert(buf[7] == '4');

  test_assert(bin_count(s, 16, 'X') == 4);
  test_assert(bin_diff(s + 4, buf, 8) == -16);
  test_assert(bin_same(s, buf, 8));
  test_assert(bin_rchr(s, 16, 'X') == 15);

  i = bin_rchar(s, 16, 'X', &pos);
  test_assert(i == 1);
  test_assert(pos == 15);

  bin_set(buf, 8, 0x41);
  test_assert(buf[0] == 0x41);
  test_assert(buf[1] == 0x41);
  test_assert(buf[2] == 0x41);
  test_assert(buf[3] == 0x41);
  test_assert(buf[4] == 0x41);
  test_assert(buf[5] == 0x41);
  test_assert(buf[6] == 0x41);
  test_assert(buf[7] == 0x41);

  bin_set(buf, 8, 'A');
  bin_tolower(buf, 8);
  test_assert(buf[0] == 'a');
  test_assert(buf[1] == 'a');
  test_assert(buf[2] == 'a');
  test_assert(buf[3] == 'a');
  test_assert(buf[4] == 'a');
  test_assert(buf[5] == 'a');
  test_assert(buf[6] == 'a');
  test_assert(buf[7] == 'a');

  bin_toupper(buf, 8);
  test_assert(buf[0] == 'A');
  test_assert(buf[1] == 'A');
  test_assert(buf[2] == 'A');
  test_assert(buf[3] == 'A');
  test_assert(buf[4] == 'A');
  test_assert(buf[5] == 'A');
  test_assert(buf[6] == 'A');
  test_assert(buf[7] == 'A');

  return 0;
}
