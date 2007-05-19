#ifndef CORELIB_DSTRING_H
#define CORELIB_DSTRING_H

#define DSTRING_OVERALLOC 32
#define dstring_INIT {0,0,0}

struct dstring {
  char *s;
  unsigned long len;
  unsigned long a;
};

int dstring_init(struct dstring *, unsigned long);
void dstring_free(struct dstring *);

int dstring_cat(struct dstring *, const struct dstring *);
int dstring_catb(struct dstring *, const char *, unsigned long);
int dstring_cats(struct dstring *, const char *);
int dstring_cat0(struct dstring *);
void dstring_0(struct dstring *);

int dstring_cpyb(struct dstring *, const char *, unsigned long);
int dstring_cpys(struct dstring *, const char *);
int dstring_copy(struct dstring *, const struct dstring *);

void dstring_trunc(struct dstring *);
void dstring_chop(struct dstring *, unsigned long);

unsigned long dstring_size(const struct dstring *);
const char *dstring_data(const struct dstring *);

#endif
