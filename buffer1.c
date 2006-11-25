#include "buffer.h"
#include "write.h"

static char bc001[4096];
static struct buffer bb001 = buffer_INIT(write, 1, bc001, sizeof bc001);
struct buffer *buffer1 = &bb001;
