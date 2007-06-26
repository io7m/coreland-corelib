#include "alloc.h"
#include "bin.h"
#include "iarray.h"

/* allocate list of new nodes */
int iarray_newnodes(struct iarray_node **headptr, struct iarray_node **tailptr, 
                    unsigned long num)
{
  struct iarray_node *head;
  struct iarray_node *in = 0;
  struct iarray_node *in_prev;
  struct iarray_node *in_next;
  unsigned long ind;

  in_prev = 0;
  head = 0;
  for (ind = 0; ind < num; ++ind) {
    in = alloc(sizeof(struct iarray_node));
    if (!in) {
      if (!head) return 0;
      in = head;
      for (;;) {
        in_next = in->next;
        dealloc(in);
        if (in_next)
          in = in_next;
        else
          break;
      }
      return 0;
    }
    in->data = 0;
    in->len = 0;
    in->next = 0;
    in->prev = 0;
    if (!ind) head = in;
    if (ind) {
      in->prev = in_prev;
      in_prev->next = in;
    }
    in_prev = in;
  }
  if (headptr)
    *headptr = head;
  if (tailptr)
    *tailptr = in;
  return 1;
}

int iarray_fillnode(struct iarray_node *n, void *dat, unsigned long len)
{
  void *xdat;

  xdat = alloc(len);
  if (!xdat) return 0;

  bin_copy(dat, xdat, len);  

  n->data = xdat;
  n->len = len;
  return 1;
}
