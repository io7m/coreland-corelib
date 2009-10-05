#include "fd.h"
#include "sd_fcntl.h"

int fd_reset(int fd)
{
#if defined(SD_HAVE_FCNTL)
  return fcntl(fd, F_SETFD, 0);
#else
  #error "system does not support file descriptor reset"
#endif
}
