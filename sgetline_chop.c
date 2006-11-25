#include "sgetline.h"

void sgetline_trunc(struct sgetline *s)
{
  sgetline_chop(s, 0);
}

void sgetline_chop(struct sgetline *s, unsigned long len)
{
  if (!s->len) return;
  if (len >= s->len) len = s->len - 1;
  s->s[len] = 0;
  s->len = len;
}
