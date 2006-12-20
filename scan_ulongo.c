#include "scan.h"

unsigned int scan_ulongo(const char *str, unsigned long *ul)
{
  const char *ptr;
  unsigned long num;
  char ch;

  ptr = str;
  num = 0;
  for (;;) {
    ch = *ptr;
    if (!ch) break;
    if (ch >= '0' && ch < '8') {
      ch -= '0';
      num = (num * 8) + ch; ++ptr;
    } else break;
  }
  *ul = num;
  return ptr - str;
}

