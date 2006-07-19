#include "sstring.h"

unsigned long sstring_cat(sstring *ds, const sstring *ss)
{
  return sstring_catb(ds, ss->s, ss->len);
}
