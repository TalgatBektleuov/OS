#include <stdio.h>
#include <stdlib.h>
int main(void) {
  char command[100];
 
  while(1){
    printf("Write a command: ");
    fgets(command, 10, stdin);
    system(command);
  }
  return 0;
}
