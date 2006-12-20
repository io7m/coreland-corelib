#ifndef SSTACK_H
#define SSTACK_H

struct sstack {
  void *x;
  unsigned long a;
  unsigned long u;
  unsigned int es;
};

void sstack_init(struct sstack *, void *, unsigned long, unsigned int);
int sstack_push(struct sstack *, void *);
int sstack_pop(struct sstack *, void **);
int sstack_peek(struct sstack *, void **);
void sstack_free(struct sstack *);

unsigned long sstack_size(const struct sstack *);
unsigned long sstack_bytes(const struct sstack *);
void *sstack_data(const struct sstack *);

#define sstack_SIZE(s) ((s)->u)
#define sstack_BYTES(s) ((s)->u * (s)->es)
#define sstack_DATA(s) ((s)->x)

#endif
