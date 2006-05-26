#include "fmt.h"

unsigned int fmt_nstr(char *s, const char *t, unsigned int n)
{
  unsigned int len;
  char c;

  len = 0;
  if (s)
    while (n-- && (c = t[len])) s[len++] = c;
  else
    while (n-- && t[len]) len++;

  return len;
}
