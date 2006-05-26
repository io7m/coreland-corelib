#ifndef SIGNAL_H
#define SIGNAL_H

int sig_alarm;
int sig_child;
int sig_cont;
int sig_hangup;
int sig_pipe;
int sig_term;
int sig_segv;
int sig_int;

void (*sig_defaulthandler)();
void (*sig_ignorehandler)();

void sig_catch(int, void (*)());
#define sig_ignore(s) (sig_catch((s), sig_ignorehandler))
#define sig_uncatch(s) (sig_catch((s), sig_defaulthandler))

void sig_block(int);
void sig_unblock(int);
void sig_blocknone(void);
void sig_pause(void);

#endif
