#include "str.h"

int str_rchar(register const char *s, register int c, unsigned long *pos)
{
  register const char *t;
  register const char *u;
  register char cc;
  int f = 0;
  for (t = s, cc = c, u = 0;;) {
    if (!*t) break; if (*t == cc) { u = t; f = 1; } ++t;
    if (!*t) break; if (*t == cc) { u = t; f = 1; } ++t;
    if (!*t) break; if (*t == cc) { u = t; f = 1; } ++t;
    if (!*t) break; if (*t == cc) { u = t; f = 1; } ++t;
  }
  if (f == 0) return 0;
  if (!u) u = t;
  *pos = u - s;
  return 1;
}
