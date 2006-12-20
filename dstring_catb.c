#include "alloc.h"
#include "bin.h"
#include "dstring.h"

int dstring_catb(struct dstring *d, const char *str, unsigned long len)
{
  unsigned long da;
  unsigned long dlen;
  unsigned long tmplen;
  unsigned long tmpadd;
  char *ds;

  da = d->a;
  dlen = d->len;
  ds = d->s;

  tmplen = dlen + len;
  if (tmplen < dlen) return 0; /* check overflow */

  if (tmplen >= da) {
    tmpadd = len + DSTRING_OVERALLOC;
    if (tmpadd < len) return 0; /* check overflow */
    tmplen = da + tmpadd;
    if (tmplen < da) return 0; /* check overflow */
    if (!alloc_re((void **) &d->s, da, tmplen)) return 0;
    da = tmplen;
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
