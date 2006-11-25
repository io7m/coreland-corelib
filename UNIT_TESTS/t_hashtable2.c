#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../hashtable.h"
#include "../bin.h"
#include "../alloc.h"

static unsigned long num_allocs = 0;
static void *count_malloc(unsigned long n)
{
  ++num_allocs;
  return malloc(n);
}

void check(int tnum, const char *tname, struct hashtable *h, const char *key,
           const char *data, unsigned int slot, unsigned long allocd,
           unsigned long used, struct ht_table_node *tnode)
{
  if (h->slots[slot].allocd != allocd) {
    printf("%d %s slots[%d].allocd %lu != %lu\n",
            tnum, tname, slot, h->slots[slot].allocd, allocd);
    _exit(1);
  }
  if (h->slots[slot].used != used) {
    printf("%d %s slots[%d].used %lu != %lu\n",
            tnum, tname, slot, h->slots[slot].used, used);
    _exit(1);
  }
  if (key) {
    if (!bin_same(key, tnode->key, tnode->keylen)) {
      printf("%d) %s node->key ", tnum, tname);
      printn(tnode->key, tnode->keylen);
      printf(" != %s\n", key);
      _exit(1);
    }
  }
  if (data) {
    if (!bin_same(data, tnode->data, tnode->keylen)) {
      printf("%d) %s node->data ", tnum, tname);
      printn(tnode->data, tnode->datalen);
      printf(" != %s\n", data);
      _exit(1);
    }
  }
}

void add1(struct hashtable *h)
{
  struct ht_table_node *tn;
  const unsigned int slot = 1;

  /* should allocate one node */
  add(h, ch1str[0], ch1str[0], 1);
  tn = h->slots[slot].head;
  check(1, "add1", h, ch1str[0], ch1str[0], slot, 1, 1, tn);

  if (num_allocs != 3) {
    printf("1 add1 num_allocs == %lu\n", num_allocs); _exit(1);
  }

  /* should refuse duplicate */
  add(h, ch1str[0], ch1str[0], 0);
  delete_key(h, ch1str[0], 1);
  check(2, "add1", h, 0, 0, slot, 1, 0, 0);

  /* should reuse node */
  add(h, ch1str[0], ch1str[0], 1);
  tn = h->slots[slot].head;
  check(3, "add1", h, ch1str[0], ch1str[0], slot, 1, 1, tn);

  if (num_allocs != 5) {
    printf("3 add1 num_allocs == %lu\n", num_allocs); _exit(1);
  }

  /* should add new node */
  add(h, ch1str[1], ch1str[1], 1);
  tn = h->slots[slot].head->next;
  check(4, "add1", h, ch1str[1], ch1str[1], slot, 2, 2, tn);

  if (num_allocs != 8) {
    printf("3 add1 num_allocs == %lu\n", num_allocs); _exit(1);
  }

  /* should add new node */
  add(h, ch1str[2], ch1str[2], 1);
  tn = h->slots[slot].head->next->next;
  check(5, "add1", h, ch1str[2], ch1str[2], slot, 3, 3, tn);

  if (num_allocs != 11) {
    printf("3 add1 num_allocs == %lu\n", num_allocs); _exit(1);
  }

  /* delete middle node in chain */
  delete_key(h, ch1str[1], 1);
  tn = h->slots[slot].head->next;
  check(6, "add1", h, 0, 0, slot, 3, 2, tn);

  /* reuse middle node */
  add(h, ch1str[3], ch1str[3], 1);
  tn = h->slots[slot].head->next;
  check(7, "add1", h, ch1str[3], ch1str[3], slot, 3, 3, tn);

  delete_key(h, ch1str[0], 1);
  delete_key(h, ch1str[2], 1);
  delete_key(h, ch1str[3], 1);

  /* chain should be unused */
  check(7, "add1", h, 0, 0, slot, 3, 0, 0);
}

int main()
{
  struct hashtable ht;

  set_alloc(count_malloc);

  ht_init(&ht);
  add1(&ht);
  ht_free(&ht);
  return 0;
}
