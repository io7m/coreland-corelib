#include <math.h> /* severe problems on PPC if this is not included */
#include "scan_float.h"
#include "float32.h"

unsigned int scan_f32(const char *s, float32 *f)
{
  const char *t;
  char c;
  unsigned int pc;
  unsigned int div;
  float32 tf;
  float32 df;
  float32 xf; 

  t = s;
  pc = 0;
  tf = 0;
  df = 0;
  div = 1;

  if (s[0] == '-') ++s;

  for (;;) {
    c = s[pc];
    if (!c) goto END;
    if (c == '.') break;
    if ((c < '0') || (c > '9')) goto END;
    c -= '0';
    tf = (tf * 10) + c;
    ++pc;
  }

  /* skip '.' */
  ++pc;

  for (;;) {
    c = s[pc];
    if (!c) break;
    if ((c < '0') || (c > '9')) break;
    c -= '0';
    xf = (float32) c / pow(10, div);
    df += xf;
    ++pc;
    ++div;
  }

  tf = df + tf;

END:
  if (t[0] == '-') tf = -tf;
  *f = tf;

  return pc;
}
