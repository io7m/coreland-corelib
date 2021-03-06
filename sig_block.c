#include <signal.h>
#include "sig.h"
#include "sig_pmask.h"

void sig_block(int sig)
{
#ifdef SD_HAVE_SIGPROCMASK
  sigset_t ss;
  sigemptyset(&ss);
  sigaddset(&ss, sig);
  sigprocmask(SIG_BLOCK, &ss, (sigset_t *) 0);
#else
  sigblock(1 << (sig - 1));
#endif
}
void sig_unblock(int sig)
{
#ifdef SD_HAVE_SIGPROCMASK
  sigset_t ss;
  sigemptyset(&ss);
  sigaddset(&ss,sig);
  sigprocmask(SIG_UNBLOCK, &ss, (sigset_t *) 0);
#else
  sigsetmask(sigsetmask(~0) & ~(1 << (sig - 1)));
#endif
}
void sig_blocknone(void)
{
#ifdef SD_HAVE_SIGPROCMASK
  sigset_t ss;
  sigemptyset(&ss);
  sigprocmask(SIG_SETMASK, &ss, (sigset_t *) 0);
#else
  sigsetmask(0);
#endif
}
