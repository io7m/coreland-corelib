#ifndef CORELIB_DIR_HASH_H
#define CORELIB_DIR_HASH_H

#include "dir_array.h"

#define DIR_HASH_BUCKETS 256

struct dir_hash_tnode { struct dir_hash_tnode *next; const char *name; };

struct dir_hash {
  struct dir_array da;
  struct dir_hash_tnode *tab[DIR_HASH_BUCKETS];
};

void dir_hash_init(struct dir_hash *);
int dir_hash_open(struct dir_hash *, const char *);
int dir_hash_check(struct dir_hash *, const char *);
void dir_hash_free(struct dir_hash *);

#define dir_hash_array(dh) (&(dh)->da)

#endif
