#include "close.h"
#include "fd.h"
#include <fcntl.h>

#ifdef HAVE_DUP2
extern int dup2(int, int); /* avoid unistd.h here */
#endif

int fd_dup(int src, int dst)
{
  if (src == dst) return 0;
#ifdef HAVE_DUP2
  return (dup2(src, dst) != -1) ? 1 : -1;
#else
  if (fcntl(src, F_GETFL, 0) == -1) return -1;
  close(dst);
  if (fcntl(src, F_DUPFD, dst) == -1) return -1;
  return 1;
#endif
}
