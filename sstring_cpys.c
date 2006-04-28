#include "sstring.h"

unsigned int sstring_cpys(register sstring *ss, const char *s)
{
  register const char* t;
  for (t = s;;) {
    if (!*t) return sstring_cpyb(ss, s, t-s); ++t;
    if (!*t) return sstring_cpyb(ss, s, t-s); ++t;
    if (!*t) return sstring_cpyb(ss, s, t-s); ++t;
    if (!*t) return sstring_cpyb(ss, s, t-s); ++t;
  }
}
