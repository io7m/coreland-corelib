#include "alloc.h"
#include "bin.h"
#include "hashtable.h"
#include "uint32.h"

int ht_getu32(hashtable *h, const char *k, uint32 klen, uint32 *n)
{
  int ret;
  char *ptr;
  uint32 xlen;

  ret = ht_getb(h, k, klen, &ptr, &xlen);
  if (ret <= 0) return ret;
  if (xlen < 4) return -1;

  *n = *(uint32 *) ptr;
  return 1;
}
