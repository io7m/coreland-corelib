#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
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
  switch (ht_adds(&ht, key, "ABCD")) {
    case -1:
      perror("ht_adds");
      _exit(2);
    case 0:
      printf("fail: %s should not be in table\n", key);
      _exit(1);
    default:
      break;
  }
}

int main()
{
  ht_init(&ht);

  addkey("conf-ldfflistxx");
  addkey("conf-ldfflist");

  ht_free(&ht);
  return 0;
}
