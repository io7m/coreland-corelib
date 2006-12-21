#include "fmt.h"

unsigned long fmt_nstr(char *str, const char *t, unsigned long num)
{
  unsigned long len;
  char ch;

  len = 0;
  if (str)
    while (num-- && (ch = t[len])) str[len++] = ch;
  else
    while (num-- && t[len]) len++;

  return len;
}
