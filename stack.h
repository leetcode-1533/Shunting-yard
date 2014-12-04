#define stack_size 20

typedef char val;


struct buffer_stack{
    val * base;
    val * head;
};

int init(val * con, struct buffer_stack * starter);

int pop (val * con, struct buffer_stack * node);

int push(val con, struct buffer_stack * node);

void temp_debug(struct buffer_stack * node);

