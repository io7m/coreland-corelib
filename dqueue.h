#ifndef CORELIB_DQUEUE_H
#define CORELIB_DQUEUE_H

struct dqueue {
  void *x;
  unsigned long hpos;
  unsigned long tpos;
  unsigned long a;
  unsigned long u;
  unsigned int es;
};

int dqueue_init(struct dqueue *, unsigned long, unsigned int);
int dqueue_enq(struct dqueue *, void *);
int dqueue_deq(struct dqueue *, void **);
int dqueue_peek(struct dqueue *, void **);
void dqueue_free(struct dqueue *);
void dqueue_zero(struct dqueue *);

unsigned long dqueue_size(const struct dqueue *);
unsigned long dqueue_bytes(const struct dqueue *);
const void *dqueue_data(const struct dqueue *);

#define dqueue_SIZE(q) ((q)->u)
#define dqueue_BYTES(q) ((q)->u * ((q)->es))
#define dqueue_DATA(q) ((q)->x)

#endif
