#include "fmt.h"

unsigned int fmt_byte(char *s, unsigned char ul)
{
  return fmt_u64(s, (uint64) ul);
}
