#include <sys/types.h>
#include <fcntl.h>
#include "closeonexec.h"

#ifndef FD_CLOEXEC
#define FD_CLOEXEC 1
#endif

int closeonexec(int fd)
{
  return fcntl(fd, F_SETFD, FD_CLOEXEC);
}
