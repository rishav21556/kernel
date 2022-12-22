#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <semaphore.h>
#include<sys/sem.h>
#include<string.h>
#include<time.h>

int main(int argc ,char *argv){
    char *data ;
    char path[100]  ;
    getcwd(path,100);
    //printf("%s\n",path);
    key_t key = ftok(path,'A');
    int shmid = shmget(key,55,0644|IPC_CREAT);
    if (shmid ==-1){
        printf("nos");
    }
    data = shmat(shmid,(void *)0,0);
    if (data==(char *)(-1)){
        printf("no");
    }
    int max = -1;
    for (int i = 0;i<55;i++){
        if (i==0 || i%11==0){
            printf("\n");
            printf("ID : %d : ",(int)(data[i])-2);
            if ((int)(data[i])-2>max){
                max = (int)(data[i])-2;
            }
        }
        else{
            printf("%c",data[i]);
        }
    }
    printf("\n");
    char send[1] ;
    send[0]= (char)(max);
    strncpy(data,send,1);



    shmdt(data);


}

