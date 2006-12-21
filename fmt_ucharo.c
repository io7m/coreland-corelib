#include "fmt.h"

unsigned int fmt_ucharo(char *str, unsigned char uio)
{
  return fmt_ulongo(str, (unsigned long) uio);
}
