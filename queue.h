
#define queue_size 20

#include "stack.h" //Using the val type;

struct alg_queue{
    val * rear;
    val * lead;
};


int alg_init(val * con, struct alg_queue * starter);

int alg_inqueue(val con, struct alg_queue * node);

int alg_loc(struct alg_queue * node);

int alg_insert(val con, struct alg_queue * node);
