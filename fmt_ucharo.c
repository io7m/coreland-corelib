#include "fmt.h"

unsigned int fmt_ucharo(char *s, unsigned char uio)
{
  return fmt_ulongo(s, (unsigned long) uio);
}

