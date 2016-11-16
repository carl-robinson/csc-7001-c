/* schtack.c */

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "schtack.h"

//////////////////////////////////////////
//new stack function
//returns a null valued pointer to a struct element i.e. the start of a stack
stack new () {
    return NULL;
}

///////////////////////////////////////
//is_empty function
//checks if pointer is NULL and returns 0 if so
int isempty(stack s){
    if(s) {
        return 0;
    } else {
        return 1;
    }
}
/////////////////////////////////////////
//push function
//creates a new struct element pointer, assigns memory space for its contents
//then sets the value of i to the int parameter, and the value of link to the
//stack pointer, then updates the stack pointer to point to the new element 
//and returns it
stack push(stack s, int i){
    struct element * e;
    e = (struct element *) malloc(sizeof(struct element));
    e->val = i;
    e->link = s;
    printf("Pushed %d to stack\n",i);
    printf("Top of stack is: %d\n",i);
    return e;
}
///////////////////////////////////////
//pop function
stack pop(stack s){
    if (isempty(s)){
        printf("Cannot pop. Stack is empty.\n");
        return NULL;
    }
    free(s);
    printf("Popped top of stack\n");
    printf("Top of stack is: %d\n",s->link->val);
    return s->link;
}
///////////////////////////////////////
//top function
int top(stack s){
    if (isempty(s)){
        printf("Cannot pop. Stack is empty.\n");
        return 0;
    }
    printf("Top of stack is: %d\n",s->val);
    return s->val;
}



