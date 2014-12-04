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
    val container_oper[stack_size] = {0};
    val container_numb[stack_size] = {0} ;
    struct buffer_stack con_oper;
    struct buffer_stack con_numb;

    struct buffer_stack * oper;
    struct buffer_stack * numb;

    oper = & con_oper;
    numb = & con_numb;

    init(container_oper,oper);
    init(container_numb,numb);

    push('@',oper);

    val inspector;
    int code;
    val exp1;
    val para;
    val exp2;

    int temp_result;

    do{
      //temp_debug(buffer);

      //stage 1
      if(head_loc(buffer) != 0){
        pop(&inspector,buffer);
        code = encoder(inspector);
        if(code == NUM)
            push(inspector,numb);
        else if( code > peek(oper) )
            push(inspector,oper);
        else if( code <= peek(oper) ){ //exp1 para exp2
            pop(&exp2,numb);
            pop(&para,oper);
            pop(&exp1,numb);

            temp_result = two_eval(exp1,para,exp2);
        }
      }
    }
    while( peek(oper) != '@' || head_loc(buffer)!=0 );

    return 0;
}

float two_eval(val exp1, val para, val exp2){

    char code = (char) para;
    switch(code){
        case '+' : return (exp1 + exp2); break;
        case '-' : return (exp1 - exp2); break;
        case '*' : return (exp1 * exp2); break;
        case '/' : return (exp1 / exp2); break;
        default :
            return -1;
    }
}

int encoder(val input){
    int output;
    int int_input = (char)input;
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
