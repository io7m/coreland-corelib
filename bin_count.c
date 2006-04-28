#include "bin.h"

/*
 return number of chars c in buffer b of length l
 */

unsigned int bin_count(register const char *b, register unsigned int l,
                       register int c)
{
  register unsigned int n;
  for (n = 0;;) {
    if (!l--) return n; if (*b == c) ++n; ++b;
    if (!l--) return n; if (*b == c) ++n; ++b;
    if (!l--) return n; if (*b == c) ++n; ++b;
    if (!l--) return n; if (*b == c) ++n; ++b;
  }
}
