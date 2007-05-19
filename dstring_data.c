#include "dstring.h"

const char *dstring_data(const struct dstring *ds)
{
  return ds->s;
}
