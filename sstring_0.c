#include "sstring.h"

unsigned long sstring_0(sstring *ss)
{
  if (ss->len == ss->a) ss->len--;
  ss->s[ss->len] = 0; return ss->len;
}
