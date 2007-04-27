#ifndef CORELIB_ENV_H
#define CORELIB_ENV_H

#define ENV_OVERALLOC 32

extern char **environ;

int env_get(const char *, const char **);
int env_put(const char *, const char *);
int env_unset(const char *);
void env_clear();

#endif
