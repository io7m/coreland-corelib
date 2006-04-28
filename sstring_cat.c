#include "sstring.h"

unsigned int sstring_cat(const sstring *s, sstring *d)
{
  return sstring_catb(d, s->s, s->len);
}
