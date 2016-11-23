/* inputoutput.c */

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <unistd.h>
# define S_IREAD 0400 

//use SYSTEMCALLS
int main ( int argc, char * argv []) {

//get arg param

//create a file descriptor
int fd;

//create counters
int newline_counter = 0, char_counter = 0, word_counter = 0;

//create buffers for characters
char buffer, ch; 
int state_last = 1, state = 1;

//open the file
fd = open(argv[1],O_RDONLY,S_IREAD); 
if(fd < 0){
    perror("Unable to open data");
    exit (1);
}
printf("loaded file\n");

//Read all charactes in file - stop when read returns 0 (EOF)
while ( (ch = read(fd, &buffer, 1)) > 0 ){
    //increment char_counter for each char read
    if(buffer != '\n'){
        char_counter++;
    }

    //increment newline_counter for each \n read
    if(buffer == '\n'){
        newline_counter++;
    }

    //increment word_counter if FSM flip flops 
    //if(buffer isalpha change sign of state bit)
    if(!isalnum(buffer)){
        state *= -1; 
        //printf("state changed\n",word_counter);
    }
    //test state bit - if different to what it was, increment counter
    if(state != state_last){
        //set state_last to state
        state_last = state;
        //increment word counter
        word_counter++;
    }
}

printf("char_counter = %d\n",char_counter);
printf("newline_counter = %d\n",newline_counter);
printf("word_counter = %d\n",word_counter);
close(fd);
exit(0);
}
