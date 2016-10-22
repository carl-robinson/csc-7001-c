/* equation.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

int main ( int argc, char * argv []) {

	int size;
	sscanf (argv[1],"%d",&size);
	int sieve[size];
	
	//set them all to ones - one means it's a prime
	int i;
	for(i = 0; i < size; i++){
		sieve[i] = 1;
	}

	//loop through every element of the sieve matrix which contains all ones
	int j, k;
	for(j = 2; j < size; j++){
		//loop through all elements from j to the end
		for(k = 2; k < size; k++){
			//if j % k == 0, it's not a prime, so set sieve[k] to 0
			//and break
			//printf("j=%d,k=%d, \n", j,k);
			if (j % k == 0){
				//sieve[j] = 0;
				break;

			printf("j=%d,k=%d,sieve[%d]=%d\n", j,k,j,sieve[j]);
			}
		}
	}

}
