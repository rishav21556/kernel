#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(){
    int len ,s ; //s -->SOCKET DESCRIPTOR
    int s2; // NEW SOCKET DESCRIPTOR
    char path[100];
    getcwd(path);
    struct socketaddr_un local,remote;

    socket(AF_UNIX,SOCK_STREAM,0);
    local.sun_family = AF_UNIX;
    strcpy(local.sun_path,path);
    unlink(local.sun_path);
    len = strlen(local.sun_path)+sizeof(local.sun_family);
    bind(s,(struct sockaddr *)local,len);


    listen(s,1); //2nd arg --> NUMBER OF CONNECTION

    s2 = accept(s,&remote,&len);
    char str[11];

    int returnedSize = recv(s2,str,100,0);
    while(n<=0){
        recv(s2,str,100,0);
    }
    printf("%s\n",str);

    close(s2);
    




    return 0;
}