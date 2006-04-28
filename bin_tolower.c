#include "bin.h"

void bin_tolower(char *s, unsigned int l)
{
  register char x;
  for (;;) {
    x = *s; if (!l) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --l;
    x = *s; if (!l) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --l;
    x = *s; if (!l) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --l;
    x = *s; if (!l) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x; --l;
  }
}
