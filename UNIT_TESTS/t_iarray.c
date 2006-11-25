#include <stdio.h>
#include "t_iarray.h"
#include "../iarray.h"

int iarray_integrity(struct iarray *ia)
{
  struct iarray_node *in;
  struct iarray_node *in_prev;
  struct iarray_node *in_next;
  unsigned long x;
  unsigned long ind;

  x = ia->a;
  in = ia->head;
  in_prev = 0;
  for (ind = 0; ind < x; ++ind) {
    if (in->prev != in_prev) {
      printf("fail: integrity: prev corrupted at %lu\n", ind);
      return 0;
    }
    in_prev = in;
    if (!in->next) {
      if (ind + 1 != x) {
        printf("fail: integrity: list truncated at %lu\n", ind);
        return 0;
      }
      break;
    } else in = in->next;
  }

  x = ia->a;
  in = ia->tail;
  in_next = 0;
  for (ind = 0; ind < x; ++ind) {
    if (in->next != in_next) {
      printf("fail: integrity: next corrupted at %lu\n", ind);
      return 0;
    }
    in_next = in;
    if (!in->prev) {
      if (ind + 1 != x) {
        printf("fail: integrity: list truncated at %lu\n", ind);
        return 0;
      }
      break;
    } else in = in->prev;
  }

  return 1;
}
