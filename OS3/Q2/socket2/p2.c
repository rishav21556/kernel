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

    int initialSdes;
    struct sockaddr_un local,remote;
    int len;

    initialSdes = socket(AF_UNIX,SOCK_STREAM,0);

    if (initialSdes==-1){
        perror("socket");
    }

    local.sun_family = AF_UNIX; 
    strcpy(local.sun_path, path);
    unlink(local.sun_path);

    len = strlen(local.sun_path)+sizeof(local.sun_family);
    int bid = bind(initialSdes,(struct sockaddr *)&local,len);
    if (bid==-1){
        perror("bind");
    }


    int list = listen(initialSdes,1);
    if (list ==-1){
        perror("listen");
    }
    len = sizeof(struct sockaddr_un);
    int acceptingSdes = accept(initialSdes, (struct sockaddr *)&remote, &len);

    if (acceptingSdes == -1){
        perror("accept");
    }

    char buf[100];

    while(len= recv(acceptingSdes,&buf,100,0),len>0){
        printf("%s\n",buf);
    }
    close(acceptingSdes);
    close(initialSdes);

}