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

int str2stack(char * str, struct buffer_stack * node){
    char * char_pointer;
    char_pointer = str;
    while( *char_pointer != '\0'){
        if( push(*char_pointer,node) == 0 )
            char_pointer ++;
        else{
            return -1;
        }
    }
    return 0;
}
