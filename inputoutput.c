/* inputoutput.c */

# include <stdio.h>
# include <fcnt1.h>
# define BUFSIZE 1024

//use SYSTEMCALLS
int main ( int argc, char * argv []) {

//get arg param

//create a file descriptor
int fd;

//create counters
int char_counter, newline_counter, word_counter;

//create a buffer for characters
char buffer [BUFSIZE]; 

//open the file
if(fd = open(argv[0],O_RDONLY|O_TEXT,S_IREAD < 0){
    perror("Unable to open data");
    exit (1);
}

//Read all charactes in file - stop when read returns 0 (EOF)
while ( (length = read (fd, buffer, 1)) > 0 ){
    //increment char_counter for each char read

    //increment newline_counter for each \n read
    //increment word_counter if FSM flip flops 
}

close (fd);
exit (0); 
