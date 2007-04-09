#include <stdio.h>
#include "../env.h"
#include "../str.h"
#include "t_assert.h"

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
    test_assert(env_put(exp_tab[ind].exp_key, exp_tab[ind].exp_val));
    test_assert(env_get(exp_tab[ind].exp_key, &s));
    test_assert(str_same(s, exp_tab[ind].exp_val));
  }
  test_assert(env_unset(exp_tab[0].exp_key));
  test_assert(!env_get(exp_tab[0].exp_key, &s));
  test_assert(env_put(exp_tab[0].exp_key, exp_tab[0].exp_val));
  return 1;
}
int test_hammer()
{
  char cnum[32];
  const char *ptr;
  unsigned int ind;
  
  for (ind = 0; ind < 1024U; ++ind) {
    test_assert(snprintf(cnum, 32, "%x", ind) != -1);
    test_assert(env_put(cnum, cnum));
    test_assert(env_get(cnum, &ptr));
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
  env_clear();

  test_basic();
  test_assert(check() == 1);

  test_hammer();
  test_assert(check() == 1025U);
  return 0;
}
