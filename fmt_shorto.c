#include "fmt.h"

unsigned int fmt_ushorto(char *str, unsigned short uio)
{
  return fmt_ulongo(str, (unsigned long) uio);
}

