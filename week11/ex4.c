#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#include <fcntl.h>


int main(void) {
FILE *file1=fopen("ex1.txt","r");
char text1[100];
int size=0;
char text[100];
if(file1){
  while (fscanf(file1, "%s", text1)!=EOF){
    strcat(text,text1);
    strcat(text," ");
  }
  fclose(file1);
}
  size_t length=strlen(text)+1;
  FILE *file2=fopen("ex1.memcpy.txt","w");
  ftruncate(fileno(file2),length-1);
  fclose(file1);
  int file3=open("ex1.memcpy.txt",O_RDWR);
  char *maping=mmap(NULL,length,PROT_WRITE|PROT_READ,MAP_SHARED,file3,0);
  for (int i=0;i<length;i++)
    maping[i]=text[i];



  return 0;
}
