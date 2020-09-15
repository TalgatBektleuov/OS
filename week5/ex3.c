#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>

#define N 10
char buffer[N];
int position=1;
int consumberIsSleeping, producerIsSleeping;
long long int number;
void* consume(void *x){
  while(1){
    if(consumberIsSleeping){
      continue;
    }
    if(position==0){
      consumberIsSleeping=1;
      producerIsSleeping=0;
      continue;
    }
    
    printf("%d", buffer[position]);
    position--;
  }
  pthread_exit(NULL);
  return NULL;
}

void* produce(void *x){
  while(1){
    if(producerIsSleeping){
      continue;
    }
    if(position==N){
      producerIsSleeping=1;
      consumberIsSleeping=0;
      
      printf(", number is %lld\n", number++);
      continue;
    }
    buffer[position]=position;
    position++;
  }
  pthread_exit(NULL);
  return NULL;
}


int main(){
    consumberIsSleeping=1;
    producerIsSleeping=0;
    pthread_t Producer_thread, Consumer_thread;
    pthread_create(&Producer_thread, NULL, produce, NULL);
    pthread_create(&Consumer_thread, NULL, consume, NULL);
    while(1);
    return 0;
    //Stopped at number 99229
}
