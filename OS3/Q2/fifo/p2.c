#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,int *argv[]){
    int length = 12;
    char s[length];
    int fd = open("fifo",O_RDONLY);
    int size;
    int num = read(fd,s,length);

    while(num<=0){
        num = read(fd,s,length);
    }
    printf("ID : %d : STRING : ",(s[10])-2);
    for (int i = 0;i<length-2;i++){
        printf("%c",s[i]);
    }
    printf("\n");

    char return_id[1];
    return_id[0] = s[10];

    fd = open("fifo2",O_WRONLY);

    write(fd,return_id,1);


    return 0;
}