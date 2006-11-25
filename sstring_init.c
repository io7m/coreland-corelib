#include "sstring.h"

void sstring_init(struct sstring *s, char *buf, unsigned long len)
{
  s->s = buf;
  s->a = len;
  s->len = 0;
}
