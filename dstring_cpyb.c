#include "alloc.h"
#include "bin.h"
#include "dstring.h"

int dstring_cpyb(struct dstring *d, const char *s, unsigned long len)
{
  unsigned long dlen;
  unsigned long da;
  unsigned long tmplen;
  char *ds;

  dlen = d->len;
  da = d->a;
  ds = d->s;

  if (len >= da) {
    tmplen = len + 1 + DSTRING_OVERALLOC;
    if (tmplen < len) return 0;
    if (!alloc_re((void **) &d->s, da, tmplen)) return 0;
    ds = d->s;
    da = tmplen;
  }

  bin_copy(s, ds, len);
  dlen = len;

  d->len = dlen;
  d->a = da;
  d->s = ds;
  return 1;
}
