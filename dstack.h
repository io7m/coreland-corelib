#ifndef CORELIB_DSTACK_H
#define CORELIB_DSTACK_H

#include "array.h"

struct dstack {
  struct array x;
};

int dstack_init(struct dstack *, unsigned long, unsigned int);
int dstack_push(struct dstack *, void *);
int dstack_pop(struct dstack *, void **);
int dstack_peek(struct dstack *, void **);
void dstack_free(struct dstack *);

unsigned long dstack_size(const struct dstack *);
unsigned long dstack_bytes(const struct dstack *);
const void *dstack_data(const struct dstack *);

#define dstack_SIZE(s) array_SIZE(&(s)->x)
#define dstack_BYTES(s) array_BYTES(&(s)->x)
#define dstack_DATA(s) array_DATA(&(s)->x)

#endif
