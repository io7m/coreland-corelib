#include "sstring.h"

/* copies ss->len chars, doesn't care about 0x0.
   returns new length of string */

unsigned long sstring_cpyb(sstring *ss, register const char *cs,
                           unsigned long len)
{
  register unsigned long n;
  register char* ssp;
  ssp = ss->s;
  if (len >= ss->a) { len = ss->a; }
  for (n = len;;) {
    if (!n) return ss->len = len; *ssp = *cs; --n; ++ssp; ++cs;
    if (!n) return ss->len = len; *ssp = *cs; --n; ++ssp; ++cs;
    if (!n) return ss->len = len; *ssp = *cs; --n; ++ssp; ++cs;
    if (!n) return ss->len = len; *ssp = *cs; --n; ++ssp; ++cs;
  }
}
