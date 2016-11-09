/* stringcopy.c */

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>
# include <string.h>

/////////////////////////////////////////////////
void stringcopy( char * strDest , char * strSource ) {

  strcpy(strDest, strSource);

}

///////////////////////////////////////////////
//main function
int main ( int argc, char * argv []) {

  char strA[]="Sample string";
  char strB[40];
  stringcopy(strB, strA);
  printf ("strA: %s\nstrB: %s\n",strA,strB);
  return 0;

}// end of main function



