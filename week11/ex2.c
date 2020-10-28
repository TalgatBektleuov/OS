#include <stdio.h>


int main(void) {
  char text[5];
  int size=5*sizeof(char);
  setvbuf(stdin, text, _IOLBF, size);
  printf("H");
  sleep(1);
  printf("E");
  sleep(1);
  printf("L");
  sleep(1);
  printf("L");
  sleep(1);
  printf("O");
  sleep(1);

  return 0;
}
