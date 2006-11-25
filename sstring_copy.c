#include "sstring.h"

unsigned long sstring_copy(struct sstring *ds, const struct sstring *ss)
{
  return sstring_cpyb(ds, ss->s, ss->a);
}
