#include "bin.h"

void bin_set(void *bv, unsigned long n, int c)
{
  register char *bc;
  bc = (char *) bv;
  for (;;) {
    if (!n) return; *bc++ = c; --n;
    if (!n) return; *bc++ = c; --n;
    if (!n) return; *bc++ = c; --n;
    if (!n) return; *bc++ = c; --n;
  }
}
