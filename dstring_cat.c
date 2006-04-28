#include "dstring.h"

int dstring_cat(const dstring *sd, dstring *dd)
{
  return dstring_catb(dd, sd->s, sd->len);
}
