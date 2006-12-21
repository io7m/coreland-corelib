#include "scan.h"

unsigned long scan_notcharset(const char *str, const char *chars)
{
  unsigned long len;
  const char *cmp;
  char ch;

  len = 0;
  for (;;) {
    ch = str[len];
    if (!ch) break;
    for (cmp = chars;;) {
      if (!*cmp) break; if (*cmp == ch) return len; ++cmp;
      if (!*cmp) break; if (*cmp == ch) return len; ++cmp;
      if (!*cmp) break; if (*cmp == ch) return len; ++cmp;
      if (!*cmp) break; if (*cmp == ch) return len; ++cmp;
    }
    ++len;
  }

  return len;
}
