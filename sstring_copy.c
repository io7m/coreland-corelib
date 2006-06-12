#include "sstring.h"

unsigned int sstring_copy(sstring *ds, const sstring *ss)
{
  return sstring_cpyb(ds, ss->s, ss->a);
}
