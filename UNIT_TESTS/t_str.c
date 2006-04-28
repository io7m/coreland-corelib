#include "../error.h"
#include "../str.h"
#include <stdio.h>

int main()
{
  const char *s = "ABCD1234EFGHXXXX";
  const char *t = "ABCD1234EFGHXXXX";
  char *x;
  int i;

  i = str_chr(s, 'D');
  if (i != 3) { printf("str_chr: i == %d\n", i); return 1; }

  i = str_diff(s, t);
  if (i != 0) { printf("str_diff: i == %d\n", i); return 1; }

  i = str_same(s, t);
  if (i != 1) { printf("str_same: i == %d\n", i); return 1; }

  i = str_rchr(s, 'X');
  if (i != 15) { printf("str_rchr: i == %d\n", i); return 1; }

  if (!str_dup(s, &x)) {
    perror("str_dup");
    return 2;
  } 

  i = str_same(s, x);
  if (i != 1) { printf("(str_dup) str_same: i == %d\n", i); return 1; }

  i = str_starts(s, "ABCD");
  if (i != 1) { printf("(1) str_starts: i == %d\n", i); return 1; }
  i = str_starts(s, "XYZA");
  if (i != 0) { printf("(2) str_starts: i == %d\n", i); return 1; }
  i = str_starts(s, "1234EFGH1234EFGH1234EFGH");
  if (i != 0) { printf("(3) str_starts: i == %d\n", i); return 1; }

  i = str_ends(s, "XXXX");
  if (i != 1) { printf("(1) str_ends: i == %d\n", i); return 1; }
  i = str_ends(s, "ABCD");
  if (i != 0) { printf("(2) str_ends: i == %d\n", i); return 1; }
  i = str_ends(s, "GH1234EFGH123GH1234EFGH123");
  if (i != 0) { printf("(3) str_ends: i == %d\n", i); return 1; }

  i = str_len(s);
  if (i != 16) { printf("str_len: i == %d\n", i); return 1; }
  
  str_toupper(x);
  if (x[0] != 'A') { printf("str_toupper: x[0] == %c\n", x[0]); return 1; }
  str_tolower(x);
  if (x[0] != 'a') { printf("str_tolower: x[0] == %c\n", x[0]); return 1; }

  i = str_ncopy(s, x, str_len(s));
  if (x[0] != s[0]) { printf("str_ncopy: x[0] == %c\n", x[0]); return 1; }
  if (x[1] != s[1]) { printf("str_ncopy: x[1] == %c\n", x[1]); return 1; }
  if (x[2] != s[2]) { printf("str_ncopy: x[2] == %c\n", x[2]); return 1; }
  if (x[3] != s[3]) { printf("str_ncopy: x[3] == %c\n", x[3]); return 1; }
  if (x[4] != s[4]) { printf("str_ncopy: x[4] == %c\n", x[4]); return 1; }
  if (x[5] != s[5]) { printf("str_ncopy: x[5] == %c\n", x[5]); return 1; }
  if (x[6] != s[6]) { printf("str_ncopy: x[6] == %c\n", x[6]); return 1; }
  if (x[7] != s[7]) { printf("str_ncopy: x[7] == %c\n", x[7]); return 1; }
  if (x[9] != s[9]) { printf("str_ncopy: x[9] == %c\n", x[9]); return 1; }
  if (x[10] != s[10]) { printf("str_ncopy: x[10] == %c\n", x[10]); return 1; }
  if (x[11] != s[11]) { printf("str_ncopy: x[11] == %c\n", x[11]); return 1; }
  if (x[12] != s[12]) { printf("str_ncopy: x[12] == %c\n", x[12]); return 1; }
  if (x[13] != s[13]) { printf("str_ncopy: x[13] == %c\n", x[13]); return 1; }
  if (x[14] != s[14]) { printf("str_ncopy: x[14] == %c\n", x[14]); return 1; }
  if (x[15] != s[15]) { printf("str_ncopy: x[15] == %c\n", x[15]); return 1; }

  return 0;
}
