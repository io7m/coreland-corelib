#include "bin.h"

void bin_copyr(register void *dv, register const void *sv,
               register unsigned long n)
{
  register const char *sc;
  register char *dc;

  sc = (const char *) sv;
  dc = (char *) dv;
  dc += n;
  sc += n;

  for (;;) {
    if (!n) return; *--dc = *--sc; --n;
  }
}
