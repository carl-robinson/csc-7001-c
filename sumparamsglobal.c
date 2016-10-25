/* sumparamsglobal.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>

//global variable that is increased by the result of each sumintegers call
int summation = 0;

//takes int param and adds to summation global var, then returns that
int sumintegers ( int numbertoadd ) {
    summation += numbertoadd;
    return summation;

} //end of sumintegers function
////////////////////////////////////////////////

int main ( int argc, char * argv []) {

//call sumintegers function and print result
int i;
for (i=1; i<11; i++){ 
    printf("%d + %d = ",summation, i);
    printf("%d\n",sumintegers(i));
}
}// end of main function



