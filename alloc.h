#ifndef CORELIB_ALLOC_H
#define CORELIB_ALLOC_H

typedef void * (*alloc_proto)(unsigned long);
typedef void  (*dealloc_proto)(void *);
typedef int   (*realloc_proto)(void **, unsigned long, unsigned long);
typedef void * vptr;

int alloc_set_alloc(alloc_proto);
int alloc_set_dealloc(dealloc_proto);
int alloc_set_realloc(realloc_proto);

void *alloc(unsigned long);
void *alloc_zero(unsigned long);
int   alloc_re(void **, unsigned long, unsigned long);
void  dealloc(void *);
void  dealloc_null(void **);

#endif
