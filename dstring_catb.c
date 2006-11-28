#include "alloc.h"
#include "bin.h"
#include "dstring.h"

int dstring_catb(struct dstring *d, const char *str, unsigned long len)
{
  unsigned long da;
  unsigned long dlen;
  unsigned long na;
  char *ds;
  char *s;

  da = d->a;
  dlen = d->len;
  ds = d->s;

  if ((dlen + len) < dlen) return 0; /* detect int overflow */

  if ((dlen + len) >= da) {
    na = da + len + DSTRING_OVERALLOC;
    if (!alloc_re((void **) &d->s, da, na)) return 0;
    da = na;
    ds = d->s;
  }

  bin_copy(str, ds + dlen, len);
  dlen += len;
  ds[dlen] = 'X';

  d->a = da;
  d->len = dlen;
  d->s = ds;
  return 1;
}
