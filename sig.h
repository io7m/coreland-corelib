#ifndef CORELIB_SIGNAL_H
#define CORELIB_SIGNAL_H

extern int sig_alarm;
extern int sig_child;
extern int sig_cont;
extern int sig_hangup;
extern int sig_pipe;
extern int sig_term;
extern int sig_segv;
extern int sig_int;

extern void (*sig_defaulthandler)(int);
extern void (*sig_ignorehandler)(int);

void sig_catch(int, void (*)(int));
#define sig_ignore(s) (sig_catch((s), sig_ignorehandler))
#define sig_uncatch(s) (sig_catch((s), sig_defaulthandler))

void sig_block(int);
void sig_unblock(int);
void sig_blocknone(void);
void sig_pause(void);

#endif
