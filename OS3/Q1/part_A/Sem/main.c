#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<semaphore.h>
#include<unistd.h>

int AmountToEat = 10;
int ToEatInOneTime  = 2;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;
int flag5 = 0;


int fork12 = 0;
int fork23 = 0;
int fork34 = 0;
int fork45 = 0;
int fork51 = 0;

sem_t sem12;
sem_t sem23;
sem_t sem34;
sem_t sem45;
sem_t sem15;

void *Philosopher1(void *arg){
    int amountOnPlate = AmountToEat;
    while(1){
        //printf("hi");
        printf("---------------------------------------------------------\n");
        if (amountOnPlate>0){
            sem_wait(&sem12);
            fork12 = 1;
            sem_wait(&sem15);
            fork51 = 1;
            printf("Philospher 1 start eating\n");
            for (int i= 0;i<ToEatInOneTime;i++){
                amountOnPlate--;
            }
            printf("Philosopher 1 has done eating\n");
            fork12 = 0;
            fork51 = 0;
            sem_post(&sem15);
            sem_post(&sem12);
            sleep(1);
        }
        else{
            printf("Philospher 1 plate is empty\n");
            break;
        }
        printf("---------------------------------------------------------\n");
    }
}

void *Philosopher2(void *arg){
    int amountOnPlate = AmountToEat;
    while(1){
        //printf("hi");
        
        printf("---------------------------------------------------------\n");
        if (amountOnPlate>0){
            sem_wait(&sem12);
            fork12 = 1;
            sem_wait(&sem23);
            fork23 = 1;
            printf("Philospher 2 start eating\n");
            
            for (int i= 0;i<ToEatInOneTime;i++){
                
                amountOnPlate--;
            }
            fork12 = 0;
            fork23 = 0;
            printf("Philosopher 2 has done eating\n");
            sem_post(&sem23);
            sem_post(&sem12);
            sleep(2);
        }
        else{
            printf("Philosopher 2 plate is empty\n");
            break;
        }
        printf("---------------------------------------------------------\n");
    }
}

void *Philosopher3(void *arg){
    int amountOnPlate = AmountToEat;
    while(1){
        //printf("hi");
        
        printf("---------------------------------------------------------\n");
        if (amountOnPlate>0){
            sem_wait(&sem34);
            fork34 = 1;
            sem_wait(&sem23);
            fork23 = 1;
            printf("Philospher 3 start eating\n");
            
            for (int i= 0;i<ToEatInOneTime;i++){
                amountOnPlate--;
            }
            fork34 = 0;
            fork23 = 0;
            printf("Philosopher 3 has done eating\n");
            sem_post(&sem23);
            sem_post(&sem34);
            sleep(0.5);
        }
        else{
            printf("Philosopher 3 plate is empty\n");
            break;
        }
        printf("---------------------------------------------------------\n");
    }
}

void *Philosopher4(void *arg){
    int amountOnPlate = AmountToEat;
    while(1){
        //printf("hi");
        
        printf("---------------------------------------------------------\n");
        if (amountOnPlate>0){
            sem_wait(&sem34);
            fork34 = 1;
            sem_wait(&sem45);
            fork45 = 1;
            printf("Philospher 4 start eating\n");
            
            for (int i= 0;i<ToEatInOneTime;i++){
                
                amountOnPlate--;
            }
            fork34 = 0;
            fork45 = 0;
            printf("Philosopher 4 has done eating\n");
            sem_post(&sem34);
            sem_post(&sem45);
            sleep(1);
        }
        else{
            printf("Philosopher 4 plate is empty\n");
            break;
        }
        printf("---------------------------------------------------------\n");
    }
}

void *Philosopher5(void *arg){
    int amountOnPlate = AmountToEat;
    while(1){
        //printf("hi");
        
        printf("---------------------------------------------------------\n");
        if (amountOnPlate>0){
            while(fork51==1 || fork45==1){
                
            }
            sem_wait(&sem15);
            fork51 = 1;
            sem_wait(&sem45);
            fork45 = 1;
            printf("Philospher 5 start eating\n");
            
            for (int i= 0;i<ToEatInOneTime;i++){
                
                amountOnPlate--;
            }
            fork51 = 0;
            fork45 = 0;
            printf("Philosopher 5 has done eating\n");
            sem_post(&sem15);
            sem_post(&sem45);
            sleep(1.5);
        }
        else{
            printf("Philosopher 5 plate is empty\n");
            break;
        }
        printf("---------------------------------------------------------\n");
    }
}
int main(){

    sem_init(&sem12,0,1);
    sem_init(&sem23,0,1);
    sem_init(&sem34,0,1);
    sem_init(&sem45,0,1);
    sem_init(&sem15,0,1);


    pthread_t p1;
    pthread_t p2;
    pthread_t p3;
    pthread_t p4;
    pthread_t p5;

    pthread_create(&p1,NULL,Philosopher1,NULL);
    pthread_create(&p2,NULL,Philosopher2,NULL);
    pthread_create(&p3,NULL,Philosopher3,NULL);
    pthread_create(&p4,NULL,Philosopher4,NULL);
    pthread_create(&p5,NULL,Philosopher5,NULL);

    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    pthread_join(p3,NULL);
    pthread_join(p4,NULL);
    pthread_join(p5,NULL);

    return 0;
}