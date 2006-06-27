#include "scan.h"

unsigned long scan_charset(const char *s, const char *chars)
{
  unsigned long len;
  const char *cmp;
  char ch;

  len = 0;
  for (;;) {
    ch = s[len];
    if (!ch) break;
    for (cmp = chars;;) {
      if (!*cmp) return len; if (*cmp == ch) { ++len; break; } ++cmp;
      if (!*cmp) return len; if (*cmp == ch) { ++len; break; } ++cmp;
      if (!*cmp) return len; if (*cmp == ch) { ++len; break; } ++cmp;
      if (!*cmp) return len; if (*cmp == ch) { ++len; break; } ++cmp;
    }
  }
  return len;
}
