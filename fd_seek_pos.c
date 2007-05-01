#include "fd_seek.h"

off_t fd_seek_pos(int fd, off_t pos)
{
  return lseek(fd, pos, FD_SEEK_SET);
}
