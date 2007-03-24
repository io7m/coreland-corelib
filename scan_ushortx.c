#include "scan.h"

unsigned int scan_ushortx(const char *s, unsigned short *up)
{
  unsigned long ul;
  unsigned short us;
  unsigned int len;

  len = scan_ulongx(s, &ul);
  if (!len) return 0;

  us = (unsigned short) ul; *up = us;
  return len;
}
