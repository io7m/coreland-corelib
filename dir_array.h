#ifndef DIR_ARRAY_H
#define DIR_ARRAY_H

struct dir_array {
  char **a;
  unsigned long p;
  unsigned long n;
};

int dir_array_init(struct dir_array *, const char *);
int dir_array_next(struct dir_array *, char **);

void dir_array_rewind(struct dir_array *);
void dir_array_free(struct dir_array *);
void dir_array_dump(struct dir_array *);

#endif
