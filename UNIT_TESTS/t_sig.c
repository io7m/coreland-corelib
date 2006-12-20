#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "../sig.h"

int sig_alarm_num;
int sig_child_num;
int sig_cont_num;
int sig_hangup_num;
int sig_pipe_num;
int sig_term_num;

void t1_handle(int sig)
{
  if (sig == sig_alarm) { ++sig_alarm_num; return; }
  if (sig == sig_child) { ++sig_child_num; return; }
  if (sig == sig_cont) { ++sig_cont_num; return; }
  if (sig == sig_hangup) { ++sig_hangup_num; return; }
  if (sig == sig_pipe) { ++sig_pipe_num; return; }
  if (sig == sig_term) { ++sig_term_num; return; }
}

int test1()
{
  int pid;

  pid = getpid();

  /* catch lots of signals */

  sig_catch(sig_alarm, t1_handle);
  sig_catch(sig_child, t1_handle);
  sig_catch(sig_cont, t1_handle);
  sig_catch(sig_hangup, t1_handle);
  sig_catch(sig_pipe, t1_handle);
  sig_catch(sig_term, t1_handle);
 
  if (kill(pid, sig_alarm) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_child) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_cont) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_hangup) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_pipe) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_term) == -1) { perror("kill"); return 0; }

  if (sig_alarm_num != 1) { printf("fail: %s == %d\n", "sig_alarm", sig_alarm_num); return 0; }
  if (sig_child_num != 1) { printf("fail: %s == %d\n", "sig_child", sig_child_num); return 0; }
  if (sig_cont_num != 1) { printf("fail: %s == %d\n", "sig_cont", sig_cont_num); return 0; }
  if (sig_hangup_num != 1) { printf("fail: %s == %d\n", "sig_hangup", sig_hangup_num); return 0; }
  if (sig_pipe_num != 1) { printf("fail: %s == %d\n", "sig_pipe", sig_pipe_num); return 0; }
  if (sig_term_num != 1) { printf("fail: %s == %d\n", "sig_term", sig_term_num); return 0; }

  /* block lots of signals */

  sig_block(sig_alarm);
  sig_block(sig_child);
  sig_block(sig_cont);
  sig_block(sig_hangup);
  sig_block(sig_pipe);
  sig_block(sig_term);

  if (kill(pid, sig_alarm) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_child) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_cont) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_hangup) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_pipe) == -1) { perror("kill"); return 0; }
  if (kill(pid, sig_term) == -1) { perror("kill"); return 0; }

  if (sig_alarm_num != 1) { printf("fail: %s == %d\n", "sig_alarm", sig_alarm_num); return 0; }
  if (sig_child_num != 1) { printf("fail: %s == %d\n", "sig_child", sig_child_num); return 0; }
  if (sig_cont_num != 1) { printf("fail: %s == %d\n", "sig_cont", sig_cont_num); return 0; }
  if (sig_hangup_num != 1) { printf("fail: %s == %d\n", "sig_hangup", sig_hangup_num); return 0; }
  if (sig_pipe_num != 1) { printf("fail: %s == %d\n", "sig_pipe", sig_pipe_num); return 0; }
  if (sig_term_num != 1) { printf("fail: %s == %d\n", "sig_term", sig_term_num); return 0; }

  /* XXX: how to check sig_pause? */

  return 1;
}

int main()
{
  if (!test1()) return 1;

  return 0;
}
