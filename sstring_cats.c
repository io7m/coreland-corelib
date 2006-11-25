#include "sstring.h"

unsigned long sstring_cats(struct sstring *ss, const char *s)
{
  register const char* t;
  for (t = s;;) {
    if (!*t) return sstring_catb(ss, s, t-s); ++t;
    if (!*t) return sstring_catb(ss, s, t-s); ++t;
    if (!*t) return sstring_catb(ss, s, t-s); ++t;
    if (!*t) return sstring_catb(ss, s, t-s); ++t;
  }
}
