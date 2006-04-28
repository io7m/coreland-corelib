#include "sgetline.h"

void sgetline_trunc(sgetline *s)
{
  sgetline_chop(s, 0);
}

void sgetline_chop(sgetline *s, unsigned int len)
{
  if (!s->len) return;
  if (len >= s->len) len = s->len - 1;
  s->s[len] = 0;
  s->len = len;
}
