#include "scan.h"

unsigned int scan_chars(const char *s, const char *chars)
{
  uint32 n;
  const char *t;
  int c;
  if (!s) return 0;
  n = 0;
  for (;;) {
    c = s[n];
    if (!c) break;
    for (t = chars;;) {
      if (!*t) return n; if (*t == c) { ++n; break; } ++t;
      if (!*t) return n; if (*t == c) { ++n; break; } ++t;
      if (!*t) return n; if (*t == c) { ++n; break; } ++t;
      if (!*t) return n; if (*t == c) { ++n; break; } ++t;
    }
  }
  return n;
}
