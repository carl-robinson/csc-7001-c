# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>

//global counter for sum function
int i, total = 0;
char c;

int main ( int argc, char * argv [ ] )
{
//  printf("one: %d\n",dispatcher()); 

    //create semaphore
    int semid;
    semid = semget(IPC_PRIVATE, 3, IPC_CREAT | 600);
    //create semaphore structs 0=sum, 1=trans
    //struct sembuf P[3] = {{0,-1,0}, {1,-1,0}, {2,-1,0}};
    struct sembuf P[2] = {{0,-1,0}, {1,-1,0}};
    //struct sembuf V[3] = {{0,1,0}, {1,1,0}, {2,1,0}};
    struct sembuf V[2] = {{0,1,0}, {1,1,0}};
    //initialise semaphore
    union semun {
        int val;
        struct semid_ds * buf;
        unsigned short * array;
        struct seminfo * __buf;
    };
    
    union semun semopts;
    semctl(semid, 0, SETVAL, semopts);

    //create shared memory (so it's linked to all children)
    int shmid;
    char * addr;
    key_t key;
    key = ftok("/mci/msc2015/robinson/key4",71);
    perror("SHMKEY");
    shmid = shmget(key, sizeof(char), IPC_CREAT | IPC_EXCL | 0666);
    perror("SHMGET");
    printf ("shmid:%p\n", shmid);
    //attach main/dispatcher proc to shm
    addr = (char *) shmat(shmid,NULL,0);
    perror("SHMAT");
    printf ("shared memory attached at address %p\n", addr);
    //fork processes 
    pid_t ret;

    switch(ret = fork()){
        case -1:
            perror("fork");
            _exit(1);
        case 0:
            //sum code
            printf("sum\n");
            while(1){
                 //P for trans to get val/wait
                semop(semid, &P[1], 1);
                //get value from shm
                c = *addr; 

                //test value and increment       
                if(isdigit(c)){
                    total += (c - '0');
                }
                else{
                    total = 0;
                }
                //put total into shm
                c = (char) total + '0';
                sprintf (addr, &c);
 
                //V for trans to release shm
                semop(semid, &V[1], 1);       
            }
            _exit(1);
        default:
            switch(ret = fork()){
                case -1:
                    perror("fork");
                    _exit(1);
                case 0:
                    //translate code
                    printf("translate\n");
                    while(1){
                        //P for sum to get val/wait
                        semop(semid, &P[0], 1);
                        //get value from shm
                        c = *addr; 
                       
                        if(isalpha(c)){
                            if(islower(c)){
                                c = (char) toupper(c);
                            }
                            else{
                                c = (char) tolower(c);
                            }
                        }
                        //put modified char in shm
                        sprintf (addr, &c);
                        
                        //V for disp to release shm
                        semop(semid, &V[0], 1);
                    }
                    _exit(1);
                default:
                    //dispatcher code
                    printf("dispatcher\n");
                    while(1){
                        //getchar and put in shm
                        c = getchar();
                        
                        //if EOF with ^D quit loop
                        if(c == 'q'){
                            break;
                        }

                        //put c in shm
                        sprintf (addr, &c);

                        if(isalpha(c)){
                            //V for trans to do operation
                            semop(semid, &V[1], 1);
                        }
                        else if(isdigit(c)){
                            //V for sum to do operation
                            semop(semid, &V[0], 1);
                        }

                        //clear input stream of all other chars
                        while('\n'!=getchar()); 
                        
                       //get result from shm
                        c = *addr; 

                       //print it
                       printf("%c\n",c); 
                    }
                    
                    //detach the shared memory
                    shmdt(addr);
                    shmctl(shmid, IPC_RMID,0);
                    _exit(1);
            }
        }
}


