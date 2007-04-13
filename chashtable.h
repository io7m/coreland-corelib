#ifndef CHASHTABLE_H
#define CHASHTABLE_H

#define CHT_TRIES_MULT 8

typedef int (cht_callback)(void *, unsigned long, void *);

struct cht_node {
  void *key;
  void *data;
  unsigned long klen;
  unsigned long dlen;
};

struct chashtable {
  struct cht_node *table1;
  struct cht_node *table2;
  struct cht_node *oflow;
  unsigned long len;
  unsigned long oflow_a;
  unsigned long oflow_len;
};

int cht_init(struct chashtable *);
int cht_addb(struct chashtable *, const void *, unsigned long, const void *, unsigned long);
int cht_adds(struct chashtable *, const void *, const void *);
int cht_getb(const struct chashtable *, const void *, unsigned long, void **, unsigned long *);
int cht_gets(const struct chashtable *, const void *, void **, unsigned long *);
int cht_deleteb(struct chashtable *, const void *, unsigned long);
int cht_deletes(struct chashtable *, const void *);
int cht_replaceb(struct chashtable *, const void *, unsigned long, const void *, unsigned long);
int cht_replaces(struct chashtable *, const void *, const void *);
int cht_replaceb_ext(struct chashtable *, const void *, unsigned long, const void *, unsigned long, cht_callback *, void *);
int cht_replaces_ext(struct chashtable *, const void *, const void *, cht_callback *, void *);
int cht_checkb(const struct chashtable *, const void *, unsigned long);
int cht_checks(const struct chashtable *, const void *);

void cht_iter(struct chashtable *, cht_callback *, void *);
void cht_free(struct chashtable *);
void cht_free_ext(struct chashtable *, cht_callback *, void *);
void cht_clear(struct chashtable *);
void cht_clear_ext(struct chashtable *, cht_callback *, void *);

unsigned long cht_hash1(const void *, unsigned long);
unsigned long cht_hash2(const void *, unsigned long);
unsigned long cht_bytes(const struct chashtable *);

#endif
