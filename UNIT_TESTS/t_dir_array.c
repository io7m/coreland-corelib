#include <stdio.h>
#include "../dir_array.h"
#include "../str.h"
#include "t_assert.h"

int cmp(const char *a, const char *b, void *x)
{
  return -str_diff(a, b);
}

int main(void)
{
  struct dir_array da;
  char *fname;

  test_assert(dir_array_init(&da, "testdata/dir_array"));

  dir_array_rewind(&da);
  for (;;) {
    if (!dir_array_next(&da, &fname)) break;
    test_assert(fname);
  }
  test_assert(da.n == 12);
  test_assert(da.a[0][0] == '.');
  test_assert(da.a[1][0] == '.');
  test_assert(da.a[2][0] == '1');
  test_assert(da.a[3][0] == '1');
  test_assert(da.a[4][0] == '2');
  test_assert(da.a[5][0] == '3');
  test_assert(da.a[6][0] == '4');
  test_assert(da.a[7][0] == '5');
  test_assert(da.a[8][0] == '6');
  test_assert(da.a[9][0] == '7');
  test_assert(da.a[10][0] == '8');
  test_assert(da.a[11][0] == '9');

  dir_array_setcmp(&da, cmp);
  dir_array_sort(&da);

  dir_array_rewind(&da);
  for (;;) {
    if (!dir_array_next(&da, &fname)) break;
    test_assert(fname);
  }
  test_assert(da.n == 12);
  test_assert(da.a[0][0] == '9');
  test_assert(da.a[1][0] == '8');
  test_assert(da.a[2][0] == '7');
  test_assert(da.a[3][0] == '6');
  test_assert(da.a[4][0] == '5');
  test_assert(da.a[5][0] == '4');
  test_assert(da.a[6][0] == '3');
  test_assert(da.a[7][0] == '2');
  test_assert(da.a[8][0] == '1');
  test_assert(da.a[9][0] == '1');
  test_assert(da.a[10][0] == '.');
  test_assert(da.a[11][0] == '.');

  dir_array_free(&da);
  return 0;
}
