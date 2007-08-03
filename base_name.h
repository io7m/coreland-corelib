#ifndef CORELIB_BASE_NAME_H
#define CORELIB_BASE_NAME_H

#define BASE_NAME_MAX 1024

int base_name_r(const char *, char *, unsigned long);
int base_name(const char *, char **);

#endif
