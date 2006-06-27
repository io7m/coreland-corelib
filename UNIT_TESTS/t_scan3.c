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
    printf("1 scan_charset: %s num == %u\n", str, num); return 1;
  }

  str += num;
  num = scan_charset(str, "D");
  if (num != 0) {
    printf("2 scan_charset: %s num == %u\n", str, num); return 1;
  }

  num = scan_notcharset(str, "D");
  if (num != 4) {
    printf("3 scan_notcharset: %s num == %u\n", str, num); return 1;
  }

  str += num;
  num = scan_notcharset(str, "D");
  if (num != 0) {
    printf("4 scan_notcharset: %s num == %u\n", str, num); return 1;
  }

  num = scan_charset(str, "D");
  if (num != 4) {
    printf("5 scan_charset: %s num == %u\n", str, num); return 1;
  }

  str += num;
  num = scan_whitespace(str);
  if (num != 4) {
    printf("5 scan_space: %s num == %u\n", str, num); return 1;
  }

  str += num;
  num = scan_newline(str);
  if (num != 1) {
    printf("5 scan_newline: %s num == %u\n", str, num); return 1;
  }

  /* will not cross 0 */

  str += num;
  num = scan_charset(str, "A");
  if (num != 4) {
    printf("5 scan_charset: %s num == %u\n", str, num); return 1;
  }
  str += num;
  num = scan_charset(str, "A");
  if (num) {
    printf("5 scan_charset: %s num == %u\n", str, num); return 1;
  }

  return 0;
}
