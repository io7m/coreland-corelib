#include "../fmt.h"
#include <stdio.h>

char cuc[FMT_ULONG];
char cui[FMT_ULONG];
char cull[FMT_ULONGLONG];

int main()
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
  if (cuc[0] != '1') { printf("fail: cuc[0] == %c\n", cuc[0]); return 1; }
  if (cuc[1] != '0') { printf("fail: cuc[1] == %c\n", cuc[1]); return 1; }
  if (cuc[2] != '0') { printf("fail: cuc[2] == %c\n", cuc[2]); return 1; }
 
  uc = 0xffU;
  cuc[fmt_ucharx(cuc, uc)] = 0;
  if (cuc[0] != 'f') { printf("fail: cuc[0] == %c\n", cuc[0]); return 1; }
  if (cuc[1] != 'f') { printf("fail: cuc[1] == %c\n", cuc[1]); return 1; }

  uc = 0377U;
  cuc[fmt_ucharo(cuc, uc)] = 0;
  if (cuc[0] != '3') { printf("fail: cuc[0] == %c\n", cuc[0]); return 1; }
  if (cuc[1] != '7') { printf("fail: cuc[1] == %c\n", cuc[1]); return 1; }
  if (cuc[2] != '7') { printf("fail: cuc[2] == %c\n", cuc[2]); return 1; }

  /* uint */
  ui = 10000U;
  cui[fmt_uint(cui, ui)] = 0;
  if (cui[0] != '1') { printf("fail: cui[0] == %c\n", cui[0]); return 1; }
  if (cui[1] != '0') { printf("fail: cui[1] == %c\n", cui[1]); return 1; }
  if (cui[2] != '0') { printf("fail: cui[2] == %c\n", cui[2]); return 1; }
  if (cui[3] != '0') { printf("fail: cui[3] == %c\n", cui[3]); return 1; }
  if (cui[4] != '0') { printf("fail: cui[4] == %c\n", cui[4]); return 1; }

  ui = 0xdeadfaceU;
  cui[fmt_uintx(cui, ui)] = 0;
  if (cui[0] != 'd') { printf("fail: cui[0] == %c\n", cui[0]); return 1; }
  if (cui[1] != 'e') { printf("fail: cui[1] == %c\n", cui[1]); return 1; }
  if (cui[2] != 'a') { printf("fail: cui[2] == %c\n", cui[2]); return 1; }
  if (cui[3] != 'd') { printf("fail: cui[3] == %c\n", cui[3]); return 1; }
  if (cui[4] != 'f') { printf("fail: cui[4] == %c\n", cui[4]); return 1; }
  if (cui[5] != 'a') { printf("fail: cui[5] == %c\n", cui[5]); return 1; }
  if (cui[6] != 'c') { printf("fail: cui[6] == %c\n", cui[6]); return 1; }
  if (cui[7] != 'e') { printf("fail: cui[7] == %c\n", cui[7]); return 1; }

  ui = 0123456U;
  cui[fmt_uinto(cui, ui)] = 0;
  if (cui[0] != '1') { printf("fail: cui[0] == %c\n", cui[0]); return 1; }
  if (cui[1] != '2') { printf("fail: cui[1] == %c\n", cui[1]); return 1; }
  if (cui[2] != '3') { printf("fail: cui[2] == %c\n", cui[2]); return 1; }
  if (cui[3] != '4') { printf("fail: cui[3] == %c\n", cui[3]); return 1; }
  if (cui[4] != '5') { printf("fail: cui[4] == %c\n", cui[4]); return 1; }
  if (cui[5] != '6') { printf("fail: cui[5] == %c\n", cui[5]); return 1; }

