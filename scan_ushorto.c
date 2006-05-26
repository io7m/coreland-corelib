#include "scan.h"

unsigned int scan_ushorto(const char *s, unsigned short *ul)
{
  return scan_ulongo(s, (unsigned long *) ul);
}

