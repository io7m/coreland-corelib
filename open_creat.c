#include "sd_fcntl.h"
#include "open.h"

int open_creat(const char *f)
{
  return open(f, O_WRONLY | O_CREAT | O_NONBLOCK, 0600);
}
