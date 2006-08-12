#include "bin.h"

int bin_char(register const void *s, unsigned long len,
             register int ch, unsigned long *pos)
{
  register const char *tc;
  register const char *sc;
  register char cc;

  tc = (const char *) s;
  sc = tc;
  cc = (char) ch;

  for (;;) {
    if (!len) return 0; if (*tc == cc) { *pos = tc - sc; return 1; } ++tc; --len;
  }
}
