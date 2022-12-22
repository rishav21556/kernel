#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>



int amountToEat = 10;


void* Philosopher1(void *args){
    printf("Philospher 1 is eating\n");
    int *amount = args;
    for (int i = 0;i<amountToEat;i++){
        (*amount)--;
    }
}
void* Philosopher2(void *args){
    printf("Philospher 2 is eating\n");
    int *amount = args;
    for (int i = 0;i<amountToEat;i++){
        (*amount)--;
    }
}
void* Philosopher3(void *args){
    printf("Philospher 3 is eating\n");
    int *amount = args;
    for (int i = 0;i<amountToEat;i++){
        (*amount)--;
    }
}
void* Philosopher4(void *args){
    printf("Philospher 4 is eating\n");
    int *amount = args;
    for (int i = 0;i<amountToEat;i++){
        (*amount)--;
    }
}
void* Philosopher5(void *args){
    printf("Philospher 5 is eating\n");
    int *amount = args;
    for (int i = 0;i<amountToEat;i++){
        (*amount)--;
    }
}
int main(){
    int amountOnPlate_1 = 100;
    int amountOnPlate_2 = 100;
    int amountOnPlate_3 = 100;
    int amountOnPlate_4 = 100;
    int amountOnPlate_5 = 100;

    int fork12 = 0;
    int fork23 = 0;
    int fork34 = 0;
    int fork45 = 0;
    int fork51 = 0;

    int souce1 = 0;
    int souce2 = 0;

    pthread_t p1;
    pthread_t p2;
    pthread_t p3;
    pthread_t p4;
    pthread_t p5;

    for (int i = 0;i<5;i++){
        if (fork12 == 0  && fork51==0 && fork23==0 && fork34==0 && (souce1==0 && souce2==0)){
            printf("-------------------------------------------------------\n");
            pthread_create(&p1,NULL,Philosopher1,&amountOnPlate_1);
            fork12 = 1;
            fork51 = 1;
            pthread_create(&p3,NULL,Philosopher3,&amountOnPlate_3);
            fork23 = 1;
            fork34 = 1;
            souce1 = 1;
            souce2 = 1;
            pthread_join(p1,NULL);
            fork12 = 0;
            fork51 = 0;
            pthread_join(p3,NULL);
            fork23 = 0;
            fork34 = 0;
            souce1 = 0;
            souce2 = 0;
            printf("-------------------------------------------------------\n");
        }
        if (fork12 == 0  && fork23==0 && fork45==0 && fork34==0 && souce1==0 && souce2==0){
            printf("-------------------------------------------------------\n");
            pthread_create(&p2,NULL,Philosopher2,&amountOnPlate_2);
            fork12 = 1;
            fork23 = 1;
            pthread_create(&p4,NULL,Philosopher4,&amountOnPlate_4);
            fork45 = 1;
            fork34 = 1;
            souce1 = 1;
            souce2 = 1;
            pthread_join(p2,NULL);
            fork12 = 0;
            fork23 = 0;
            pthread_join(p4,NULL);
            fork45 = 0;
            fork34 = 0;
            souce1 = 0;
            souce2 = 0;
            printf("-------------------------------------------------------\n");
        }


        
        if (fork34==0 && fork23==0 && fork45==0 && fork51==0 && souce1==0 && souce2==0){
            printf("-------------------------------------------------------\n");
            pthread_create(&p3,NULL,Philosopher3,&amountOnPlate_3);
            fork34 = 1;
            fork23 = 1;
            pthread_create(&p5,NULL,Philosopher5,&amountOnPlate_5);
            fork45 = 1;
            fork51 = 1;
            souce1 = 1;
            souce2 = 1;
            pthread_join(p3,NULL);
            fork34 = 0;
            fork23 = 0;
            pthread_join(p5,NULL);
            fork45 = 0;
            fork51 = 0;
            souce1 = 0;
            souce2 = 0;
            printf("-------------------------------------------------------\n");
        }     

       

        if (fork34==0 && fork45==0 && fork12==0 && fork51==0 && souce1==0 && souce2==0){
            printf("-------------------------------------------------------\n");
            pthread_create(&p4,NULL,Philosopher4,&amountOnPlate_4);
            fork34 = 1;
            fork45 = 1;
            pthread_create(&p1,NULL,Philosopher1,&amountOnPlate_1);
            fork12 = 1;
            fork51 = 1;
            souce1 = 1;
            souce2 = 1;
            pthread_join(p4,NULL);
            fork34 = 0;
            fork45 = 0;
            pthread_join(p1,NULL);
            fork12 = 0;
            fork51 = 0;
            souce1 = 0;
            souce2 = 0;
            printf("-------------------------------------------------------\n");
        }    

        if (fork51==0 && fork45==0 && fork12==0 && fork23==0 && souce1==0 && souce2==0){
            printf("-------------------------------------------------------\n");
            pthread_create(&p5,NULL,Philosopher5,&amountOnPlate_5);
            fork51 = 1;
            fork45 = 1;
            pthread_create(&p2,NULL,Philosopher2,&amountOnPlate_2);
            fork12 = 1;
            fork23 = 1;
            souce1 = 1;
            souce2 = 1;
            pthread_join(p5,NULL);
            fork51 = 0;
            fork45 = 0;
            pthread_join(p2,NULL);
            fork12 = 0;
            fork23 = 0;
            souce1 = 0;
            souce2 = 0;
            printf("-------------------------------------------------------\n");
        }
    }
}