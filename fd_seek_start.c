#include "fd_seek.h"

off_t fd_seek_start(int fd)
{
  return lseek(fd, 0, FD_SEEK_SET);
}
