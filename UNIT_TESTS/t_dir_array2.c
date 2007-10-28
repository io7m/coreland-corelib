#include <stdio.h>
#include "../dir_array.h"
#include "../str.h"
#include "t_assert.h"

static int
cmp(const char *a, const char *b, void *x)
{
  return -str_diff(a, b);
}

/* just a hack to make this test pass in SVN */
static int
filt(const char *a, void *x)
{
  return a[0] != '.';
}

int
main(void)
{
  struct dir_array da;
  char *fname;

  dir_array_init(&da);
  da.filter = filt;
  test_assert(dir_array_open(&da, "testdata/empty"));
  test_assert(dir_array_next(&da, &fname) == 0);
  dir_array_free(&da);
  return 0;
}
