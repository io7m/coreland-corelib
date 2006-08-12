#include "bin.h"

void bin_tolower(void *v, unsigned long len)
{
  register char *s;
  register char x;

  s = (char *) v;
  for (;;) {
    x = *s; if (!len) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --len;
  }
}
