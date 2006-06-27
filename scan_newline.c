#include "scan.h"

unsigned long scan_newline(const char *s)
{
  return scan_charset(s, "\n");
}
