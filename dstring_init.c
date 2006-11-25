#include "alloc.h"
#include "dstring.h"

int dstring_init(struct dstring *ds, unsigned long len)
{
  char *s;

  if (!len) return 0;

  s = alloc(len + DSTRING_OVERALLOC);
  if (!s) return 0;

  ds->s = s;
  ds->len = 0;
  ds->a = len + DSTRING_OVERALLOC;
  return 1;
}

void dstring_free(struct dstring *ds)
{
  dealloc(ds->s);
  ds->s = 0;
  ds->len = 0;
  ds->a = 0;
}
