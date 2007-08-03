#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "../alloc.h"
#include "t_assert.h"

#define CHUNK 128

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

int main(void)
{
  char *p1;
  char *p2;
  char *p3;
  unsigned int ind;

  p1 = alloc(CHUNK);
  p2 = alloc(CHUNK);
  p3 = alloc(CHUNK);

  test_assert(p1);
  test_assert(p2);
  test_assert(p3);

  set(p1, CHUNK);
  set(p2, CHUNK);
  set(p3, CHUNK);

  sp1 = alloc(CHUNK);
  sp2 = alloc(CHUNK);
  sp3 = alloc(CHUNK);

  test_assert(sp1);
  test_assert(sp2);
  test_assert(sp3);

  set(sp1, CHUNK);
  set(sp2, CHUNK);
  set(sp3, CHUNK);

  test_assert(alloc_re((void *) &p1, CHUNK, CHUNK * 2)); 
  test_assert(alloc_re((void *) &p2, CHUNK, CHUNK * 2));
  test_assert(alloc_re((void *) &p3, CHUNK, CHUNK * 2));

  test_assert(p1[0] == 0x41);
  test_assert(p2[0] == 0x41);
  test_assert(p3[0] == 0x41);

  set(p1, CHUNK * 2);
  set(p2, CHUNK * 2);
  set(p3, CHUNK * 2);

  test_assert(alloc_re((void *) &sp1, CHUNK, CHUNK * 2)); 
  test_assert(alloc_re((void *) &sp2, CHUNK, CHUNK * 2));
  test_assert(alloc_re((void *) &sp3, CHUNK, CHUNK * 2));

  test_assert(sp1[0] == 0x41);
  test_assert(sp2[0] == 0x41);
  test_assert(sp3[0] == 0x41);

  set(sp1, CHUNK * 2);
  set(sp2, CHUNK * 2);
  set(sp3, CHUNK * 2);

  dealloc(p1);
  dealloc(p2);
  dealloc(p3);

  dealloc(sp1);
  dealloc(sp2);
  dealloc(sp3);

  p1 = alloc_zero(CHUNK);
  test_assert(p1);

  for (ind = 0; ind < CHUNK; ++ind)
    test_assert(p1[ind] == 0);

  dealloc_null(&p1);
  test_assert(p1 == 0);
  return 0;
}
