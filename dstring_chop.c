#include "dstring.h"

void dstring_chop(struct dstring *d, unsigned long len)
{
  if (len >= d->len) return;
  d->s[len] = 0;
  d->len = len;
}
