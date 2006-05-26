#include "fmt.h"

unsigned int fmt_str(char *s, const char *t)
{
  unsigned int len;
  char c;

  len = 0;
  if (s)
    while ((c = t[len])) s[len++] = c;
  else
    while (t[len]) len++;

  return len;
}
