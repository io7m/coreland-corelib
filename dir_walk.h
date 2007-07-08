#ifndef DIR_WALK_H
#define DIR_WALK_H

#include <limits.h>
#include "sstring.h"

struct dir_walk {
  struct sstring path;
  char pbuf[PATH_MAX];
  char *base;
  void *data;
  int (*cb_dir)(const char *, const char *, void *);
  int (*cb_fifo)(const char *, const char *, void *);
  int (*cb_chr)(const char *, const char *, void *);
  int (*cb_blk)(const char *, const char *, void *);
  int (*cb_reg)(const char *, const char *, void *);
  int (*cb_lnk)(const char *, const char *, void *);
  int (*cb_sock)(const char *, const char *, void *);
};

void dir_walk_init(struct dir_walk *);
int dir_walk(struct dir_walk *);

#endif
