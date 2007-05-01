#include "fd_seek.h"

off_t fd_seek_cur(int fd, off_t pos)
{
  return lseek(fd, pos, 1);
}
