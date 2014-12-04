#include "stack.h"

#include <stdio.h>



int init(val * con, struct buffer_stack * starter){
    starter -> base = con;
    starter -> head = starter->base;
    return 0;
}


int f_init(val * con, struct float_stack * starter){
    starter -> base = con;
    starter -> head = starter->base;
    return 0;
}


int f_pop (val * con, struct float_stack * node){
    if(node->base == node->head){
        return -1;
    }else{
        node->head = node->head -1;
        * con = *(node->head);
        return 0;
    }
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

int f_push(val con, struct float_stack * node){
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
    while(node->head != node->base){
        pop(&temp,node);
        printf("%c\n",temp);
    }
}

val peek(struct buffer_stack * node){
    return *((node->head)-1);
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

float eval(struct buffer_stack * buffer){
    val container_oper[stack_size] = {'0'};
    val container_numb[stack_size] = {'0'};
    struct buffer_stack con_oper;
    struct buffer_stack con_numb;

    struct buffer_stack * oper;
    struct buffer_stack * numb;

    oper = & con_oper;
    numb = & con_numb;

    init(container_oper,oper);
    init(container_numb,numb);

    push('@',oper);

    do{
      //  peek()
      temp_debug(buffer);

    }
    while( peek(oper) != '@' || head_loc(buffer)!=0 );

    return 0;

}

int encoder(val input){
    int output;
    int int_input = (int)input;
    switch(int_input){
        case '+' :
        case '-' : output = MIDDLE; break;
        case '@' : output = LOWEST; break;
        case '*' :
        case '/' : output = HIGHEST; break;
        default :
            output = NUM;
    }
    return output;
}
