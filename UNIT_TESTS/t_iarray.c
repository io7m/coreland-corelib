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

void iarray_dump(struct iarray *ia, unsigned int type)
{
  struct iarray_node *ptr;
  unsigned long ind = 0;
  unsigned long num;
  char *str;

  ptr = ia->head;
  for (;;) {
    if (ptr) {
      printf("[%lu] [%p] ", ind, ptr);
      if (ptr->data) {
        switch (type) {
          case IARRAY_DUMP_STRING:
            str = ptr->data;
            printf("%s %lu", str, ptr->len);
            break;
          case IARRAY_DUMP_INT:
            num = * (unsigned long *) ptr->data;
            printf("%lu %lu", num, ptr->len);
            break;
          default:
            break;
        }
      } else printf("(null) (null)");
      printf(" %p %p\n", ptr->prev, ptr->next);
      ptr = ptr->next;
      ++ind;
    } else break;
  }
  printf("\n");
}
