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

unsigned int scan_shortx(const char *s, short *p)
{
  long lo;
  unsigned int len;
  short num;

  len = scan_longx(s, &lo);
  if (!len) return 0;

  num = (short) lo; *p = num;
  return len;
}
