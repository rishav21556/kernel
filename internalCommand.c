#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/wait.h>

void echo(char *str){
	printf("%s",str);
}

void showdir(DIR *pointer){
	struct dirent *de;
	while((de=readdir(pointer))!=NULL){
		printf("%s\n",de->d_name);
	}
	closedir(pointer);
}

int main(){
	char *args = (char*)malloc(100*sizeof(char));
	char exit[] = "exit";
	char *path = (char*)malloc(100*sizeof(char));
	getcwd(path,100);
	while(strcmp(args,exit)!=0){


		printf("%s","RishavLaptop$~");
		printf("%s",path);
		printf("~");
		scanf("%[^\n]%*c",args);
		char tobreak[] = " ";
		char *ptr = strtok(args, tobreak);
		struct dirent *de;
		DIR *pointerTodirectory = opendir(path);		
		if (strcmp(ptr,"echo")==0){
			ptr = strtok(NULL, tobreak);
			if (ptr==NULL){
				printf("%s","invalid command\n");
			}
			else{
				while(ptr!=NULL){
					echo(ptr);
					printf(" ");
					ptr = strtok(NULL,tobreak);
				}
				printf("\n");	
			}
		}
		else if (strcmp(ptr,"ls")==0){
			showdir(pointerTodirectory);
		}
		else if(strcmp(ptr,"ls1")==0){
			pid_t Pid = fork();
			if (Pid==0){
				execl("cd.out","cd.out",(char*)NULL);
			}
			wait(NULL);		

		}
		else if (strcmp(ptr,"cd")==0){
			ptr = strtok(NULL, tobreak);
			if(ptr==NULL){
				chdir("..");
				char n[100];
				getcwd(n,100);
				path = n;
				pointerTodirectory = opendir(path);
			}
			else{
				
				if (chdir(ptr)!=0){
					perror("BASH");
				}
				else{
					char s[100];
					getcwd(s,100);
					path = s;
					pointerTodirectory = opendir(path);
				}
			}	
		}
		else if (strcmp(ptr,"pwd")==0){
			char s[50];
			printf("%s\n",getcwd(s,50));
		}		

	} 
}
