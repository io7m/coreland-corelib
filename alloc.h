#ifndef ALLOC_H
#define ALLOC_H

/* read ALLOC for details */

typedef void * (*alloc_proto)(unsigned int);
typedef void  (*dealloc_proto)(void *);
typedef int   (*realloc_proto)(void **, unsigned int, unsigned int);
typedef void * vptr;

int set_alloc(alloc_proto);
int set_dealloc(dealloc_proto);
int set_realloc(realloc_proto);

void *alloc(unsigned int);
int   alloc_re(void **, unsigned int, unsigned int);
void  dealloc(void *);

#endif
