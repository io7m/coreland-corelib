#include "bin.h"

void bin_toupper(char *s, unsigned int l)
{
  register char x;
  for (;;) {
    x = *s; if (!l) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --l;
    x = *s; if (!l) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --l;
    x = *s; if (!l) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --l;
    x = *s; if (!l) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x; --l;
  }
}
