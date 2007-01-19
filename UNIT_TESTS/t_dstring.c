#include "../alloc.h"
#include "../dstring.h"
#include <stdio.h>
#include <stdlib.h>

#define BIG_STRING \
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\

void die_sys(const char *s)
{
  perror(s);
  exit(2);
}
void die_wrongnum(const char *s, unsigned int wanted, unsigned int got)
{
  printf("fail: %s %u %u\n", s, wanted, got);
  exit(1);
}
void die_wrongnumt(unsigned int t, const char *s, unsigned int wanted,
                   unsigned int got)
{
  printf("fail: (%u) ", t);
  die_wrongnum(s, wanted, got);
}

#define T_COMPARE(w,g,s,t) if ((w)!=(g)) die_wrongnumt((t),(s),(w),(g))

#define INITTEST "init_test:"
#define CATTEST "cat_test:"
#define COPYTEST "copy_test:"
#define CHOPTEST "chop_test:"

void initfree_test(struct dstring *ds)
{
  unsigned int num;
  if (!dstring_init(ds, 1)) die_sys("dstring_init");

  num = 1 + DSTRING_OVERALLOC;
  T_COMPARE(num, ds->a, INITTEST" a", 1);
  T_COMPARE(0, ds->len, INITTEST" len", 2);
  T_COMPARE(0, ds->s[0], INITTEST" s[0]", 3);

  dstring_free(ds);
  T_COMPARE(0, ds->a, INITTEST" a", 1);
  T_COMPARE(0, ds->len, INITTEST" len", 2);
  T_COMPARE(0, (unsigned long) ds->s, INITTEST" s ", 3); /* XXX: long ptr */
}

void cat_test(struct dstring *ds)
{
  /* 223 + 32 == 255 */
  if (!dstring_init(ds, 223)) die_sys("dstring_init");
  T_COMPARE(0, ds->len, CATTEST" len", 1);
  T_COMPARE(255, ds->a, CATTEST" a", 2);
  /* ds->s[255] == ok, ds->s[256] == overflow */

  T_COMPARE(0, dstring_0(ds), CATTEST" dstring_0", 3);

  /* 255 + 256 + 32 == 543 */
  if (!dstring_cats(ds, BIG_STRING)) die_sys("dstring_cats");
  T_COMPARE(256, ds->len, CATTEST" len", 4);
  T_COMPARE(543, ds->a, CATTEST" a", 5);

  T_COMPARE('A', ds->s[0], CATTEST" s[0]", 6);
  T_COMPARE('B', ds->s[1], CATTEST" s[1]", 7);
  T_COMPARE('C', ds->s[2], CATTEST" s[2]", 8);
  T_COMPARE('D', ds->s[3], CATTEST" s[3]", 9);
  T_COMPARE('E', ds->s[4], CATTEST" s[4]", 10);
  T_COMPARE('F', ds->s[5], CATTEST" s[5]", 11);
  T_COMPARE('G', ds->s[6], CATTEST" s[6]", 12);
  T_COMPARE('H', ds->s[7], CATTEST" s[7]", 13);

  T_COMPARE('1', ds->s[8], CATTEST" s[8]", 14);
  T_COMPARE('2', ds->s[9], CATTEST" s[9]", 15);
  T_COMPARE('3', ds->s[10], CATTEST" s[10]", 16);
  T_COMPARE('4', ds->s[11], CATTEST" s[11]", 17);
  T_COMPARE('5', ds->s[12], CATTEST" s[12]", 18);
  T_COMPARE('6', ds->s[13], CATTEST" s[13]", 19);
  T_COMPARE('7', ds->s[14], CATTEST" s[14]", 20);
  T_COMPARE('8', ds->s[15], CATTEST" s[15]", 21);

  T_COMPARE('1', ds->s[248], CATTEST" s[248]", 22);
  T_COMPARE('2', ds->s[249], CATTEST" s[249]", 23);
  T_COMPARE('3', ds->s[250], CATTEST" s[250]", 24);
  T_COMPARE('4', ds->s[251], CATTEST" s[251]", 25);
  T_COMPARE('5', ds->s[252], CATTEST" s[252]", 26);
  T_COMPARE('6', ds->s[253], CATTEST" s[253]", 27);
  T_COMPARE('7', ds->s[254], CATTEST" s[254]", 28);
  T_COMPARE('8', ds->s[255], CATTEST" s[255]", 29);

  T_COMPARE(256, dstring_0(ds), CATTEST" dstring_0", 30);

  while (ds->len != 542)
    if (!dstring_catb(ds, "X", 1)) die_sys("dstring_catb");

  T_COMPARE(543, ds->a, CATTEST" a", 31);
  T_COMPARE(542, ds->len, CATTEST" len", 32);

  if (!dstring_cat0(ds)) die_sys("dstring_cat0");

  /* 543 + 1 + 32 == 576 */
  T_COMPARE(576, ds->a, CATTEST" a", 33);
  T_COMPARE(543, ds->len, CATTEST" len", 34);

  dstring_free(ds);

  /* try integer overflow */

  if (!dstring_init(ds, 1)) die_sys("dstring_init");

  ds->a = (unsigned long) -8;
  ds->len = (unsigned long) -8;

  if (dstring_cats(ds, "ABCDEFGH12345678")) {
    printf("fail: cat_test: did not prevent integer overflow\n");
    printf("fail: ds.a = %lu\nds.len = %lu\n", ds->a, ds->len);
    exit(1);
  }

  dstring_free(ds);
}

