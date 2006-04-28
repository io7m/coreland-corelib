#ifndef STALLOC_H
#define STALLOC_H

#define STALLOC_ALIGN 16
#define STALLOC_SPACE 4096

void *stalloc(unsigned int);
int strealloc(void **, unsigned int, unsigned int);
void stdealloc(void *);

#endif
