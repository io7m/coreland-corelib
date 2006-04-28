#include "str.h"

unsigned int str_copy(const char *s, char *d)
{
  register unsigned int n;
  for (n = 0;;) {
    if (!(*d = *s)) return n; ++s; ++d; ++n;
    if (!(*d = *s)) return n; ++s; ++d; ++n;
    if (!(*d = *s)) return n; ++s; ++d; ++n;
    if (!(*d = *s)) return n; ++s; ++d; ++n;
  }
}
