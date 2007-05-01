#include "fd_seek.h"

off_t fd_seek_end(int fd)
{
  return lseek(fd, 0, FD_SEEK_END);
}
