#ifndef CORELIB_BUFFER_H
#define CORELIB_BUFFER_H

#define BUFFER_OUTSIZE 8192
#define BUFFER_INSIZE 8192

struct buffer {
  char *buf;
  unsigned long pos;
  unsigned long size;
  int fd;
  long (*op)(int, char *, unsigned long);
};

typedef long (*buffer_op)(int, char *, unsigned long);

#define buffer_INIT(op,fd,buf,len) { (buf), 0, (len), (fd), (buffer_op)(op) }

void buffer_init(struct buffer *, long (*)(int, char *, unsigned long), int, char *,
                 unsigned long);
long buffer_get(struct buffer *, char *, unsigned long);
long buffer_feed(struct buffer *);
char *buffer_peek(struct buffer *);
void buffer_seek(struct buffer *, unsigned long);

long buffer_flush(struct buffer *);
int buffer_put(struct buffer *, const char *, unsigned long);
int buffer_puts(struct buffer *, const char *);
int buffer_putflush(struct buffer *, const char *, unsigned long);
int buffer_putsflush(struct buffer *, const char *);

int buffer_copy(struct buffer *, struct buffer *);

#define buffer_PEEK(s) ( (s)->buf + (s)->size )
#define buffer_SEEK(s,len) ( ( (s)->pos -= (len) ) , ( (s)->size += (len) ) )
#define buffer_GETC(s,c) \
  ( ((s)->pos > 0) \
    ? ( *(c) = (s)->buf[(s)->size], buffer_SEEK((s),1), 1 ) \
    : buffer_get((s),(c),1) \
  )

extern struct buffer *buffer0;
extern struct buffer *buffer1;
extern struct buffer *buffer2;

#endif
