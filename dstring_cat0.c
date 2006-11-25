#include "dstring.h"

int dstring_cat0(struct dstring *ds)
{
  return dstring_catb(ds, "\0", 1);
}
