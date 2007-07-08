#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#include "../error.h"
#include "../dir_walk.h"

int dirfile(const char *fn, const char *rp, void *vp)
{
  printf("directory %s %s\n", rp, fn);
  return 1;
}
int regfile(const char *fn, const char *rp, void *vp)
{
  printf("regular %s %s\n", rp, fn);
  return 1;
}
int lnkfile(const char *fn, const char *rp, void *vp)
{
  printf("symlink %s %s\n", rp, fn);
  return 1;
}
int fifofile(const char *fn, const char *rp, void *vp)
{
  printf("fifo %s %s\n", rp, fn);
  return 1;
}

int main()
{
  int ret = 0;
  struct dir_walk dw;

  dir_walk_init(&dw);

  dw.cb_dir = dirfile;
  dw.cb_reg = regfile;
  dw.cb_lnk = lnkfile;
  dw.cb_fifo = fifofile;

  dw.base = "testdata/dir_walk";

  if (mkfifo("testdata/dir_walk/fifo", 0644) == -1) {
    printf("fail: mkfifo: %s\n", error_str(errno));
    return 1;
  }
  if (!dir_walk(&dw)) {
    printf("fail: dir_walk_start() returned 0: %s\n", error_str(errno));
    ret = 1;
    goto END;
  }

  END:
  if (unlink("testdata/dir_walk/fifo") == -1)
    printf("error: unlink: %s\n", error_str(errno));
  return ret;
}
