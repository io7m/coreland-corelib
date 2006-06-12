#include "dstring.h"

int dstring_cat(dstring *dd, const dstring *sd)
{
  return dstring_catb(dd, sd->s, sd->len);
}
