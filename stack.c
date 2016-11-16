/* stack.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>
# include <string.h>

struct element {
    int val;
    struct element * link;
}; //struct element holds an int and a pointer to another struct element/NULL

typedef struct element * stack; //stack is a pointer to a struct element

stack new ();
int isempty(stack s);
stack push(stack s, int i);
stack pop(stack s);
int top(stack s);


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



