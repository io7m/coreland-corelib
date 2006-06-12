#include "dstring.h"

int dstring_copy(dstring *dd, const dstring *sd)
{
  return dstring_cpyb(dd, sd->s, sd->len);
}
