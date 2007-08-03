#include <stdlib.h>
#include "alloc.h"

/* pointers to default mem functions */
static void *def_alloc(unsigned long);
static void  def_dealloc(void *);
static int   def_realloc(void **, unsigned long, unsigned long);

static alloc_proto allocfunc = def_alloc;
static realloc_proto reallocfunc = def_realloc;
static dealloc_proto deallocfunc = def_dealloc;

static void copy_bytes(const char *sc, char *dc, unsigned long size)
{
  for (;;) {
    if (!size) return; *dc++ = *sc++; --size;
    if (!size) return; *dc++ = *sc++; --size;
    if (!size) return; *dc++ = *sc++; --size;
    if (!size) return; *dc++ = *sc++; --size;
  }
}
static void zero_bytes(char *sc, unsigned long size)
{
  for (;;) {
    if (!size) return; *sc++ = 0; --size;
    if (!size) return; *sc++ = 0; --size;
    if (!size) return; *sc++ = 0; --size;
    if (!size) return; *sc++ = 0; --size;
  }
}
static void *def_alloc(unsigned long size)
{
  return malloc(size);
}
static void def_dealloc(void *ptr)
{
  free(ptr);
}
static int def_realloc(void **ptr, unsigned long size_old, unsigned long size_new)
{
  char *ptr_new = def_alloc(size_new);
  if (!ptr_new) return 0;
  copy_bytes(*ptr, ptr_new, size_old);
  def_dealloc(*ptr);
  *ptr = ptr_new;
  return 1;
}

/* interface */

int alloc_set_alloc(alloc_proto ap)
{
  if (ap) { allocfunc = ap; } return 0;
}

int alloc_set_realloc(realloc_proto rp)
{
  if (rp) { reallocfunc = rp; } return 0;
}

int alloc_set_dealloc(dealloc_proto dp)
{
  if (dp) { deallocfunc = dp; } return 0;
}

void *alloc(unsigned long size)
{
  return allocfunc(size);
}

void *alloc_zero(unsigned long size)
{
  void *ptr = allocfunc(size);
  if (ptr) zero_bytes(ptr, size);
  return ptr;
}

int alloc_re(void **ptr, unsigned long size_old, unsigned long size_new)
{
  return reallocfunc(ptr, size_old, size_new);
}

void dealloc(void *ptr)
{
  deallocfunc(ptr);
}
void dealloc_null_core(void **ptr)
{
  deallocfunc(*ptr);
  *ptr = 0;
}
