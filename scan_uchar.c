#include "scan.h"

unsigned int scan_uchar(const char *str, unsigned char *ul)
{
  return scan_ulong(str, (unsigned long *) ul);
}

