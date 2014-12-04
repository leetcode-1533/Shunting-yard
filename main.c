#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    val container[stack_size] = {'0'};
    struct buffer_stack head_con;
    struct buffer_stack * head;
    head = & head_con;
/*
    val temp;
    init(container,head);
    push('c',head);
    pop(&temp,head);
    push('e',head);
    printf("%c",(head->base)[0]);
*/
    init(container,head);
    val temp;
    /*
    int i;
    for( i = 0 ; i <= 18 ; i ++ ){
        scanf(" %c",&temp);
        push(temp,head);
        printf("The number :%d\n",i);
    }
    temp_debug(head);*/
    int i = 0;
    while(temp != 'e'){
        switch(temp){
            case '#':{
                    pop(&temp,head);
                    i--;
                    break;
                }
            case 'f':{
                scanf(" %c",&temp);
                continue;
                }
            default :{
                push(temp,head);
                i++;
                break;
                }
        }
        if( i <= stack_size -1 ){
            //maximum capacity stack_size -1
            scanf(" %c",&temp);
        }
        else{
            printf("full");
            init(container,head);
            i = 0;
            temp = 'f';
        }
    }
    temp_debug(head);
    return 0;
}
