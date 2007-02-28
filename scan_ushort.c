#include "scan.h"

unsigned int scan_ushort(const char *s, unsigned short *up)
{
  unsigned long ul;
  unsigned short us;
  unsigned int len;

  len = scan_ulong(s, &ul); us = (unsigned short) ul; *up = ul;
  return len;
}
