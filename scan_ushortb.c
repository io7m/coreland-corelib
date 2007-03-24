#include "scan.h"

unsigned int scan_ushortb(const char *s, unsigned short *up)
{
  unsigned long ul;
  unsigned short us;
  unsigned int len;

  len = scan_ulongb(s, &ul);
  if (!len) return 0;

  us = (unsigned short) ul; *up = us;
  return len;
}
