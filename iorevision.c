# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

int main ( int argc, char * argv []) {
    
    //open file to read
    //get line number from stdin
    //read that line from file, and write to output file (with \n)
    //keep doing that until EOF sent with ^D
    
    //declare vars
    char c,ch;

    //write a string to a file
    FILE * fdw;
    fdw = fopen("iorevision_out","w+");

    //open file to read
    FILE * fdr;
    fdr = fopen(argv[1],"r");
    //printf("%s\n",argv[1]);

    //while not EOF use getchar to process stdin
    while(!feof(stdin)){
        c = getchar();
    
        if(isdigit(c)){
            fseek(fdr, (long)c-'0', SEEK_SET);
            ch=getc(fdr);
            printf("%c\n",ch);
            putc(ch,fdw);
        }
    }

    

    fclose(fdr); 
    fclose(fdw); 
}
