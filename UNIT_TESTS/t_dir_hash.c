#include "../dir_hash.h"
#include "t_assert.h"

int main(void)
{
  struct dir_hash dh;

  test_assert(dir_hash_init(&dh, "testdata/dir_hash"));
  test_assert(dir_hash_check(&dh, "file001"));

  test_assert(dir_hash_check(&dh, "file001"));
  test_assert(dir_hash_check(&dh, "file002"));
  test_assert(dir_hash_check(&dh, "file003"));
  test_assert(dir_hash_check(&dh, "file004"));
  test_assert(dir_hash_check(&dh, "file005"));
  test_assert(dir_hash_check(&dh, "file006"));
  test_assert(dir_hash_check(&dh, "file007"));
  test_assert(dir_hash_check(&dh, "file008"));

  test_assert(dir_hash_check(&dh, "A"));
  test_assert(dir_hash_check(&dh, "B"));
  test_assert(dir_hash_check(&dh, "C"));
  test_assert(dir_hash_check(&dh, "D"));
  test_assert(dir_hash_check(&dh, "E"));
  test_assert(dir_hash_check(&dh, "F"));
  test_assert(dir_hash_check(&dh, "G"));
  test_assert(dir_hash_check(&dh, "H"));

  dir_hash_free(&dh);
  return 0;
}
