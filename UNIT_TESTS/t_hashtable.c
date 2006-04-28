#include <stdio.h>
#include "../hashtable.h"

#define LOOPS 1000

struct thing {
  uint32 x;
  uint32 y;
  uint32 z;
};
struct big_thing {
  uint32 x;
  uint32 y;
  uint32 z;
  char pad[16];
};

int init_test(hashtable *ht)
{
  uint64 n;

  ht_init(ht);
  if (ht->size != HASH_BUCKETS) {
    printf("init_test: size == %u\n", ht->size);
    return 0;
  }
  n = ht_bytes(ht);
  if (n != (HASH_BUCKETS * sizeof(table_head)) + 4) {
    printf("init_test: n == %u\n", n);
    return 0;
  }
  return 1;
}
int add_test(hashtable *ht)
{
  uint32 k;
  int ret;
  struct thing th;

  for (k = 0; k < LOOPS; ++k) {
    th.x = k;
    th.y = (k + k) ^ k;
    th.z = (k + k) ^ th.y;

    ret = ht_addb(ht, (char *) &k, sizeof(uint32),
                      (char *) &th, sizeof(struct thing));
    switch (ret) {
      case -1:
        printf("add_test: ht_addb: no memory\n"); return 0; break;
      case 0:
        printf("add_test: ht_addb: duplicate key %u\n", k); return 0; break;
      default: break;
    }
  }
  return 1;
}
int get_test(hashtable *ht)
{
  uint32 k;
  uint32 sz;
  int ret;
  struct thing *tp;

  for (k = 0; k < LOOPS; ++k) {
    ret = ht_getb(ht, (char *) &k, sizeof(uint32),
                      (void *) &tp, &sz);
    switch (ret) {
      case 0:
        printf("get_test: ht_getb: key not found %u\n", k); return 0; break;
      default: break;
    }
    if (tp->x != k) { printf("get_test: x == %u\n", tp->x); return 0; }
    if (tp->y != ((k + k) ^ k)) {
      printf("get_test: y == %u\n", tp->y); return 0;
    }
    if (tp->z != ((k + k) ^ tp->y)) {
      printf("get_test: z == %u\n", tp->z); return 0;
    }
  }
  return 1;
}
/* replace calls deleteb */
int replace_test(hashtable *ht)
{
  uint32 k;
  uint32 j;
  uint32 sz;
  int ret;
  struct big_thing th;
  struct big_thing *tp;

  for (k = 0; k < LOOPS; ++k) {
    j = k * 2;
    th.x = j;
    th.y = j * 3;
    th.z = j * 4;

    ret = ht_replaceb(ht, (char *) &k, sizeof(uint32),
                          (void *) &th, sizeof(struct big_thing));
    switch (ret) {
      case 0:
        printf("replace_test: ht_replaceb: key not found %u\n", k);
        return 0; break;
      case -1:
        printf("replace_test: ht_replaceb: no memory\n");
        return 0; break;
      default: break;
    }
  }

  for (k = 0; k < LOOPS; ++k) {
    j = k * 2;
    ret = ht_getb(ht, (char *) &k, sizeof(uint32),
                      (void *) &tp, &sz);
    switch (ret) {
      case 0:
        printf("replace_test: ht_getb: key not found %u\n", k);
        return 0; break;
      default: break; 
    }
    if (tp->x != j) {
      printf("replace_test: %u != %u\n", tp->x, j);
      return 0;
    }
    if (tp->y != (j * 3)) {
      printf("replace_test: %u != %u\n", tp->y, (j * 3));
      return 0;
    }
    if (tp->z != (j * 4)) {
      printf("replace_test: %u != %u\n", tp->z, (j * 4));
      return 0;
    }
  }
  return 1;
}
int destroy_test(hashtable *ht)
{
  uint64 n;
  ht_destroy(ht);
  n = ht_bytes(ht);
  if (n != (HASH_BUCKETS * sizeof(table_head)) + 4) {
    printf("destroy_test: n == %u\n", n);
    return 0;
  }
  return 1;
}
int u32_test(hashtable *ht)
{
  uint32 u32;
  uint32 k;
  int ret;

  ht_init(ht);
  for (k = 0; k < LOOPS; ++k) {
    u32 = k * 2;
    ret = ht_addu32(ht, (char *) &k, sizeof(uint32), u32);
    switch (ret) {
      case 0:
        printf("u32_test: ht_addu32: duplicate key %u\n", k);
        return 0; break;
      case -1:
        printf("u32_test: ht_addu32: out of memory\n");
        return 0; break;
      default: break;
    }
  }
  for (k = 0; k < LOOPS; ++k) {
    ret = ht_getu32(ht, (char *) &k, sizeof(uint32), &u32);
    switch (ret) {
      case 0:
        printf("u32_test: ht_getu32: key not found %u\n", k);
        return 0; break;
      default: break;
    }
    if (u32 != (k * 2)) {
      printf("u32_test: %u != %u\n", u32, (k * 2));
      return 0;
    }
  }
  ht_destroy(ht);
  return 1;
}

int main()
{
  static hashtable ht;

  if (!init_test(&ht)) return 1;
  if (!add_test(&ht)) return 1;
  if (!get_test(&ht)) return 1;
  if (!replace_test(&ht)) return 1;
  if (!destroy_test(&ht)) return 1;
  if (!u32_test(&ht)) return 1;

  return 0;
}
