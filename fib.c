/* fib.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

int main ( int argc, char * argv []) {
//define vars
//loop 100 times, summing previous two elements in the sequence and printing

int un,unplus1,unplus2,n;
un = unplus1 = unplus2 = n = 1;

//print u0 and u1. n=0,1
printf("%d\n",un);
printf("%d\n",unplus1);

//print values of un from n=2 to 100
for(n=2;n<101;n++){
//calc un
unplus2 = un + unplus1;
//print unplus2
printf("%d\n",unplus2);

//set un and unplus
un = unplus1;
unplus1 = unplus2;

}

}