void copy_test(struct dstring *ds)
{
  /* 1 + 32 == 33 */
  if (!dstring_init(ds, 1)) die_sys("dstring_init");

  /* 256 + 32 + 1 == 289 */
  if (!dstring_cpys(ds, BIG_STRING)) die_sys("dstring_cpys");
  T_COMPARE(256, ds->len, COPYTEST" len", 1);
  T_COMPARE(289, ds->a, COPYTEST" a", 2);
  /* ds->s[288] == ok, ds->s[289] == overflow */

  T_COMPARE('1', ds->s[248], COPYTEST" s[248]", 3);
  T_COMPARE('2', ds->s[249], COPYTEST" s[249]", 4);
  T_COMPARE('3', ds->s[250], COPYTEST" s[250]", 5);
  T_COMPARE('4', ds->s[251], COPYTEST" s[251]", 6);
  T_COMPARE('5', ds->s[252], COPYTEST" s[252]", 7);
  T_COMPARE('6', ds->s[253], COPYTEST" s[253]", 8);
  T_COMPARE('7', ds->s[254], COPYTEST" s[254]", 9);
  T_COMPARE('8', ds->s[255], COPYTEST" s[255]", 10);

  T_COMPARE('1', ds->s[8], COPYTEST" s[8]", 11);
  T_COMPARE('2', ds->s[9], COPYTEST" s[9]", 12);
  T_COMPARE('3', ds->s[10], COPYTEST" s[10]", 13);
  T_COMPARE('4', ds->s[11], COPYTEST" s[11]", 14);
  T_COMPARE('5', ds->s[12], COPYTEST" s[12]", 15);
  T_COMPARE('6', ds->s[13], COPYTEST" s[13]", 16);
  T_COMPARE('7', ds->s[14], COPYTEST" s[14]", 17);
  T_COMPARE('8', ds->s[15], COPYTEST" s[15]", 18);
}

void chop_test(struct dstring *ds)
{
  if (!dstring_cpys(ds, BIG_STRING)) die_sys("dstring_cpys");
  /* len == 256 */

  /* should do nothing */
  dstring_chop(ds, 300);
  T_COMPARE(256, ds->len, CHOPTEST" len", 1);

  /* should work */
  dstring_chop(ds, 20);
  T_COMPARE(20, ds->len, CHOPTEST" len ", 2);
  T_COMPARE(0, ds->s[20], CHOPTEST" s[20]", 3);

  /* edge case */
  if (!dstring_cpys(ds, BIG_STRING)) die_sys("dstring_cpys");

  while (ds->len != ds->a - 1)
    if (!dstring_catb(ds, "X", 1)) die_sys("dstring_catb");

  dstring_chop(ds, ds->a);
  T_COMPARE(288, ds->len, CHOPTEST" len ", 4);
  T_COMPARE(289, ds->a, CHOPTEST" a", 5);

  dstring_trunc(ds);
  T_COMPARE(0, ds->len, CHOPTEST" len ", 6);
  T_COMPARE(289, ds->a, CHOPTEST" a", 7);

  dstring_trunc(ds);
  T_COMPARE(0, ds->len, CHOPTEST" len ", 6);
  T_COMPARE(289, ds->a, CHOPTEST" a", 7);
}

int main()
{
  static struct dstring ds;

  initfree_test(&ds);
  cat_test(&ds);
  copy_test(&ds);
  chop_test(&ds);

  return 0;
}
