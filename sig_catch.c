#include <signal.h>
#include "signal.h"
#include "sig_action.h"

void sig_catch(int sig, void (*func)())
{
#ifdef HASSIGACTION
  struct sigaction sa;
  sa.sa_handler = func;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sigaction(sig, &sa, (struct sigaction *) 0);
#else
  signal(sig, func);
#endif
}

