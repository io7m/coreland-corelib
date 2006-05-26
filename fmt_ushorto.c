#include "fmt.h"

unsigned int fmt_ushorto(char *s, unsigned short uio)
{
  return fmt_ulongo(s, (unsigned long) uio);
}

