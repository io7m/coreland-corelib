#include "scan.h"

unsigned int scan_ushortx(const char *s, unsigned short *ul)
{
  return scan_ulongx(s, (unsigned long *) ul);
}

