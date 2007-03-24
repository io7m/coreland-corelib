#include "scan.h"

unsigned int scan_ushort(const char *s, unsigned short *up)
{
  unsigned long ul;
  unsigned short us;
  unsigned int len;

  len = scan_ulong(s, &ul);
  if (!len) return 0;

  us = (unsigned short) ul; *up = us;
  return len;
}
