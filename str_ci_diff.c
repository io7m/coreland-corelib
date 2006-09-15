#include "str.h"

int str_casei_diff(register const char *s, 
                   register const char *t)
{
  register char sc;
  register char tc;

  for (;;) {
    sc = *s;
    tc = *t;
    if ((sc >= 'A') && (sc <= 'Z')) sc += 32;
    if ((tc >= 'A') && (tc <= 'Z')) tc += 32;
    if (sc != tc) break;
    if (!sc) break;
    ++s;
    ++t;
  }
  return ((int)(unsigned int)(unsigned char) sc) - 
         ((int)(unsigned int)(unsigned char) tc);
}
