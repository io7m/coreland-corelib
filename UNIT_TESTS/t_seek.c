/* DO NOT EDIT THIS LINE - required for test */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../seek.h"
#include "../int64.h"

void readchar(int fd, char *c)
{
  static unsigned long n = 0;
  int r;
  r = read(fd, c, 1);
  if (r == -1) { perror("read"); exit(2); }
  if (r == 0) { printf("fail: %u unexpected end of file\n", n); exit(2); }
  ++n;
}

int main()
{
  int fd;
  int64 s;
  char c;
  struct stat sb;

  fd = open("t_seek.c", O_RDONLY);
  if (fd == -1) { perror("open"); return 2; }

  s = seek_start(fd);
  if (s != 0) { printf("fail: 1 seek_start: s == %ld\n", s); return 1; }

  s = seek_cur(fd, 4);
  if (s != 4) { printf("fail: 2 seek_cur: s == %ld\n", s); return 1; }
  readchar(fd, &c);
  if (c != 'O') { printf("fail: 3 seek_cur: c == %c\n", c); return 1; }

  s = seek_start(fd);
  if (s != 0) { printf("fail: 4 seek_start: s == %ld\n", s); return 1; }

  s = seek_pos(fd, 8);
  if (s != 8) { printf("fail: 5 seek_pos: s == %ld\n", s); return 1; }
  readchar(fd, &c);
  if (c != 'T') { printf("fail: 6 seek_pos: c == %c\n", c); return 1; }
 
  if (fstat(fd, &sb) == -1) { perror("fstat"); return 2; }
  s = seek_end(fd);
  if (s != sb.st_size) {
    printf("fail: 7 seek_end: s == %ld expected %ld\n", s, (sb.st_size));
    return 1;
  }
 
  s = seek_cur(fd, -2);
  if (s != (sb.st_size - 2)) {
    printf("fail: 9 seek_cur: s == %ld expected %ld\n", s, (sb.st_size - 2));
    return 1;
  }
  readchar(fd, &c);
  if (c != '/') { printf("fail: 10 seek_cur: c == %c\n", c); return 1; }
 
  if (close(fd) == -1) perror("close");
  return 0;
}

/* DO NOT EDIT THIS LINE - required for test */
