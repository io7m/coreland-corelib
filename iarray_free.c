#include "alloc.h"
#include "iarray.h"

void iarray_free(struct iarray *ia)
{
  struct iarray_node *in;
  struct iarray_node *in_next;

  in = ia->head;
  in_next = 0;
  for (;;) {
    in_next = in->next;
    if (in->data)
      dealloc(in->data);
    dealloc(in);
    if (in_next)
      in = in_next;
    else
      break;
  }
  ia->a = 0;
  ia->u = 0;
  ia->head = 0;
  ia->tail = 0;
}
