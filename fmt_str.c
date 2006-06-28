#include "fmt.h"

unsigned long fmt_str(char *s, const char *t)
{
  unsigned long len;
  char c;

  len = 0;
  if (s)
    while ((c = t[len])) s[len++] = c;
  else
    while (t[len]) len++;

  return len;
}
