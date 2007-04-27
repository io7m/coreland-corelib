#include "sd_fcntl.h"
#include "open.h"

int open_append(const char *f)
{
  return open(f, O_APPEND | O_CREAT | O_WRONLY | O_NONBLOCK, 0600);
}
