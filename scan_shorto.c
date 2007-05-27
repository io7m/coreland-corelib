#include "scan.h"

unsigned int scan_ushorto(const char *s, unsigned short *up)
{
  unsigned long ul;
  unsigned short us;
  unsigned int len;

  len = scan_ulongo(s, &ul);
  if (!len) return 0;

  us = (unsigned short) ul; *up = us;
  return len;
}

unsigned int scan_shorto(const char *s, short *p)
{
  long lo;
  unsigned int len;
  short num;

  len = scan_longo(s, &lo);
  if (!len) return 0;

  num = (short) lo; *p = num;
  return len;
}
