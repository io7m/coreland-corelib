#include "bin.h"

/*
 returns index of last occuring c or -1 if none
 */

int bin_rchr(register const char *s, unsigned int l, register int c)
{
  register const char *t;
  register const char *u;
  register char cc;
  int f = 0;
  for (t = s, cc = c, u = 0;;) {
    if (!l) break; if (*t == cc) { u = t; f = 1; } ++t; --l;
    if (!l) break; if (*t == cc) { u = t; f = 1; } ++t; --l;
    if (!l) break; if (*t == cc) { u = t; f = 1; } ++t; --l;
    if (!l) break; if (*t == cc) { u = t; f = 1; } ++t; --l;
  }
  if (f == 0) return -1;
  if (!u) u = t;
  return u - s;
}
