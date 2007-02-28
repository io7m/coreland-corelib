#include "scan.h"

unsigned int scan_ushortx(const char *s, unsigned short *up)
{
  unsigned long ul;
  unsigned short us;
  unsigned int len;

  len = scan_ulongx(s, &ul); us = (unsigned short) ul; *up = ul;
  return len;
}
