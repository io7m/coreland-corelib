#ifndef DIR_ARRAY_H
#define DIR_ARRAY_H

typedef struct {
  char  **a;
  unsigned long p;
  unsigned long n;
} dir_array;

int dir_array_init(dir_array *, const char *);
int dir_array_next(dir_array *, char **);

void dir_array_rewind(dir_array *);
void dir_array_free(dir_array *);
void dir_array_dump(dir_array *);

#endif
