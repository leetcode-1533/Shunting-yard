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



int head_loc(struct buffer_stack * node){
    return (node->head - node->base);
}


void temp_debug(struct buffer_stack * node){
    val temp;
    char char_temp;
    while(node->head != node->base){
        pop(&temp,node);
        char_temp = (char)temp;
        printf("%c\n",char_temp);
    }
}

val peek(struct buffer_stack * node){
    return *((node->head)-1);
}



int stack2str(char * str, struct buffer_stack * node){
    val temp;
    char char_temp;

    while( head_loc(node) != 0){
        pop(&temp,node);
        char_temp = (char) temp;
        *str = char_temp;
        str ++;
    }
    *str = '\0';
    return 0;
}

int single_reverse(struct buffer_stack * input, struct buffer_stack * target){
    val temp;
    while( head_loc(input) != 0 ){
        pop(&temp,input);
        push(temp,target);
    }
    return 0;
}

int buffer_reverse(struct buffer_stack * head){
    val f_container_temp[stack_size] = {0};
    struct buffer_stack f_temp_con;
    struct buffer_stack * f_temp;
    f_temp = & f_temp_con;
    init(f_container_temp,f_temp);

    val s_container_temp[stack_size] = {0};
    struct buffer_stack s_temp_con;
    struct buffer_stack * s_temp;
    s_temp = & s_temp_con;
    init(s_container_temp,s_temp);

    single_reverse(head,f_temp);
    single_reverse(f_temp,s_temp); //s_temp==head
    single_reverse(s_temp,head); //head = f_temp
    return 0;
}






