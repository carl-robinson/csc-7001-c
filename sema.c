# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>

# define KEY (1492)

//global counter for sum function
int i, total = 0;
char c;


int main ( int argc, char * argv [ ] )
{
//  printf("one: %d\n",dispatcher()); 

    //create semaphore
    int semid;
    semid = semget(KEY, 3, IPC_CREAT | 600);

    //create semaphore structs 0=disp, 1=sum, 2=trans
    struct sembuf P[3] = {{0,-1,0}, {1,-1,0}, {2,-1,0}};
    struct sembuf V[3] = {{0,1,0}, {1,1,0}, {2,1,0}};

    //initialise semaphores
    union semun {
        int val;
        struct semid_ds * buf;
        unsigned short * array;
        struct seminfo * __buf;
    };
    
    union semun semopts_disp;
    union semun semopts_sum;
    union semun semopts_trans;
    //set dispatcher to start immediately
    semopts_disp.val = 0;
    semctl(semid, 0, SETVAL, semopts_disp);
    //set sum and trans to wait
    semopts_sum.val = 0;
    semctl(semid, 1, SETVAL, semopts_sum);
    semopts_trans.val = 0;
    semctl(semid, 2, SETVAL, semopts_trans);

    //create shared memory (so it's linked to all children)
    int shmid;
    char * addr;
    key_t key;
    //key = ftok("/mci/msc2015/robinson/key6",71);
    perror("SHMKEY");
    shmid = shmget(KEY, sizeof(char), IPC_CREAT | IPC_EXCL | 0666);
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
                 //P for sum to get val/wait
                semop(semid, &P[1], 1);
                //get value from shm
                c = *addr; 

                //test value and increment       
                if(isdigit(c)){
                    total += (c - '0');
                    c = (char) total + '0';
                    //put total into shm
                    printf("c=%c\n",c);
                    sprintf (addr, &c);
                }
                else{
                    total = 0;
                }

                //V for disp to release shm
                semop(semid, &V[0], 1);
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
                        //P for trans to get val/wait
                        semop(semid, &P[2], 1);

                        printf("in translate proc\n");
                        //get value from shm
                        c = *addr; 
                        printf("trans proc got result from shared c=%c\n",c);
                       
                        if(isalpha(c)){
                            if(islower(c)){
                                c = (char) toupper(c);
                            }
                            else{
                                c = (char) tolower(c);
                            }
                        }
                        printf("trans proc changed char. c=%c\n",c);
                        //put modified char in shm
                        sprintf (addr, &c); 
                        printf("put c in shared mem. addr=%c\n",*addr);
                        
                        //V for disp to release shm
                        semop(semid, &V[0], 1);
                        printf("V sent from trans\n");
                    }
                    _exit(1);
                default:
                    //dispatcher code
                    printf("dispatcher\n");
                    while(1){
                        
                        //P for disp to run 
                        semop(semid, &P[0], 1);

                        //getchar and put in shm
                        c = getchar();
                        
                        //if EOF with ^D quit loop
                        if(c == 'q'){
                            break;
                        }

                        //put c in shm
                        printf("putting c in shared mem. c=%c\n",c);
                        sprintf (addr, &c);
                        printf("put c in shared mem. addr=%c\n",*addr);

                        if(isalpha(c)){
                            //V for trans to do operation
                            semop(semid, &V[2], 1);
                            printf("V sent for trans\n");
                        }
                        else if(isdigit(c)){
                            //V for sum to do operation
                            semop(semid, &V[1], 1);
                            printf("V sent for sum\n");
                        }

                        //clear input stream of all other chars
                        while('\n'!=getchar()); 
                        
                       //get result from shm
                        printf("getting result from shared mem. addr=%c\n",*addr);
                        c = *addr; 
                        printf("got result from shared c=%c\n",c);
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


