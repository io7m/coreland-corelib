#include "fmt.h"

unsigned int fmt_uchar(char *s, unsigned char ui)
{
  return fmt_ulong(s, (unsigned long) ui);
}

