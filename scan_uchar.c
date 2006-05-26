#include "scan.h"

unsigned int scan_uchar(const char *s, unsigned char *ul)
{
  return scan_ulong(s, (unsigned long *) ul);
}

