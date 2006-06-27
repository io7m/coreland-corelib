#include "bin.h"

/*
 returns -1 if strings don't differ
 returns index of differing chars otherwise
*/

int bin_diff(register const char *ac, 
             register const char *bc,
             unsigned long len)
{
  register unsigned long n;
  for (n = len;;) {
    if (!n--) return -1; if (*ac != *bc) break; ++ac; ++bc;
    if (!n--) return -1; if (*ac != *bc) break; ++ac; ++bc;
    if (!n--) return -1; if (*ac != *bc) break; ++ac; ++bc;
    if (!n--) return -1; if (*ac != *bc) break; ++ac; ++bc;
  }
  return (signed int)(len - n);
}

int bin_same(register const char *a, 
             register const char *b, 
             register unsigned long len)
{
  return bin_diff(a, b, len) == -1;
}
