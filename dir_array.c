#include "alloc.h"
#include "bin.h"
#include "dir_array.h"
#include "direntry.h"
#include "str.h"

static int
dir_array_strdiff(const char *a, const char *b, void *x) { return str_diff(a, b); }
void
dir_array_rewind(struct dir_array *da) { da->p = 0; }

int
dir_array_next(struct dir_array *da, char **p)
{
  unsigned long m;
  unsigned long n;

  if (!da->n) return 0;

  m = da->p;
  n = da->n - 1;

  if (m > n) return 0;
  *p = da->a[m];
  da->p++;

  return 1;
}

void
dir_array_sort(struct dir_array *da)
{
  unsigned long m;
  unsigned long n;
  unsigned long x;
  unsigned long y;
  char **arr;
  char *tmp;
  int (*cmp)(const char *, const char *, void *);

  if (!da->n) return;

  n = da->n;
  m = (n >> 1);
  arr = da->a;
  tmp = 0;
  cmp = 0;

  cmp = da->cmp;
  for (;;) {
    if (m > 0) {
      --m;
      tmp = arr[m];
    } else {
      --n;
      if (!n) break;
      tmp = arr[n];
      arr[n] = arr[0];
    }
    x = m;
    y = (m << 1) + 1;
    
    while (y < n) {
      if ((y + 1 < n) && (cmp(arr[y + 1], arr[y], da->data) > 0)) ++y;
      if (cmp(arr[y], tmp, da->data) > 0) {
        arr[x] = arr[y];
        x = y;
        y = (x << 1) + 1;
      } else {
        break;
      }
    }
    arr[x] = tmp;
  } 
}

void
dir_array_init(struct dir_array *da)
{
  da->a = 0;
  da->p = 0;
  da->n = 0;
  da->cmp = dir_array_strdiff;
  da->filter = 0;
  da->data = 0;
}

int
dir_array_open(struct dir_array *da, const char *p)
{
  DIR *dir;
  direntry *d_ent;
  unsigned long n;
  unsigned long len;
  char *tmp;

  dir = opendir(p);
  if (!dir) return 0;

  n = 0;
  for (;;) {
    d_ent = readdir(dir);
    if (!d_ent) break;
    if (da->filter)
      if (!da->filter(d_ent->d_name, da->data)) continue;
    ++n;
  }
  rewinddir(dir);

  if (!n) return 1;

  da->p = 0;
  da->n = n;
  da->a = alloc(n * sizeof(char *));
  if (!da->a) {
    closedir(dir);
    return 0;
  }

  n = 0;
  for (;;) {
    if (n == da->n) break;
    d_ent = readdir(dir);
    if (!d_ent) break;
    len = str_len(d_ent->d_name);
    if (!len) continue;
    if (da->filter)
      if (!da->filter(d_ent->d_name, da->data)) continue;
    tmp = alloc(len + 1);
    if (!tmp) goto NOMEM;
    bin_copy(d_ent->d_name, tmp, len);
    tmp[len] = 0;
    da->a[n] = tmp; ++n;
  }

  closedir(dir);
  dir_array_sort(da);
  return 1;
NOMEM:
  closedir(dir);
  dir_array_free(da);
  return 0;
}

void dir_array_free(struct dir_array *da)
{
  unsigned long n;
  unsigned long m;

  n = da->n;
  m = 0;

  while (m != n) {
    if (da->a[m]) dealloc(da->a[m]); ++m;
  }

  dealloc(da->a);
  da->p = 0;
  da->n = 0;
  da->cmp = 0;
  da->filter = 0;
  da->data = 0;
  return;
}
