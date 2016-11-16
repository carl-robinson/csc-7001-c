/* schtack.h */
#ifndef _SCHTACK_H_
#define _SCHTACK_H_

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

#endif // #ifndef _SCHTACK_H_
