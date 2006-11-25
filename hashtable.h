#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HT_HASH_BUCKETS 2048UL

#define HT_SLOT_UNUSED  0x00
#define HT_SLOT_USED    0x01

struct ht_table_node {
  struct ht_table_node *next;
  char *key;
  char *data;
  unsigned long keylen;
  unsigned long datalen;
  unsigned int state;
};

struct ht_table_head {
  struct ht_table_node *head;
  unsigned long allocd;
  unsigned long used;
};

struct hashtable {
  struct ht_table_head slots[HT_HASH_BUCKETS];
};

void ht_init(struct hashtable *);
void ht_free(struct hashtable *);

int ht_addb(struct hashtable *, const void *, unsigned long, const void *, unsigned long);
int ht_adds(struct hashtable *, const void *, const void *);
int ht_getb(const struct hashtable *, const void *, unsigned long, void **, unsigned long *);
int ht_gets(const struct hashtable *, const void *, void **, unsigned long *);
int ht_deleteb(struct hashtable *, const void *, unsigned long);
int ht_deletes(struct hashtable *, const void *);
int ht_replaceb(struct hashtable *, const void *, unsigned long, const void *, unsigned long);
int ht_replaces(struct hashtable *, const void *, const void *);

unsigned long ht_hash(const char *, unsigned long);
unsigned long ht_bytes(const struct hashtable *);

#endif
