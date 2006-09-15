#include "str.h"

int str_casei_ndiff(const char *s, const char *t, unsigned long len)
{
  register char sc;
  register char tc;

  for (;;) {
    if (!len--) return 0;
    sc = *s;
    tc = *t;
    if ((sc >= 'A') && (sc <= 'Z')) sc += 32;
    if ((tc >= 'A') && (tc <= 'Z')) tc += 32;
    if (sc != tc) break;
    if (!sc) break;
    ++s;
    ++t;
  }
  return ((int)(unsigned long)(unsigned char) sc)
       - ((int)(unsigned long)(unsigned char) tc);
}
