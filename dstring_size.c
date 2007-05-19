#include "dstring.h"

unsigned long dstring_size(const struct dstring *ds)
{
  return ds->len;
}
