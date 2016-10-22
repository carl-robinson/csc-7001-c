/* equation.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

int main ( int argc, char * argv []) {

	if( argc == 4 ) {
		//printf("Well done\n");
		//printf("argc = %d\n", argc);
	}
	else if( argc != 3 ) {
		printf("Three arguments required [a,b,c] for ax2 + bx + c.\n");
		exit(0);
   	}
	else {
		printf("Unexpected error.\n");
		exit(0);
   	}	

	double a,b,c,root1,root2;

	sscanf (argv[1],"%lf",&a);
	sscanf (argv[2],"%lf",&b);
	sscanf (argv[3],"%lf",&c);
/*
	printf("argv[1] = %lf\n", a);
	printf("argv[2] = %lf\n", b);
	printf("argv[3] = %lf\n", c);
*/
	if (b*b-4*a*c>0)
	{
		root1 = (-b + sqrt(b*b-4*a*c) ) / (2*a);
		root2 = (-b - sqrt(b*b-4*a*c) ) / (2*a);

		printf("root1 = %lf\n", root1);
		printf("root2 = %lf\n", root2);
	}
	else
	{
		printf("\n Discriminant is negative! No roots!\n");
	}

	return 0;
}
