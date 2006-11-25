#include "dstring.h"

int dstring_cat(struct dstring *dd, const struct dstring *sd)
{
  return dstring_catb(dd, sd->s, sd->len);
}
