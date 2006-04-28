#include "fmt.h"

unsigned int fmt_byteo(char *s, unsigned char ul)
{
  return fmt_u64o(s, (uint64) ul);
}
