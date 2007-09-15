#include <sys/types.h>
#include <sys/stat.h>

#include "bin.h"
#include "dir_array.h"
#include "open.h"
#include "str.h"
#include "sstring.h"
#include "dir_walk.h"

int
dir_func(struct dir_walk *dw, const char *dn)
{
  struct dir_array da = {0, 0, 0, 0, 0};
  struct stat sb;
  unsigned long pos;
  char *name;
  int ret = 1;

  if (dw->path.len) 
    sstring_catb(&dw->path, "/", 1);
  sstring_cats(&dw->path, dn);
  sstring_0(&dw->path);

  if (!dir_array_init(&da, dw->path.s)) { ret = 0; goto END; }

  for (;;) {
    if (!dir_array_next(&da, &name)) break;
    if (!str_same(name, ".") && !str_same(name, "..")) {
      sstring_catb(&dw->path, "/", 1);
      sstring_cats(&dw->path, name);
      sstring_0(&dw->path);

      if (lstat(dw->path.s, &sb) != -1) {
        sstring_chop(&dw->path, dw->path.len - (str_len(name) + 1));
        switch (sb.st_mode & S_IFMT) {
          case S_IFIFO:
            if (dw->cb_fifo)
              if (!dw->cb_fifo(name, dw->path.s, dw->data)) goto END;
            break;
          case S_IFCHR:
            if (dw->cb_chr)
              if (!dw->cb_chr(name, dw->path.s, dw->data)) goto END;
            break;
          case S_IFDIR:
            if (dw->cb_dir)
              if (!dw->cb_dir(name, dw->path.s, dw->data)) goto END;
            if (!dir_func(dw, name)) goto END;
            break;
          case S_IFBLK:
            if (dw->cb_blk)
              if (!dw->cb_blk(name, dw->path.s, dw->data)) goto END;
            break;
          case S_IFREG:
            if (dw->cb_reg)
              if (!dw->cb_reg(name, dw->path.s, dw->data)) goto END;
            break;
          case S_IFLNK:
            if (dw->cb_lnk)
              if (!dw->cb_lnk(name, dw->path.s, dw->data)) goto END;
            break;
          case S_IFSOCK: 
            if (dw->cb_sock)
              if (!dw->cb_sock(name, dw->path.s, dw->data)) goto END;
            break;
          default:
            break;
        }
      } else { ret = 0; goto END; }
    }
  }

  END:
  if (str_rchar(dw->path.s, '/', &pos)) {
    sstring_chop(&dw->path, pos);
    sstring_0(&dw->path);
  }

  if (da.a) dir_array_free(&da);
  return ret;
}

int
dir_walk(struct dir_walk *dw)
{
  sstring_trunc(&dw->path);
  return dir_func(dw, dw->base);
}

void
dir_walk_init(struct dir_walk *dw)
{
  bin_zero(dw, sizeof(struct dir_walk));
  sstring_init(&dw->path, dw->pbuf, sizeof(dw->pbuf));
}
