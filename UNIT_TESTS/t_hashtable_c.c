#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../hashtable.h"
#include "../bin.h"
#include "../str.h"

void printn(const char *s, unsigned int len)
{
  while (len--) printf("%c", *s);
}

void addb(struct hashtable *h, const char *key, unsigned long klen,
                               const char *dat, unsigned long dlen, int exp)
{
  switch (ht_addb(h, key, klen, dat, dlen)) {
    case -1:
      if (exp != -1) {
        perror("ht_add: unexpected error -1");
        _exit(2);
      }
      break;
    case 1:
      if (exp != 1) {
        printf("fail: ht_add: unexpectedly returned 1\n");
        _exit(1);
      }
      break;
    case 0:
      if (exp != 0) {
        printf("fail: ht_add: unexpectedly returned 0\n");
        _exit(1);
      }
      break;
    default:
      printf("fail: add: reached default case statement, should never happen\n");
      _exit(1);
  }
}

void delete_keyb(struct hashtable *h, const char *key, unsigned long len, int exp)
{
  switch (ht_deleteb(h, key, len)) {
    case -1:
      if (exp != -1) {
        perror("ht_delete: unexpected error -1");
        _exit(2);
      }
      break;
    case 1:
      if (exp != 1) {
        printf("fail: ht_delete: unexpectedly returned 1\n");
        _exit(1);
      }
      break;
    case 0:
      if (exp != 0) {
        printf("fail: ht_delete: unexpectedly returned 0\n");
        _exit(1);
      }
      break;
    default:
      printf("fail: delete_key: reached default case statement, should never happen\n");
      _exit(1);
  }
}

void getb(struct hashtable *h, const char *key, unsigned long klen,
                               char **x, unsigned long *len, int exp)
{
  switch (ht_getb(h, key, klen, (void **) x, len)) {
    case -1:
      if (exp != -1) {
        perror("ht_get: unexpected error -1");
        _exit(2);
      }
      break;
    case 1:
      if (exp != 1) {
        printf("fail: ht_get: unexpectedly returned 1\n");
        _exit(1);
      }
      break;
    case 0:
      if (exp != 0) {
        printf("fail: ht_get: unexpectedly returned 0\n");
        _exit(1);
      }
      break;
    default:
      printf("fail: get: reached default case statement, should never happen\n");
      _exit(1);
  }
}

void replaceb(struct hashtable *h, const char *key, unsigned long klen,
                                   const char *dat, unsigned long dlen, int exp)
{
  switch (ht_replaceb(h, key, klen, dat, dlen)) {
    case -1:
      if (exp != -1) {
        perror("ht_replace: unexpected error -1");
        _exit(2);
      }
      break;
    case 1:
      if (exp != 1) {
        printf("fail: ht_replace: unexpectedly returned 1\n");
        _exit(1);
      }
      break;
    case 0:
      if (exp != 0) {
        printf("fail: ht_replace: unexpectedly returned 0\n");
        _exit(1);
      }
      break;
    default:
      printf("fail: replace: reached default case statement, should never happen\n");
      _exit(1);
  }
}

void add(struct hashtable *h, const char *k, const char *x, int exp)
{
  addb(h, k, str_len(k), x, str_len(x), exp);
}
void delete_key(struct hashtable *h, const char *k, int exp)
{
  delete_keyb(h, k, str_len(k), exp);
}
void get(struct hashtable *h, const char *k, char **x, unsigned long *len, int exp)
{
  getb(h, k, str_len(k), x, len, exp);
}
void replace(struct hashtable *h, const char *k, const char *x, int exp)
{
  replaceb(h, k, str_len(k), x, str_len(x), exp);
}
