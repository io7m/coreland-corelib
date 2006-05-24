#include "alloc.h"
#include "bin.h"
#include "env.h"
#include "str.h"

static int inited;
static unsigned int esize;
static unsigned int eused;

static int do_init()
{
  char *vp;
  char **new_env;
  unsigned int i;
  unsigned int j;

  eused = 0;
  esize = 0;

  if (environ)
    for (;;) if (environ[++esize] == 0) break;

  esize += ENV_OVERALLOC;
  new_env = (char **) alloc(esize * sizeof(char *));
  if (!new_env) return 0;

  if (environ) {
    for (i = 0;; ++i) {
      vp = environ[i];
      if (!vp) break;
      if (!str_dup(vp, &new_env[i])) {
        for (j = 0; j < i; ++j)
          if (new_env[j]) { dealloc(new_env[j]); new_env[j] = 0; }
        dealloc(environ);
        environ = 0;
        return 0;
      }
      ++eused;
    }
  }

  environ = new_env;
  return inited = 1;
}

static void delete_all(const char *key, unsigned int klen)
{
  unsigned int len;
  unsigned int slen;
  unsigned int i;

  if (!eused) return;

  for (i = eused - 1;; --i) {
    len = klen;
    slen = str_len(environ[i]);
    if (len > slen) len = slen;
    if (str_nsame(key, environ[i], len))
      if (environ[i][len] == '=') {
        dealloc(environ[i]);
        environ[i] = environ[--eused];
        environ[eused] = 0;
      }
    if (!i) break;
  }
}

static int add(const char *key, const char *val,
               unsigned int klen, unsigned int vlen)
{
  char *s;
  char *to_put;
  char **new_env;
  unsigned int ind;

  if (!inited)
    if (!do_init()) return 0;

  delete_all(key, klen);

  if (eused == (esize - 1)) {
    new_env = (char **) alloc((esize + 1 + ENV_OVERALLOC) * sizeof(char *));
    if (!new_env) {
      env_clear();
      return 0;
    }
    for (ind = 0; ind < (esize - 1); ++ind)
      new_env[ind] = environ[ind];
    dealloc(environ);
    environ = new_env;
    esize += 1 + ENV_OVERALLOC;
  }

  to_put = alloc(klen + 1 + vlen + 1);
  s = to_put;

  bin_copy(key, s, klen); s += klen;
  s[0] = '='; ++s;
  bin_copy(val, s, vlen); s += vlen;
  s[0] = 0;

  environ[eused++] = to_put;
  environ[eused] = 0;
  return 1;
}

/* interface */

int env_put(const char *key, const char *val)
{
  unsigned int klen;
  unsigned int vlen;

  klen = str_len(key);
  vlen = str_len(val);
  
  if (!klen) return 0;
  return add(key, val, klen, vlen);
}

int env_unset(const char *key)
{
  unsigned int klen;
  const char *dummy;

  klen = str_len(key);
  if (!klen) return 0;
  if (!env_get(key, &dummy)) return 0;
  
  delete_all(key, klen);
  return 1;
}

void env_clear()
{
  if (inited) {
    unsigned int ind;
    for (ind = 0; ind < esize; ++ind)
      if (environ[ind]) {
        dealloc(environ[ind]);
        environ[ind] = 0;
      }
    dealloc(environ);
  }
  environ = 0;
}
