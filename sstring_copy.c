#include "sstring.h"

unsigned int sstring_copy(const sstring *s, sstring *d)
{
  return sstring_cpyb(d, s->s, s->a);
}
