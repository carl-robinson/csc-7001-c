/* letter.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

int main ( int argc, char * argv []) {
//Generate random number between 1 and 100
time_t t;
srand((unsigned) time(&t));
int intNumber = rand() % 100 + 1;
//Print welcome message and ask for a guess of the number
printf("Hi, I'm going to think of a number between 1 and 100... Try and guess it!\n");
//scanf to get first guess (enter do/while loop)
int intGuess,i;
do {
scanf("%d",&intGuess);
//check if guess is higher/lower than random number, and inform user
if (intGuess > intNumber) {
printf("Too high! Guess again!:\n");
continue;
}
else {
	//check if guess is higher/lower than random number, and inform user
	if (intGuess < intNumber) {
	printf("Too low! Guess again!:\n");
	continue;
	}
	else {
		//if guess is correct, break out of loop and congratulate user
		if (intGuess == intNumber) {
		printf("You got it, well done!:\n");
		break;
		}
	}
}

} while (1);
}
