#include "str.h"

int str_ndiff(const char *s, const char *t, unsigned int len)
{
  register char u;

  for (;;) {
    if (!len--) return 0; u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
    if (!len--) return 0; u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
    if (!len--) return 0; u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
    if (!len--) return 0; u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
  }

  return ((int)(unsigned int)(unsigned char) u)
       - ((int)(unsigned int)(unsigned char) *t);
}
