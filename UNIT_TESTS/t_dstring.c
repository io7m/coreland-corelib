#include "../dstring.h"
#include <stdio.h>

#define BIG_STRING \
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\
"ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678ABCDEFGH12345678"\

int init_test(dstring *ds)
{
  if (!dstring_init(ds, 1)) {
    perror("dstring_init");
    return 0;
  }
  if (ds->a != (1 + DSTRING_OVERALLOC)) {
    printf("init_test: a == %u\n", ds->a);
    return 0;
  }
  if (ds->len != 0) {
    printf("init_test: len == %u\n", ds->len);
    return 0;
  }
  if (ds->s[0] != 0) {
    printf("init_test: s[0] == %c\n", ds->s[0]);
    return 0;
  }
  return 1;
}

int cat_test(dstring *ds)
{
  if (!dstring_cats(ds, "ABCDEFGH")) {
    perror("dstring_cats");
    return 0;
  }

  if (ds->s[0] != 'A') { printf("cat_test: s[0] == %c\n", ds->s[0]); return 0; }
  if (ds->s[1] != 'B') { printf("cat_test: s[1] == %c\n", ds->s[1]); return 0; }
  if (ds->s[2] != 'C') { printf("cat_test: s[2] == %c\n", ds->s[2]); return 0; }
  if (ds->s[3] != 'D') { printf("cat_test: s[3] == %c\n", ds->s[3]); return 0; }
  if (ds->s[4] != 'E') { printf("cat_test: s[4] == %c\n", ds->s[4]); return 0; }
  if (ds->s[5] != 'F') { printf("cat_test: s[5] == %c\n", ds->s[5]); return 0; }
  if (ds->s[6] != 'G') { printf("cat_test: s[6] == %c\n", ds->s[6]); return 0; }
  if (ds->s[7] != 'H') { printf("cat_test: s[7] == %c\n", ds->s[7]); return 0; }
  if (ds->len != 8) { printf("cat_test: len == %u\n", ds->len); return 0; }

  if (!dstring_cat0(ds)) {
    perror("dstring_cat0");
    return 0;
  }

  if (ds->s[8] != 0) { printf("cat_test: s[8] == %c\n", ds->s[8]); return 0; }

  if (!dstring_catb(ds, "12345678", 8)) {
    perror("dstring_catb");
    return 0;
  }

  if (ds->s[9] != '1') { printf("cat_test: s[9] == %c\n", ds->s[9]); return 0; }
  if (ds->s[10] != '2') { printf("cat_test: s[10] == %c\n", ds->s[10]); return 0; }
  if (ds->s[11] != '3') { printf("cat_test: s[11] == %c\n", ds->s[11]); return 0; }
  if (ds->s[12] != '4') { printf("cat_test: s[12] == %c\n", ds->s[12]); return 0; }
  if (ds->s[13] != '5') { printf("cat_test: s[13] == %c\n", ds->s[13]); return 0; }
  if (ds->s[14] != '6') { printf("cat_test: s[14] == %c\n", ds->s[14]); return 0; }
  if (ds->s[15] != '7') { printf("cat_test: s[15] == %c\n", ds->s[15]); return 0; }
  if (ds->s[16] != '8') { printf("cat_test: s[16] == %c\n", ds->s[16]); return 0; }
  if (ds->len != 17) { printf("cat_test: len == %u\n", ds->len); return 0; }

  /* suspicious use of byte copying... */

  if (!dstring_catb(ds, ds->s, ds->len)) {
    perror("dstring_catb");
    return 0;
  }

  if (ds->len != 34) { printf("cat_test: len == %u\n", ds->len); return 0; }
  if (ds->s[0] != 'A') { printf("cat_test: s[0] == %c\n", ds->s[0]); return 0; }
  if (ds->s[1] != 'B') { printf("cat_test: s[1] == %c\n", ds->s[1]); return 0; }
  if (ds->s[2] != 'C') { printf("cat_test: s[2] == %c\n", ds->s[2]); return 0; }
  if (ds->s[3] != 'D') { printf("cat_test: s[3] == %c\n", ds->s[3]); return 0; }
  if (ds->s[4] != 'E') { printf("cat_test: s[4] == %c\n", ds->s[4]); return 0; }
  if (ds->s[5] != 'F') { printf("cat_test: s[5] == %c\n", ds->s[5]); return 0; }
  if (ds->s[6] != 'G') { printf("cat_test: s[6] == %c\n", ds->s[6]); return 0; }
  if (ds->s[7] != 'H') { printf("cat_test: s[7] == %c\n", ds->s[7]); return 0; }
  if (ds->s[8] != 0) { printf("cat_test: s[8] == %c\n", ds->s[8]); return 0; }
  if (ds->s[9] != '1') { printf("cat_test: s[9] == %c\n", ds->s[9]); return 0; }
  if (ds->s[10] != '2') { printf("cat_test: s[10] == %c\n", ds->s[10]); return 0; }
  if (ds->s[11] != '3') { printf("cat_test: s[11] == %c\n", ds->s[11]); return 0; }
  if (ds->s[12] != '4') { printf("cat_test: s[12] == %c\n", ds->s[12]); return 0; }
  if (ds->s[13] != '5') { printf("cat_test: s[13] == %c\n", ds->s[13]); return 0; }
  if (ds->s[14] != '6') { printf("cat_test: s[14] == %c\n", ds->s[14]); return 0; }
  if (ds->s[15] != '7') { printf("cat_test: s[15] == %c\n", ds->s[15]); return 0; }
  if (ds->s[16] != '8') { printf("cat_test: s[16] == %c\n", ds->s[16]); return 0; }
  if (ds->s[17] != 'A') { printf("cat_test: s[17] == %c\n", ds->s[17]); return 0; }
  if (ds->s[18] != 'B') { printf("cat_test: s[18] == %c\n", ds->s[18]); return 0; }
  if (ds->s[19] != 'C') { printf("cat_test: s[19] == %c\n", ds->s[19]); return 0; }
  if (ds->s[20] != 'D') { printf("cat_test: s[20] == %c\n", ds->s[20]); return 0; }
  if (ds->s[21] != 'E') { printf("cat_test: s[21] == %c\n", ds->s[21]); return 0; }
  if (ds->s[22] != 'F') { printf("cat_test: s[22] == %c\n", ds->s[22]); return 0; }
  if (ds->s[23] != 'G') { printf("cat_test: s[23] == %c\n", ds->s[23]); return 0; }
  if (ds->s[24] != 'H') { printf("cat_test: s[24] == %c\n", ds->s[24]); return 0; }
  if (ds->s[25] != 0) { printf("cat_test: s[25] == %c\n", ds->s[25]); return 0; }
  if (ds->s[26] != '1') { printf("cat_test: s[26] == %c\n", ds->s[26]); return 0; }
  if (ds->s[27] != '2') { printf("cat_test: s[27] == %c\n", ds->s[27]); return 0; }
  if (ds->s[28] != '3') { printf("cat_test: s[28] == %c\n", ds->s[28]); return 0; }
  if (ds->s[29] != '4') { printf("cat_test: s[29] == %c\n", ds->s[29]); return 0; }
  if (ds->s[30] != '5') { printf("cat_test: s[30] == %c\n", ds->s[30]); return 0; }
  if (ds->s[31] != '6') { printf("cat_test: s[31] == %c\n", ds->s[31]); return 0; }
  if (ds->s[32] != '7') { printf("cat_test: s[32] == %c\n", ds->s[32]); return 0; }
  if (ds->s[33] != '8') { printf("cat_test: s[33] == %c\n", ds->s[33]); return 0; }

  /* more suspicious use of byte copying and this will cause a
     re-allocation */

  if (!dstring_catb(ds, "X", 1)) return 0;
  if (!dstring_catb(ds, ds->s, ds->len)) {
    perror("dstring_catb");
    return 0;
  }

  if (ds->len != 70) { printf("cat_test: len == %u\n", ds->len); return 0; }
  if (ds->a != (50 + DSTRING_OVERALLOC)) {
    printf("cat_test: a == %u\n", ds->a); return 0;
  }

  if (ds->s[0] != 'A') { printf("cat_test: s[0] == %c\n", ds->s[0]); return 0; }
  if (ds->s[1] != 'B') { printf("cat_test: s[1] == %c\n", ds->s[1]); return 0; }
  if (ds->s[2] != 'C') { printf("cat_test: s[2] == %c\n", ds->s[2]); return 0; }
  if (ds->s[3] != 'D') { printf("cat_test: s[3] == %c\n", ds->s[3]); return 0; }
  if (ds->s[4] != 'E') { printf("cat_test: s[4] == %c\n", ds->s[4]); return 0; }
  if (ds->s[5] != 'F') { printf("cat_test: s[5] == %c\n", ds->s[5]); return 0; }
  if (ds->s[6] != 'G') { printf("cat_test: s[6] == %c\n", ds->s[6]); return 0; }
  if (ds->s[7] != 'H') { printf("cat_test: s[7] == %c\n", ds->s[7]); return 0; }
  if (ds->s[8] != 0) { printf("cat_test: s[8] == %c\n", ds->s[8]); return 0; }
  if (ds->s[9] != '1') { printf("cat_test: s[9] == %c\n", ds->s[9]); return 0; }
  if (ds->s[10] != '2') { printf("cat_test: s[10] == %c\n", ds->s[10]); return 0; }
  if (ds->s[11] != '3') { printf("cat_test: s[11] == %c\n", ds->s[11]); return 0; }
  if (ds->s[12] != '4') { printf("cat_test: s[12] == %c\n", ds->s[12]); return 0; }
  if (ds->s[13] != '5') { printf("cat_test: s[13] == %c\n", ds->s[13]); return 0; }
  if (ds->s[14] != '6') { printf("cat_test: s[14] == %c\n", ds->s[14]); return 0; }
  if (ds->s[15] != '7') { printf("cat_test: s[15] == %c\n", ds->s[15]); return 0; }
  if (ds->s[16] != '8') { printf("cat_test: s[16] == %c\n", ds->s[16]); return 0; }
  if (ds->s[17] != 'A') { printf("cat_test: s[17] == %c\n", ds->s[17]); return 0; }
  if (ds->s[18] != 'B') { printf("cat_test: s[18] == %c\n", ds->s[18]); return 0; }
  if (ds->s[19] != 'C') { printf("cat_test: s[19] == %c\n", ds->s[19]); return 0; }
  if (ds->s[20] != 'D') { printf("cat_test: s[20] == %c\n", ds->s[20]); return 0; }
  if (ds->s[21] != 'E') { printf("cat_test: s[21] == %c\n", ds->s[21]); return 0; }
  if (ds->s[22] != 'F') { printf("cat_test: s[22] == %c\n", ds->s[22]); return 0; }
  if (ds->s[23] != 'G') { printf("cat_test: s[23] == %c\n", ds->s[23]); return 0; }
  if (ds->s[24] != 'H') { printf("cat_test: s[24] == %c\n", ds->s[24]); return 0; }
  if (ds->s[25] != 0) { printf("cat_test: s[25] == %c\n", ds->s[25]); return 0; }
  if (ds->s[26] != '1') { printf("cat_test: s[26] == %c\n", ds->s[26]); return 0; }
  if (ds->s[27] != '2') { printf("cat_test: s[27] == %c\n", ds->s[27]); return 0; }
  if (ds->s[28] != '3') { printf("cat_test: s[28] == %c\n", ds->s[28]); return 0; }
  if (ds->s[29] != '4') { printf("cat_test: s[29] == %c\n", ds->s[29]); return 0; }
  if (ds->s[30] != '5') { printf("cat_test: s[30] == %c\n", ds->s[30]); return 0; }
  if (ds->s[31] != '6') { printf("cat_test: s[31] == %c\n", ds->s[31]); return 0; }
  if (ds->s[32] != '7') { printf("cat_test: s[32] == %c\n", ds->s[32]); return 0; }
  if (ds->s[33] != '8') { printf("cat_test: s[33] == %c\n", ds->s[33]); return 0; }
  if (ds->s[34] != 'X') { printf("cat_test: s[34] == %c\n", ds->s[34]); return 0; }

  if (ds->s[35] != 'A') { printf("cat_test: s[35] == %c\n", ds->s[35]); return 0; }
  if (ds->s[36] != 'B') { printf("cat_test: s[36] == %c\n", ds->s[36]); return 0; }
  if (ds->s[37] != 'C') { printf("cat_test: s[37] == %c\n", ds->s[37]); return 0; }
  if (ds->s[38] != 'D') { printf("cat_test: s[38] == %c\n", ds->s[38]); return 0; }
  if (ds->s[39] != 'E') { printf("cat_test: s[39] == %c\n", ds->s[39]); return 0; }
  if (ds->s[40] != 'F') { printf("cat_test: s[40] == %c\n", ds->s[40]); return 0; }
  if (ds->s[41] != 'G') { printf("cat_test: s[41] == %c\n", ds->s[41]); return 0; }
  if (ds->s[42] != 'H') { printf("cat_test: s[42] == %c\n", ds->s[42]); return 0; }
  if (ds->s[43] != 0) { printf("cat_test: s[43] == %c\n", ds->s[43]); return 0; }
  if (ds->s[44] != '1') { printf("cat_test: s[44] == %c\n", ds->s[44]); return 0; }
  if (ds->s[45] != '2') { printf("cat_test: s[45] == %c\n", ds->s[45]); return 0; }
  if (ds->s[46] != '3') { printf("cat_test: s[46] == %c\n", ds->s[46]); return 0; }
  if (ds->s[47] != '4') { printf("cat_test: s[47] == %c\n", ds->s[47]); return 0; }
  if (ds->s[48] != '5') { printf("cat_test: s[48] == %c\n", ds->s[48]); return 0; }
  if (ds->s[49] != '6') { printf("cat_test: s[49] == %c\n", ds->s[49]); return 0; }
  if (ds->s[50] != '7') { printf("cat_test: s[50] == %c\n", ds->s[50]); return 0; }
  if (ds->s[51] != '8') { printf("cat_test: s[51] == %c\n", ds->s[51]); return 0; }
  if (ds->s[52] != 'A') { printf("cat_test: s[52] == %c\n", ds->s[52]); return 0; }
  if (ds->s[53] != 'B') { printf("cat_test: s[53] == %c\n", ds->s[53]); return 0; }
  if (ds->s[54] != 'C') { printf("cat_test: s[54] == %c\n", ds->s[54]); return 0; }
  if (ds->s[55] != 'D') { printf("cat_test: s[55] == %c\n", ds->s[55]); return 0; }
  if (ds->s[56] != 'E') { printf("cat_test: s[56] == %c\n", ds->s[56]); return 0; }
  if (ds->s[57] != 'F') { printf("cat_test: s[57] == %c\n", ds->s[57]); return 0; }
  if (ds->s[58] != 'G') { printf("cat_test: s[58] == %c\n", ds->s[58]); return 0; }
  if (ds->s[59] != 'H') { printf("cat_test: s[59] == %c\n", ds->s[59]); return 0; }
  if (ds->s[60] != 0) { printf("cat_test: s[60] == %c\n", ds->s[60]); return 0; }
  if (ds->s[61] != '1') { printf("cat_test: s[61] == %c\n", ds->s[61]); return 0; }
  if (ds->s[62] != '2') { printf("cat_test: s[62] == %c\n", ds->s[62]); return 0; }
  if (ds->s[63] != '3') { printf("cat_test: s[63] == %c\n", ds->s[63]); return 0; }
  if (ds->s[64] != '4') { printf("cat_test: s[64] == %c\n", ds->s[64]); return 0; }
  if (ds->s[65] != '5') { printf("cat_test: s[65] == %c\n", ds->s[65]); return 0; }
  if (ds->s[66] != '6') { printf("cat_test: s[66] == %c\n", ds->s[66]); return 0; }
  if (ds->s[67] != '7') { printf("cat_test: s[67] == %c\n", ds->s[67]); return 0; }
  if (ds->s[68] != '8') { printf("cat_test: s[68] == %c\n", ds->s[68]); return 0; }

  /* cache THAT otellini */  

  dstring_trunc(ds);

  if (ds->a != (50 + DSTRING_OVERALLOC)) {
    printf("cat_test: a == %u\n", ds->a); return 0;
  }
  if (ds->len != 0) { printf("cat_test: len == %u\n", ds->len); return 0; }
  if (ds->s[0] != 0) { printf("cat_test: s[0] == %c\n", ds->s[0]); return 0; }

  return 1;
}

