/* syracuse.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>

////////////////////////////////////////////////
//function that takes s0 and n as args, and returns nth element in series
int element ( unsigned int s, unsigned int n ) {
    //declare counter for element in the series
    int i;
    //while loop, to test if s0 and subsequent s != 1. Start at 2, as first
    //element is the parameter s before modification
    for (i=2; i<=n; i++) {
        
        //if s is even, divide it by two
        if (s % 2 == 0 ) {
            s /= 2;
        }
        //if s is odd, multiply it by 3 then add 1
        else {
            s = 3 * s + 1;
        }
    }

    return s;
}

////////////////////////////////////////////////
//function that takes s0 and returns number of iterations before reaching 1
unsigned int iterationsto1 ( unsigned int s ) {
    //must initialise counter to zero, or else could start from any value
    unsigned int iterations = 0;
    //iterations = 222;

    //while loop, to test if s0 and subsequent s != 1
    while (s != 1) {
        
        //if s is even, divide it by two
        if (s % 2 == 0 ) {
            s /= 2;
        }
        //if s is odd, multiply it by 3 then add 1
        else {
            s = 3 * s + 1;
        }

        //increment iterations counter in either case
        iterations++;

    }

    return iterations;
}

////////////////////////////////////////////////
//function that takes s0 and returns the number of iterations before reaching
//less than s0
unsigned int iterationstos0 ( unsigned int s ) {
    //must initialise counter to zero, or else could start from any value
    unsigned int iterations = 0;
    //save value of s0
    unsigned int s0 = s;

    //while loop, to test if s0 and subsequent s >= s0
    while (s >= s0) {
        
        //if s is even, divide it by two
        if (s % 2 == 0 ) {
            s /= 2;
        }
        //if s is odd, multiply it by 3 then add 1
        else {
            s = 3 * s + 1;
        }

        //increment iterations counter in either case
        iterations++;
    }

    return iterations;
}

////////////////////////////////////////////////
//function that takes s0 and continues until reaching 1, returning the highest value taken by sN along the way 
int highestvalue ( unsigned int s ) {
    //declare highest value counter as 1
    int highest = 1;

     //while loop, to test if s0 and subsequent s != 1
    while (s != 1) {
        
        //if s is even, divide it by two
        if (s % 2 == 0 ) {
            s /= 2;
        }
        //if s is odd, multiply it by 3 then add 1
        else {
            s = 3 * s + 1;
        }

        //if s > highest, set highest to s, otherwise do nothing
        if (s > highest) {
            highest = s;
        }

    }    

    return highest;
}

////////////////////////////////////////////////
//main function
int main ( int argc, char * argv []) {

    //declare vars
    int mode, s0, n;
    char term;

    //display 4 options to user, parse input and call switch

    printf("Please choose one of the following 4 modes:\n");
    printf("[1] Display nth element for a given s0\n");
    printf("[2] Display the number of iterations before reaching 1\n");
    printf("[3] Display the number of iterations before reaching < s0\n");
    printf("[4] Display the highest value taken by sN in the series\n");
    printf("Enter the mode number followed by <enter>:\n");

    if(scanf("%d%c", &mode, &term) != 2 || term != '\n' || mode > 4 || mode < 1){
            printf("Unrecognised character - enter a valid integer [1-4].\n");
            exit(0);
    }

    //ask user for s0, exit if invalid
    printf("Please enter the value of the first element of the syracuse series (positive integer):\n");
    if(scanf("%d%c", &s0, &term) != 2 || term != '\n' || s0 < 1){
        printf("Unrecognised character - enter a positive integer.\n");
        exit(0);
    }
     
    //call one of four functions based on input
    switch (mode) {
        //option 1 - nth element
        case 1: 
            //ask user for nth element to fetch
            printf("Please enter a value for n. The nth element of the series will then be displayed:\n");
            if(scanf("%d%c", &n, &term) != 2 || term != '\n' || n < 1){
                printf("Unrecognised character - enter a positive integer.\n");
                exit(0);
            }
            //call element() with s0 as param and display result
            printf("Element number %d of the syracuse series starting at %d is: %d\n", n, s0, element(s0, n));
            break; 
        case 2:
            //call iterationsto1() with s0 as param and display result
            printf("The number of iterations required to reach 1 in the syracuse series starting at %d is: %d\n", s0, iterationsto1(s0));
            break; 
        case 3:
            //call iterationstos0) with s0 as param and display result
            printf("The number of iterations required to drop below s0 in the syracuse series starting at %d is: %d\n", s0, iterationstos0(s0));
            break;
        case 4:
            //highestvalue()highestvaluehighestvalue
            //call highestvalue() with s0 as param and display result
            printf("The highest value taken by sN in the syracuse series starting at %d is: %d\n", s0, highestvalue(s0));
            break; 
        default:
            printf("Error occured.\n");
            exit(0);

    }


}// end of main function



