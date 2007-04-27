#ifndef CORELIB_FD_SEEK_H
#define CORELIB_FD_SEEK_H

#include <sys/types.h>
#include <unistd.h>
 
#if defined(CORELIB_USE_LONGLONG)
  #include "sd_longlong.h"
  #if defined(HAVE_LONGLONG)
    typedef long long fd_seek_int;
  #else
    typedef long fd_seek_int;
  #endif
#else
  typedef long fd_seek_int;
#endif

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

fd_seek_int fd_seek_cur(int, fd_seek_int);
fd_seek_int fd_seek_pos(int, fd_seek_int);
fd_seek_int fd_seek_start(int);
fd_seek_int fd_seek_end(int);

#endif
