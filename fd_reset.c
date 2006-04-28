#include "fd.h"
#include <fcntl.h>

int fd_reset(int fd)
{
  return fcntl(fd, F_SETFD, 0);
}
