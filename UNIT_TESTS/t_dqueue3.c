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

void queue_chars(char ch, unsigned long num)
{
  unsigned long ind;
  for (ind = 0; ind < num; ++ind) {
    test_assert(dqueue_enq(&dq, &ch) == 1);
    dump();
  }
}

void dequeue_chars(char ch, unsigned long num)
{
  unsigned long ind;
  char *cp;

  for (ind = 0; ind < num; ++ind) {
    test_assert(dqueue_peek(&dq, (void **) &cp) == 1);
    test_assert(ch == *cp);
    test_assert(dqueue_deq(&dq, (void **) &cp) == 1);
    test_assert(ch == *cp);
    *cp = 0;
    dump();
  }
}

int main(void)
{
  unsigned long exp;

  dqueue_init(&dq, QUEUE_SIZE, sizeof(char));

  printf("h t a u\n");
  dump();

  /* check size is zero */
  test_assert(dqueue_size(&dq) == 0);
  test_assert(dqueue_SIZE(&dq) == 0);
  printf("\n");

  /* allow queue to enlarge */
  exp = QUEUE_SIZE;
  queue_chars('A', QUEUE_SIZE);
  test_assert(exp == dqueue_size(&dq));
  test_assert(exp == dqueue_SIZE(&dq));

  exp -= QUEUE_SIZE / 2;
  dequeue_chars('A', QUEUE_SIZE / 2);
  test_assert(exp == dqueue_size(&dq));
  test_assert(exp == dqueue_SIZE(&dq));

  exp += QUEUE_SIZE;
  queue_chars('B', QUEUE_SIZE);
  test_assert(exp == dqueue_size(&dq));
  test_assert(exp == dqueue_SIZE(&dq));

  exp -= QUEUE_SIZE / 2;
  dequeue_chars('A', QUEUE_SIZE / 2);
  test_assert(exp == dqueue_size(&dq));
  test_assert(exp == dqueue_SIZE(&dq));

  exp += QUEUE_SIZE * 2;
  queue_chars('A', QUEUE_SIZE * 2);
  test_assert(exp == dqueue_size(&dq));
  test_assert(exp == dqueue_SIZE(&dq));

  exp -= QUEUE_SIZE / 2;
  dequeue_chars('B', QUEUE_SIZE / 2);
  test_assert(exp == dqueue_size(&dq));
  test_assert(exp == dqueue_SIZE(&dq));

  exp += QUEUE_SIZE * 2;
  queue_chars('C', QUEUE_SIZE * 2);
  test_assert(exp == dqueue_size(&dq));
  test_assert(exp == dqueue_SIZE(&dq));

  /* clear queue */
  dequeue_chars('B', QUEUE_SIZE / 2);
  dequeue_chars('A', QUEUE_SIZE * 2);
  dequeue_chars('C', QUEUE_SIZE * 2);

  return 0;
}
