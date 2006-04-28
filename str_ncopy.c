#include "str.h"

/*
 returns number of bytes copied
 */

unsigned int str_ncopy(register const char *s, 
                       register char *d, 
                       register unsigned int l)
{
  register unsigned int n;
  for (n = 0;;) {
    if (!(*d = *s) || (!l)) return n; ++d; ++s; --l; ++n;
    if (!(*d = *s) || (!l)) return n; ++d; ++s; --l; ++n;
    if (!(*d = *s) || (!l)) return n; ++d; ++s; --l; ++n;
    if (!(*d = *s) || (!l)) return n; ++d; ++s; --l; ++n;
  }
}
