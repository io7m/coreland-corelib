#include "str.h"

void str_tolower(char *s)
{
  register char x;
  for (;;) {
    x = *s; if (!x) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x;
    x = *s; if (!x) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x;
    x = *s; if (!x) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x;
    x = *s; if (!x) return; if ((x >= 'A') && (x <= 'Z')) x += 32; *s++ = x;
  }
}
