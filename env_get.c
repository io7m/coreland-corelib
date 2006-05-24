#include "env.h"
#include "str.h"

int env_get(const char *key, const char **val)
{
  char *vp;
  unsigned int klen;
  unsigned int vlen;
  unsigned int i;

  if ((!key) || (!environ)) return 0;
  klen = str_len(key);
  if (!klen) return 0;

  for (i = 0; (vp = environ[i]); ++i) {
    vlen = str_len(vp);
    if (klen >= vlen) continue;
    if (str_nsame(key, vp, klen) && (vp[klen] == '=')) {
      *val = vp + klen + 1;;
      return 1;
    }
  }
  return 0;
}
