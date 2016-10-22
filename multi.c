/* multi.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

int main ( int argc, char * argv []) {

int intNumber,i;
char term;

//ask user for number
printf("Enter an integer and I'll display the first ten multiples for you:\n");
//check it's an integer, quit if not
if(scanf("%d%c", &intNumber, &term) != 2 || term != '\n'){
	printf("Please enter a valid integer.\n");
	exit(0);
}
else{
//for loop, multiplying by 1 to 10, printing results
	for(i=1;i<=10;i++){
		printf("x%d: %d\n",i,intNumber * i);
	}
}
}
