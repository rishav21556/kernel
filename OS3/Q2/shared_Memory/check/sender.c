#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <semaphore.h>
#include<sys/sem.h>
#include <string.h>
#include<time.h>

int main(){
    //data = malloc(sizeof(char)*55);
    char path[100]  ;
    getcwd(path,100);
    //printf("%s\n",path);


    char *RandomString[50];
    int length = 12;
    for (int i = 0;i<50;i++){
        RandomString[i] = (char*) malloc(sizeof(char)*length);
        char ID = (char)(i+2);
        RandomString[i][0] = ID;
        for (int j = 1;j<length-1;j++){
            int num = (rand()%26)+97;
            RandomString[i][j] = (char)num;

        }
        

    }
    key_t key;
    int shmid;

    char *tocopy[2] = {"Rishav","raj"};

    key = ftok(path,'A');
    shmid = shmget(key,55,0644 | IPC_CREAT); // GET THE ID OF THE MEMORY SEGMENT CREATED
    char *data;
    struct timespec startTime;
    clock_gettime(CLOCK_REALTIME,&startTime);
    
    for (int i= 0;i<50;i= i+1){

        data = shmat(shmid,(void *)0,0);
        
        char message[60] ;
        strcpy(message,"");
        
        if (data ==(char*)(-1)){
            printf("no");
        }
        //strncpy(data,RandomString[i],12);
        for (int j = 0;j<=4;j++){
            strcat(message,RandomString[i+j]);
            //strcat(message," ");
        }
        strncpy(data,message,55);
        //printf("%s\n",data);
        pid_t pid ;
        pid = fork();
        if (pid ==0){
            execv("./recv.out",NULL);
        }
        wait(NULL);
        data = shmat(shmid,(void *)0,0);
        i = (int)data[0];
        
    }
    struct timespec endTime;
    clock_gettime(CLOCK_REALTIME,&endTime);
    printf("Time taken for above procedure is %f\n ",(endTime.tv_sec+(endTime.tv_nsec/(double)1000000000))-(startTime.tv_sec+(startTime.tv_nsec/(double)1000000000)));

    // sb.sem_op = 1;
    // semop(semid,&sb,1);
    // strncpy(data,tocopy[0],6);
    // strcat(data,tocopy[1]);
    // sb.sem_op = 1;
    // semop(semid,&sb,1);

    // shmdt(data);
    
}