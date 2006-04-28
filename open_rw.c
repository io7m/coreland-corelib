#include "open.h"

int open_rw(const char *f)
{
  return open(f, O_RDWR | O_NONBLOCK);
}
