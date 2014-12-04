#include "stack.h"

#include <stdio.h>



int init(val * con, struct buffer_stack * starter){
    starter -> base = con;
    starter -> head = starter->base;
    return 0;
}

int pop (val * con, struct buffer_stack * node){

    if(node->base == node->head){
        return -1;
    }else{
        node->head = node->head -1;
        * con = *(node->head);
        return 0;
    }
}

int push(val con, struct buffer_stack * node){
    if(node->head - node->base >= stack_size )
    {
        return -1;
    }
    else{
        *(node->head) = con;
        (node->head) ++;
        return 0;
    }
}

void temp_debug(struct buffer_stack * node){
    val temp;
    while(node->head != node->base){
        pop(&temp,node);
        printf("%c\n",temp);
    }
}
