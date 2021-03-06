#ifndef CORELIB_GETOPT_H
#define CORELIB_GETOPT_H

extern int opteof;
extern int optproblem;
extern int optind;
extern int optpos;
extern int optdone;
extern char *optprogname;
extern char *optarg;

int get_opt(int, char **, char *);
void get_opt_reset();

#endif
