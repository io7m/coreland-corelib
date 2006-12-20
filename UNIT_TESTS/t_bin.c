#include "../bin.h"
#include <stdio.h>

int main()
{
  const char *s = "ABCD1234EFGHXXXX";
  char buf[8];
  long i;
  unsigned long pos;

  i = bin_chr(s, 16, 'D');
  if (i != 3) { printf("fail: bin_chr: i == %ld\n", i); return 1; }

  i = bin_char(s, 16, 'D', &pos);
  if (i != 1) { printf("fail: bin_char: i == %ld\n", i); return 1; }
  if (pos != 3) { printf("fail: bin_char: pos == %ld\n", pos); return 1; }

  bin_copy(s, buf, 8);
  if (buf[0] != 'A') { printf("fail: bin_copy: buf[0] == %c\n", buf[0]); return 1; }
  if (buf[1] != 'B') { printf("fail: bin_copy: buf[1] == %c\n", buf[1]); return 1; }
  if (buf[2] != 'C') { printf("fail: bin_copy: buf[2] == %c\n", buf[2]); return 1; }
  if (buf[3] != 'D') { printf("fail: bin_copy: buf[3] == %c\n", buf[3]); return 1; }
  if (buf[4] != '1') { printf("fail: bin_copy: buf[4] == %c\n", buf[4]); return 1; }
  if (buf[5] != '2') { printf("fail: bin_copy: buf[5] == %c\n", buf[5]); return 1; }
  if (buf[6] != '3') { printf("fail: bin_copy: buf[6] == %c\n", buf[6]); return 1; }
  if (buf[7] != '4') { printf("fail: bin_copy: buf[7] == %c\n", buf[7]); return 1; }

  bin_zero(buf, 8);
  if (buf[0] != 0) { printf("fail: bin_zero: buf[0] == %c\n", buf[0]); return 1; }

  bin_copyr(buf, s, 8);
  if (buf[0] != 'A') { printf("fail: bin_copyr: buf[0] == %c\n", buf[0]); return 1; }
  if (buf[1] != 'B') { printf("fail: bin_copyr: buf[1] == %c\n", buf[1]); return 1; }
  if (buf[2] != 'C') { printf("fail: bin_copyr: buf[2] == %c\n", buf[2]); return 1; }
  if (buf[3] != 'D') { printf("fail: bin_copyr: buf[3] == %c\n", buf[3]); return 1; }
  if (buf[4] != '1') { printf("fail: bin_copyr: buf[4] == %c\n", buf[4]); return 1; }
  if (buf[5] != '2') { printf("fail: bin_copyr: buf[5] == %c\n", buf[5]); return 1; }
  if (buf[6] != '3') { printf("fail: bin_copyr: buf[6] == %c\n", buf[6]); return 1; }
  if (buf[7] != '4') { printf("fail: bin_copyr: buf[7] == %c\n", buf[7]); return 1; }

  i = bin_count(s, 16, 'X');
  if (i != 4) { printf("fail: bin_count: i == %ld\n", i); return 1; }

  i = bin_diff(s + 4, buf, 8);
  if (i != -16) { printf("fail: bin_diff: i == %ld\n", i); return 1; }

  i = bin_same(s, buf, 8);
  if (i != 1) { printf("fail: bin_same: i == %ld\n", i); return 1; }

  i = bin_rchr(s, 16, 'X');
  if (i != 15) { printf("fail: bin_rchr: i == %ld\n", i); return 1; }

  i = bin_rchar(s, 16, 'X', &pos);
  if (i != 1) { printf("fail: bin_rchar: i == %ld\n", i); return 1; }
  if (pos != 15) { printf("fail: bin_rchar: pos == %ld\n", pos); return 1; } 

  bin_set(buf, 8, 0x41);
  if (buf[0] != 0x41) { printf("fail: bin_set: buf[0] == %c\n", buf[0]); return 1; }

  bin_set(buf, 8, 'A');
  bin_tolower(buf, 8);
  if (buf[0] != 'a') { printf("fail: bin_tolower: buf[0] == %c\n", buf[0]); return 1; }
  bin_toupper(buf, 8);
  if (buf[0] != 'A') { printf("fail: bin_tolower: buf[0] == %c\n", buf[0]); return 1; }

  return 0;
}
