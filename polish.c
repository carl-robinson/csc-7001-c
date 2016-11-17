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
stack s;
int a,b;

printf("Welcome to the Reverse Polish Calculator!\n");
printf("Enter single numbers from 0-9 and operators +-*/ to calculate.\n");
printf("At any time press  p to print top of stack, or q to quit.\n");

while(1){
    printf("Enter number/operator/p/q: \n");
    while((c = getchar()) != '\n' && c != 'q'){
        //printf("yes");
        switch(c){
            case '0' :
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
                //push
                s = push(s,c - '0');
                break;
            case '+' :
                //top,pop,top,pop,calc,push
                b = top(s);
                s = pop(s);
                a = top(s);
                s = pop(s);
                printf("%d + %d = %d\n",a,b,a+b);
                s = push(s,a+b);
                top(s);
                break;
           case '-' :
                //top,pop,top,pop,calc,push
                //subtracts b from a, e.g. 52- means 5-2
                b = top(s);
                s = pop(s);
                a = top(s);
                s = pop(s);
                printf("%d * %d = %d\n",a,b,a-b);
                s = push(s,a-b);
                top(s);
                break;
            case '*' :
                //top,pop,top,pop,calc,push
                b = top(s);
                s = pop(s);
                a = top(s);
                s = pop(s);
                printf("%d * %d = %d\n",a,b,a*b);
                s = push(s,a*b);
                top(s);
                break;
            case '/' :
                //top,pop,top,pop,calc,push
                //divides b by a, e.g. 52/ means 5/2
                b = top(s);
                s = pop(s);
                a = top(s);
                s = pop(s);
                printf("%d / %d = %d\n",a,b,a/b);
                s = push(s,a/b);
                top(s);
                break;
            case 'p' :
                top(s);
                break;
            case 'q' :
                break;
            default :
                printf("Invalid command, please try again\n");
                break;
        }
    }
    if(c == 'q') break;
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



