#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    val container[stack_size] = {'0'};
    struct buffer_stack head_con;
    struct buffer_stack * head;
    head = & head_con;

    init(container,head);
    //val temp;

    //int i = 0;
    //char str[] = "2+1";
    //if( str2stack(str,head) == 0)
      //  temp_debug(head);
      push('c',head);
      push('c',head);

      printf("%d",head_loc(head));
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
