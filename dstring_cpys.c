#include "dstring.h"
#include "str.h"

int dstring_cpys(struct dstring *ds, const char *s)
{
  return dstring_cpyb(ds, s, str_len(s));
}
