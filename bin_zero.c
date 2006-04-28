#include "bin.h"

void bin_zero(char *vc, unsigned int n)
{
  for (;;) {
    if (!n) return; *vc++ = 0; --n;
    if (!n) return; *vc++ = 0; --n;
    if (!n) return; *vc++ = 0; --n;
    if (!n) return; *vc++ = 0; --n;
  }
}
