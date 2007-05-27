#include "scan.h"

unsigned int scan_uintb(const char *s, unsigned int *up)
{
  unsigned long ul;
  unsigned int ui;
  unsigned int len;

  len = scan_ulongb(s, &ul);
  if (!len) return 0;

  ui = (unsigned int) ul; *up = ui;
  return len;
}

unsigned int scan_intb(const char *s, int *p)
{
  long lo;
  unsigned int len;
  int i;

  len = scan_longb(s, &lo);
  if (!len) return 0;

  i = (int) lo; *p = i;
  return len;
}
