#include <stdio.h>
#include "../scan.h"
#include "t_assert.h"

int main(void)
{
  const char *a = "AAAABBBBCCCCDDDD    \nAAAA";
  const char *str;
  unsigned long num = 0;

  str = a;
  num = scan_charset(str, "AB");
  test_assert(num == 8);

  str += num;
  num = scan_charset(str, "D");
  test_assert(num == 0);

  num = scan_notcharset(str, "D");
  test_assert(num == 4);

  str += num;
  num = scan_notcharset(str, "D");
  test_assert(num == 0);

  num = scan_charset(str, "D");
  test_assert(num == 4);

  str += num;
  num = scan_whitespace(str);
  test_assert(num == 4);

  str += num;
  num = scan_newline(str);
  test_assert(num == 1);

  /* will not cross 0 */

  str += num;
  num = scan_charset(str, "A");
  test_assert(num == 4);

  str += num;
  num = scan_charset(str, "A");
  test_assert(num == 0);

  return 0;
}
