#include "chashtable.h"

unsigned long cht_hash1(const void *k, unsigned long len)
{
  const char *key = k;
  unsigned long hash = 5381;
  unsigned long ch;

  while (len) {
    ch = *key;
    hash = ((hash << 5) + hash) ^ ch;
    --len; ++key;
  }
  return hash;
}

unsigned long cht_hash2(const void *k, unsigned long len)
{
  const char *key = k;
  unsigned long hash = 0x4E67C6A7;
  unsigned long ch;

  while (len) {
    ch = *key;
    hash = (hash << 4) + ch;
    hash ^= (hash >> 24);
    hash &= ~hash;
    --len; ++key;
  }
  return hash;
}
