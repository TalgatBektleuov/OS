#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>

#define N 10
char buffer[N];
int position=1;
int consumberIsSleeping, producerIsSleeping;
long long int t;
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
      consumberIsSleeping=0;
      producerIsSleeping=1;
      printf(", number is %lld\n", t++);
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
    pthread_t Producer_thread, Consumer_thread;
    pthread_create(&Producer_thread, NULL, produce, NULL);
    pthread_create(&Consumer_thread, NULL, consume, NULL);
    while(1);
    return 0;
    //Stopped at number 99229
}
