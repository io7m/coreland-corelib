#include "bin.h"

int bin_chr(register const char *s, unsigned long len, register int c)
{
  register const char *t;
  register char cc;
  for (t = s, cc = (char) c;;) {
    if (!len) return -1; if (*t == cc) return t - s; ++t; --len;
    if (!len) return -1; if (*t == cc) return t - s; ++t; --len;
    if (!len) return -1; if (*t == cc) return t - s; ++t; --len;
    if (!len) return -1; if (*t == cc) return t - s; ++t; --len;
  }
}
