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
  i = str_nsame(s, x, 8);
  if (i != 1) { printf("(str_dup) str_nsame: i == %d\n", i); return 1; }

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

  return 0;
}
