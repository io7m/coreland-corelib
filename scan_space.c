#include "scan.h"

unsigned long scan_whitespace(const char *s)
{
  return scan_charset(s, " \t");
}
