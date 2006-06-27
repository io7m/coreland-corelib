#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "uint32.h"
#include "uint64.h"

#define HASH_BUCKETS 2048
#define SLOT_UNUSED  0x0000
#define SLOT_USED    0x0001

typedef struct table_node {
  struct table_node *next;
  char *key;
  char *data;
  uint32 keylen;
  uint32 datalen;
  uint32 state;
} table_node;

typedef struct table_head {
  table_node  *head;
  uint32 allocd;
  uint32 used;
} table_head;

typedef struct {
  table_head slots[HASH_BUCKETS];
  uint32 size;
} hashtable;

void ht_init(hashtable *);
void ht_destroy(hashtable *);

int ht_addb(hashtable *, const char *, uint32, const char *, uint32);
int ht_adds(hashtable *, const char *, const char *);
int ht_addu32(hashtable *, const char *, uint32, uint32);
int ht_getb(hashtable *, const char *, uint32, char **, uint32 *);
int ht_gets(hashtable *, const char *, char **, uint32 *);
int ht_getu32(hashtable *, const char *, uint32, uint32 *);
int ht_deleteb(hashtable *, const char *, uint32);
int ht_deletes(hashtable *, const char *);
int ht_replaceb(hashtable *, const char *, uint32, const char *, uint32);
int ht_replaces(hashtable *, const char *, const char *);

uint32 ht_hash(const char *, uint32);
uint64 ht_bytes(hashtable *);

#endif
