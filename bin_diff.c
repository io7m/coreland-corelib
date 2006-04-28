#include "bin.h"

/*
 returns -1 if strings don't differ
 returns index of differing chars otherwise
*/

int bin_diff(register const char *ac, 
             register const char *bc,
             unsigned int l)
{
  register unsigned int n;
  for (n = l;;) {
    if (!n--) return -1; if (*ac != *bc) break; ++ac; ++bc;
    if (!n--) return -1; if (*ac != *bc) break; ++ac; ++bc;
    if (!n--) return -1; if (*ac != *bc) break; ++ac; ++bc;
    if (!n--) return -1; if (*ac != *bc) break; ++ac; ++bc;
  }
  return (signed int)(l - n);
}

/*
 returns 1 if strings match
 returns 0 otherwise
*/

int bin_same(register const char *a, 
             register const char *b, 
             register unsigned int l)
{
  if (bin_diff(a, b, l) == -1)
    return 1;
  else
    return 0;
}
