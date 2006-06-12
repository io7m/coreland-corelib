#include "sstring.h"

unsigned int sstring_cat(sstring *ds, const sstring *ss)
{
  return sstring_catb(ds, ss->s, ss->len);
}
