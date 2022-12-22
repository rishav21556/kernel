#include<stdio.h>
#include<stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <resolv.h>
#include<unistd.h>

int main(){
    char path[100];
    getcwd(path,100);
    char *RandomString[50];
    int length = 12;
    for (int i = 0;i<50;i++){
        RandomString[i] = (char*) malloc(sizeof(char)*length);
        char ID = (char)(i+2);

        for (int j = 0;j<length-2;j++){
            int num = (rand()%26)+97;
            RandomString[i][j] = (char)num;

        }
        RandomString[i][10] = ID;
    }

    int initialSdes;
    struct sockaddr_un remote;
    int len;

    if (initialSdes==-1){
        perror("socket");
    }

    remote.sun_family = AF_UNIX;
    strcpy(remote.sun_path,path);
    len = strlen(remote.sun_path)+sizeof(remote.sun_family);

    if (connect(initialSdes,(struct sockaddr *)&remote,len)==-1){
        perror("connect");
    }
    send(initialSdes,RandomString[0],11,0);
    close(initialSdes);
    return 0;
}

