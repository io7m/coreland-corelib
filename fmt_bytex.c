#include "fmt.h"

unsigned int fmt_bytex(char *s, unsigned char ul)
{
  return fmt_u64x(s, (uint64) ul);
}
