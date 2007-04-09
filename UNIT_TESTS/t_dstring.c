#include <stdio.h>
#include <stdlib.h>
#include "../alloc.h"
#include "../dstring.h"
#include "t_assert.h"

#define BIG_STRING \
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\

void initfree_test(struct dstring *ds)
{
  unsigned int num;
  test_assert(dstring_init(ds, 1));

  num = 1 + DSTRING_OVERALLOC;
  test_assert(num == ds->a);
  test_assert(ds->len == 0);

  dstring_free(ds);
  test_assert(ds->a == 0);
  test_assert(ds->len == 0);
  test_assert(ds->s == 0);
}

void cat_test(struct dstring *ds)
{
  /* 223 + 32 == 255 */
  test_assert(dstring_init(ds, 223));

  test_assert(ds->len == 0);
  test_assert(ds->a == 255);
  test_assert(dstring_0(ds) == 0);

  /* 255 + 256 + 32 == 543 */
  test_assert(dstring_cats(ds, BIG_STRING));
  test_assert(ds->len == 256);
  test_assert(ds->a == 543);

  test_assert('A' ==  ds->s[0]);
  test_assert('B' ==  ds->s[1]);
  test_assert('C' ==  ds->s[2]);
  test_assert('D' ==  ds->s[3]);
  test_assert('E' ==  ds->s[4]);
  test_assert('F' ==  ds->s[5]);
  test_assert('G' ==  ds->s[6]);
  test_assert('H' ==  ds->s[7]);

  test_assert('1' ==  ds->s[8]);
  test_assert('2' ==  ds->s[9]);
  test_assert('3' ==  ds->s[10]);
  test_assert('4' ==  ds->s[11]);
  test_assert('5' ==  ds->s[12]);
  test_assert('6' ==  ds->s[13]);
  test_assert('7' ==  ds->s[14]);
  test_assert('8' ==  ds->s[15]);

  test_assert('1' ==  ds->s[248]);
  test_assert('2' ==  ds->s[249]);
  test_assert('3' ==  ds->s[250]);
  test_assert('4' ==  ds->s[251]);
  test_assert('5' ==  ds->s[252]);
  test_assert('6' ==  ds->s[253]);
  test_assert('7' ==  ds->s[254]);
  test_assert('8' ==  ds->s[255]);

  test_assert(256 == dstring_0(ds));

  while (ds->len != 542)
    test_assert(dstring_catb(ds, "X", 1));

  test_assert(543 == ds->a);
  test_assert(542 == ds->len);

  test_assert(dstring_cat0(ds));

  /* 543 + 1 + 32 == 576 */
  test_assert(576 == ds->a);
  test_assert(543 == ds->len);

  dstring_free(ds);

  /* try integer overflow */

  test_assert(dstring_init(ds, 1));

  ds->a = (unsigned long) -8;
  ds->len = (unsigned long) -8;

  test_assert(dstring_cats(ds, "ABCDEFGH12345678") == 0);
  dstring_free(ds);
}

void copy_test(struct dstring *ds)
{
  /* 1 + 32 == 33 */
  test_assert(dstring_init(ds, 1));

  /* 256 + 32 + 1 == 289 */
  test_assert(dstring_cpys(ds, BIG_STRING));
  test_assert(256 == ds->len);
  test_assert(289 == ds->a);
  /* ds->s[288] == ok, ds->s[289] == overflow */

  test_assert('1' ==  ds->s[248]);
  test_assert('2' ==  ds->s[249]);
  test_assert('3' ==  ds->s[250]);
  test_assert('4' ==  ds->s[251]);
  test_assert('5' ==  ds->s[252]);
  test_assert('6' ==  ds->s[253]);
  test_assert('7' ==  ds->s[254]);
  test_assert('8' ==  ds->s[255]);

  test_assert('1' ==  ds->s[8]);
  test_assert('2' ==  ds->s[9]);
  test_assert('3' ==  ds->s[10]);
  test_assert('4' ==  ds->s[11]);
  test_assert('5' ==  ds->s[12]);
  test_assert('6' ==  ds->s[13]);
  test_assert('7' ==  ds->s[14]);
  test_assert('8' ==  ds->s[15]);
}

void chop_test(struct dstring *ds)
{
  test_assert(dstring_cpys(ds, BIG_STRING));
  /* len == 256 */

  /* should do nothing */
  dstring_chop(ds, 300);
  test_assert(256 == ds->len);

  /* should work */
  dstring_chop(ds, 20);
  test_assert(20 == ds->len);
  test_assert(0 == ds->s[20]);

  /* edge case */
  test_assert(dstring_cpys(ds, BIG_STRING));

  while (ds->len != ds->a - 1)
    test_assert(dstring_catb(ds, "X", 1));

  dstring_chop(ds, ds->a);
  test_assert(288 == ds->len);
  test_assert(289 == ds->a);

  dstring_trunc(ds);
  test_assert(0 == ds->len);
  test_assert(289 == ds->a);

  dstring_trunc(ds);
  test_assert(0 == ds->len);
  test_assert(289 == ds->a);
}

int main(void)
{
  static struct dstring ds;

  initfree_test(&ds);
  cat_test(&ds);
  copy_test(&ds);
  chop_test(&ds);

  return 0;
}
