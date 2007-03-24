#include <stdio.h>
#include <unistd.h>
#include "../open.h"

int main(void)
{
  int fd;

  fd = open_ro("./t_open.c");
  if (fd == -1) { perror("open_ro"); return 1; }
  if (close(fd) == -1) perror("close");

  fd = open_creat("./abcxyz.tmp");
  if (fd == -1) { perror("open_creat"); return 1; }
  if (close(fd) == -1) perror("close");
  fd = open_append("./abcxyz.tmp");
  if (fd == -1) { perror("open_append"); return 1; }
  if (close(fd) == -1) perror("close");
  if (unlink("./abcxyz.tmp") == -1) { perror("unlink"); return 1; }
  
  fd = open_trunc("./abcxyz.tmp");
  if (fd == -1) { perror("open_trunc"); return 1; }
  if (close(fd) == -1) perror("close");
  fd = open_excl("./abcxyz.tmp");
  if (fd != -1) { printf("fail: open_excl: opened existing file!\n"); return 1; }

  fd = open_rw("./abcxyz.tmp");
  if (fd == -1) { perror("open_rw"); return 1; }
  if (close(fd) == -1) perror("close");
  fd = open_wo("./abcxyz.tmp");
  if (fd == -1) { perror("./abcxyz.tmp"); return 1; }
  if (close(fd) == -1) perror("close");

  if (unlink("./abcxyz.tmp") == -1) { perror("unlink"); return 1; }

  return 0;
}
