#include "buffer.h"
#include "write.h"

static char bc002[256];
static struct buffer bb002 = buffer_INIT(write, 2, bc002, sizeof bc002);
struct buffer *buffer2 = &bb002;
