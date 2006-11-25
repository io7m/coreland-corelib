#include <stdio.h>
#include "../dir_array.h"

int main()
{
  struct dir_array da;
  char *fname;

  if (!dir_array_init(&da, ".")) {
    printf("dir_array_init: could not open directory\n"); return 1;
  }

  dir_array_rewind(&da);
  for (;;) {
    if (!dir_array_next(&da, &fname)) break;
    if (!fname) { printf("fname == 0\n"); return 1; }
  }
  dir_array_free(&da);

  return 0;
}
