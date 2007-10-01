#ifndef CORELIB_DIR_ARRAY_H
#define CORELIB_DIR_ARRAY_H

#define DIR_ARRAY_ZERO {0,0,0,0,0,0}

struct dir_array {
  char **a;
  unsigned long p;
  unsigned long n;
  int (*cmp)(const char *, const char *, void *);
  int (*filter)(const char *, void *);
  void *data;
};

void dir_array_init(struct dir_array *);
int dir_array_open(struct dir_array *, const char *);
void dir_array_rewind(struct dir_array *);
void dir_array_sort(struct dir_array *);
int dir_array_next(struct dir_array *, char **);
void dir_array_free(struct dir_array *);

#endif
