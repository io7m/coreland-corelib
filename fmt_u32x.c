#include "fmt.h"

unsigned int fmt_u32x(char *s, uint32 ul)
{
  return fmt_u64x(s, (uint64) ul);
}
