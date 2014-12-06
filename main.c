#include <stdio.h>
#include <stdlib.h>

#include "cal.h"

int main(){
    val container[stack_size] = {0};
    struct buffer_stack head_con;
    struct buffer_stack * head;
    head = & head_con;
    init(container,head);
    //val temp;



    push('4',head);
    push('*',head);
    push('3',head);
    push('-',head);
    push('2',head);
    push('+',head);
    push('4',head);
    push('*',head);
    push('5',head);
    push('-',head);
    push('6',head);
    push('*',head);
    push('6',head);
    push('6',head);
    push('*',head);
    push('3',head);


  /*  if( 1 ){
        float temp = eval(head);
        char c[50]="0";
        stack2str(c,head);
        printf("%d\n",head_loc(head));
       printf("%d",atoi(c));
       // printf("%f",temp);
      //  printf("%c",peek(head));
       // eval(head);
       // printf("%f",two_eval(3.1,'-',12));
        //eval(head);
    }*/
    float temp = eval(head);
    printf("%f\n",temp);

    struct alg_queue temp_queue;
    alg_init(&temp_queue);


    printf("%d\n",alg_insert(2,&temp_queue));
    alg_delete(&temp,&temp_queue);
    printf("%f",temp);
    //buffer_reverse(head);
  //  temp_debug(head);


  /*  while(temp != 'e'){
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
    temp_debug(head);*/
    return 0;
}
