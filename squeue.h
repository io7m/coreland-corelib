#ifndef SQUEUE_H
#define SQUEUE_H

struct squeue {
  void *x;
  unsigned long hpos;
  unsigned long tpos;
  unsigned long a;
  unsigned long u;
  unsigned int es;
};

void squeue_init(struct squeue *, void *, unsigned long, unsigned int);
int squeue_enq(struct squeue *, void *);
int squeue_deq(struct squeue *, void **);
int squeue_peek(struct squeue *, void **);

unsigned long squeue_size(const struct squeue *);
unsigned long squeue_bytes(const struct squeue *);
const void *squeue_data(const struct squeue *);

#define squeue_SIZE(q) ((q)->u)
#define squeue_BYTES(q) ((q)->u * ((q)->es))
#define squeue_DATA(q) ((q)->x)

#endif
