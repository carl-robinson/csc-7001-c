/* myfirststruct.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>
# include <string.h>

///////////////////////////////////////////////
//main function
int main ( int argc, char * argv []) {

    struct complex {
    
        double dblReal;
        double dblImaginary;
    
    } complex1;
    
    union {

        double dblInput;
        unsigned char array [8];

    } myunion;

    //Print welcome message and ask for a guess of the number
    printf("Hi, please enter a number with a decimal point, and I'll give you the 4 bytes that make it up!\n");
    ////scanf to get double
    scanf("%f",&myunion.dblInput);
    
    int i;
    for (i=0;i<8;i++){

        printf("%02x ",myunion.array[i]);

    }   

    printf("\n");
    return 0;

}// end of main function



