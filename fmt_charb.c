#include "fmt.h"

unsigned int fmt_ucharb(char *str, unsigned char ucb)
{
  return fmt_ulongb(str, (unsigned long) ucb);
}

unsigned int fmt_charb(char *str, char cb)
{
  return fmt_longb(str, (long) cb);
}
