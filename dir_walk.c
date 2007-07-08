#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "bin.h"
#include "direntry.h"
#include "open.h"
#include "str.h"
#include "sstring.h"
#include "dir_walk.h"

int dir_func(struct dir_walk *dw, const char *dn)
{
  struct stat sb;
  DIR *dir;
  direntry *de;
  unsigned long pos;
  int pwdfd;
  int ret;

  dir = 0;
  ret = 1;

  pwdfd = open_ro(".");
  if (pwdfd == -1) return 0;  
  if (chdir(dn) == -1) { ret = 0; goto END; }

  dir = opendir(".");
  if (!dir) { ret = 0; goto END; }

  if (dw->path.len) 
    sstring_catb(&dw->path, "/", 1);

  sstring_cats(&dw->path, dn);
  sstring_0(&dw->path);

  for (;;) {
    de = readdir(dir);
    if (!de) break;
    if (!str_same(de->d_name, ".") && !str_same(de->d_name, "..")) {
      if (lstat(de->d_name, &sb) == -1) continue; 
      switch (sb.st_mode & S_IFMT) {
        case S_IFIFO:
          if (dw->cb_fifo)
            if (!dw->cb_fifo(de->d_name, dw->path.s, dw->data)) goto END;
          break;
        case S_IFCHR:
          if (dw->cb_chr)
            if (!dw->cb_chr(de->d_name, dw->path.s, dw->data)) goto END;
          break;
        case S_IFDIR:
          if (dw->cb_dir)
            if (!dw->cb_dir(de->d_name, dw->path.s, dw->data)) goto END;
          if (!dir_func(dw, de->d_name)) goto END;
          break;
        case S_IFBLK:
          if (dw->cb_blk)
            if (!dw->cb_blk(de->d_name, dw->path.s, dw->data)) goto END;
          break;
        case S_IFREG:
          if (dw->cb_reg)
            if (!dw->cb_reg(de->d_name, dw->path.s, dw->data)) goto END;
          break;
        case S_IFLNK:
          if (dw->cb_lnk)
            if (!dw->cb_lnk(de->d_name, dw->path.s, dw->data)) goto END;
          break;
        case S_IFSOCK: 
          if (dw->cb_sock)
            if (!dw->cb_sock(de->d_name, dw->path.s, dw->data)) goto END;
          break;
        default:
          break;
      }
    }
  }

  END:
  if (str_rchar(dw->path.s, '/', &pos)) {
    sstring_chop(&dw->path, pos);
    sstring_0(&dw->path);
  }

  if (pwdfd != -1) {
    fchdir(pwdfd);
    close(pwdfd);
  }
  if (dir) closedir(dir);
  return ret;
}

int dir_walk(struct dir_walk *dw)
{
  sstring_trunc(&dw->path);
  return dir_func(dw, dw->base);
}
void dir_walk_init(struct dir_walk *dw)
{
  bin_zero(dw, sizeof(struct dir_walk));
  sstring_init(&dw->path, dw->pbuf, sizeof(dw->pbuf));
}
