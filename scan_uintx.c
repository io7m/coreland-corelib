#include "scan.h"

unsigned int scan_uintx(const char *s, unsigned int *up)
{
  unsigned long ul;
  unsigned int ui;
  unsigned int len;

  len = scan_ulongx(s, &ul);
  if (!len) return 0;

  ui = (unsigned int) ul; *up = ui;
  return len;
}
