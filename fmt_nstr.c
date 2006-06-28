#include "fmt.h"

unsigned long fmt_nstr(char *s, const char *t, unsigned long n)
{
  unsigned long len;
  char c;

  len = 0;
  if (s)
    while (n-- && (c = t[len])) s[len++] = c;
  else
    while (n-- && t[len]) len++;

  return len;
}
