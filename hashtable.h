#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HT_HASH_BUCKETS 2048UL

typedef int (ht_callback)(void *, unsigned long, void *);

struct ht_table_node {
  struct ht_table_node *next;
  void *key;
  void *data;
  unsigned long keylen;
  unsigned long datalen;
};

struct ht_table_head {
  struct ht_table_node *head;
  unsigned long allocd;
  unsigned long used;
};

struct hashtable {
  struct ht_table_head slots[HT_HASH_BUCKETS];
};

int ht_init(struct hashtable *);
int ht_addb(struct hashtable *, const void *, unsigned long, const void *, unsigned long);
int ht_adds(struct hashtable *, const void *, const void *);
int ht_getb(const struct hashtable *, const void *, unsigned long, void **, unsigned long *);
int ht_gets(const struct hashtable *, const void *, void **, unsigned long *);
int ht_deleteb(struct hashtable *, const void *, unsigned long);
int ht_deletes(struct hashtable *, const void *);
int ht_replaceb(struct hashtable *, const void *, unsigned long, const void *, unsigned long);
int ht_replaces(struct hashtable *, const void *, const void *);
int ht_replaceb_ext(struct hashtable *, const void *, unsigned long, const void *, unsigned long, ht_callback *, void *);
int ht_replaces_ext(struct hashtable *, const void *, const void *, ht_callback *, void *);
int ht_checkb(const struct hashtable *, const void *, unsigned long);
int ht_checks(const struct hashtable *, const void *);

void ht_iter(struct hashtable *, ht_callback *, void *);
void ht_free(struct hashtable *);
void ht_free_ext(struct hashtable *, ht_callback *, void *);
void ht_clear(struct hashtable *);
void ht_clear_ext(struct hashtable *, ht_callback *, void *);

unsigned long ht_hash(const void *, unsigned long);
unsigned long ht_bytes(const struct hashtable *);

#endif
