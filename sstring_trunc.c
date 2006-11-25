#include "sstring.h"

void sstring_trunc(struct sstring *ss)
{
  register unsigned long n;
  register char* t;
  n = ss->a;
  t = ss->s;
  for (;;) {
    if (!n) break; *t++ = 0; --n;
    if (!n) break; *t++ = 0; --n;
    if (!n) break; *t++ = 0; --n;
    if (!n) break; *t++ = 0; --n;
  }
  ss->len = 0;
}
