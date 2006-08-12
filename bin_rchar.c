#include "bin.h"

int bin_rchar(register const void *s, unsigned long len,
              register int ch, unsigned long *pos)
{
  register const char *tc;
  register const char *u;
  register char cc;
  int f;

  tc = (const char *) s;
  cc = (char) ch;
  f = 0;
  u = 0;

  for (;;) {
    if (!len) break; if (*tc == cc) { u = tc; f = 1; } ++tc; --len;
    if (!len) break; if (*tc == cc) { u = tc; f = 1; } ++tc; --len;
    if (!len) break; if (*tc == cc) { u = tc; f = 1; } ++tc; --len;
    if (!len) break; if (*tc == cc) { u = tc; f = 1; } ++tc; --len;
  }
  if (f == 0) return 0;
  if (!u) u = tc;
  *pos = u - (const char *) s;
  return 1;
}
