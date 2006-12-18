#include "fmt.h"

unsigned int fmt_ucharb(char *s, unsigned char uib)
{
  return fmt_ulongb(s, (unsigned long) uib);
}
