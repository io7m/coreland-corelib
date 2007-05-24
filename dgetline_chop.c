#include "dgetline.h"

void dgetline_trunc(struct dgetline *s)
{
  dgetline_chop(s, 0);
}

void dgetline_chop(struct dgetline *s, unsigned long len)
{
  dstring_chop(&s->d, len);
}
