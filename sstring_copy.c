#include "sstring.h"

unsigned long sstring_copy(sstring *ds, const sstring *ss)
{
  return sstring_cpyb(ds, ss->s, ss->a);
}
