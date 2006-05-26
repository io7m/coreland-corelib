#include "fmt.h"

unsigned int fmt_ushortx(char *s, unsigned short uix)
{
  return fmt_ulongx(s, (unsigned long) uix);
}

