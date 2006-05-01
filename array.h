#ifndef ARRAY_H
#define ARRAY_H

#include "uint32.h"
#include "uint64.h"

#define ARRAY_OVERALLOC 8

typedef struct {
  char *x;
  uint64 a;
  uint64 u;
  uint32 es;
} array;

int array_init(array *, uint64, uint32);
char *array_index(array *, uint64);
int array_cat(array *, void *);
void array_free(array *);
int array_copy(const array *, array *);
int array_resize(array *, uint64);
void array_trunc(array *, uint64);

uint64 array_size(array *);
uint64 array_bytes(array *);
void *array_data(array *);

#define array_INIT {0,0,0,0}
#define array_SIZE(a) ((a)->u)
#define array_BYTES(a) ((a)->u * (a)->es)
#define array_DATA(a) ((a)->x)

#endif
