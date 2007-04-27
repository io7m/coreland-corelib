#include "fd_seek.h"

long fd_seek_start(int fd)
{
  return lseek(fd, 0, FD_SEEK_SET);
}
