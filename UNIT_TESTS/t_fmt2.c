#include <stdio.h>
#include "../fmt.h"
#include "../str.h"

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
 
  if (!str_same(buf, exp)) {
    printf("fail: 1 buf == %s\n", buf);
    return 1;
  }

  printf("%s\n", buf);
  return 0;
}
