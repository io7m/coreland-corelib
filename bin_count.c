#include "bin.h"

unsigned long bin_count(register const void *b, register unsigned long len,
                        register int c)
{
  register const char *bc;
  register unsigned long n;

  bc = (const char *) b;
  for (n = 0;;) {
    if (!len--) return n; if (*bc == c) ++n; ++bc;
    if (!len--) return n; if (*bc == c) ++n; ++bc;
    if (!len--) return n; if (*bc == c) ++n; ++bc;
    if (!len--) return n; if (*bc == c) ++n; ++bc;
  }
}
