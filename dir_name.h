#ifndef CORELIB_DIR_NAME_H
#define CORELIB_DIR_NAME_H

#define DIR_NAME_MAX 1024

int dir_name_r(const char *, char *, unsigned long);
int dir_name(const char *, char **);

#endif
