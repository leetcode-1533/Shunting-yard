
int alg_init(val * con, struct alg_queue * starter){
    starter -> rear = con;
    starter -> lead = starter->rear;
    return 0;
}

int alg_loc(struct alg_queue * node){
    return (node->rear - node->lead);
}

int alg_insert(val con, struct alg_queue * node){
    *(node->lead) = con;
    node->lead ++;
    return 0;
}
