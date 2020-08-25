#include <stdio.h> 
#include <string.h>
void foo(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
int main() 
{ 
   int a,b;
   scanf("%d%d",&a,&b);
   printf("a=%d\nb=%d\n",a,b);
   foo(&a,&b);
   printf("SWAP\n");
   printf("a=%d\nb=%d",a,b);
   return 0; 
} 

