#include <stdio.h>
#include "../dir_array.h"
#include "../str.h"

int cmp(const char *a, const char *b)
{
  return -str_diff(a, b);
}

int main()
{
  struct dir_array da;
  char *fname;

  if (!dir_array_init(&da, "testdata/dir_array")) {
    printf("dir_array_init: could not open directory\n"); return 1;
  }

  dir_array_rewind(&da);
  for (;;) {
    if (!dir_array_next(&da, &fname)) break;
    if (!fname) { printf("fname == 0\n"); return 1; }
  }
  if (da.n != 12) { printf("da.n == %u expected %u\n", da.n, 12); return 1; }
  if (da.a[0][0] != '.') { printf("[%u] == %s\n", 0, da.a[0]); return 1; }
  if (da.a[1][0] != '.') { printf("[%u] == %s\n", 1, da.a[1]); return 1; }
  if (da.a[2][0] != '1') { printf("[%u] == %s\n", 2, da.a[2]); return 1; }
  if (da.a[3][0] != '1') { printf("[%u] == %s\n", 3, da.a[3]); return 1; }
  if (da.a[4][0] != '2') { printf("[%u] == %s\n", 4, da.a[4]); return 1; }
  if (da.a[5][0] != '3') { printf("[%u] == %s\n", 5, da.a[5]); return 1; }
  if (da.a[6][0] != '4') { printf("[%u] == %s\n", 6, da.a[6]); return 1; }
  if (da.a[7][0] != '5') { printf("[%u] == %s\n", 7, da.a[7]); return 1; }
  if (da.a[8][0] != '6') { printf("[%u] == %s\n", 8, da.a[8]); return 1; }
  if (da.a[9][0] != '7') { printf("[%u] == %s\n", 9, da.a[9]); return 1; }
  if (da.a[10][0] != '8') { printf("[%u] == %s\n", 10, da.a[10]); return 1; }
  if (da.a[11][0] != '9') { printf("[%u] == %s\n", 11, da.a[11]); return 1; }

  dir_array_setcmp(&da, cmp);
  dir_array_sort(&da);

  dir_array_rewind(&da);
  for (;;) {
    if (!dir_array_next(&da, &fname)) break;
    if (!fname) { printf("fname == 0\n"); return 1; }
  }
  if (da.n != 12) { printf("da.n == %u expected %u\n", da.n, 12); return 1; }
  if (da.a[0][0] != '9') { printf("[%u] == %s\n", 0, da.a[0]); return 1; }
  if (da.a[1][0] != '8') { printf("[%u] == %s\n", 1, da.a[1]); return 1; }
  if (da.a[2][0] != '7') { printf("[%u] == %s\n", 2, da.a[2]); return 1; }
  if (da.a[3][0] != '6') { printf("[%u] == %s\n", 3, da.a[3]); return 1; }
  if (da.a[4][0] != '5') { printf("[%u] == %s\n", 4, da.a[4]); return 1; }
  if (da.a[5][0] != '4') { printf("[%u] == %s\n", 5, da.a[5]); return 1; }
  if (da.a[6][0] != '3') { printf("[%u] == %s\n", 6, da.a[6]); return 1; }
  if (da.a[7][0] != '2') { printf("[%u] == %s\n", 7, da.a[7]); return 1; }
  if (da.a[8][0] != '1') { printf("[%u] == %s\n", 8, da.a[8]); return 1; }
  if (da.a[9][0] != '1') { printf("[%u] == %s\n", 9, da.a[9]); return 1; }
  if (da.a[10][0] != '.') { printf("[%u] == %s\n", 10, da.a[10]); return 1; }
  if (da.a[11][0] != '.') { printf("[%u] == %s\n", 11, da.a[11]); return 1; }

  dir_array_free(&da);
  return 0;
}
