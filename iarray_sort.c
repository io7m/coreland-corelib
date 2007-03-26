#include "iarray.h"

/* in-place mergesort. does not require extra space. */
void iarray_sort(struct iarray *ia, int (*cmp)(const void *, unsigned long,
                                               const void *, unsigned long))
{
  struct iarray_node *subl1;
  struct iarray_node *subl2;
  struct iarray_node *enext;
  struct iarray_node *merge_tail;
  struct iarray_node *merge_head;
  unsigned long base_size;
  unsigned long num_merges;
  unsigned long subl1_len;
  unsigned long subl2_len;
  unsigned long ind;

  /* initial size of sub-list */
  base_size = 1;
  merge_head = ia->head;

  for (;;) {
    subl1 = merge_head;
    num_merges = 0;
    merge_head = 0;
    merge_tail = 0;
    
    while (subl1) {
      num_merges++;

      /* work out size of sublist1 */
      subl2 = subl1;
      for (ind = 0; ind < base_size; ++ind) {
        subl1_len++;
        subl2 = subl2->next;
        if (!subl2) break;
      }
      subl2_len = base_size;

      /* attempt to merge lists */
      while (subl1_len || (subl2_len && subl2)) {
        if (!subl1_len) {
          enext = subl2; subl2 = subl2->next; --subl2_len;
          goto ADD_ELEMENT;
        }
        if (!subl2_len || !subl2) {
          enext = subl1; subl1 = subl1->next; --subl1_len;
          goto ADD_ELEMENT;
        }

        /* if node is unused, pick from other list to push unused nodes to end */
        if (!subl2->data) {
          if (!subl1->data) {
            enext = subl2; subl2 = subl2->next; --subl2_len;
            goto ADD_ELEMENT;
          } else {
            enext = subl1; subl1 = subl1->next; --subl1_len;
            goto ADD_ELEMENT;
          }
        }
        if (!subl1->data) {
          if (!subl2->data) {
            enext = subl1; subl1 = subl1->next; --subl1_len;
            goto ADD_ELEMENT;
          } else {
            enext = subl2; subl2 = subl2->next; --subl2_len;
            goto ADD_ELEMENT;
          }
        }

        /* always pick from first list if nodes are equal */
        if (cmp(subl1->data, subl1->len, subl2->data, subl2->len) <= 0) {
          enext = subl1; subl1 = subl1->next; --subl1_len;
          goto ADD_ELEMENT;
        } else {
          enext = subl2; subl2 = subl2->next; --subl2_len;
          goto ADD_ELEMENT;
        }

        ADD_ELEMENT:
        if (merge_tail)
          merge_tail->next = enext;
        else
          merge_head = enext;

        enext->prev = merge_tail;
        merge_tail = enext;
      }

      /* subl1 and subl2 have processed base_size nodes */
      subl1 = subl2;
    }

    merge_tail->next = 0;

    /* merge is finished? */
    if (num_merges <= 1) {
      ia->head = merge_head;
      ia->tail = merge_tail;
      return;
    }

    /* try again with larger merge lists */
    base_size *= 2;
  }
}
