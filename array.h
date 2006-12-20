#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_OVERALLOC 8

struct array {
  void *x;
  unsigned long a;
  unsigned long u;
  unsigned int es;
};

int array_init(struct array *, unsigned long, unsigned int);
void array_free(struct array *);
void array_zero(struct array *);

void *array_index(const struct array *, unsigned long);
void array_chop(struct array *, unsigned long);
void array_trunc(struct array *, unsigned long);
int array_cat(struct array *, void *);
int array_copy(struct array *, const struct array *);
int array_resize(struct array *, unsigned long);

unsigned long array_size(const struct array *);
unsigned long array_bytes(const struct array *);
void *array_data(const struct array *);

#define array_TRUNC(a) array_chop((a),0)
#define array_SIZE(a) ((a)->u)
#define array_BYTES(a) ((a)->u * (a)->es)
#define array_DATA(a) ((a)->x)

#endif
