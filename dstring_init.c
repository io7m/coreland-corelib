#include "alloc.h"
#include "dstring.h"

int dstring_init(dstring *ds, unsigned int len)
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

void dstring_free(dstring *ds)
{
  dealloc(ds->s);
  ds->s = 0;
  ds->len = 0;
  ds->a = 0;
}
