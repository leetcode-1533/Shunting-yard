#include "queue.h"

int alg_init(struct alg_queue * starter){
   /* starter -> rear = starter->container;
    starter -> lead = starter->rear;*/
    starter->lead = 0;
    starter->rear = 0;
    return 0;
}

int alg_isfull(struct alg_queue * node){
    if(node->lead == (node->rear+1)%queue_size){
        return 1;
    }
    else{
        return 0;
    }
}

int alg_isempty(struct alg_queue * node){
    if(node->lead == node->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int alg_insert(val con, struct alg_queue * node){
    if(alg_isfull(node)) //full
        return -1;
    node->container[node->rear] = con;
    node->rear = (node->rear + 1)%queue_size;

    return 0;
}

int alg_delete(val *con, struct alg_queue * node){
    if(alg_isempty(node)){
        return -1;
    }
    *con = node->container[node->lead];
    node->lead = (node->lead+1)&queue_size;
    return 0;

}
