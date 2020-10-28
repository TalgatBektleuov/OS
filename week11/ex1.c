#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(void) {
  char* text="This is a nice day";
  size_t length=strlen(text)+1;
  FILE *file=fopen("ex1.txt","w");
  ftruncate(fileno(file),length-1);
  fclose(file);
  int file2=open("ex1.txt",O_RDWR);
  char *maping=mmap(NULL,length,PROT_WRITE|PROT_READ,MAP_SHARED,file2,0);
  for (int i=0;i<length;i++)
    maping[i]=text[i];
  return 0;
}
