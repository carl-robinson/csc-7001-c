/* sumint.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>

//takes pointer to array of chars, interprets them as ints, then sums them
int sumintegers ( int argc, int argi []) {
//loop through argi array using pointer arithmetic to access array elements
//and increment variable by array contents
//then return variable
    int i,sum = 0;
    //keep looping while contents of pointer location is non-zero
    for (i = 1; i < argc; i++) {
       
        //add contents of pointer location (element of array) 
        sum += argi[i];
        //increment the pointer by one element's worth of bytes (4)
        //argi++;
        //print the values for debugging
        //printf("sum=%d,argi=%d\n",sum,argi);
    }
    return sum;

} //end of sumintegers function
////////////////////////////////////////////////

int main ( int argc, char * argv []) {

//make an int array of the same size
int i;
int argi[argc];
//convert char array to int array before calling function
for (i = 1; i < argc; i++) {
    //sscanf to convert string to int
    sscanf (argv[i],"%d",&argi[i]);
    //debug string
    //printf("argc=%d, argi%d=%d\n",argc,i,argi[i]);
} 

//call sumintegers with params used to run program
//and print returned result to screen
printf("The sum of the integers is: %d\n",sumintegers(argc,argi));

}// end of main function



