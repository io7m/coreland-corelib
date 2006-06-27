#ifndef STALLOC_H
#define STALLOC_H

#define STALLOC_ALIGN 16
#define STALLOC_SPACE 4096

void *stalloc(unsigned long);
int strealloc(void **, unsigned long, unsigned long);
void stdealloc(void *);

#endif
