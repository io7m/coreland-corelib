#ifndef CORELIB_FD_SEEK_H
#define CORELIB_FD_SEEK_H

#include <sys/types.h>
#include <unistd.h>
 
#include "int64.h"
                      
#if defined(SEEK_SET)
  #define FD_SEEK_SET SEEK_SET
#else
  #define FD_SEEK_SET 0
#endif

#if defined(SEEK_CUR)
  #define FD_SEEK_CUR SEEK_CUR
#else
  #define FD_SEEK_CUR 1
#endif

#if defined(SEEK_END)
  #define FD_SEEK_END SEEK_END
#else
  #define FD_SEEK_END 2
#endif

/* assumes filesystem max file size > 4gb */

int64 fd_seek_cur(int, int64);
int64 fd_seek_pos(int, int64);
int64 fd_seek_start(int);
int64 fd_seek_end(int);

#endif
