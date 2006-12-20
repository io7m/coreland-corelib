#include "../alloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define CHUNK 2048

static char *sp1;
static char *sp2;
static char *sp3;

void set(char *p, unsigned long len)
{
  for (;;) {
    if (!len) break; *p = 0x41; ++p; --len;
    if (!len) break; *p = 0x41; ++p; --len;
    if (!len) break; *p = 0x41; ++p; --len;
    if (!len) break; *p = 0x41; ++p; --len;
  }
}

int main()
{
  char *p1;
  char *p2;
  char *p3;

  p1 = alloc(CHUNK);
  p2 = alloc(CHUNK);
  p3 = alloc(CHUNK);

  if (!p1) { printf("fail: !p1\n"); return 1; }
  if (!p2) { printf("fail: !p2\n"); return 1; }
  if (!p3) { printf("fail: !p3\n"); return 1; }

  set(p1, CHUNK);
  set(p2, CHUNK);
  set(p3, CHUNK);

  sp1 = alloc(CHUNK);
  sp2 = alloc(CHUNK);
  sp3 = alloc(CHUNK);

  if (!sp1) { printf("fail: !sp1\n"); return 1; }
  if (!sp2) { printf("fail: !sp2\n"); return 1; }
  if (!sp3) { printf("fail: !sp3\n"); return 1; }

  set(sp1, CHUNK);
  set(sp2, CHUNK);
  set(sp3, CHUNK);

  if (!alloc_re((void *) &p1, CHUNK, CHUNK * 2)) {
    printf("fail: !alloc_re(p1)\n"); return 1;
  }
  if (!alloc_re((void *) &p2, CHUNK, CHUNK * 2)) {
    printf("fail: !alloc_re(p2)\n"); return 1;
  }
  if (!alloc_re((void *) &p3, CHUNK, CHUNK * 2)) {
    printf("fail: !alloc_re(p3)\n"); return 1;
  }

  if (p1[0] != 0x41) { printf("fail: p1[0] == %c\n", p1[0]); return 1; }
  if (p2[0] != 0x41) { printf("fail: p2[0] == %c\n", p2[0]); return 1; }
  if (p3[0] != 0x41) { printf("fail: p3[0] == %c\n", p3[0]); return 1; }

  set(p1, CHUNK * 2);
  set(p2, CHUNK * 2);
  set(p3, CHUNK * 2);

  if (!alloc_re((void *) &sp1, CHUNK, CHUNK * 2)) {
    printf("fail: !alloc_re(sp1)\n"); return 1;
  }
  if (!alloc_re((void *) &sp2, CHUNK, CHUNK * 2)) {
    printf("fail: !alloc_re(sp2)\n"); return 1;
  }
  if (!alloc_re((void *) &sp3, CHUNK, CHUNK * 2)) {
    printf("fail: !alloc_re(sp3)\n"); return 1;
  }

  if (sp1[0] != 0x41) { printf("fail: sp1[0] == %c\n", sp1[0]); return 1; }
  if (sp2[0] != 0x41) { printf("fail: sp2[0] == %c\n", sp2[0]); return 1; }
  if (sp3[0] != 0x41) { printf("fail: sp3[0] == %c\n", sp3[0]); return 1; }

  set(sp1, CHUNK * 2);
  set(sp2, CHUNK * 2);
  set(sp3, CHUNK * 2);

  dealloc(p1);
  dealloc(p2);
  dealloc(p3);

  dealloc(sp1);
  dealloc(sp2);
  dealloc(sp3);

  return 0;
}
