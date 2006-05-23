#ifndef DIR_HASH_H
#define DIR_HASH_H

#include "dir_array.h"

#define DIR_HASH_BUCKETS 256

struct dir_hash_tnode { struct dir_hash_tnode *next; const char *name; };

typedef struct {
  dir_array da;
  struct dir_hash_tnode *tab[DIR_HASH_BUCKETS];
} dir_hash;

int dir_hash_init(dir_hash *, const char *);
int dir_hash_check(dir_hash *, const char *);

void dir_hash_free(dir_hash *);
void dir_hash_dump(dir_hash *);

#define dir_hash_array(dh) (&(dh)->da)

#endif
