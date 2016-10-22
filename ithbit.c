/* ithbit.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>

unsigned int divide ( unsigned int intNumberParam ) {
unsigned int intResult = 1;

if ( intNumberParam & 1 == 1) { //number is odd
	return intResult;
}
else
{
	//find max bit set and return 2^maxbit
	while (intNumberParam >>= 1) {
		intResult *= 2;
	}
	
	return (intResult * 2) - 1;
} //endif

} //end of divide function

////////////////////////////////////////////////

int main ( int argc, char * argv []) {

unsigned int intNumber;
char term;

//ask user for number
printf("Enter an integer and I'll display the numbers that will divide into it (in hex):\n");
//check it's an integer, quit if not
if(scanf("%d%c", &intNumber, &term) != 2 || term != '\n'){
	printf("Unrecognised character - you must enter a valid integer.\n");
	exit(0);
}
else {
	//call divide with inputted number as param, and print result in hex
	printf("Result in hex: %x\n",divide(intNumber));
}
}// end of main function



