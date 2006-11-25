#include "alloc.h"
#include "bin.h"
#include "dir_array.h"
#include "dir_hash.h"
#include "str.h"

static unsigned int keyhash(const char *key)
{
  unsigned int h = 5381;
  char c;

  for (;;) {
    c = *key;
    if (!c) return h;
    h = ((h << 5) + h) ^ c;
    ++key;
  }
}
int dir_hash_init(struct dir_hash *dh, const char *path)
{
  struct dir_array *da;
  struct dir_hash_tnode *tn;
  struct dir_hash_tnode *tp;
  char *name;
  unsigned int hash;

  da = &dh->da;
  if (!dir_array_init(da, path)) return 0;

  bin_zero(&dh->tab, DIR_HASH_BUCKETS * sizeof(struct dir_hash_tnode *));

  for (;;) {
    if (!dir_array_next(da, &name)) break;
    hash = keyhash(name) % DIR_HASH_BUCKETS;
    tp = dh->tab[hash];
    for (;;) {
      if (!tp) break;
      if (tp->next)
        tp = tp->next;
      else
        break;
    }
    tn = alloc(sizeof(struct dir_hash_tnode));
    if (!tn) { dir_hash_free(dh); return 0; }
    tn->name = name;
    tn->next = 0;
    if (!tp)
      dh->tab[hash] = tn;
    else
      tp->next = tn;
  }

  dir_array_rewind(da);
  return 1;
}
int dir_hash_check(struct dir_hash *dh, const char *key)
{
  unsigned int hash;
  struct dir_hash_tnode *tn;

  hash = keyhash(key) % DIR_HASH_BUCKETS;
  tn = dh->tab[hash];
  if (!tn) return 0;

  for (;;) {
    if (str_same(tn->name, key)) return 1;
    if (!tn->next) return 0;
    tn = tn->next;
  }
}
void dir_hash_free(struct dir_hash *dh)
{
  unsigned int i;
  struct dir_hash_tnode *tn;
  struct dir_hash_tnode *tn_next;
  dir_array_free(&dh->da);

  for (i = 0; i < DIR_HASH_BUCKETS; ++i) {
    tn = dh->tab[i];
    if (!tn) continue;
    for (;;) {
      tn_next = tn->next;
      dealloc(tn);
      if (tn_next)
        tn = tn_next;
      else
        break;
    }
  }
}
