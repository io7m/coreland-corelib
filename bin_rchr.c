#include "bin.h"

long bin_rchr(register const void *s, unsigned long len, register int ch)
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
  if (f == 0) return -1;
  if (!u) u = tc;
  return u - (const char *) s;
}
