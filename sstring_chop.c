#include "sstring.h"

unsigned long sstring_chop(struct sstring *s, unsigned long len)
{
  char *str;

  if (len >= s->a) return s->a;

  str = s->s;
  str[len] = 0;
  s->len = len;
  return len;
}
