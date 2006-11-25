#include "sstring.h"

/* concat s ss->s
   returns new length of string
 */

unsigned long sstring_catb(struct sstring *ss, const char *s, unsigned long len)
{
  register unsigned long n;
  register char* ssp;
  n = len; ssp = ss->s;
  
  if (ss->len == ss->a) return 0;
  if ((ss->len + n) > ss->a) n = ss->a - ss->len; /* refuse overflow */
  ssp += ss->len;
  for (;;) {
    if (!n) break; *ssp++ = *s++; --n;
    if (!n) break; *ssp++ = *s++; --n;
    if (!n) break; *ssp++ = *s++; --n;
    if (!n) break; *ssp++ = *s++; --n;
  }
  return ss->len = ssp - ss->s;
}
