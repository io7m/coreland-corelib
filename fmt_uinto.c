#include "fmt.h"

unsigned int fmt_uinto(char *str, unsigned int uio)
{
  return fmt_ulongo(str, (unsigned long) uio);
}

