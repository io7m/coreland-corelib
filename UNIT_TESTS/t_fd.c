#include "../fd.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
  int fd0;
  int fd1;
  int fd2;
  int fd02;
  int fd03;
  int r;

  fd0 = 0;
  fd1 = 1;
  fd2 = 2;
  fd02 = 0;

  r = fd_dup(fd0, fd02);
  if (r != 0) { printf("(1) fd_dup: r == %d\n", r); return 1; }

  fd02 = 3;
  r = fd_dup(fd0, fd02);
  if (r != 1) { printf("(2) fd_dup: r == %d\n", r); return 1; }

  fd03 = open("./t_fd.c", O_RDONLY);
  if (fd03 == -1) { printf("(3) open: fd03 == %d\n", fd03); return 1; }
  fd02 = open("./t_fd.ld", O_RDONLY);
  if (fd02 == -1) { printf("(4) open: fd02 == %d\n", fd02); return 1; }

  r = fd_move(fd03, fd02);
  if (r != 1) { printf("(5) fd_move: r == %d\n", r); return 1; }

  return 0;
}
