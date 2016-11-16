/* polish.c */

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "schtack.h"

///////////////////////////////////////////////
//main function
int main ( int argc, char * argv []) {

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

    return 0; 

}// end of main function



