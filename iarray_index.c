#include "iarray.h"

int iarray_nindex(const struct iarray *ia, unsigned long ind,
                  struct iarray_node **pin)
{
  struct iarray_node *in;
  unsigned long pind;

  if (ind >= ia->u) return 0;

  pind = 0;
  in = ia->head;

  for (;;) {
    if (in->data) {
      if (ind == pind) {
        *pin = in;
        return 1;
      }
      ++pind;
    }
    if (in->next)
      in = in->next;
    else
      return 0;
  }
}

int iarray_index(const struct iarray *ia, unsigned long ind,
                 void **ptr, unsigned long *len)
{
  struct iarray_node *in;

  if (iarray_nindex(ia, ind, &in)) {
    *ptr = in->data;
    *len = in->len;
    return 1;
  } else return 0;
}
