#include "bin.h"

void bin_toupper(char *s, unsigned long len)
{
  register char x;
  for (;;) {
    x = *s; if (!len) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --len;
  }
}
