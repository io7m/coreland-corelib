#include <signal.h>
#include "sig.h"
#include "sig_pmask.h"

void sig_pause(void)
{
#ifdef SD_HAVE_SIGPROCMASK
  sigset_t ss;
  sigemptyset(&ss);
  sigsuspend(&ss);
#else
  sigpause(0);
#endif
}
