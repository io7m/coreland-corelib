#include <stdio.h>
#include "../fmt.h"
#include "../str.h"
#include "t_assert.h"

static char buf[32];
static const char *exp = "100 multiplied by 256 is 25600.";

int main(void)
{
  char *str;

  str = buf;
  str += fmt_uint(str, 100);
  str += fmt_nstr(str, " multiplied by ", 15);
  str += fmt_uint(str, 256);
  str += fmt_str(str, " is ");
  str += fmt_uint(str, 256 * 100);
  str += fmt_str(str, ".");
  *str = 0;
 
  test_assert(str_same(buf, exp));
  return 0;
}
