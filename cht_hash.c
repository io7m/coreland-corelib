#include "chashtable.h"

#define CHT_HASH_MAGIC 0x3107

unsigned long cht_hash1(const void *k, unsigned long klen)
{
  unsigned const char *key = k; 
  unsigned long hash = CHT_HASH_MAGIC;
  unsigned char ch;

  while (klen--) { ch = *key; hash += ch; ++key; }

  hash -= hash << 6;
  hash ^= hash >> 17;
  hash -= hash << 9;
  hash ^= hash << 4;
  hash -= hash << 3;
  hash ^= hash << 10;
  hash ^= hash >> 15;

  return hash;
}

unsigned long cht_hash2(const void *k, unsigned long klen)
{
  unsigned const char *key = k; 
  unsigned long hash = CHT_HASH_MAGIC;
  unsigned char ch;

  while (klen--) { ch = *key; hash += ch; ++key; }

  hash += ~(hash << 15);
  hash ^= hash >> 10;
  hash += hash << 3;
  hash ^= hash >> 6;
  hash += ~(hash << 11);
  hash ^= hash >> 16;

  return hash;
}
