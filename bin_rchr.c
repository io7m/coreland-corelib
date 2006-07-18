#include "bin.h"

int bin_rchr(register const char *s, unsigned long len, register int c)
{
  register const char *t;
  register const char *u;
  register char cc;
  int f = 0;
  for (t = s, cc = c, u = 0;;) {
    if (!len) break; if (*t == cc) { u = t; f = 1; } ++t; --len;
    if (!len) break; if (*t == cc) { u = t; f = 1; } ++t; --len;
    if (!len) break; if (*t == cc) { u = t; f = 1; } ++t; --len;
    if (!len) break; if (*t == cc) { u = t; f = 1; } ++t; --len;
  }
  if (f == 0) return -1;
  if (!u) u = t;
  return u - s;
}
