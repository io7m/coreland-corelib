#include "scan.h"

unsigned long scan_charsetn(const char *str, const char *chars, unsigned long n)
{
  unsigned long len;
  const char *cmp;
  char ch;

  len = 0;
  for (;;) {
    ch = str[len];
    if (!ch) break;
    if (!n) break;
    for (cmp = chars;;) {
      if (!*cmp) return len; if (*cmp == ch) { ++len; break; } ++cmp;
      if (!*cmp) return len; if (*cmp == ch) { ++len; break; } ++cmp;
      if (!*cmp) return len; if (*cmp == ch) { ++len; break; } ++cmp;
      if (!*cmp) return len; if (*cmp == ch) { ++len; break; } ++cmp;
    }
    --n;
  }
  return len;
}
