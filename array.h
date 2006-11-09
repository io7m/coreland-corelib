#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_OVERALLOC 8

typedef struct {
  char *x;
  unsigned long a;
  unsigned long u;
  unsigned int es;
} array;

int array_init(array *, unsigned long, unsigned int);
char *array_index(array *, unsigned long);
int array_cat(array *, void *);
void array_free(array *);
int array_copy(array *, const array *);
int array_resize(array *, unsigned long);
void array_trunc(array *, unsigned long);

unsigned long array_size(array *);
unsigned long array_bytes(array *);
void *array_data(array *);
void array_chop(array *, unsigned long);

#define array_trunc(a) array_chop((a),0)

#define array_SIZE(a) ((a)->u)
#define array_BYTES(a) ((a)->u * (a)->es)
#define array_DATA(a) ((a)->x)

#endif
