#include "buffer.h"
#include "read.h"

static char bc000[4096];
static struct buffer bb000 = buffer_INIT(read, 0, bc000, sizeof bc000);
struct buffer *buffer0 = &bb000;
