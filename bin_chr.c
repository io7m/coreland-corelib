#include "bin.h"

/*
 returns index of first occuring c or -1
 */

int bin_chr(register const char *s, unsigned int l, register int c)
{
  register const char *t;
  register char cc;
  for (t = s, cc = (char) c;;) {
    if (!l) return -1; if (*t == cc) return t-s; ++t; --l;
    if (!l) return -1; if (*t == cc) return t-s; ++t; --l;
    if (!l) return -1; if (*t == cc) return t-s; ++t; --l;
    if (!l) return -1; if (*t == cc) return t-s; ++t; --l;
  }
}
