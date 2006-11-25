#include "alloc.h"
#include "iarray.h"

int iarray_insert(struct iarray *ia, unsigned long ind,
                  void *dat, unsigned long dlen)
{
  struct iarray_node *in;
  struct iarray_node *tn;
  struct iarray_node *sn;

  tn = 0;
  sn = 0;
  if (iarray_nindex(ia, ind, &in)) {
    if (in->prev) {
      /* find unused node */
      sn = in->prev;
      for (;;) {
        if (!sn->data)
          tn = sn;
        else
          break;
        if (sn->prev)
          sn = sn->prev;
        else
          break;
      }
      if (tn) {
        ++ia->u;
        return iarray_fillnode(tn, dat, dlen);
      } else {
        /* insert new node */
        if (!iarray_newnodes(&tn, 0, 1)) return 0;
        if (!iarray_fillnode(tn, dat, dlen)) {
          dealloc(tn);
          return 0;
        }
        tn->next = in;
        tn->prev = in->prev;
        in->prev->next = tn;
        in->prev = tn;
        ++ia->a;
        ++ia->u;
        return 1;
      }
    } else {
      /* new head node */
      if (!iarray_newnodes(&tn, 0, 1)) return 0;
      if (!iarray_fillnode(tn, dat, dlen)) {
        dealloc(tn);
        return 0;
      }
      tn->next = ia->head;
      ia->head->prev = tn;
      ia->head = tn;
      ++ia->a;
      ++ia->u;
    }
    return 1;
  } else return 0;
}
