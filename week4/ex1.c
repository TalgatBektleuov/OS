#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
  int n=10;
  pid_t pid;
  pid=fork();
  if(pid>0)
    printf("Hello from parent [%d-%d]\n",getpid(),n);  
  else if(pid==0)
    printf("Hello from child [%d-%d]\n",getpid(),n);
  else{
    return EXIT_FAILURE;
  }
  //after each execution, pid will change as we create new process because each process has its unique ID. getpid() returns its value
  //if pid > 0, then it is parent
  //if pid==0, then it is child
  //if id is negative, there is an error so process is waiting 
    
  return 0;
}
