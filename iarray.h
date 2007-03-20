#ifndef IARRAY_H
#define IARRAY_H

#define IARRAY_OVERALLOC 8

struct iarray_node {
  unsigned long len;
  void *data;
  struct iarray_node *next;
  struct iarray_node *prev;
};

struct iarray {
  unsigned long a;
  unsigned long u;
  struct iarray_node *head; /* first allocated node */
  struct iarray_node *tail; /* last allocated node */
};

int iarray_init(struct iarray *, unsigned long);
void iarray_free(struct iarray *);
void iarray_zero(struct iarray *);

int iarray_index(const struct iarray *, unsigned long, void **, unsigned long *);
void iarray_chop(struct iarray *, unsigned long);
void iarray_trunc(struct iarray *);
int iarray_cat(struct iarray *, void *, unsigned long);
int iarray_copy(struct iarray *, const struct iarray *);
int iarray_insert(struct iarray *, unsigned long, void *, unsigned long);
void iarray_remove(struct iarray *, unsigned long);
void iarray_sort(struct iarray *, int (*)(const void *, unsigned long, const void *, unsigned long));

unsigned long iarray_size(const struct iarray *);
unsigned long iarray_bytes(const struct iarray *);

#define iarray_TRUNC(a) iarray_chop((a),0)
#define iarray_SIZE(a) ((a)->u)

/* private */
int iarray_nindex(const struct iarray *, unsigned long, struct iarray_node **);
int iarray_newnodes(struct iarray_node **, struct iarray_node **, unsigned long);
int iarray_fillnode(struct iarray_node *, void *, unsigned long);

#endif
