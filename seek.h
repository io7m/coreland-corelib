#ifndef SEEK_H
#define SEEK_H

#include "int64.h"
#include <sys/types.h>
#include <unistd.h>   /* seems to be required for lseek on OSX
                         and possibly others
                       */
#define _SEEK_SET 0
#define _SEEK_CUR 1
#define _SEEK_END 2

/* assumes filesystem max file size > 4gb */

int64 seek_cur(int, int64);
int64 seek_pos(int, int64);
int64 seek_start(int);
int64 seek_end(int);

#endif
