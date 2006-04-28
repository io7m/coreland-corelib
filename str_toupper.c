#include "str.h"

void str_toupper(char *s)
{
  register char x;
  for (;;) {
    x = *s; if (!x) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x;
    x = *s; if (!x) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x;
    x = *s; if (!x) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x;
    x = *s; if (!x) return; if ((x >= 'a') && (x <= 'z')) x -= 32; *s++ = x;
  }
}
