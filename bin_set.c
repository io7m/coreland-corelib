#include "bin.h"

void bin_set(char *vc, unsigned long n, int c)
{
  for (;;) {
    if (!n) return; *vc++ = c; --n;
    if (!n) return; *vc++ = c; --n;
    if (!n) return; *vc++ = c; --n;
    if (!n) return; *vc++ = c; --n;
  }
}
