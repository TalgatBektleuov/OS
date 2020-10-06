#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
int main(void) {
  struct rusage usage;
  for(int i=0;i<10;i++){
    int* a1 = malloc(1048576);
    memset(a1,0,1048576);
    getrusage(RUSAGE_SELF, &usage);
    int mem_in_use=usage.ru_maxrss;
    printf("%d\n",mem_in_use);
    sleep(1);
  }
//memory always increases
  return 0;
}

