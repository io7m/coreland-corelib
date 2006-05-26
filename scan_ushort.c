#include "scan.h"

unsigned int scan_ushort(const char *s, unsigned short *ul)
{
  return scan_ulong(s, (unsigned long *) ul);
}

