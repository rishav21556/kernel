#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/resource.h>



void *count1(void *num){
    struct sched_param param;
    struct timespec getTime1;
    clock_gettime(CLOCK_REALTIME,&getTime1);
    struct timespec getTimeFinal;
    pthread_t id = pthread_self();
    setpriority(PRIO_PROCESS,0,-20);
    param.sched_priority = 0;
    if (pthread_setschedparam(id,SCHED_OTHER,&param)!=0){
        printf("Error A\n");
    }
    long long int n =pow(2,32);
    int i  = 1;
    while(i<n){   // 4294967296
        i++;
    }
    clock_gettime(CLOCK_REALTIME,&getTimeFinal);
    printf("Time taken by SCHED_OTHER_SCHEDULING --> %f\n",(getTimeFinal.tv_sec+(getTimeFinal.tv_nsec/(double)1000000000))-(getTime1.tv_sec+(getTime1.tv_nsec/(double)1000000000)));
}
void *count2(void *num){
    struct timespec getTime2;
    struct sched_param param;
    clock_gettime(CLOCK_REALTIME,&getTime2);
    
    pthread_t id = pthread_self();
    param.sched_priority = 0;
    if (pthread_setschedparam(id,SCHED_RR,&param)!=0){
        printf("Error B\n");
    }
    
    long long int n =pow(2,32);
    long long int i = 1;
    while(i<n){
        i++;
    }
    struct timespec getTimeFinal;
    clock_gettime(CLOCK_REALTIME,&getTimeFinal);
    printf("Time taken by RR_SCHEDULING (10) --> %f\n",(getTimeFinal.tv_sec+(getTimeFinal.tv_nsec/(double)1000000000))-(getTime2.tv_sec+(getTime2.tv_nsec/(double)1000000000)));
}
void *count3(void *num){
    struct timespec getTime2;
    struct sched_param param;
    clock_gettime(CLOCK_REALTIME,&getTime2);
    
    pthread_t id = pthread_self();
    param.sched_priority = 0;
    if (pthread_setschedparam(id,SCHED_FIFO,&param)!=0){
        printf("Error C\n");
    }
    
    long long int n =pow(2,32);
    long long int i = 1;
    while(i<n){
        i++;
    }
    struct timespec getTimeFinal;
    clock_gettime(CLOCK_REALTIME,&getTimeFinal);
printf("Time taken by FIFO_SCHEDULING --> %f\n",(getTimeFinal.tv_sec+(getTimeFinal.tv_nsec/(double)1000000000))-(getTime2.tv_sec+(getTime2.tv_nsec/(double)1000000000)));
}


int main(){
    pthread_t tp1;
    pthread_t tp2;
    pthread_t tp3;
    pthread_attr_t *attr;
    
    
    

    pthread_create(&tp1,NULL,count1,NULL);
    pthread_create(&tp2,NULL,count2,NULL);
    pthread_create(&tp3,NULL,count3,NULL);

    
    pthread_join(tp1,NULL);
    pthread_join(tp2,NULL);
    pthread_join(tp3,NULL);

}