#include "sd_fcntl.h"
#include "open.h"

int open_wo(const char *f)
{
  return open(f, O_WRONLY | O_NONBLOCK);
}
