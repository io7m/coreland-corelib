#include <stdio.h>
#include "../env.h"
#include "../str.h"

void env_dump()
{
  unsigned int i;
  if (!environ) return;
  for (i = 0; environ[i]; ++i)
    printf("%s\n", environ[i]);
}

struct exp {
  const char *exp_key;
  const char *exp_val;
};

static const struct exp exp_tab[] = {
  {"sun", "stars"},
  {"sun", "moon"},
  {"sun", "planet"},
};

int test_basic()
{
  unsigned int ind;
  const char *s;

  for (ind = 0; ind < sizeof(exp_tab) / sizeof(struct exp); ++ind) {
    if (!env_put(exp_tab[ind].exp_key, exp_tab[ind].exp_val)) {
      perror("env_put"); return 0;
    }
    if (!env_get(exp_tab[ind].exp_key, &s)) {
      printf("fail: env_get returned 0\n");
      return 0;
    }
    if (!str_same(s, exp_tab[ind].exp_val)) {
      printf("fail: env_get expected %s got %s\n", exp_tab[ind].exp_val, s);
      return 0;
    }
  }
  if (!env_unset(exp_tab[0].exp_key)) {
    printf("fail: env_unset no such key\n");
    return 0;
  }
  if (env_get(exp_tab[0].exp_key, &s)) {
    printf("fail: env_get returned 1 for nonexistant key\n");
    return 0;
  }
  if (!env_put(exp_tab[0].exp_key, exp_tab[0].exp_val)) {
    perror("env_put"); return 0;
  }
  return 1;
}
int test_hammer()
{
  char cnum[32];
  const char *ptr;
  unsigned int ind;
  
  for (ind = 0; ind < 1024U; ++ind) {
    if (snprintf(cnum, 32, "%x", ind) == -1) { perror("snprintf"); return 0; }
    if (!env_put(cnum, cnum)) { perror("env_put"); return 0; } 
    if (!env_get(cnum, &ptr)) {
      printf("fail: could not retrieve variable %s\n", cnum);
      return 0;
    }
  }
  return 1;
}

unsigned int check()
{
  char *vp;
  unsigned int ind;

  for (ind = 0;; ++ind) {
    vp = environ[ind];
    if (!vp) break;
  }
  return ind;
}

int main(void)
{
  unsigned int len;

  env_clear();

  if (!test_basic()) return 1;
  len = check();
  if (len != 1) { printf("fail: check 1 == %u\n", len); return 1; }

  if (!test_hammer()) return 1;
  len = check();
  if (len != 1025U) { printf("fail: check 2 == %u\n", len); return 1; }

  return 0;
}
