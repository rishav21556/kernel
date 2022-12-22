#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

char *RandomString[50];
int i = 0;

int main(){
    int length = 12;
    for (int i=0;i<50;i++){
        RandomString[i] = (char*)malloc(sizeof(char)*length);
        char ID = (char)(i+2);

        for (int j=0;j<length-2;j++){
            int num = (rand()%26)+97;
            RandomString[i][j] = (char)num;
        }
        RandomString[i][10] = ID;
        RandomString[i][11] = '\0';
    }
    int status = mkfifo("fifo",0666);
    int status2 = mkfifo("fifo2",0666);
    if (status<0){
        if (errno!=EEXIST){
                perror("mkfifo");
        }
    }
    if (status2<0){
        if (errno!=EEXIST){
                perror("mkfifo");
        }
    }
    int num;
    int fd;
    int max = -1;
    struct timespec StartTime;
    clock_gettime(CLOCK_REALTIME,&StartTime);
    for (int i = 0;i<50;i++){
        pthread_t thread;
        for (int j = 0;j<5;j++){
            pid_t pid;
            pid = fork();

            if (pid==0){
                execv("./p2.out",NULL);
            }
            fd = open("fifo",O_WRONLY);
            write(fd,RandomString[i+j],length);

            int fd2 = open("fifo2",O_RDONLY);
            char a[i];
            int num = read(fd,a,1);
            while(num<=0){
                num = read(fd2,a,1);
            }
            int returne = (int)(a[0]);
            if (returne>max){
                max = returne;
            }
            close(fd);
            close(fd2);
        }
        i = max-2;
    }
    struct timespec EndTime;
    clock_gettime(CLOCK_REALTIME,&EndTime);
    printf("Time taken by whole procedure is : %f\n",(EndTime.tv_sec+EndTime.tv_nsec/(double)1000000000)-(StartTime.tv_sec+StartTime.tv_nsec/(double)1000000000));
    
}