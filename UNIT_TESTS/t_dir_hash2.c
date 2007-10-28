#include "../dir_hash.h"
#include "t_assert.h"

static int
nodot(const char *a, void *x)
{
  return a[0] != '.';
}

int
main(void)
{
  struct dir_hash dh;
  struct dir_array *da;

  dir_hash_init(&dh);
  da = dir_hash_array(&dh);
  da->filter = nodot;
  test_assert(dir_hash_open(&dh, "testdata/empty"));
  test_assert(dir_hash_check(&dh, "file001") == 0);
  dir_hash_free(&dh);
  return 0;
}
