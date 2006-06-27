#include "bin.h"

void bin_tolower(char *s, unsigned long len)
{
  register char x;
  for (;;) {
    x = *s; if (!len) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --len;
  }
}
