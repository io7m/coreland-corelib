#include "bin.h"

void bin_toupper(void *v, unsigned long len)
{
  register char *s;
  register char x;

  s = (char *) v;
  for (;;) {
    x = *s; if (!len) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --len;
    x = *s; if (!len) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --len;
  }
}
