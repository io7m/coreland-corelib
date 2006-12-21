#include "scan.h"

unsigned long scan_whitespace(const char *str)
{
  return scan_charset(str, " \t");
}
