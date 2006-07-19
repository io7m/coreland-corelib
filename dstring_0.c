#include "dstring.h"

unsigned long dstring_0(dstring *ds)
{
  if (ds->len == ds->a) --ds->len;
  ds->s[ds->len] = 0;
  return ds->len;
}
