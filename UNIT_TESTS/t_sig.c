#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "../sig.h"
#include "t_assert.h"

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
  int pid = getpid();

  /* catch lots of signals */
  sig_catch(sig_alarm, t1_handle);
  sig_catch(sig_child, t1_handle);
  sig_catch(sig_cont, t1_handle);
  sig_catch(sig_hangup, t1_handle);
  sig_catch(sig_pipe, t1_handle);
  sig_catch(sig_term, t1_handle);
 
  test_assert(kill(pid, sig_alarm) != -1);
  test_assert(kill(pid, sig_child) != -1);
  test_assert(kill(pid, sig_cont) != -1);
  test_assert(kill(pid, sig_hangup) != -1);
  test_assert(kill(pid, sig_pipe) != -1);
  test_assert(kill(pid, sig_term) != -1);

  test_assert(sig_alarm_num == 1);
  test_assert(sig_child_num == 1);
  test_assert(sig_cont_num == 1);
  test_assert(sig_hangup_num == 1);
  test_assert(sig_pipe_num == 1);
  test_assert(sig_term_num == 1);

  /* block lots of signals */

  sig_block(sig_alarm);
  sig_block(sig_child);
  sig_block(sig_cont);
  sig_block(sig_hangup);
  sig_block(sig_pipe);
  sig_block(sig_term);

  test_assert(kill(pid, sig_alarm) != -1);
  test_assert(kill(pid, sig_child) != -1);
  test_assert(kill(pid, sig_cont) != -1);
  test_assert(kill(pid, sig_hangup) != -1);
  test_assert(kill(pid, sig_pipe) != -1);
  test_assert(kill(pid, sig_term) != -1);

  test_assert(sig_alarm_num == 1);
  test_assert(sig_child_num == 1);
  test_assert(sig_cont_num == 1);
  test_assert(sig_hangup_num == 1);
  test_assert(sig_pipe_num == 1);
  test_assert(sig_term_num == 1);

  /* XXX: how to check sig_pause? */
  return 1;
}

int main(void)
{
  test1();

  return 0;
}
