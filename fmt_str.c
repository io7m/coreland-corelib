#include "fmt.h"

unsigned long fmt_str(char *str, const char *t)
{
  unsigned long len;
  char ch;

  len = 0;
  if (str)
    while ((ch = t[len])) str[len++] = ch;
  else
    while (t[len]) len++;

  return len;
}