int copy_test(dstring *ds)
{
  if (!dstring_cpys(ds, "ABCDEFGH")) {
    perror("dstring_cpys");
    return 0;
  }

  if (ds->len != 8) {
    printf("copy_test: len == %u\n", ds->len); return 0;
  }

  if (ds->s[0] != 'A') { printf("copy_test: s[0] == %c\n", ds->s[0]); return 0; }
  if (ds->s[1] != 'B') { printf("copy_test: s[1] == %c\n", ds->s[1]); return 0; }
  if (ds->s[2] != 'C') { printf("copy_test: s[2] == %c\n", ds->s[2]); return 0; }
  if (ds->s[3] != 'D') { printf("copy_test: s[3] == %c\n", ds->s[3]); return 0; }
  if (ds->s[4] != 'E') { printf("copy_test: s[4] == %c\n", ds->s[4]); return 0; }
  if (ds->s[5] != 'F') { printf("copy_test: s[5] == %c\n", ds->s[5]); return 0; }
  if (ds->s[6] != 'G') { printf("copy_test: s[6] == %c\n", ds->s[6]); return 0; }
  if (ds->s[7] != 'H') { printf("copy_test: s[7] == %c\n", ds->s[7]); return 0; }

  /* self copy? */
  if (!dstring_cpyb(ds, ds->s, ds->len)) {
    perror("dstring_cpyb");
    return 0;
  }

  if (ds->len != 8) {
    printf("copy_test: len == %u\n", ds->len); return 0;
  }

  if (ds->s[0] != 'A') { printf("copy_test: s[0] == %c\n", ds->s[0]); return 0; }
  if (ds->s[1] != 'B') { printf("copy_test: s[1] == %c\n", ds->s[1]); return 0; }
  if (ds->s[2] != 'C') { printf("copy_test: s[2] == %c\n", ds->s[2]); return 0; }
  if (ds->s[3] != 'D') { printf("copy_test: s[3] == %c\n", ds->s[3]); return 0; }
  if (ds->s[4] != 'E') { printf("copy_test: s[4] == %c\n", ds->s[4]); return 0; }
  if (ds->s[5] != 'F') { printf("copy_test: s[5] == %c\n", ds->s[5]); return 0; }
  if (ds->s[6] != 'G') { printf("copy_test: s[6] == %c\n", ds->s[6]); return 0; }
  if (ds->s[7] != 'H') { printf("copy_test: s[7] == %c\n", ds->s[7]); return 0; }

  /* explicit dealloc and copy */
  dstring_free(ds);
  
  if (!dstring_init(ds, 1)) {
    perror("dstring_init");
    return 0;
  }

  if (ds->len != 0) { printf("copy_test: len == %u\n", ds->len); return 0; }
  if (ds->a != (1 + DSTRING_OVERALLOC)) {
    printf("copy_test: a == %u\n", ds->a); return 0;
  }
  if (!dstring_cpys(ds, BIG_STRING)) {
    perror("dstring_cpys");
    return 0;
  }
  if (ds->len != 256) { printf("copy_test: len == %u\n", ds->len); return 0; }
  if (ds->a != (256 + DSTRING_OVERALLOC)) {
    printf("copy_test: a == %u\n", ds->a); return 0;
  }

  /* for the sake of brevity, just check some characters */
  if (ds->s[0] != BIG_STRING[0]) { printf("s[0] == %c\n", ds->s[0]); return 0; }
  if (ds->s[63] != BIG_STRING[63]) { printf("s[63] == %c\n", ds->s[63]); return 63; }
  if (ds->s[127] != BIG_STRING[127]) { printf("s[127] == %c\n", ds->s[127]); return 127; }
  if (ds->s[255] != BIG_STRING[255]) { printf("s[255] == %c\n", ds->s[255]); return 255; }

  return 1;
}

int chop_test(dstring *ds)
{
  /* len == 256 */

  /* should do nothing */
  dstring_chop(ds, 300);
  if (ds->len != 256) { printf("chop_test: len == %u\n", ds->len); return 0; }

  /* should work */
  dstring_chop(ds, 20);
  if (ds->len != 20) { printf("chop_test: len == %u\n", ds->len); return 0; }
  if (ds->s[20] != 0) { printf("s[20] == %c\n", ds->s[20]); return 0; }

  return 1;
}

int main()
{
  static dstring ds;

  if (!init_test(&ds)) return 1;
  if (!cat_test(&ds)) return 1;
  if (!copy_test(&ds)) return 1;
  if (!chop_test(&ds)) return 1;

  return 0;
}
