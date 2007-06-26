#include <stdio.h>
#include "../dqueue.h"
#include "t_assert.h"

#define QUEUE_SIZE 8

struct dqueue dq;

void dump()
{
  unsigned long i;
  char *x = dq.x;

  printf("%lu %lu %lu %lu\n", dq.hpos, dq.tpos, dq.a, dq.u);
  for (i = 0; i < dq.a; ++i) {
   if (x[i] < 'A')
      printf("x");
    else
      printf("%c", x[i]);
  }
  printf("\n");
  for (i = 0; i < dq.a; ++i) {
    if (i == dq.hpos) { printf("H"); continue; }
    if (i == dq.tpos) { printf("T"); continue; }
    printf(" ");
  }
  printf("\n");
}

int main(void)
{
  unsigned long num;
  char ch;
  char *cp;

  dqueue_init(&dq, QUEUE_SIZE, sizeof(ch));

  printf("h t a u\n");
  dump();

  /* check size is zero */
  test_assert(dqueue_size(&dq) == 0);
  test_assert(dqueue_SIZE(&dq) == 0);
  printf("\n");

  /* fill queue */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    ch = 'A';
    test_assert(dqueue_enq(&dq, &ch) == 1);
    dump();
  }
  for (num = 0; num < QUEUE_SIZE / 2; ++num) {
    test_assert(dqueue_deq(&dq, (void **) &cp) == 1);
    test_assert(*cp == 'A');
    *cp = 0;
    dump();
  }
  for (num = 0; num < QUEUE_SIZE; ++num) {
    ch = 'B';
    test_assert(dqueue_enq(&dq, &ch) == 1);
    dump();
  }
  for (num = 0; num < QUEUE_SIZE / 2; ++num) {
    test_assert(dqueue_deq(&dq, (void **) &cp) == 1);
    test_assert(*cp == 'A');
    *cp = 0;
    dump();
  }
  for (num = 0; num < QUEUE_SIZE / 2; ++num) {
    test_assert(dqueue_deq(&dq, (void **) &cp) == 1);
    test_assert(*cp == 'B');
    dump();
  }
 
  return 0;
}
