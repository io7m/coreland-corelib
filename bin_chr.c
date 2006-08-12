#include "bin.h"

long bin_chr(register const void *s, unsigned long len, register int ch)
{
  register const char *tc;
  register const char *sc;
  register char cc;

  tc = (const char *) s;
  sc = tc;
  cc = (char) ch;

  for (;;) {
    if (!len) return -1; if (*tc == cc) return tc - sc; ++tc; --len;
    if (!len) return -1; if (*tc == cc) return tc - sc; ++tc; --len;
    if (!len) return -1; if (*tc == cc) return tc - sc; ++tc; --len;
    if (!len) return -1; if (*tc == cc) return tc - sc; ++tc; --len;
  }
}
