#include "sstring.h"

void sstring_init(sstring *s, char *buf, unsigned int len)
{
  s->s = buf;
  s->a = len;
  s->len = 0;
}
