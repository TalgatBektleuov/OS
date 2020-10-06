#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  for(int i=0;i<10;i++){
    int* a1 = malloc(1048576);
    memset(a1,0,1048576);
    sleep(1);
  }
//si and so fields always have zero values when the program is executed with vmstat 1
//When the program is executed in background with top, VIRT field in ex2_o was constantly increasing from 3520 to 12772
//%MEM increased only once by 0.1%
  return 0;
}
