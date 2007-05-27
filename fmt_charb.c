#include "fmt.h"

unsigned int fmt_ucharb(char *str, unsigned char uib)
{
  return fmt_ulongb(str, (unsigned long) uib);
}
