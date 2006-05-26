#include "scan.h"

unsigned int scan_notcharset(const char *s, const char *chars)
{
  unsigned int len;
  const char *cmp;
  char ch;

  len = 0;
  for (;;) {
    ch = s[len];
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
