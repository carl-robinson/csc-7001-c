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

//////////////////////////////////////////
//new stack function
//returns a null valued pointer to a struct element i.e. the start of a stack
stack * new () {
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
    s = e;
    return s;
}
///////////////////////////////////////
//pop function
stack pop(stack s){
    return s->link;
}
///////////////////////////////////////
//top function
int top(stack s){
    return s->val;
}
///////////////////////////////////////////////
//main function
int main ( int argc, char * argv []) {

   return 0; 

}// end of main function



