#include "scan.h"

unsigned int scan_uint(const char *s, unsigned int *up)
{
  unsigned long ul;
  unsigned int ui;
  unsigned int len;

  len = scan_ulong(s, &ul);
  if (!len) return 0;

  ui = (unsigned int) ul; *up = ui;
  return len;
}

unsigned int scan_int(const char *s, int *p)
{
  long lo;
  unsigned int len;
  int i;

  len = scan_long(s, &lo);
  if (!len) return 0;

  i = (int) lo; *p = i;
  return len;
}
