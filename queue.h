
#define queue_size 2// Actually is 19

typedef float val;

struct alg_queue{
    int rear;
    int lead;
    val container[queue_size];
};


int alg_init(struct alg_queue * starter);

int alg_isfull(struct alg_queue * node);

int alg_insert(val con, struct alg_queue * node);

int alg_isempty(struct alg_queue * node);

int alg_delete(val * con, struct alg_queue * node);
