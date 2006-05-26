#include "scan.h"

unsigned int scan_ushort(const char *s, unsigned short *ul)
{
  return scan_ulong(s, (unsigned long *) ul);
}

unsigned int scan_ushortx(const char *s, unsigned short *ul)
{
  return scan_ulongx(s, (unsigned long *) ul);
}

unsigned int scan_ushorto(const char *s, unsigned short *ul)
{
  return scan_ulongo(s, (unsigned long *) ul);
}
