#include "sstring.h"

unsigned long sstring_cpys(register struct sstring *ss, const char *s)
{
  register const char* t;
  for (t = s;;) {
    if (!*t) return sstring_cpyb(ss, s, t-s); ++t;
    if (!*t) return sstring_cpyb(ss, s, t-s); ++t;
    if (!*t) return sstring_cpyb(ss, s, t-s); ++t;
    if (!*t) return sstring_cpyb(ss, s, t-s); ++t;
  }
}
