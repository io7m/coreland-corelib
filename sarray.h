#ifndef SARRAY_H
#define SARRAY_H

struct sarray {
  void *x;
  unsigned long a;
  unsigned long u;
  unsigned int es;
};

void sarray_init(struct sarray *, void *, unsigned long, unsigned int);
void *sarray_index(struct sarray *, unsigned long);
void sarray_chop(struct sarray *, unsigned long);
void sarray_trunc(struct sarray *);
int sarray_cat(struct sarray *, void *);

unsigned long sarray_size(const struct sarray *);
unsigned long sarray_bytes(const struct sarray *);
void *sarray_data(const struct sarray *);

#define sarray_TRUNC(s) (sarray_chop((s),0))
#define sarray_SIZE(s) ((s)->u)
#define sarray_BYTES(s) ((s)->u * (s)->es)
#define sarray_DATA(s) ((s)->x)

#endif
