#include <stdio.h>
#include <pthread.h>
int j=1;
void *show_thread(void *vargp) 
{ 
     
    sleep(1);
    printf("Message from thread #%d\n",j); //prints the message
    j++;
    return NULL; 
} 
int main(void) {
  pthread_t tid; 
  for (int i = 1; i <= 3; i++) {

    printf("Thread  #%d created\n", i);//printing message
    pthread_create(&tid, NULL, &show_thread, NULL); //new thread is created
    pthread_join(tid, NULL);//wait until the old thread exited before creating the next one
  }
  pthread_exit(NULL);
//here function pthread_join() is used to wait for thread  finishing


  return 0;
}
