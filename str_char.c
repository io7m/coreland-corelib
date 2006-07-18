#include "str.h"

int str_char(register const char *s, register int ch, unsigned long *pos)
{
  register const char* t;
  register char cc;
  for (t = s, cc = ch;;) {
    if (!*t) return 0; if (*t == cc) { *pos = t - s; return 1; } ++t;
    if (!*t) return 0; if (*t == cc) { *pos = t - s; return 1; } ++t;
    if (!*t) return 0; if (*t == cc) { *pos = t - s; return 1; } ++t;
    if (!*t) return 0; if (*t == cc) { *pos = t - s; return 1; } ++t;
  }
}
