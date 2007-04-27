#include <unistd.h>
#include "sd_fd.h"
#include "sd_fcntl.h"
#include "close.h"
#include "fd.h"

int fd_dup(int src, int dst)
{
  if (src == dst) return 0;
#if defined(HAVE_DUP2)
  return (dup2(src, dst) != -1) ? 1 : -1;
#else
  #if defined(HAVE_FCNTL)
    if (fcntl(src, F_GETFL, 0) == -1) return -1;
    close(dst);
    if (fcntl(src, F_DUPFD, dst) == -1) return -1;
  #else
    #error "system does not support file descriptor duplication"
  #endif
#endif
  return 1;
}
