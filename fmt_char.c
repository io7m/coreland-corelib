#include "fmt.h"

unsigned int fmt_uchar(char *str, unsigned char ui)
{
  return fmt_ulong(str, (unsigned long) ui);
}
