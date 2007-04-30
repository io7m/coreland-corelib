#include <signal.h>
#include "sig.h"

int sig_alarm = SIGALRM;
int sig_child = SIGCHLD;
int sig_cont = SIGCONT;
int sig_hangup = SIGHUP;
int sig_pipe = SIGPIPE;
int sig_term = SIGTERM;
int sig_int = SIGINT;
int sig_segv = SIGSEGV;

void (*sig_defaulthandler)(int) = SIG_DFL;
void (*sig_ignorehandler)(int) = SIG_IGN;
