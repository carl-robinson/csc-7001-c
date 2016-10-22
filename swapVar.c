/* equation.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

int a,b;

void swap(int varA, int varB){

		int a_backup;
		a_backup = varA;
		a = varB;
		b = a_backup;

}

int main ( int argc, char * argv []) {
	
	a = 2;
	b = 3;
	swap(a,b);

	printf("a=%d b=%d\n", a, b);

}

