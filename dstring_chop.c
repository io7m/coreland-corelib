#include "dstring.h"

void dstring_chop(dstring *d, unsigned int len)
{
  if (len >= d->len) return;
  d->s[len] = 0;
  d->len = len;
}
