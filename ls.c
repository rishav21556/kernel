#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>

void _showdir(DIR *pointer){
	struct dirent *de;
	while((de=readdir(pointer))!=NULL){
		printf("%s\n",de->d_name);
	}
	closedir(pointer);
	
}


void main(char *arg[],char *argv[]){
	printf("hi");
	//_showdir(pointerTodirectory);	
}
