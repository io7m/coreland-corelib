#include "dstring.h"

void dstring_trunc(dstring *d)
{
  dstring_chop(d, 0);
}
