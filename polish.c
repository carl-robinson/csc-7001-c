/* polish.c */

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "schtack.h"

///////////////////////////////////////////////
//main function
int main ( int argc, char * argv []) {

//do while loop to read characters entered at command line one at a time
//read one character using getchar
//for each character use switch case to determine what stack func
//for 0-9 push
//for operators pop twice saving values, perform operation, push result
//for q break
//for p print top

char c;

printf("Welcome to the Reverse Polish Calculator!\n");
printf("Enter single numbers from 0-9 and operators +-*/ to calculate.\n");
printf("At any time press  p to print top of stack, or q to quit.\n");

while(1){
    printf("Enter number/operator/p/q: \n");
    while((c = getchar()) != '\n'){
        printf("yes");
    }
}


/*
    stack s = new();
    int i;
    
    for(i=1;i<=5;i++){
        s = push(s,i);
    }

    s = pop(s);
    s = pop(s);
    s = pop(s);
    s = push(s,6);
    s = push(s,7);
    s = pop(s);
    s = push(s,8);
    s = push(s,9);
    s = push(s,10);
    s = push(s,11);
    s = push(s,12);
    s = pop(s);
*/


    return 0; 

}// end of main function



