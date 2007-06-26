#include "alloc.h"
#include "bin.h"
#include "dqueue.h"

int dqueue_enq(struct dqueue *dq, void *p)
{
  register unsigned char *dp;
  register unsigned char *sp;
  unsigned long cur_alloc;
  unsigned long cur_used;
  unsigned long new_alloc;
  unsigned long head_bpos;
  unsigned long head_size;
  unsigned long tail_bpos;
  unsigned int es;

  es = dq->es;
  cur_used = dq->u * es;
  cur_alloc = dq->a * es;

  /* reallocate? */
  if (cur_alloc / dq->a != es) return 0; /* check wrap */
  new_alloc = cur_alloc * 2;
  if (new_alloc < cur_alloc) return 0; /* check wrap */
  if (cur_used + 1 > cur_alloc) {
    if (!alloc_re(&dq->x, cur_alloc, new_alloc)) return 0;
    dq->a = new_alloc / es;
    head_bpos = dq->hpos * es;
    tail_bpos = dq->tpos * es;
    /* move data past hpos into end of newly allocated section */
    if (head_bpos > tail_bpos) {
      head_size = cur_alloc - head_bpos;
      dp = ((unsigned char *) dq->x) + new_alloc - head_size;
      sp = ((unsigned char *) dq->x) + head_bpos;
      bin_copy(sp, dp, head_size);
      bin_zero(sp, head_size);
      head_bpos = new_alloc - head_size;
      dq->hpos = head_bpos / es;
    }
  }

  dq->tpos = (dq->tpos + 1) % dq->a;
  ++dq->u;

  dp = ((unsigned char *) dq->x) + (dq->tpos * es);
  sp = p;
 
  for (;;) {
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
    if (!es) break; *dp++ = *sp++; --es;
  }
  return 1;
}
