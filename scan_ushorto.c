#include "scan.h"

unsigned int scan_ushorto(const char *s, unsigned short *up)
{
  unsigned long ul;
  unsigned short us;
  unsigned int len;

  len = scan_ulongo(s, &ul); us = (unsigned short) ul; *up = ul;
  return len;
}
