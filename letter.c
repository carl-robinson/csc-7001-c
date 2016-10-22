/* letter.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

int main ( int argc, char * argv []) {

//scanf to get a character inputted
char charInput;
printf("Please enter a letter of the alphabet:\n");
scanf("%c",&charInput);
//isalpha to check its a letter
if isalpha(charInput){
	//tolower to get into lowercase
	charInput = tolower(charInput);
	//switch to check it's a vowel
	switch(charInput){
	//print message if it is a vowel
	case 'a' : case 'e' : case 'i' : case 'o' : case 'u' :
		printf("Your letter is a vowel.\n");
		break;
	//print message if it is a consonant
	default :
		printf("Your letter is a consonant.\n");
		break;
	}
}
else {
printf("Unrecognised input. Please enter a letter from a to z.\n");
}
}
