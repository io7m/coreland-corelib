#include "t_assert.h"
#include "../rmkdir.h"

int main(void)
{
  test_assert(rmkdir("test_rmkdir/a/b/c/d/e/f", 0700) != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d/e/f") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d/e") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c") != -1);
  test_assert(rmdir("test_rmkdir/a/b") != -1);
  test_assert(rmdir("test_rmkdir/a") != -1);
  test_assert(rmdir("test_rmkdir") != -1);

  test_assert(rmkdir("test_rmkdir/a/b/c/d/e/f/", 0700) != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d/e/f") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d/e") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c") != -1);
  test_assert(rmdir("test_rmkdir/a/b") != -1);
  test_assert(rmdir("test_rmkdir/a") != -1);
  test_assert(rmdir("test_rmkdir") != -1);

  test_assert(rmkdir("test_rmkdir/a/b/c/d/e", 0700) != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d/e") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c") != -1);
  test_assert(rmdir("test_rmkdir/a/b") != -1);
  test_assert(rmdir("test_rmkdir/a") != -1);
  test_assert(rmdir("test_rmkdir") != -1);

  test_assert(rmkdir("test_rmkdir/a/b/c/d/e/", 0700) != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d/e") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c/d") != -1);
  test_assert(rmdir("test_rmkdir/a/b/c") != -1);
  test_assert(rmdir("test_rmkdir/a/b") != -1);
  test_assert(rmdir("test_rmkdir/a") != -1);
  test_assert(rmdir("test_rmkdir") != -1);

  test_assert(rmkdir("test_rmkdir", 0700) != -1);
  test_assert(rmdir("test_rmkdir") != -1);

  test_assert(rmkdir("test_rmkdir/a", 0700) != -1);
  test_assert(rmdir("test_rmkdir/a") != -1);
  test_assert(rmdir("test_rmkdir") != -1);

  test_assert(rmkdir("test_rmkdir/../test_rmkdir2/../test_rmkdir3", 0700) != -1);
  test_assert(rmdir("test_rmkdir") != -1);
  test_assert(rmdir("test_rmkdir2") != -1);
  test_assert(rmdir("test_rmkdir3") != -1);

  return 0;
}
