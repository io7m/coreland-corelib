#include "str.h"

int str_ndiff(const char *s, const char *t, unsigned long len)
{
  register char u;

  for (;;) {
    if (!len--) return 0; u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
    if (!len--) return 0; u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
    if (!len--) return 0; u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
    if (!len--) return 0; u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
  }

  return ((int)(unsigned long)(unsigned char) u)
       - ((int)(unsigned long)(unsigned char) *t);
}
