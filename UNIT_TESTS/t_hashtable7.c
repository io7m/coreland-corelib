#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "t_assert.h"
#include "../hashtable.h"

/* 
 * if two keys hash to the same slot number and 
 * match in all characters of the shorter key, there
 * is an incorrect key collision. this bug is now fixed
 * and this test prevents regression
 *
 */

struct hashtable ht;

void addkey(const char *key)
{
  int r;

  r = ht_adds(&ht, key, "ABCD");
  test_assert(r != -1);
  test_assert(r != 0);
}

int main(void)
{
  test_assert(ht_init(&ht));

  addkey("conf-ldfflistxx");
  addkey("conf-ldfflist");

  ht_free(&ht);
  return 0;
}