#if defined(HAVE_LONGLONG)
  /* ull */
  ull = 12302652060662212828ULL;
  cull[fmt_ulonglong(cull, ull)] = 0;  
  if (cull[0] != '1') { printf("fail: cull[0] == %c\n", cull[0]); return 1; }
  if (cull[1] != '2') { printf("fail: cull[1] == %c\n", cull[1]); return 1; }
  if (cull[2] != '3') { printf("fail: cull[2] == %c\n", cull[2]); return 1; }
  if (cull[3] != '0') { printf("fail: cull[3] == %c\n", cull[3]); return 1; }
  if (cull[4] != '2') { printf("fail: cull[4] == %c\n", cull[4]); return 1; }
  if (cull[5] != '6') { printf("fail: cull[5] == %c\n", cull[5]); return 1; }
  if (cull[6] != '5') { printf("fail: cull[6] == %c\n", cull[6]); return 1; }
  if (cull[7] != '2') { printf("fail: cull[7] == %c\n", cull[7]); return 1; }
  if (cull[8] != '0') { printf("fail: cull[8] == %c\n", cull[8]); return 1; }
  if (cull[9] != '6') { printf("fail: cull[9] == %c\n", cull[9]); return 1; }
  if (cull[10] != '0') { printf("fail: cull[10] == %c\n", cull[10]); return 1; }
  if (cull[11] != '6') { printf("fail: cull[11] == %c\n", cull[11]); return 1; }
  if (cull[12] != '6') { printf("fail: cull[12] == %c\n", cull[12]); return 1; }
  if (cull[13] != '2') { printf("fail: cull[13] == %c\n", cull[13]); return 1; }
  if (cull[14] != '2') { printf("fail: cull[14] == %c\n", cull[14]); return 1; }
  if (cull[15] != '1') { printf("fail: cull[15] == %c\n", cull[15]); return 1; }
  if (cull[16] != '2') { printf("fail: cull[16] == %c\n", cull[16]); return 1; }
  if (cull[17] != '8') { printf("fail: cull[17] == %c\n", cull[17]); return 1; }
  if (cull[18] != '2') { printf("fail: cull[18] == %c\n", cull[18]); return 1; }
  if (cull[19] != '8') { printf("fail: cull[19] == %c\n", cull[19]); return 1; }

  ull = 0xaabbccddeeffaabbULL;
  cull[fmt_ulonglongx(cull, ull)] = 0;
  if (cull[0] != 'a') { printf("fail: cull[0] == %c\n", cull[0]); return 1; }
  if (cull[1] != 'a') { printf("fail: cull[1] == %c\n", cull[1]); return 1; }
  if (cull[2] != 'b') { printf("fail: cull[2] == %c\n", cull[2]); return 1; }
  if (cull[3] != 'b') { printf("fail: cull[3] == %c\n", cull[3]); return 1; }
  if (cull[4] != 'c') { printf("fail: cull[4] == %c\n", cull[4]); return 1; }
  if (cull[5] != 'c') { printf("fail: cull[5] == %c\n", cull[5]); return 1; }
  if (cull[6] != 'd') { printf("fail: cull[6] == %c\n", cull[6]); return 1; }
  if (cull[7] != 'd') { printf("fail: cull[7] == %c\n", cull[7]); return 1; }
  if (cull[8] != 'e') { printf("fail: cull[8] == %c\n", cull[8]); return 1; }
  if (cull[9] != 'e') { printf("fail: cull[9] == %c\n", cull[9]); return 1; }
  if (cull[10] != 'f') { printf("fail: cull[10] == %c\n", cull[10]); return 1; }
  if (cull[11] != 'f') { printf("fail: cull[11] == %c\n", cull[11]); return 1; }
  if (cull[12] != 'a') { printf("fail: cull[12] == %c\n", cull[12]); return 1; }
  if (cull[13] != 'a') { printf("fail: cull[13] == %c\n", cull[13]); return 1; }
  if (cull[14] != 'b') { printf("fail: cull[14] == %c\n", cull[14]); return 1; }
  if (cull[15] != 'b') { printf("fail: cull[15] == %c\n", cull[15]); return 1; }

  ull = 01252736315675677724000ULL;
  cull[fmt_ulonglongo(cull, ull)] = 0;
  if (cull[0] != '1') { printf("fail: cull[0] == %c\n", cull[0]); return 1; }
  if (cull[1] != '2') { printf("fail: cull[1] == %c\n", cull[1]); return 1; }
  if (cull[2] != '5') { printf("fail: cull[2] == %c\n", cull[2]); return 1; }
  if (cull[3] != '2') { printf("fail: cull[3] == %c\n", cull[3]); return 1; }
  if (cull[4] != '7') { printf("fail: cull[4] == %c\n", cull[4]); return 1; }
  if (cull[5] != '3') { printf("fail: cull[5] == %c\n", cull[5]); return 1; }
  if (cull[6] != '6') { printf("fail: cull[6] == %c\n", cull[6]); return 1; }
  if (cull[7] != '3') { printf("fail: cull[7] == %c\n", cull[7]); return 1; }
  if (cull[8] != '1') { printf("fail: cull[8] == %c\n", cull[8]); return 1; }
  if (cull[9] != '5') { printf("fail: cull[9] == %c\n", cull[9]); return 1; }
  if (cull[10] != '6') { printf("fail: cull[10] == %c\n", cull[10]); return 1; }
  if (cull[11] != '7') { printf("fail: cull[11] == %c\n", cull[11]); return 1; }
  if (cull[12] != '5') { printf("fail: cull[12] == %c\n", cull[12]); return 1; }
  if (cull[13] != '6') { printf("fail: cull[13] == %c\n", cull[13]); return 1; }
  if (cull[14] != '7') { printf("fail: cull[14] == %c\n", cull[14]); return 1; }
  if (cull[15] != '7') { printf("fail: cull[15] == %c\n", cull[15]); return 1; }
  if (cull[16] != '7') { printf("fail: cull[16] == %c\n", cull[16]); return 1; }
  if (cull[17] != '2') { printf("fail: cull[17] == %c\n", cull[17]); return 1; }
  if (cull[18] != '4') { printf("fail: cull[18] == %c\n", cull[18]); return 1; }
  if (cull[19] != '0') { printf("fail: cull[19] == %c\n", cull[19]); return 1; }
  if (cull[20] != '0') { printf("fail: cull[20] == %c\n", cull[20]); return 1; }
  if (cull[21] != '0') { printf("fail: cull[21] == %c\n", cull[21]); return 1; }
#endif

  return 0;
}
