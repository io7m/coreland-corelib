#include <stdio.h>
#include "../scan.h"

int main()
{
  const char *a = "AAAABBBBCCCCDDDD    \nAAAA";
  const char *str;
  unsigned long num = 0;

  str = a;
  num = scan_charset(str, "AB");
  if (num != 8) {
    printf("fail: 1 scan_charset: %s num == %lu\n", str, num); return 1;
  }

  str += num;
  num = scan_charset(str, "D");
  if (num != 0) {
    printf("fail: 2 scan_charset: %s num == %lu\n", str, num); return 1;
  }

  num = scan_notcharset(str, "D");
  if (num != 4) {
    printf("fail: 3 scan_notcharset: %s num == %lu\n", str, num); return 1;
  }

  str += num;
  num = scan_notcharset(str, "D");
  if (num != 0) {
    printf("fail: 4 scan_notcharset: %s num == %lu\n", str, num); return 1;
  }

  num = scan_charset(str, "D");
  if (num != 4) {
    printf("fail: 5 scan_charset: %s num == %lu\n", str, num); return 1;
  }

  str += num;
  num = scan_whitespace(str);
  if (num != 4) {
    printf("fail: 6 scan_space: %s num == %lu\n", str, num); return 1;
  }

  str += num;
  num = scan_newline(str);
  if (num != 1) {
    printf("fail: 7 scan_newline: %s num == %lu\n", str, num); return 1;
  }

  /* will not cross 0 */

  str += num;
  num = scan_charset(str, "A");
  if (num != 4) {
    printf("fail: 8 scan_charset: %s num == %lu\n", str, num); return 1;
  }
  str += num;
  num = scan_charset(str, "A");
  if (num) {
    printf("fail: 9 scan_charset: %s num == %lu\n", str, num); return 1;
  }

  return 0;
}
