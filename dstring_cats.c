#include "alloc.h"
#include "bin.h"
#include "dstring.h"
#include "str.h"

int dstring_cats(struct dstring *d, const char *s)
{
  return dstring_catb(d, s, str_len(s));
}
