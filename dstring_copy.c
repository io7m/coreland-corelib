#include "dstring.h"

int dstring_copy(struct dstring *dd, const struct dstring *sd)
{
  return dstring_cpyb(dd, sd->s, sd->len);
}
