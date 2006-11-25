#include "alloc.h"
#include "bin.h"
#include "dstring.h"

int dstring_catb(struct dstring *d, const char *str, unsigned long len)
{
  unsigned long da;
  unsigned long dlen;
  char *ds;
  char *s;

  da = d->a;
  dlen = d->len;
  ds = d->s;

  if ((dlen + len) < dlen) return 0; /* detect int overflow */

  if ((dlen + len) >= da) {
    unsigned long nal;
    nal = da + len + DSTRING_OVERALLOC;
    s = alloc(nal);
    if (!s) return 0;
    bin_copy(ds, s, dlen);
    da = nal;
    dealloc(ds);
    ds = s;
  }

  bin_copy(str, ds + dlen, len);
  dlen += len;
  ds[dlen] = 'X';

  d->a = da;
  d->len = dlen;
  d->s = ds;
  return 1;
}
