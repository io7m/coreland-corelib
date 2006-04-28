#include "buffer.h"
#include "read.h"

static char bc000[4096];
static buffer bb000 = buffer_INIT(read, 0, bc000, sizeof bc000);
buffer *buffer0 = &bb000;
