#define stack_size 20

//Priority codes
#define NUM 1
#define LOWEST 9
#define MIDDLE 10
#define HIGHEST 11

typedef char val;


struct buffer_stack{
    val * base;
    val * head;
    int current_size;
};

struct float_stack{
    val * base;
    val * head;
};


int init(val * con, struct buffer_stack * starter);

int f_init(val * con, struct float_stack * starter);

int pop (val * con, struct buffer_stack * node);

int f_pop (val * con, struct float_stack * node);

int push(val con, struct buffer_stack * node);

int f_push(val con, struct float_stack * node);

int head_loc(struct buffer_stack * node);

val peek(struct buffer_stack * node);

void temp_debug(struct buffer_stack * node);

int str2stack(char * str, struct buffer_stack * node);

float eval(struct buffer_stack * buffer);

int encoder(val input);
