#include "sstring.h"

unsigned long sstring_cat(struct sstring *ds, const struct sstring *ss)
{
  return sstring_catb(ds, ss->s, ss->len);
}
