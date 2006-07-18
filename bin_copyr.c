#include "bin.h"

void bin_copyr(register char *to, register const char *from,
               register unsigned long n)
{
  to += n;
  from += n;
  for (;;) {
    if (!n) return; *--to = *--from; --n;
    if (!n) return; *--to = *--from; --n;
    if (!n) return; *--to = *--from; --n;
    if (!n) return; *--to = *--from; --n;
  }
}
