#include "bin.h"

/*
 return number of chars c in buffer b of length len
 */

unsigned long bin_count(register const char *b, register unsigned long len,
                        register int c)
{
  register unsigned long n;
  for (n = 0;;) {
    if (!len--) return n; if (*b == c) ++n; ++b;
    if (!len--) return n; if (*b == c) ++n; ++b;
    if (!len--) return n; if (*b == c) ++n; ++b;
    if (!len--) return n; if (*b == c) ++n; ++b;
  }
}
