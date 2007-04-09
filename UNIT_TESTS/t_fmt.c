#include <stdio.h>
#include "../fmt.h"
#include "t_assert.h"

char cuc[FMT_ULONG];
char cui[FMT_ULONG];
char cull[FMT_ULONGLONG];

int main(void)
{
  unsigned char uc;
  unsigned int ui;
#if defined(HAVE_LONGLONG)
  unsigned long long ull;
#endif

  printf("FMT_ULONG %u\n", FMT_ULONG);
  printf("FMT_ULONGLONG %u\n", FMT_ULONGLONG);

  /* uchar */
  uc = 100U;
  cuc[fmt_uchar(cuc, uc)] = 0;
  test_assert(cuc[0] == '1');
  test_assert(cuc[1] == '0');
  test_assert(cuc[2] == '0');
 
  uc = 0xffU;
  cuc[fmt_ucharx(cuc, uc)] = 0;
  test_assert(cuc[0] == 'f');
  test_assert(cuc[1] == 'f');

  uc = 0377U;
  cuc[fmt_ucharo(cuc, uc)] = 0;
  test_assert(cuc[0] == '3');
  test_assert(cuc[1] == '7');
  test_assert(cuc[2] == '7');

  /* uint */
  ui = 10000U;
  cui[fmt_uint(cui, ui)] = 0;
  test_assert(cui[0] == '1');
  test_assert(cui[1] == '0');
  test_assert(cui[2] == '0');
  test_assert(cui[3] == '0');
  test_assert(cui[4] == '0');

  ui = 0xdeadfaceU;
  cui[fmt_uintx(cui, ui)] = 0;
  test_assert(cui[0] == 'd');
  test_assert(cui[1] == 'e');
  test_assert(cui[2] == 'a');
  test_assert(cui[3] == 'd');
  test_assert(cui[4] == 'f');
  test_assert(cui[5] == 'a');
  test_assert(cui[6] == 'c');
  test_assert(cui[7] == 'e');

  ui = 0123456U;
  cui[fmt_uinto(cui, ui)] = 0;
  test_assert(cui[0] == '1');
  test_assert(cui[1] == '2');
  test_assert(cui[2] == '3');
  test_assert(cui[3] == '4');
  test_assert(cui[4] == '5');
  test_assert(cui[5] == '6');

#if defined(HAVE_LONGLONG)
  /* ull */
  ull = 12302652060662212828ULL;
  cull[fmt_ulonglong(cull, ull)] = 0;  
  test_assert(cull[0] == '1');
  test_assert(cull[1] == '2');
  test_assert(cull[2] == '3');
  test_assert(cull[3] == '0');
  test_assert(cull[4] == '2');
  test_assert(cull[5] == '6');
  test_assert(cull[6] == '5');
  test_assert(cull[7] == '2');
  test_assert(cull[8] == '0');
  test_assert(cull[9] == '6');
  test_assert(cull[10] == '0');
  test_assert(cull[11] == '6');
  test_assert(cull[12] == '6');
  test_assert(cull[13] == '2');
  test_assert(cull[14] == '2');
  test_assert(cull[15] == '1');
  test_assert(cull[16] == '2');
  test_assert(cull[17] == '8');
  test_assert(cull[18] == '2');
  test_assert(cull[19] == '8');

  ull = 0xaabbccddeeffaabbULL;
  cull[fmt_ulonglongx(cull, ull)] = 0;
  test_assert(cull[0] == 'a');
  test_assert(cull[1] == 'a');
  test_assert(cull[2] == 'b');
  test_assert(cull[3] == 'b');
  test_assert(cull[4] == 'c');
  test_assert(cull[5] == 'c');
  test_assert(cull[6] == 'd');
  test_assert(cull[7] == 'd');
  test_assert(cull[8] == 'e');
  test_assert(cull[9] == 'e');
  test_assert(cull[10] == 'f');
  test_assert(cull[11] == 'f');
  test_assert(cull[12] == 'a');
  test_assert(cull[13] == 'a');
  test_assert(cull[14] == 'b');
  test_assert(cull[15] == 'b');

  ull = 01252736315675677724000ULL;
  cull[fmt_ulonglongo(cull, ull)] = 0;
  test_assert(cull[0] == '1');
  test_assert(cull[1] == '2');
  test_assert(cull[2] == '5');
  test_assert(cull[3] == '2');
  test_assert(cull[4] == '7');
  test_assert(cull[5] == '3');
  test_assert(cull[6] == '6');
  test_assert(cull[7] == '3');
  test_assert(cull[8] == '1');
  test_assert(cull[9] == '5');
  test_assert(cull[10] == '6');
  test_assert(cull[11] == '7');
  test_assert(cull[12] == '5');
  test_assert(cull[13] == '6');
  test_assert(cull[14] == '7');
  test_assert(cull[15] == '7');
  test_assert(cull[16] == '7');
  test_assert(cull[17] == '2');
  test_assert(cull[18] == '4');
  test_assert(cull[19] == '0');
  test_assert(cull[20] == '0');
  test_assert(cull[21] == '0');
#endif

  return 0;
}
