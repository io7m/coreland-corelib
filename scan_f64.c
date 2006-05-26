#include <math.h> /* severe problems on PPC if this is not included */
#include "scan_fspec.h"

unsigned int scan_float64(const char *s, float64 *f)
{
  const char *t;
  char c;
  unsigned int pc;
  unsigned int div;
  float64 tf;
  float64 df;
  float64 xf; 

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
    xf = (float64) c / pow(10, div);
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
