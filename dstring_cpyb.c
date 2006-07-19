#include "alloc.h"
#include "bin.h"
#include "dstring.h"

int dstring_cpyb(dstring *d, const char *s, unsigned long len)
{
  unsigned long dlen;
  unsigned long da;
  char *ds;

  dlen = d->len;
  da = d->a;
  ds = d->s;

  if (len >= da) {
    unsigned long nal;
    char *ns;
    nal = len + DSTRING_OVERALLOC;
    ns = alloc(nal);
    if (!ns) return 0;
    dealloc(ds);
    ds = ns;
    da = nal;
  }

  bin_copy(s, ds, len);
  dlen = len;

  d->len = dlen;
  d->a = da;
  d->s = ds;
  return 1;
}
