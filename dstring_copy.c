#include "dstring.h"

int dstring_copy(const dstring *a, dstring *b)
{
  return dstring_cpyb(b, a->s, a->len);
}
