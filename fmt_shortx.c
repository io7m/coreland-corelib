#include "fmt.h"

unsigned int fmt_ushortx(char *str, unsigned short uix)
{
  return fmt_ulongx(str, (unsigned long) uix);
}

