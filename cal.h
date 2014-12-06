#include "stack.h"
#include "queue.h"

float eval(struct buffer_stack * buffer);

float two_eval(val exp1, val para, val exp2);

int encoder(val input);

int contruct_buffer(struct buffer_stack * input, struct buffer_stack * flo );
