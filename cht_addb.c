#include "alloc.h"
#include "bin.h"
#include "chashtable.h"
#include "error.h"

int cht_grow(struct chashtable *ch)
{
  struct cht_node *t1 = 0;
  struct cht_node *t2 = 0;
  unsigned long mask;
  unsigned long size;
  unsigned long ind;

  /* check integer wrap */
  if (ch->len * 2 <= ch->len) {
    errno = error_overflow;
    return 0;
  }

  size = ch->len * 2;
  mask = size - 1;

  t1 = alloc_zero(size * sizeof(struct cht_node));
  if (!t1) goto FAIL;
  t2 = alloc_zero(size * sizeof(struct cht_node));
  if (!t2) goto FAIL;
 
  ch->table1 = t1;
  ch->table2 = t2;
  ch->len = size;
  return 1;

  FAIL:
  if (t1) dealloc(t1);
  if (t2) dealloc(t2);
  return 0;
}

#define CHT_TRIES(mask) \
  ((((mask) + 1) + (CHT_TRIES_MULT >> 1)) / CHT_TRIES_MULT) * CHT_TRIES_MULT + CHT_TRIES_MULT;

int cht_addb(struct chashtable *ch, const void *key, unsigned long klen,
                                    const void *dat, unsigned long dlen)
{
  unsigned long ind;
  unsigned long mask;
  unsigned long tries;
  struct cht_node *node;
  struct cht_node t1 = {0, 0, 0, 0};
  struct cht_node t2 = {0, 0, 0, 0};

  if (cht_checkb(ch, key, klen)) return 0;

  t1.key = alloc_zero(klen);
  if (!t1.key) goto FAIL;
  t1.data = alloc_zero(dlen);
  if (!t1.data) goto FAIL;

  t1.klen = klen;
  t1.dlen = dlen;

  /* XXX: this operation needs to be atomic. memory has been allocated
          above and the table must not be left in an inconsistent state
          if cht_grow() fails when a key + data pair has been inserted.
          ideally, the table needs to be grown ahead of time and then
          the keys inserted when available space is guaranteed. */

  /* add key atomically */

  return 1;

  FAIL:
  if (t1.key) dealloc(t1.key);
  if (t1.data) dealloc(t1.data);
  return -1;
}
