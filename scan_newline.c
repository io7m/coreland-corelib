#include "scan.h"

unsigned long scan_newline(const char *str)
{
  return scan_charset(str, "\n");
}
